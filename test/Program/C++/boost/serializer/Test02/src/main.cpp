#include <fstream>//ファイル入出力ストリーム
#include <boost/serialization/serialization.hpp>//シリアライズ

#include <boost/archive/text_oarchive.hpp>//テキスト出力アーカイブ
#include <boost/archive/text_iarchive.hpp>//テキスト入力アーカイブ

#include <boost/archive/binary_oarchive.hpp>//バイナリ出力アーカイブ
#include <boost/archive/binary_iarchive.hpp>//バイナリ入力アーカイブ

#include <boost/archive/xml_oarchive.hpp>//XML出力アーカイブ
#include <boost/archive/xml_iarchive.hpp>//XML入力アーカイブ

#include <boost/serialization/string.hpp>//std::string用
#include <boost/serialization/vector.hpp>//std::vector用
#include <boost/serialization/list.hpp>//std::list用
#include <boost/serialization/map.hpp>//std::map用
#include <boost/serialization/set.hpp>//std::set用
#include <boost/serialization/deque.hpp>//std::deque用

//#define USE_SPLIT_MEMBER//serialize()関数をload()関数とsave()関数に分けて使う場合、このマクロを有効化する
//#define USE_NON_INTRUSIVE_TYPE//非侵入型をつかってシリアライズするならこのマクロを有効化する

#ifdef USE_SPLIT_MEMBER
#include <boost/serialization/split_member.hpp>//BOOST_SERIALIZATION_SPLIT_MEMBER用
#endif//USE_SPLIT_MEMBER

//--------------------------------------------------------------------------------

//--------------------
//シリアライズ対象クラス１
class CTest1
{
public:
	//アクセッサ
	int getData1() const { return m_data1; }//データ1取得
	void setData1(const int value){ m_data1 = value; }//データ1更新
	float getData2() const { return m_data2; }//データ2取得
	void setData2(const float value){ m_data2 = value; }//データ2更新
	char getData3(const int index) const { return m_data3[index]; }//データ3取得
	void setData3(const int index, const int value){ m_data3[index] = value; }//データ3更新
private:

	//シリアライズ用テンプレート関数
	//※シリアライズとデシリアライズの共通処理
	//※privateスコープにした上でフレンドクラスを設定する
	friend class boost::serialization::access;
#ifndef USE_SPLIT_MEMBER
	template<class Archive>
	void serialize(Archive& arc, const unsigned int version)
	{
		printf("serialize:version=%d\n", version);//バージョンを表示
		arc & m_data1;//データ1 ※アーカイブに & 演算子でデータを渡す
		arc & m_data2 & m_data3;//データ2 & データ3 ※連続してデータを渡すことも可能
	}
#else//USE_SPLIT_MEMBER
	BOOST_SERIALIZATION_SPLIT_MEMBER();
	template<class Archive>
	void save(Archive& arc, const unsigned int version) const
	{
		printf("save:version=%d\n", version);//バージョンを表示
		arc & m_data1;//データ1
		arc & m_data2 & m_data3;//データ2 & データ3
	}
	template<class Archive>
	void load(Archive& arc, const unsigned int version)
	{
		printf("load:version=%d\n", version);//バージョンを表示
		arc & m_data1;//データ1
		arc & m_data2 & m_data3;//データ2 & データ3
	}
#endif//USE_SPLIT_MEMBER
private:
	//フィールド
	int m_data1;//データ1：int型
	float m_data2;//データ2：float型
	char m_data3[3];//データ3：配列型
};
//--------------------
//シリアライズ設定
BOOST_CLASS_VERSION(CTest1, 99);//バージョン設定
BOOST_CLASS_TRACKING(CTest1, boost::serialization::track_never);//VC++でエラー C4308を回避するための設定

