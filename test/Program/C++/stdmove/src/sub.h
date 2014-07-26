//検証用構造体Ａ：ムーブオペレータ／ムーブコンストラクタなし
struct type_a
{
	int var;
	type_a& operator=(const type_a& rhs);//コピーオペレータ
	type_a(const type_a& obj);//コピーコンストラクタ
	type_a(const int v);//コンストラクタ
	type_a();//コンストラクタ
	~type_a();//デストラクタ
};

//検証用構造体Ｂ：ムーブオペレータ／ムーブコンストラクタあり
struct type_b
{
	int var;
	type_b& operator=(const type_b& rhs);//コピーオペレータ
	type_b(const type_b& obj);//コピーコンストラクタ
	type_b& operator=(type_b&& rhs);//ムーブオペレータ
	type_b(type_b&& obj);//ムーブコンストラクタ
	type_b(const int v);//コンストラクタ
	type_b();//コンストラクタ
	~type_b();//デストラクタ
};

//【動作比較】
//パターンＡ①：戻り値を普通に返す
type_a getA(const int v);
//パターンＡ②：戻り値をstd::move()で返す
type_a getA_v(const int v);
//パターンＢ①：戻り値を普通に返す
type_b getB(const int v);
//パターンＢ②：戻り値をstd::move()で返す
type_b getB_v(const int v);

//--------------------------------------------------------------------------------
//完全な受け渡しテスト

//Perfectforward（完全な受け渡し）テスト用構造体
struct forPerfectForward
{
	int m_val1;
	int m_val2;

	//ムーブコンストラクタ
	forPerfectForward(const forPerfectForward&& obj);
	//コピーコンストラクタ
	forPerfectForward(const forPerfectForward& obj);
	//コンストラクタ（初期値を右辺値参照渡し）
	forPerfectForward(const int&& val1, const int&& val2);
	//コンストラクタ（初期値を参照渡し）
	forPerfectForward(const int& val1, const int& val2);
	//デフォルトコンストラクタ
	forPerfectForward();
};
//初期化用関数
#include <new>//配置new
#include <utility>//std::forward()
template<typename... Tx>
void initForPerfectForward(forPerfectForward& obj, Tx&&... args)
{
	new(&obj)forPerfectForward(std::forward<Tx>(args)...);
}

// End of file
