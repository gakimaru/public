#include <stdio.h>
#include <stdlib.h>

#include <cstddef>//srd::size_t用
#include <memory.h>//memcpy用
#include <assert.h>//assert用
#include <iterator>//std::iterator用
#include <algorithm>//algorithm用

//#define DISABLE_ROTATE_FOR_ADD//ノード追加時の回転処理を無効化する場合は、このマクロを有効化する
//#define DISABLE_ROTATE_FOR_REMOVE//ノード削除時の回転処理を無効化する場合は、このマクロを有効化する

//--------------------------------------------------------------------------------
//赤黒木（red-black tree）
//※メモリ節約のために、親ノードへのリンクを持たないデータ構造とする。
//※代わりに、検索等の関数実行時に外部からスタックを渡す事で親を辿ることが可能。
//※テンプレートにより、アルゴリズムを汎用化。
//※キー重複（同キーのノードが複数ある状態）を許容するアルゴリズムとする。
//※リンクの方法に柔軟性を持たせ、かつ、virtualを避けるために、
//　CRTPを活用して、派生クラスで幾つか既定のメソッドを実装するスタイルとする。
//　（これにより、ポインタ変数によるリンクの保持以外のスタイルにも対応可能。
//　　例えば、配列のインデックスでリンクを持つようなスタイルにも対応できる。）
//※std::mapを模したコンテナとイテレータを利用可能。
//----------------------------------------
//【具体的な活用の想定：メモリ管理での活用】
//・メモリマネージャの管理情報の連結に使用することを想定。
//・空きメモリサイズ順の連結を行うため、キー重複を許容する必要がある。
//・また、連結リストが肥大化することを避けるため、親ノードへのリンク情報は
//　持たない。
//・必要量以上の空きメモリのノードを検索したのち、アラインメントを加味した
//　上で利用可能なノードかを確認し、一つずつ大きなノードを辿って最適な
//　ノードを探し出す。
//・ノード間のリンク情報は、64bitポインタ変数による肥大化が起こらないように、
//　メモリ空間の先頭からオフセットされた32bitの相対ポインタを扱う。
namespace rbtree
{
	//--------------------
	//赤黒木のデータ構造とアルゴリズム
	//【特徴】
	//・二分木である。
	//	- ノードの左側には、キーの値が自ノードより小さいノードを連結。
	//	- ノードの右側には、キーの値が自ノードより大きいノードを連結。
	//・平衡木である。
	//	- 常に左右の木のバランスを保ち、探索時間の大きな劣化がない木構造。
	//【条件】
	//・各ノードは「赤」か「黒」の「色」を持つ。
	//・「根」（root）は必ず「黒」。
	//・「赤」の子は必ず「黒」。
	//	- 待遇により、「赤」の親は必ず「黒」。
	//	- 「黒」の子は「赤」でも「黒」でも良い。
	//・すべての「根」から「葉」までの経路上にある「黒」の数は、あらゆる経路で一定。
	//--------------------
	//赤黒木ノード構造体テンプレート
	//※CRTPを活用し、下記のような派生構造体／クラスを作成して使用する
	//  //struct 派生構造体／クラス名 : public rbtree::node_t<派生構造体／クラス名, キー型, スタックの最大の深さ = 32>
	//	struct Derived : public rbtree::node_t<Derived, int>
	//	{
	//		//子ノードの取得
	//		const data_t* getNodeS() const { return ???; }//小（左）側の子ノード取得
	//		const data_t* getNodeL() const { return ???; }//大（右）側の子ノード取得
	//		//子ノードを変更
	//		void setNodeS(const data_t* node){ ??? = node; }//小（左）側の子ノードを変更
	//		void setNodeL(const data_t* node){ ??? = node; }//大（右）側の子ノードを変更
	//		
	//		//ノードの色をチェック
	//		bool isBlack() const { return ???; }//黒か？
	//		bool isRed() const { return !???; }//赤か？
	//		//ノードの色を変更
	//		void setIsBlack() { ??? = true; }//黒に変更
	//		void setIsRed() { ??? = false; }//赤に変更
	//		
	//		//キーを返す
	//		key_t getKey() const { return ???; }
	//	};
	template<class IMPL_TYPE, typename VALUE_TYPE, int STACK_DEPTH_MAX = 32>
	struct node_t
	{
		//定数
		static const int DEPTH_MAX = STACK_DEPTH_MAX;//スタックの最大の深さ

		//型
		typedef IMPL_TYPE impl_t;//実装型（struct impl_t : public rbtree::node_t<impl_t, int>）
		typedef VALUE_TYPE key_t;//キー型

		//キャストオペレータ
		//※キーを返す
		inline operator key_t() const { return static_cast<const impl_t*>(this)->getKey(); }

		//比較オペレータ
		inline bool operator==(const key_t rhs) const { return static_cast<key_t>(*this) == rhs; }
		inline bool operator!=(const key_t rhs) const { return static_cast<key_t>(*this) != rhs; }
		inline bool operator<(const key_t rhs) const { return static_cast<key_t>(*this) < rhs; }
		inline bool operator>(const key_t rhs) const { return static_cast<key_t>(*this) > rhs; }
		inline bool operator<=(const key_t rhs) const { return static_cast<key_t>(*this) <= rhs; }
		inline bool operator>=(const key_t rhs) const { return static_cast<key_t>(*this) >= rhs; }