//--------------------
//シリアライズテスト１：テキストアーカイブ
void serializeTest1()
{
	printf("--------------------\n");
	printf("シリアライズ：テキストアーカイブ\n");
	//オブジェクト生成
	CTest1 obj;
	//テストデータをセット
	obj.setData1(123);
	obj.setData2(4.56f);
	obj.setData3(0, 7);
	obj.setData3(1, 8);
	obj.setData3(2, 9);
	//実行前の状態表示
	printf("data1=%d\n", obj.getData1());
	printf("data2=%.2f\n", obj.getData2());
	printf("data3={%d, %d, %d}\n", obj.getData3(0), obj.getData3(1), obj.getData3(2));
	//シリアライズ
	std::ofstream stream("test1.txt");//ファイル出力ストリーム生成
	boost::archive::text_oarchive arc(stream);//出力アーカイブ生成：テキストアーカイブ
	arc << obj;//シリアライズ
	stream.close();//ストリームをクローズ
}
//--------------------
//デシリアライズテスト１：テキストアーカイブ
void deserializeTest1()
{
	printf("--------------------\n");
	printf("デシリアライズ：テキストアーカイブ\n");
	//オブジェクト生成
	CTest1 obj;
	//デシリアライズ
	std::ifstream stream("test1.txt");//ファイル入力ストリーム生成
	boost::archive::text_iarchive arc(stream);//入力アーカイブ生成：テキストアーカイブ
	arc >> obj;//デシリアライズ
	stream.close();//ストリームをクローズ
	//結果を表示
	printf("data1=%d\n", obj.getData1());
	printf("data2=%.2f\n", obj.getData2());
	printf("data3={%d, %d, %d}\n", obj.getData3(0), obj.getData3(1), obj.getData3(2));
}
//--------------------
//シリアライズ＆デシリアライズテスト１：テキストアーカイブ
void test1()
{
	//シリアライズ
	serializeTest1();
	//デシリアライズ
	deserializeTest1();
}

//--------------------------------------------------------------------------------

//--------------------
//シリアライズテスト２：バイナリアーカイブ
void serializeTest2()
{
	printf("--------------------\n");
	printf("シリアライズ：バイナリアーカイブ\n");
	//オブジェクト生成
	CTest1 obj;
	//テストデータをセット
	obj.setData1(123);
	obj.setData2(4.56f);
	obj.setData3(0, 7);
	obj.setData3(1, 8);
	obj.setData3(2, 9);
	//実行前の状態表示
	printf("data1=%d\n", obj.getData1());
	printf("data2=%.2f\n", obj.getData2());
	printf("data3={%d, %d, %d}\n", obj.getData3(0), obj.getData3(1), obj.getData3(2));
	//シリアライズ
	std::ofstream stream("test2.bin");//ファイル出力ストリーム生成
	boost::archive::binary_oarchive arc(stream);//出力アーカイブ生成：バイナリアーカイブ
	arc << obj;//シリアライズ
	stream.close();//ストリームをクローズ
}
//--------------------
//デシリアライズテスト２：バイナリアーカイブ
void deserializeTest2()
{
	printf("--------------------\n");
	printf("デシリアライズ：バイナリアーカイブ\n");
	//オブジェクト生成
	CTest1 obj;
	//デシリアライズ
	std::ifstream stream("test2.bin");//ファイル入力ストリーム生成
	boost::archive::binary_iarchive arc(stream);//入力アーカイブ生成：バイナリアーカイブ
	arc >> obj;//デシリアライズ
	stream.close();//ストリームをクローズ
	//結果を表示
	printf("data1=%d\n", obj.getData1());
	printf("data2=%.2f\n", obj.getData2());
	printf("data3={%d, %d, %d}\n", obj.getData3(0), obj.getData3(1), obj.getData3(2));
}
//--------------------
//シリアライズ＆デシリアライズテスト２：バイナリアーカイブ
void test2()
{
	//シリアライズ
	serializeTest2();
	//デシリアライズ
	deserializeTest2();
}