		//キー比較メソッド
		inline int compare(const key_t rhs) const
		{
			const key_t lhs = static_cast<key_t>(*this);
			return lhs < rhs ? -1 : lhs > rhs ? 1 : 0;
		}
	};
	//--------------------
	//赤黒木操作処理用スタッククラス
	template<class T>
	class stack_t
	{
	public:
		//定数
		static const int DEPTH_MAX = T::DEPTH_MAX;//最大の深さ（スタック処理用）
	public:
		//型
		//ノード情報型
		struct info_t
		{
			const T* m_nodeRef;//ノード参照
			bool m_isLarge;//大（右）側に連結
		};
	public:
		//スタックにノード情報を記録
		void push(const T* node, const bool is_large)
		{
			assert(m_depth < DEPTH_MAX);
			info_t* stack_node = &m_array[m_depth++];
			stack_node->m_nodeRef = node;
			stack_node->m_isLarge = is_large;
		}
		//スタックからノード情報を取得
		info_t* pop()
		{
			if (m_depth == 0)
				return nullptr;
			return &m_array[--m_depth];
		}
		//スタックの現在の深さを取得
		int getDepth() const { return m_depth; }
		//スタックの現在の深さを更新
		void setDepth(const int depth)
		{
			if (depth < 0)
				m_depth = 0;
			else if (depth < m_depth)
				m_depth = depth;
		}
		//スタックの現在の深さをリセット
		void reset()
		{
			m_depth = 0;
		}
		//スタックの現在の幅を算出
		//※「幅」＝スタックの現在の深さまでの大小連結の合計値を算出
		//※小側を-1、大側を+1として計算
		int calcBreadth()
		{
			int breadth = 0;
			for (int depth = 0; depth < m_depth; ++depth)
			{
				breadth *= 2;
				breadth += (m_array[depth].m_isLarge ? 1 : 0);
			}
			return breadth;
		}
		//コピーオペレータ
		stack_t& operator=(const stack_t rhs)
		{
			m_depth = rhs.m_depth;
			memcpy(m_array, rhs.m_array, sizeof(info_t)* m_depth);
		}
		//コピーコンストラクタ
		stack_t(const stack_t& obj) :
			m_depth(obj.m_depth)
		{
			memcpy(m_array, obj.m_array, sizeof(info_t)* m_depth);
		}
		//コンストラクタ
		stack_t() :
			m_depth(0)
		{}
	private:
		//フィールド
		info_t m_array[DEPTH_MAX];//ノード情報の配列（スタック）
		int m_depth;//スタックのカレントの深さ
	};
	//--------------------
	//赤黒木操作関数：一番小さいノードを取得
	//※後からget**Node()やsearchNode()を実行できるように、スタックを渡す必要あり
	template<class T>
	const T* getSmallestNode(const T* root, stack_t<T>& stack)
	{
		if (!root)
			return nullptr;
		const T* curr_node = root;//現在の探索ノード
		while (true)
		{
			const T* child_node = curr_node->getNodeS();//小（左）側の子ノードを取得
			if (!child_node)//子が無ければ終了
				return  curr_node;
			stack.push(curr_node, false);//親ノードをスタックに記録
			curr_node = child_node;
		}
		return nullptr;
	}
	//--------------------
	//赤黒木操作関数：一番大きいノードを取得
	//※後からget**Node()やsearchNode()を実行できるように、スタックを渡す必要あり
	template<class T>
	const T* getLargestNode(const T* root, stack_t<T>& stack)
	{
		if (!root)
			return nullptr;
		const T* curr_node = root;//現在の探索ノード
		while (true)
		{
			const T* child_node = curr_node->getNodeL();//大（右）側の子ノードを取得
			if (!child_node)//子が無ければ終了
				return  curr_node;
			stack.push(curr_node, true);//親ノードをスタックに記録
			curr_node = child_node;
		}
		return nullptr;
	}
	//--------------------
	//赤黒木操作関数：カレントノードの次に大きいノードを取得
	//※get**Node()やsearchNode()でカレントノードを取得した際のスタックを渡す必要あり
	template<class T>
	const T* getNextNode(const T* curr_node, stack_t<T>& stack)
	{
		if (!curr_node)
			return nullptr;
		const T* node_l = curr_node->getNodeL();//大（右）側の子ノードを取得
		if (node_l)//子がある場合
		{
			stack.push(curr_node, true);//親ノードをスタックに記録
			return getSmallestNode(node_l, stack);//子から一番小さい子孫ノードを取得
		}
		else//if(!node_l)//子がない場合
		{
			typename stack_t<T>::info_t* stack_node = nullptr;
			while (stack_node = stack.pop())//親ノードを取得
			{
				if (stack_node->m_isLarge == false)//小（左）側の子の親なら終了
					return stack_node->m_nodeRef;
			}
		}
		return nullptr;
	}
	//--------------------
	//赤黒木操作関数：カレントノードの次に小さいノードを取得
	//※get**Node()やsearchNode()でカレントノードを取得した際のスタックを渡す必要あり
	template<class T>
	const T* getPrevNode(const T* curr_node, stack_t<T>& stack)
	{
		if (!curr_node)
			return nullptr;
		const T* node_s = curr_node->getNodeS();//小（左）側の子ノードを取得
		if (node_s)//子がある場合
		{
			stack.push(curr_node, false);//親ノードをスタックに記録
			return getLargestNode(node_s, stack);//子から一番大きい子孫ノードを取得
		}
		else//if(!node_s)//子がない場合
		{
			typename stack_t<T>::info_t* stack_node = nullptr;
			while (stack_node = stack.pop())//親ノードを取得
			{
				if (stack_node->m_isLarge == true)//大（右）側の子の親なら終了
					return stack_node->m_nodeRef;
			}
		}
		return nullptr;
	}
	//--------------------
	//赤黒木操作関数：ツリーの最大の深さを計測
	//※内部でスタックを作成
	//※-1でリストなし
	template<class T>
	int getDepthMax(const T* root)
	{
		if (!root)
			return -1;
		int depth_max = 0;//最大の深さ
		rbtree::stack_t<T> stack;//スタックを作成
		const T* node = rbtree::getSmallestNode(root, stack);//最小ノード取得
		while (node)
		{
			const int depth = stack.getDepth();//深さを取得
			depth_max = depth_max >= depth ? depth_max : depth;//最大の深さを更新
			node = rbtree::getNextNode(node, stack);//次のノード取得
		}
		return depth_max;
	}
	//--------------------
	//赤黒木操作関数：指定のキーと一致するノード、もしくは、指定のキーに最も近いノードを検索
	//※後からget**Node()やsearchNode()を実行できるように、スタックを渡す必要あり
	//※一致ノードが複数ある場合、その最初のノードを返す
	//※指定のキーの内輪で最も近いノードと同キーのノードが複数ある場合、その最後のノードを返す
	//※指定のキーより大きく最も近いノードと同キーのノードが複数ある場合、その最初のノードを返す
	enum MATCH_TYPE_T
	{
		FOR_MATCH = 0,//一致ノードを検索
		FOR_NEAREST_SMALLER,//一致ノード、もしくは、内輪で最も近いノードを検索
		FOR_NEAREST_LARGER,//一致ノード、もしくは、それより大きく最も近いノードを検索
	};
	template<class T>
	const T* searchNode(const T* root, const typename T::key_t key, stack_t<T>& stack, const MATCH_TYPE_T search_type = FOR_MATCH)
	{
		if (!root)
			return nullptr;
		const T* match_node = nullptr;//一致ノード
		int match_stack_depth = -1;//一致ノード検出時のスタック位置
		const T* nearest_node = nullptr;//最近ノード
		int nearest_stack_depth = -1;//最近ノード検出時のスタック位置
		const T* curr_node = root;//現在の探索ノード
		while (true)
		{
			const int cmp = curr_node->compare(key);//指定のキーと大小比較
			if (cmp == 0)//指定のキーと一致
			{
				//※キー重複を許容するアルゴリズムのため、
				//　一致ノードを記録した上で検索を続行する
				match_node = curr_node;//一致ノードを記録
				match_stack_depth = stack.getDepth();//一致ノード検出時のスタック位置を記録
				stack.push(curr_node, false);//仮の親ノードとしてスタックに記録
				curr_node = curr_node->getNodeS();//小（左）側の子の方に検索を続行
				if (!curr_node)//子が無ければ終了
					break;
			}
			else if (cmp < 0)//指定のキーより小さい
			{
				if (search_type == FOR_NEAREST_SMALLER && (!nearest_node || nearest_node && *nearest_node <= *curr_node))
				{
					nearest_node = curr_node;//最近ノードを記録
					nearest_stack_depth = stack.getDepth();//最近ノード検出時のスタック位置を記録
				}
				const T* child_node = curr_node->getNodeL();//大（右）側の子ノードを取得
				if (!child_node)//子が無ければ終了
					break;
				stack.push(curr_node, true);//仮の親ノードとしてスタックに記録
				curr_node = child_node;
			}
			else//if (cmp > 0)//指定のキーより大きい
			{
				if (search_type == FOR_NEAREST_LARGER && (!nearest_node || nearest_node && *nearest_node >= *curr_node))
				{
					nearest_node = curr_node;//最近ノードを記録
					nearest_stack_depth = stack.getDepth();//最近ノード検出時のスタック位置を記録
				}
				const T* child_node = curr_node->getNodeS();//小（左）側の子ノードを取得
				if (!child_node)//子が無ければ終了
					break;
				stack.push(curr_node, false);//仮の親ノードとしてスタックに記録
				curr_node = child_node;
			}
		}
		if (match_node)//一致ノード検出時
		{
			stack.setDepth(match_stack_depth);//一致ノード検出時のスタック位置に戻す
			return match_node;//一致ノードを返す
		}
		else//if (!match_node)
		{
			if (nearest_node)//最近ノード検出時
			{
				stack.setDepth(nearest_stack_depth);//最近ノード検出時のスタック位置に戻す
				return nearest_node;//最近ノードを返す
			}
		}
		return nullptr;//検索失敗
	}
	//--------------------
	//赤黒木操作関数：ツリーのノード数を計測
	template<class T>
	std::size_t countNodes(const T* node)
	{
		return !node ? 0 :
		               1 + countNodes(node->getNodeS()) +
		                   countNodes(node->getNodeL());
	}
	//--------------------
	//赤黒木操作関数：指定のキーのノード数を計測
	//※内部でスタックを作成
	template<class T>
	std::size_t countNodes(const T* root, const typename T::key_t key)
	{
		if (!root)
			return 0;
		stack_t<T> stack;
		const T* node = searchNode(root, key, stack, FOR_MATCH);
		if (!node)
			return 0;
		int count = 0;//ノード数
		while (node && *node == key)
		{
			++count;
			node = getNextNode(node, stack);
		}
		return count;
	}
	//--------------------
	//赤黒木操作関数：ノードを追加
	template<class T>
	bool addNode(T* new_node, T*& root)
	{
		if (!new_node)
			return false;
		if (!root)//ルートノードが未登録の場合
		{
			root = new_node;//ルートノードに登録
			root->setIsBlack();//ルートノードは黒
			return true;
		}
		new_node->setIsRed();//新規ノードは暫定で赤
		typename T::key_t new_key = *new_node;//新規ノードのキーを取得
		stack_t<T> stack;//スタックを用意
		const T* parent_node = nullptr;
		bool curr_is_large = false;
		const T* curr_node = root;//現在の探索ノード
		bool child_is_large = false;
		const T* child_node = nullptr;
		while (true)
		{
			child_is_large = curr_node->compare(new_key) <= 0;//指定のキーと一致もしくは指定のキーより小さければtrue
			child_node = child_is_large ?
				curr_node->getNodeL()://大（右）側の子ノードを取得
				curr_node->getNodeS();//小（左）側の子ノードを取得
			if (!child_node)//子が無ければそこに新規ノードを追加して終了
			{
				child_node = new_node;
				if (child_is_large)
					const_cast<T*>(curr_node)->setNodeL(child_node);//大（右）側の子ノードとして新規ノードを追加
				else
					const_cast<T*>(curr_node)->setNodeS(child_node);//小（左）側の子ノードとして新規ノードを追加
				break;
			}
			stack.push(curr_node, child_is_large);//親ノードをスタックに記録
			//parent_node = curr_node;
			//curr_is_large = child_is_large;
			curr_node = child_node;
		}
#ifndef DISABLE_ROTATE_FOR_ADD
		//赤黒バランス調整
		//if (parent_node && curr_node && child_node)
		if (curr_node && child_node)
		{
			bool is_rotated = false;//回転処理済みフラグ
			while (true)
			{
				const typename stack_t<T>::info_t* parent_stack_node = stack.pop();//スタックから親ノード情報取得
				if (!parent_stack_node)
					break;
				parent_node = parent_stack_node->m_nodeRef;//親ノード取得
				curr_is_large = parent_stack_node->m_isLarge;//親ノードからの大小連結情報取得
				if (is_rotated)//前回回転処理済みなら親ノードの子ノードを連結し直す
				{
					if (curr_is_large)
						const_cast<T*>(parent_node)->setNodeL(curr_node);
					else
						const_cast<T*>(parent_node)->setNodeS(curr_node);
					is_rotated = false;//回転処理済み状態リセット
				}
				if (curr_node->isRed() && child_node->isRed())//赤ノードが二つ連結していたら回転処理
				{
					//汎用左回転処理
					//      .--------[node]-------.     ⇒          .--------[node_l]
					//   [node_s]          .--[node_l]  ⇒     .--[node]--.          
					//                  [node_ls]       ⇒  [node_s]  [node_ls]      
					auto rotateL = [](const T* node) -> const T*
					{
						const T* node_l = node->getNodeL();
						const T* node_ls = node_l->getNodeS();
						const_cast<T*>(node_l)->setNodeS(node);
						const_cast<T*>(node)->setNodeL(node_ls);
						return node_l;
					};
					//汎用右回転処理
					//      .--------[node]-------.        ⇒  [node_s]-------.         
					//   [node_s]--.          [node_l]     ⇒           .---[node]--.   
					//         [node_sl]                   ⇒        [node_sl]  [node_l]
					auto rotateR = [](const T* node) -> const T*
					{
						const T* node_s = node->getNodeS();
						const T* node_sl = node_s->getNodeL();
						const_cast<T*>(node_s)->setNodeL(node);
						const_cast<T*>(node)->setNodeS(node_sl);
						return node_s;
					};
					//親ノードを軸にした左回転処理
					//     .------[parent_node:B]------.              ⇒            .------[curr_node:R]------.       
					//   [(S)]              .--[curr_node:R]--.       ⇒    .--[parent_node:B]--.       [child_node:R]
					//                   [(LS)]       [child_node:R]  ⇒  [(S)]              [(LS)]                   
					//
					//                                                ⇒           .------[parent_node:R]------.     
					//                                                ⇒    .--[(S):B]--.               [curr_node:B]
					//                                                ⇒  [(SS)]     [(SL)]                          
					auto rotateParentL = [&]() -> const T*
					{
						parent_node = rotateL(parent_node);//回転処理
						curr_is_large = true;
						curr_node = child_node;
						const_cast<T*>(curr_node)->setIsBlack();
						//child_is_large = true;
						//child_node = nullptr;
						return parent_node;
					};
					//親ノードを軸にした右回転処理
					//                .-----[parent_node:B]-----.    ⇒        .------[curr_node:R]------.           
					//        .--[curr_node:R]--.             [(L)]  ⇒  [child_node:R]       .--[parent_node:B]--.  
					//   [child_node:R]      [(SL)]                  ⇒                     [(SL)]              [(L)]
					//
					//                                               ⇒       .------[parent_node:R]------.         
					//                                               ⇒  [curr_node:B]              .--[(L):B]--.   
					//                                               ⇒                           [(LS)]     [(LL)]
					auto rotateParentR = [&]() -> const T*
					{
						parent_node = rotateR(parent_node);//回転処理
						curr_is_large = false;
						curr_node = child_node;
						const_cast<T*>(curr_node)->setIsBlack();
						//child_is_large = false;
						//child_node = nullptr;
						return parent_node;
					};
					//現在のノードを軸にした左回転処理
					//     .-----[curr_node:R]-----.          ⇒           .--------[child_node:R]
					//   [(S)]             .--[child_node:R]  ⇒    .--[curr_node:R]--.         
					//                  [(LS)]                ⇒  [(S)]            [(LS)]      
					//
					//                                        ⇒            .------[curr_node:R]
					//                                        ⇒    .--[child_node:R]--.       
					//                                        ⇒  [(SS)]            [(SL)]       
					auto rotateCurrL = [&]() -> const T*
					{
						const T* curr_node_old = curr_node;
						curr_node = rotateL(curr_node);//回転処理
						child_is_large = false;
						child_node = curr_node_old;
						return curr_node;
					};
					//現在のノードを軸にした右回転処理
					//            .-----[curr_node:R]-----.    ⇒  [child_node:R]-----.           
					//   .--[child_node:R]--.           [(L)]  ⇒           .---[curr_node:R]--.  
					//                   [(SS)]                ⇒         [(SS)]             [(L)]
					//
					//                                         ⇒  [curr_node:R]-----.             
					//                                         ⇒           .---[child_node:R]--.  
					//                                         ⇒         [(LS)]             [(LL)]
					auto rotateCurrR = [&]() -> const T*
					{
						const T* curr_node_old = curr_node;
						curr_node = rotateR(curr_node);//回転処理
						child_is_large = true;
						child_node = curr_node_old;
						return curr_node;
					};
					//回転処理
					if (!curr_is_large && !child_is_large)//小（左）→小（左）連結時：親を軸に右回転
					{
						rotateParentR();
					}
					else if (!curr_is_large &&  child_is_large)//小（左）→大（右）連結時：左回転→親を軸に右回転
					{
						const_cast<T*>(parent_node)->setNodeS(rotateCurrL());
						rotateParentR();
					}
					else if (curr_is_large && !child_is_large)//大（右）→小（左）連結時：右回転→親を軸に左回転
					{
						const_cast<T*>(parent_node)->setNodeL(rotateCurrR());
						rotateParentL();
					}
					else//if (!curr_is_large && !child_is_large)//大（右）→大（右）連結時：親を軸に左回転
					{
						rotateParentL();
					}
					is_rotated = true;
				}
				//親ノードに処理を移す
				child_is_large = curr_is_large;
				child_node = curr_node;
				curr_node = parent_node;
			}
			if (curr_node)
			{
				root = const_cast<T*>(curr_node);//ルートノードを更新
				root->setIsBlack();//ルートノードは黒
			}
		}
#endif//DISABLE_ROTATE_FOR_ADD
		return true;
	}
	//--------------------
	//赤黒木操作関数：ノードを削除
	template<class T>
	bool removeNode(const T* target_node, T*& root)
	{
		if (!target_node || !root)
			return false;
		stack_t<T> stack;//スタックを用意
		const typename T::key_t remove_key = *target_node;//削除ノードのキーを取得
		T* remove_node = const_cast<T*>(searchNode(root, remove_key, stack));//削除ノードと同キーのノード検索
		if (!remove_node)//削除ノードと同キーのノードがなければ終了
			return false;
		while (remove_node != target_node && *remove_node == remove_key)//削除ノード検索
		{
			remove_node = const_cast<T*>(getNextNode(remove_node, stack));
		}
		if (remove_node != target_node)//削除ノードがなければ終了
			return false;
		//削除開始
		T* parent_node = nullptr;//削除ノードの親ノード
		bool parent_is_large = false;//削除ノードの親ノードからの連結方向
		{
			const typename stack_t<T>::info_t* parent_info = stack.pop();//親ノード参照情報を取得
			if (parent_info)
			{
				parent_node = const_cast<T*>(parent_info->m_nodeRef);//親ノードを取得
				parent_is_large = parent_info->m_isLarge;//親ノードからの連結方向
			}
		}
		T* node_s = const_cast<T*>(remove_node->getNodeS());//小（左）側の子ノードを取得
		T* node_l = const_cast<T*>(remove_node->getNodeL());//大（右）側の子ノードを取得
		T* node_sl = nullptr;//削除ノードの最大子孫ノード（削除ノードの次に小さいノード）
		if (node_s && node_l)//大小両方の子がある場合、最大子孫ノード検索
		{
			stack.reset();//スタックをリセット
			node_sl = const_cast<T*>(getLargestNode(node_s, stack));//最大子孫ノードを取得
			const typename stack_t<T>::info_t* sl_parent_info = stack.pop();//最大子孫ノードの親ノードを取得
			if (sl_parent_info)
			{
				T* sl_parent_node = const_cast<T*>(sl_parent_info->m_nodeRef);//最大子孫ノードの親ノードを取得
				sl_parent_node->setNodeL(node_sl->getNodeS());//最大子孫ノードを親ノードから切り離し
			}
			node_sl->setNodeL(node_l);//最大子孫ノードの大側の子を変更
			if (node_sl != node_s)
				node_sl->setNodeS(node_s);//最大子孫ノードの小側の子を変更
		}
		T* replace_node =//削除ノードと置き換えるノード
			( node_s && !node_l) ? node_s ://小（左）側の子ノード
			(!node_s &&  node_l) ? node_l ://大（右）側の子ノード
			( node_s &&  node_l) ? node_sl://最大子孫ノード
			//(!node_s && !node_l) ?
			                       nullptr;//ノード削除
		if (!parent_node)//親ノードがない場合 → ルートノードが削除ノード
			root = replace_node;//ルートノードを置き換え
		else//if(parent_node)//親ノードがある場合
		{
			if (parent_is_large)
				parent_node->setNodeL(replace_node);//親ノードの大（右）側の子ノードを置き換え
			else//if (!parent_is_large)
				parent_node->setNodeS(replace_node);//親ノードの小（左）側の子ノードを置き換え
		}
		return true;
	}
	//--------------------
	//赤黒木コンテナ
	//※ルートのリンクを持つのみ
	//※std::mapを模した構造
	template<class T>
	class container
	{
	public:
		//型
		typedef stack_t<T> stack_type;
		typedef T node_type;
		typedef typename T::key_t key_type;
		typedef std::size_t size_type;
	public:
		//--------------------
		//イテレータ
		class iterator;
		typedef const iterator const_iterator;
		class iterator : public std::iterator<std::bidirectional_iterator_tag, T>
		{
			friend class container;
		public:
			//キャストオペレータ
			operator const node_type() const { return *m_node; }
			operator node_type(){ return *m_node; }
			operator key_type() const { return static_cast<key_type>(*m_node); }
		public:
			//オペレータ
			const node_type& operator*() const { return *m_node; }
			node_type& operator*(){ return *m_node; }
			const node_type* operator->() const { return m_node; }
			node_type* operator->(){ return m_node; }
			//比較オペレータ
			bool operator==(const_iterator& rhs) const
			{
				return m_node == nullptr && rhs.m_node == nullptr ? true :
				       m_node == nullptr || rhs.m_node == nullptr ? false :
				       m_node->getKey() == rhs.m_node->getKey();
			}
			bool operator!=(const_iterator& rhs) const
			{
				return m_node == nullptr && rhs.m_node == nullptr ? false :
				       m_node == nullptr || rhs.m_node == nullptr ? true :
				       m_node->getKey() != rhs.m_node->getKey();
			}
			bool operator<(const_iterator& rhs) const
			{
				return m_node == nullptr || rhs.m_node == nullptr ? false :
				       m_node->getKey() < rhs.m_node->getKey();
			}
			bool operator>(const_iterator& rhs) const
			{
				return m_node == nullptr || rhs.m_node == nullptr ? false :
				       m_node->getKey() > rhs.m_node->getKey();
			}
			bool operator<=(const_iterator& rhs) const
			{
				return m_node == nullptr || rhs.m_node == nullptr ? false :
				       m_node->getKey() <= rhs.m_node->getKey();
			}
			bool operator>=(const_iterator& rhs) const
			{
				return m_node == nullptr || rhs.m_node == nullptr ? false :
				       m_node->getKey() >= rhs.m_node->getKey();
			}
			//演算オペレータ
			const_iterator& operator++() const
			{
				m_node = const_cast<node_type*>(getNextNode(m_node, m_stack));
				return *this;
			}
			const_iterator& operator--() const
			{
				m_node = const_cast<node_type*>(getPrevNode(m_node, m_stack));
				return *this;
			}
			iterator& operator++()
			{
				m_node = const_cast<node_type*>(getNextNode(m_node, m_stack));
				return *this;
			}
			iterator& operator--()
			{
				m_node = const_cast<node_type*>(getPrevNode(m_node, m_stack));
				return *this;
			}
			const_iterator operator++(int) const
			{
				iterator ite(*this);
				++(*this);
				return ite;
			}
			const_iterator operator--(int) const
			{
				iterator ite(*this);
				--(*this);
				return ite;
			}
			iterator operator++(int)
			{
				iterator ite(*this);
				++(*this);
				return ite;
			}
			iterator operator--(int)
			{
				iterator ite(*this);
				--(*this);
				return ite;
			}
			const_iterator& operator+=(const int val) const
			{
				for (int i = 0; i < val; ++i)
					++(*this);
				return *this;
			}
			const_iterator& operator-=(const int val) const
			{
				for (int i = 0; i < val; ++i)
					--(*this);
				return *this;
			}
			iterator& operator+=(const int val)
			{
				for (int i = 0; i < val; ++i)
					++(*this);
				return *this;
			}
			iterator& operator-=(const int val)
			{
				for (int i = 0; i < val; ++i)
					--(*this);
				return *this;
			}
			const_iterator operator+(const int val) const
			{
				iterator ite(*this);
				ite += val;
				return ite;
			}
			const_iterator operator-(const int val) const
			{
				iterator ite(*this);
				ite -= val;
				return ite;
			}
			iterator operator+(const int val)
			{
				iterator ite(*this);
				ite += val;
				return ite;
			}
			iterator operator-(const int val)
			{
				iterator ite(*this);
				ite -= val;
				return ite;
			}
		public:
			//コピーオペレータ
			iterator& operator=(const_iterator& rhs)
			{
				m_stack = rhs.m_stack;
				m_node = rhs.m_node;
			}
		public:
			//リセット
			void reset() const
			{
				m_stack.reset();
				m_node = nullptr;
			}
		public:
			//コピーコンストラクタ
			iterator(const_iterator& obj) :
				m_stack(obj.m_stack),
				m_node(obj.m_node)
			{}
			//コンストラクタ
			iterator() :
				m_stack(),
				m_node(nullptr)
			{}
			iterator(const node_type* node, const stack_type& stack) :
				m_stack(*const_cast<stack_type*>(&stack)),
				m_node(const_cast<node_type*>(node))
			{}
			//デストラクタ
			~iterator()
			{}
		protected:
			//フィールド
			mutable stack_type m_stack;//スタック
			mutable node_type* m_node;//現在のノード
		};
		//--------------------
		//リバースイテレータ
		//※begin(), end() の要件が若干特殊なので、
		//　std::reverse_iterator<iterator>を使わずに実装（偽装）する。
		//　中身はoperatorの+と-を逆転しているだけで、通常のイテレータと同じ。
		class reverse_iterator;
		typedef const reverse_iterator const_reverse_iterator;
		class reverse_iterator : public iterator
		{
		public:
			//演算オペレータ
			const_reverse_iterator& operator++() const
			{
				return static_cast<const_reverse_iterator&>(iterator::operator--());
			}
			const_reverse_iterator& operator--() const
			{
				return static_cast<const_reverse_iterator&>(iterator::operator++());
			}
			reverse_iterator& operator++()
			{
				return static_cast<reverse_iterator&>(iterator::operator--());
			}
			reverse_iterator& operator--()
			{
				return static_cast<reverse_iterator&>(iterator::operator++());
			}
			const_reverse_iterator operator++(int) const
			{
				return static_cast<const_reverse_iterator&>(iterator::operator--(0));
			}
			const_reverse_iterator operator--(int) const
			{
				return static_cast<const_reverse_iterator&>(iterator::operator++(0));
			}
			reverse_iterator operator++(int)
			{
				return static_cast<reverse_iterator&>(iterator::operator--(0));
			}
			reverse_iterator operator--(int)
			{
				return static_cast<reverse_iterator&>(iterator::operator++(0));
			}
			const_reverse_iterator& operator+=(const int val) const
			{
				return static_cast<const_reverse_iterator&>(iterator::operator-=(val));
			}
			const_reverse_iterator& operator-=(const int val) const
			{
				return static_cast<const_reverse_iterator&>(iterator::operator+=(val));
			}
			reverse_iterator& operator+=(const int val)
			{
				return static_cast<reverse_iterator&>(iterator::operator-=(val));
			}
			reverse_iterator& operator-=(const int val)
			{
				return static_cast<reverse_iterator&>(iterator::operator+=(val));
			}
			const_reverse_iterator operator+(const int val) const
			{
				return static_cast<const_reverse_iterator&>(iterator::operator-(val));
			}
			const_reverse_iterator operator-(const int val) const
			{
				return static_cast<const_reverse_iterator&>(iterator::operator+(val));
			}
			reverse_iterator operator+(const int val)
			{
				return static_cast<reverse_iterator&>(iterator::operator-(val));
			}
			reverse_iterator operator-(const int val)
			{
				return static_cast<reverse_iterator&>(iterator::operator+(val));
			}
		public:
			//コピーコンストラクタ
			reverse_iterator(const_iterator& obj) :
				iterator(obj)
			{}
			//コンストラクタ
			reverse_iterator() :
				iterator()
			{}
			reverse_iterator(const node_type* node, const stack_type& stack) :
				iterator(node, stack)
			{}
			//デストラクタ
			~reverse_iterator()
			{}
		};
	public:
		//メソッド：イテレータ系
		const_iterator& _begin(const_iterator& ite) const
		{
			ite.m_node = const_cast<node_type*>(getSmallestNode(m_root, ite.m_stack));
			return ite;
		}
		const_iterator& _end(const_iterator& ite) const
		{
			ite.reset();
			return ite;
		}
		const_iterator cbegin() const
		{
			iterator ite;
			return _begin(ite);
		}
		const_iterator cend() const
		{
			iterator ite;
			return _end(ite);
		}
		const_iterator begin() const
		{
			iterator ite;
			return _begin(ite);
		}
		const_iterator end() const
		{
			iterator ite;
			return _end(ite);
		}
		iterator begin()
		{
			iterator ite;
			return _begin(ite);
		}
		iterator end()
		{
			iterator ite;
			return _end(ite);
		}
		//メソッド：リバースイテレータ系
		const_reverse_iterator& _rbegin(const_reverse_iterator& ite) const
		{
			ite.m_node = const_cast<node_type*>(getLargestNode(m_root, ite.m_stack));
			return ite;
		}
		const_reverse_iterator& _rend(const_reverse_iterator& ite) const
		{
			ite.reset();
			return ite;
		}
		const_reverse_iterator crbegin() const
		{
			reverse_iterator ite;
			return _rbegin(ite);
		}
		const_reverse_iterator crend() const
		{
			reverse_iterator ite;
			return _rend(ite);
		}
		const_reverse_iterator rbegin() const
		{
			reverse_iterator ite;
			return _rbegin(ite);
		}
		const_reverse_iterator rend() const
		{
			reverse_iterator ite;
			return _rend(ite);
		}
		reverse_iterator rbegin()
		{
			reverse_iterator ite;
			return _rbegin(ite);
		}
		reverse_iterator rend()
		{
			reverse_iterator ite;
			return _rend(ite);
		}
		//メソッド：容量系
		bool empty() const { return m_root == nullptr; }
		size_type size() const { return countNodes(m_root); }
		//size_type max_size() const { return countNodes(m_root); }
		int depth_max() const { return getDepthMax(m_root); }
		//メソッド：要素アクセス系
		//※std::mapと異なり、ノードのポインタを返す
		inline const node_type* _at(const key_type key) const
		{
			stack_type stack;
			return searchNode(m_root, key, stack, FOR_MATCH);
		}
		const node_type* at(const key_type key) const { return _at(key); }
		node_type* at(const key_type key){ return const_cast<node_type*>(_at(key)); }
		const node_type* operator[](const key_type key) const { return _at(key); }
		node_type* operator[](const key_type key){ return const_cast<node_type*>(_at(key)); }
		//メソッド：追加／削除系
		//※std::mapと異なり、ノードを直接指定し、結果をbool型で受け取る
		//※要素のメモリ確保／削除を行わない点に注意
		bool insert(const node_type& node){ return addNode(const_cast<node_type*>(&node), m_root); }
		bool erase(const node_type& node){ return removeNode(&node, m_root); }
		void clear(){ m_root = nullptr; }
		//メソッド：検索系
		//※lower_bound(), upper_bound()には非対応
		//※代わりに、find_nearestに対応
		const_iterator& _find(const_iterator& ite, const key_type key, const MATCH_TYPE_T type = FOR_MATCH) const
		{
			ite.m_node = const_cast<node_type*>(searchNode(m_root, key, ite.m_stack, type));
			return ite;
		}
		const_iterator find(const key_type key, const MATCH_TYPE_T type = FOR_MATCH) const
		{
			const_iterator ite;
			return _find(ite, key, type);
		}
		iterator find(const key_type key, const MATCH_TYPE_T type = FOR_MATCH)
		{
			iterator ite;
			return _find(ite, key, type);
		}
		size_type count(const key_type key) const { return countNodes(m_root, key); }
		const_iterator& _equal_range(const_iterator& ite, const key_type key) const
		{
			ite.m_node = const_cast<node_type*>(searchNode(m_root, key, ite.m_stack, FOR_MATCH));
			while (ite.m_node && *ite == key)
				++ite;
			return ite;
		}
		const_iterator equal_range(const key_type key) const
		{
			const_iterator ite;
			return _equal_range(ite, key);
		}
		iterator equal_range(const key_type key)
		{
			iterator ite;
			return _equal_range(ite, key);
		}
		//その他
		const node_type* root() const { return m_root; }//ルートノードを取得
		node_type*& root_ref(){ return m_root; }//ルートノードの参照を取得
	public:
		//コピーコンストラクタ
		container(const container& con) :
			m_root(con.m_root)
		{}
		//コンストラクタ
		container() :
			m_root(nullptr)
		{}
		//デストラクタ
		~container()
		{}
	private:
		//フィールド
		node_type* m_root;//ルートノード
	};
}//namespace rbtree