//--------------------------------------------------------------------------------

//--------------------
//シリアライズ対象クラス３
class CTest3
{
public:
	//アクセッサ
	int getData1() const { return m_data1; }//データ1取得
	void setData1(const int value){ m_data1 = value; }//データ1更新
	float getData2() const { return m_data2; }//データ2取得
	void setData2(const float value){ m_data2 = value; }//データ2更新
	char getData3(const int index) const { return m_data3[index]; }//データ3取得
	void setData3(const int index, const int value){ m_data3[index] = value; }//データ3更新
private:
	//シリアライズ用テンプレート関数
	//※シリアライズとデシリアライズの共通処理
	//※privateスコープにした上でフレンドクラスを設定する
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& arc, const unsigned int version)
	{
		printf("serialize:version=%d\n", version);//バージョンを表示
		arc & BOOST_SERIALIZATION_NVP(m_data1);//データ1 ※アーカイブに & 演算子でデータを渡す
		arc & BOOST_SERIALIZATION_NVP(m_data2) & BOOST_SERIALIZATION_NVP(m_data3);//データ2 & データ3 ※連続してデータを渡すことも可能
	}
private:
	//フィールド
	int m_data1;//データ1：int型
	float m_data2;//データ2：float型
	char m_data3[3];//データ3：配列型
};
//--------------------
//シリアライズ設定
BOOST_CLASS_VERSION(CTest3, 99);//バージョン設定

//--------------------
//シリアライズテスト３：XMLアーカイブ
void serializeTest3()
{
	printf("--------------------\n");
	printf("シリアライズ：XMLアーカイブ\n");
	//オブジェクト生成
	CTest3 obj;
	//テストデータをセット
	obj.setData1(123);
	obj.setData2(4.56f);
	obj.setData3(0, 7);
	obj.setData3(1, 8);
	obj.setData3(2, 9);
	//実行前の状態表示
	printf("data1=%d\n", obj.getData1());
	printf("data2=%.2f\n", obj.getData2());
	printf("data3={%d, %d, %d}\n", obj.getData3(0), obj.getData3(1), obj.getData3(2));
	//シリアライズ
	std::ofstream stream("test3.xml");//ファイル出力ストリーム生成
	boost::archive::xml_oarchive arc(stream);//出力アーカイブ生成：XMLアーカイブ
	arc << BOOST_SERIALIZATION_NVP(obj);//シリアライズ
	stream.close();//ストリームをクローズ
}
//--------------------
//デシリアライズテスト３：XMLアーカイブ
void deserializeTest3()
{
	printf("--------------------\n");
	printf("デシリアライズ：XMLアーカイブ\n");
	//オブジェクト生成
	CTest3 obj;
	//デシリアライズ
	std::ifstream stream("test3.xml");//ファイル入力ストリーム生成
	boost::archive::xml_iarchive arc(stream);//入力アーカイブ生成：XMLアーカイブ
	arc >> BOOST_SERIALIZATION_NVP(obj);//デシリアライズ
	stream.close();//ストリームをクローズ
	//結果を表示
	printf("data1=%d\n", obj.getData1());
	printf("data2=%.2f\n", obj.getData2());
	printf("data3={%d, %d, %d}\n", obj.getData3(0), obj.getData3(1), obj.getData3(2));
}
//--------------------
//シリアライズ＆デシリアライズテスト３：XMLアーカイブ
void test3()
{
	//シリアライズ
	serializeTest3();
	//デシリアライズ
	deserializeTest3();
}

//--------------------------------------------------------------------------------