//--------------------------------------------------------------------------------
//赤黒木テスト

#include <algorithm>//std::max用
#include <random>//C++11 std::random用

//----------------------------------------
//テストデータ
struct data_t : public rbtree::node_t<data_t, int>
{
	//子ノードの取得
	const data_t* getNodeS() const { return m_nodeS; }//小（左）側の子ノード取得
	const data_t* getNodeL() const { return m_nodeL; }//大（右）側の子ノード取得
	//子ノードを変更
	void setNodeS(const data_t* node){ m_nodeS = node; }//小（左）側の子ノードを変更
	void setNodeL(const data_t* node){ m_nodeL = node; }//大（右）側の子ノードを変更

	//ノードの色をチェック
	bool isBlack() const { return m_isBlack; }//黒か？
	bool isRed() const { return !m_isBlack; }//赤か？
	//ノードの色を変更
	void setIsBlack() { m_isBlack = true; }//黒に変更
	void setIsRed() { m_isBlack = false; }//赤に変更

	//キーを返す
	key_t getKey() const { return m_key; }

	//コンストラクタ
	data_t(const key_t key) :
		m_nodeS(nullptr),
		m_nodeL(nullptr),
		m_isBlack(false),
		m_key(key)
	{}
	data_t() :
		m_nodeS(nullptr),
		m_nodeL(nullptr),
		m_isBlack(false),
		m_key(0)
	{}

	//フィールド
	const data_t* m_nodeS;//小（左）側のノード
	const data_t* m_nodeL;//大（右）側のノード
	bool m_isBlack;//ノードの色
	key_t m_key;//キー
};

//----------------------------------------
//テスト
int main(const int argc, const char* argv[])
{
	static const int key_min = 0;//最小キー
	static const int key_max = 99;//最大キー
	static const int reg_num = 100;//登録数

	//赤黒木コンテナ
	typedef rbtree::container<data_t> container_t;
	typedef container_t::iterator iterator;
	typedef container_t::const_iterator const_iterator;
	typedef container_t::reverse_iterator reverse_iterator;
	typedef container_t::const_reverse_iterator const_reverse_iterator;
	container_t con;

	//データを登録
	auto regList = [&con]()
	{
		printf("--- make table ---\n");
		std::mt19937 rand_engine;
		rand_engine.seed(0);
		std::uniform_int_distribution<int> rand_dist(key_min, key_max);
		for (int i = 0; i < reg_num; ++i)
		{
			data_t* new_node = new data_t(rand_dist(rand_engine));
			printf("[%2d] ", new_node->getKey());
			con.insert(*new_node);
		}
		printf("\n");
	};
	regList();

	//ツリーを表示
	auto showTree = [&con]()
	{
		printf("--- show tree ---\n");
		static const int depth_limit = 5;
		const int _depth_max = con.depth_max();
		printf("depth_max=%d (show limit=%d)\n", _depth_max, depth_limit);
		const int depth_max = _depth_max <= depth_limit ? _depth_max : depth_limit;
		const int width_max = static_cast<int>(std::pow(2, depth_max));
		for (int depth = 0; depth <= depth_max; ++depth)
		{
			const int width = static_cast<int>(std::pow(2, depth));
			static const int label_len = 6;
			const int print_width = (width_max * label_len) / width;
			const int print_indent = (print_width - label_len) / 2;
			for (int breath = 0; breath < width; ++breath)
			{
				const data_t* node = con.root();
				int breath_tmp = breath;
				for (int depth_tmp = depth - 1; node; --depth_tmp)
				{
					if (depth_tmp < 0)
						break;
					node = (breath_tmp & (0x1 << depth_tmp)) ?
						node->getNodeL() :
						node->getNodeS();
				}
				if (node)
				{
					{
						int c = 0;
						for (; c < print_indent / 2; ++c)
							printf(" ");
						if (node->getNodeS() && c < print_indent)
						{
							printf(".");
							++c;
						}
						for (; c < print_indent; ++c)
							printf(node->getNodeS() ? "-" : " ");
					}
					printf("%s%2d:%c%s", node->getNodeS() ? "{" : "[", node->getKey(), node->isBlack() ? 'B' : 'R', node->getNodeL() ? "}" : "]");
					{
						int c = 0;
						for (; c < print_indent / 2; ++c)
							printf(node->getNodeL() ? "-" : " ");
						if (node->getNodeL() && c < print_indent)
						{
							printf(".");
							++c;
						}
						for (; c < print_indent; ++c)
							printf(" ");
					}
				}
				else
				{
					for (int c = 0; c < print_width; ++c)
						printf(" ");
				}
			}
			printf("\n");
		}
	};
	showTree();

	//各枝までのノード数を表示
	auto showNodesCount = [&con]()
	{
		printf("--- show nodes count ---\n");
		const int depth_max = con.depth_max();
		const int width_max = static_cast<int>(std::pow(2, depth_max));
		printf("depth_max=%d, width_max=%d\n", depth_max, width_max);
		const data_t* prev_node = nullptr;
		int blacks_min = 0;
		int blacks_max = 0;
		int reds_min = 0;
		int reds_max = 0;
		int total_min = 0;
		int total_max = 0;
		for (int breath = 0; breath < width_max; ++breath)
		{
			int blacks = 0;
			int reds = 0;
			const data_t* last_node = nullptr;
			int breath_tmp = breath;
			const data_t* node = con.root();
			for (int depth_tmp = depth_max - 1; node; --depth_tmp)
			{
				last_node = node;
				if (node->isBlack())
					++blacks;
				else
					++reds;
				if (depth_tmp < 0)
					break;
				node = (breath_tmp & (0x1 << depth_tmp)) ?
					node->getNodeL() :
					node->getNodeS();
			}
			int total = blacks + reds;
			blacks_min = blacks_min > blacks || blacks_min == 0 ? blacks : blacks_min;
			blacks_max = blacks_max < blacks || blacks_max == 0 ? blacks : blacks_max;
			reds_min = reds_min > reds || reds_min == 0 ? reds : reds_min;
			reds_max = reds_max < reds || reds_max == 0 ? reds : reds_max;
			total_min = total_min > total || total_min == 0 ? total : total_min;
			total_max = total_max < total || total_max == 0 ? total : total_max;
			if (prev_node != last_node)
				printf("%5d:[%2d] blacks=%d, reds=%d, total=%d\n", breath, last_node->getKey(), blacks, reds, total);
			prev_node = last_node;
		}
		printf("max: blacks=%d, reds=%d, total=%d\n", blacks_max, reds_max, total_max);
		printf("min: blacks=%d, reds=%d, total=%d\n", blacks_min, reds_min, total_min);
		printf("diff:blacks=%d, reds=%d, total=%d\n", blacks_max - blacks_min, reds_max - reds_min, total_max - total_min);
	};
	showNodesCount();

	//一番小さいノードから昇順に全ノードをリストアップ
	auto showListAsc = [&con]()
	{
		printf("--- get smallest node -> get next node (count=%d) ---\n", con.size());
		bool is_found = false;
		for (const data_t& obj : con)//C++11形式の範囲に基づくforループ
		{
			if (!is_found)
				is_found = true;
			printf("[%2d] ", obj.getKey());
		}
		//※イテレータの変数宣言と値の更新を分けた方が若干効率的
		//const_reverse_iterator ite;con._begin(ite);
		//const_reverse_iterator end;con._end(end);
		//for (; ite != end; ++ite)
		//{
		//	const data_t& obj = *ite;
		//	...
		//}
		if (is_found)
			printf("\n");
		else
			printf("(nothing)\n");
	};
	showListAsc();

	//一番大きいノードから降順に全ノードをリストアップ
	auto showListDesc = [&con]()
	{
		printf("--- get largest node -> get previous node (count=%d) ---\n", con.size());
		bool is_found = false;
		std::for_each(con.rbegin(), con.rend(),
			[&is_found](const data_t& obj)
			{
				if (!is_found)
					is_found = true;
				printf("[%2d] ", obj.getKey());
			}
		);
		//※イテレータの変数宣言と値の更新を分けた方が効率的
		//const_reverse_iterator ite;con._rbegin(ite);
		//const_reverse_iterator end;con._rend(end);
		//for (; ite != end; ++ite)
		//{
		//	const data_t& obj = *ite;
		//	...
		//}
		if (is_found)
			printf("\n");
		else
			printf("(nothing)\n");
	};
	showListDesc();

	//指定のキーのノードを検索し、同じキーのノードをリストアップ
	auto searchData = [&con]()
	{
		printf("--- search node ---\n");
		for (int search_key = key_min; search_key <= key_max; ++search_key)
		{
			rbtree::stack_t<data_t> stack;
			bool is_found = false;
			std::for_each(con.find(search_key), con.equal_range(search_key),
				[&con, &is_found, &search_key](const data_t& obj)
				{
					if (!is_found)
					{
						printf("%2d(%d):", search_key, con.count(search_key));
						is_found = true;
					}
					printf("[%2d] ", obj.getKey());
				}
			);
			//※イテレータの変数宣言と検索を分けた方が効率的
			//const_iterator ite;con._find(ite, search_key);
			//const_iterator end;con._equal_range(end, search_key);
			//for (; ite != end; ++ite)
			//{
			//	const data_t& obj = *ite;
			//	...
			//}
			if (is_found)
				printf("\n");
		}
	};
	searchData();

	//指定のキーと同じか内輪で一番近いノードを検索
	//※一致ノードは表示を省略
	//※最近ノードから数ノードを表示
	auto searchNearestData = [&con](const rbtree::MATCH_TYPE_T search_type)
	{
		printf("--- search nearest node for %s ---\n", search_type == rbtree::FOR_NEAREST_SMALLER ? "smaller" : search_type == rbtree::FOR_NEAREST_LARGER ? "larger" : "same");
		for (int search_key = key_min; search_key <= key_max; ++search_key)
		{
			rbtree::stack_t<data_t> stack;
			bool is_found = false;
			const_iterator ite(con.find(search_key, search_type));
			const_iterator end(con.end());
			for (int i = 0; ite != end && *ite != search_key && i < 4; ++i, ++ite)
			{
				const data_t& obj = *ite;
				if (!is_found)
				{
					printf("%2d:", search_key);
					is_found = true;
				}
				printf("[%2d] ", obj.getKey());
			}
			//※イテレータの変数宣言と検索を分けた方が若干効率的
			//const_iterator ite;con._find(ite, search_key, search_type);
			//const_iterator end;con._end(end);
			//...
			if (is_found)
				printf("\n");
		}
	};
	searchNearestData(rbtree::FOR_NEAREST_SMALLER);

	//指定のキーと同じかそれより大きい最近ノードを検索
	searchNearestData(rbtree::FOR_NEAREST_LARGER);

	//ノードを削除
	//※すべての値のキーを一つずつ削除
	auto removeNodes = [&con]()
	{
		printf("--- remove nodes ---\n");
		for (int search_key = key_min; search_key <= key_max; ++search_key)
		{
			const_iterator ite(con.find(search_key));
			const bool result = con.erase(*ite);
			//※イテレータの変数宣言と検索を分けた方が若干効率的
			//const_iterator ite;con._find(ite, search_key);
			//...
			if (result)
				printf("[%2d] ", search_key);
		}
		printf("\n");
	};
	removeNodes();

	//ツリーを表示
	showTree();

	//黒ノード数を表示
	showNodesCount();
	
	//一番小さいノードから昇順に全ノードをリストアップ
	showListAsc();

	//ノードを全削除
	//※すべての値のキーに対して、削除が失敗するまで削除を実行
	auto removeAllNodes = [&con]()
	{
		printf("--- remove all nodes ---\n");
		for (int search_key = key_min; search_key <= key_max;)
		{
			const_iterator ite(con.find(search_key));
			const bool result = con.erase(*ite);
			//※イテレータの変数宣言と検索を分けた方が若干効率的
			//const_iterator ite;con._find(ite, search_key);
			//...
			if (result)
				printf("[%2d] ", search_key);
			else
				++search_key;
		}
		printf("\n");
	};
	removeAllNodes();

	//一番小さいノードから昇順に全ノードをリストアップ
	showListAsc();

	return EXIT_SUCCESS;
}

// End of file