//--------------------
//シリアライズ対象クラス４
//内部クラス
class CTest4sub
{
public:
	//アクセッサ
	int getVal1() const { return m_val1; }//値1取得
	void setVal1(const int value){ m_val1 = value; }//値1更新
	int getVal2() const { return m_val2; }//値2取得
	void setVal2(const int value){ m_val2 = value; }//値2更新
private:
#ifndef USE_NON_INTRUSIVE_TYPE
	//シリアライズ用テンプレート関数
	//※シリアライズとデシリアライズの共通処理
	//※privateスコープにした上でフレンドクラスを設定する
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& arc, const unsigned int version)
	{
		printf("sub::serialize:version=%d\n", version);//バージョンを表示
		arc & BOOST_SERIALIZATION_NVP(m_val1)//値1
		    & BOOST_SERIALIZATION_NVP(m_val2);//値2
	}
private:
#else//USE_NON_INTRUSIVE_TYPE
public:
#endif//USE_NON_INTRUSIVE_TYPE
	//フィールド
	int m_val1;//値1
	int m_val2;//値2
};
#ifdef USE_NON_INTRUSIVE_TYPE
//非侵入型シリアライズ関数
namespace boost{
	namespace serialization{
		template <class Archive>
		void serialize(Archive& arc, CTest4sub& sub, const unsigned int version)
		{
			printf("[non-intrusive]sub::serialize:version=%d\n", version);//バージョンを表示
			arc & BOOST_SERIALIZATION_NVP(sub.m_val1)//値1
				& BOOST_SERIALIZATION_NVP(sub.m_val2);//値2
		}
	}
}
#endif//USE_NON_INTRUSIVE_TYPE
//データクラス
class CTest4
{
public:
	//アクセッサ
	int getData1() const { return m_data1; }//データ1取得
	void setData1(const int value){ m_data1 = value; }//データ1更新
	float getData2() const { return m_data2; }//データ2取得
	void setData2(const float value){ m_data2 = value; }//データ2更新
	char getData3(const int index) const { return m_data3[index]; }//データ3取得
	void setData3(const int index, const int value){ m_data3[index] = value; }//データ3更新
	CTest4sub& getData4(){ return m_data4; }//データ4取得
	CTest4sub& getData5(const int index){ return m_data5[index]; }//データ5取得
	CTest4sub* getData6(){ return m_data6; }//データ6取得
	void setData6(CTest4sub* obj){ m_data6 = obj; }//データ6更新
	CTest4sub* getData7(){ return m_data7; }//データ7取得
	void setData7(CTest4sub* obj){ m_data7 = obj; }//データ7更新
private:
	//シリアライズ用テンプレート関数
	//※シリアライズとデシリアライズの共通処理
	//※privateスコープにした上でフレンドクラスを設定する
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& arc, const unsigned int version)
	{
		printf("serialize:version=%d\n", version);//バージョンを表示
		arc & BOOST_SERIALIZATION_NVP(m_data1)//データ1
			& BOOST_SERIALIZATION_NVP(m_data2)//データ2
			& BOOST_SERIALIZATION_NVP(m_data3)//データ3
			& BOOST_SERIALIZATION_NVP(m_data4)//データ4
			& BOOST_SERIALIZATION_NVP(m_data5)//データ5
			& BOOST_SERIALIZATION_NVP(m_data6)//データ6
			& BOOST_SERIALIZATION_NVP(m_data7);//データ7
	}
private:
	//フィールド
	int m_data1;//データ1：int型
	float m_data2;//データ2：float型
	char m_data3[3];//データ3：配列型
	CTest4sub m_data4;//データ４：構造体
	CTest4sub m_data5[2];//データ５：構造体の配列
	CTest4sub* m_data6;//データ６：構造体のポインタ
	CTest4sub* m_data7;//データ７：構造体のポインタ（ヌル時の動作確認用）
};
//--------------------
//シリアライズ設定
BOOST_CLASS_VERSION(CTest4, 99);//バージョン設定
BOOST_CLASS_VERSION(CTest4sub, 100);//バージョン設定

//--------------------
//シリアライズテスト４：複雑な構造のデータ（XMLアーカイブ）
void serializeTest4()
{
	printf("--------------------\n");
	printf("シリアライズ：複雑な構造のデータ（XMLアーカイブ）\n");
	//オブジェクト生成
	CTest4 obj;
	//テストデータをセット
	obj.setData1(123);
	obj.setData2(4.56f);
	obj.setData3(0, 7);
	obj.setData3(1, 8);
	obj.setData3(2, 9);
	obj.getData4().setVal1(10);
	obj.getData4().setVal2(11);
	obj.getData5(0).setVal1(12);
	obj.getData5(0).setVal2(13);
	obj.getData5(1).setVal1(14);
	obj.getData5(1).setVal2(15);
	obj.setData6(new CTest4sub());//ポインタ変数にはメモリ確保したオブジェクトをセット
	obj.getData6()->setVal1(16);
	obj.getData6()->setVal2(17);
	obj.setData7(nullptr);//ヌルポインタをセット
	//実行前の状態表示
	printf("data1=%d\n", obj.getData1());
	printf("data2=%.2f\n", obj.getData2());
	printf("data3={%d, %d, %d}\n", obj.getData3(0), obj.getData3(1), obj.getData3(2));
	printf("data4={val1=%d, val2=%d}\n", obj.getData4().getVal1(), obj.getData4().getVal2());
	printf("data5[0]={val1=%d, val2=%d}\n", obj.getData5(0).getVal1(), obj.getData5(0).getVal2());
	printf("data5[1]={val1=%d, val2=%d}\n", obj.getData5(1).getVal1(), obj.getData5(1).getVal2());
	printf("data6={val1=%d, val2=%d}\n", obj.getData6()->getVal1(), obj.getData6()->getVal2());
	printf("data7=0x%p\n", obj.getData7());
	//シリアライズ
	std::ofstream stream("test4.xml");//ファイル出力ストリーム生成
	boost::archive::xml_oarchive arc(stream);//出力アーカイブ生成：XMLアーカイブ
	arc << BOOST_SERIALIZATION_NVP(obj);//シリアライズ
	stream.close();//ストリームをクローズ
}
//--------------------
//デシリアライズテスト４：複雑な構造のデータ（XMLアーカイブ）
void deserializeTest4()
{
	printf("--------------------\n");
	printf("デシリアライズ：複雑な構造のデータ（XMLアーカイブ）\n");
	//オブジェクト生成
	CTest4 obj;
	//デシリアライズ
	std::ifstream stream("test4.xml");//ファイル入力ストリーム生成
	boost::archive::xml_iarchive arc(stream);//入力アーカイブ生成：XMLアーカイブ
	arc >> BOOST_SERIALIZATION_NVP(obj);//デシリアライズ
	stream.close();//ストリームをクローズ
	//結果を表示
	printf("data1=%d\n", obj.getData1());
	printf("data2=%.2f\n", obj.getData2());
	printf("data3={%d, %d, %d}\n", obj.getData3(0), obj.getData3(1), obj.getData3(2));
	printf("data4={val1=%d, val2=%d}\n", obj.getData4().getVal1(), obj.getData4().getVal2());
	printf("data5[0]={val1=%d, val2=%d}\n", obj.getData5(0).getVal1(), obj.getData5(0).getVal2());
	printf("data5[1]={val1=%d, val2=%d}\n", obj.getData5(1).getVal1(), obj.getData5(1).getVal2());
	printf("data6={val1=%d, val2=%d}\n", obj.getData6()->getVal1(), obj.getData6()->getVal2());
	printf("data7=0x%p\n", obj.getData7());
}
//--------------------
//シリアライズ＆デシリアライズテスト４：複雑な構造のデータ（XMLアーカイブ）
void test4()
{
	//シリアライズ
	serializeTest4();
	//デシリアライズ
	deserializeTest4();
}

//--------------------------------------------------------------------------------

//--------------------
//テスト
int main()
{
	test1();
	test2();
	test3();
	test4();
}

// End of file
