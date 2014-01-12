#include <stdio.h>
#include <stdlib.h>

//ゲームデータ定義
struct T_GAME_DATA_DECL
{
	//ゲームデータ構造体定義
	struct STRUCT
	{
		//ゲームデータ構造体メンバー定義
		struct MEMBER
		{
			unsigned int memberNameCrc;	//メンバー名CRC
			unsigned int dataNameCrc;	//構造体名CRC　※型種別 = struct の場合に指定。
			unsigned int baseType : 3;	//型種別　※0 = int, 1 = float, 2 = dec, 3 = bool, 4 = str、
			//　　　　　5 = expr, 6 = ptr, 7 = struct。
			unsigned int isUnsigned : 1;	//符号無し型か？　※型種別 = int の時だけ指定可。
			unsigned int size : 4;		//型のサイズ　※int の場合は、1,2,4,8 のいずれか。
			//　　　　　　　float の場合は、2,4,8 のいずれか。
			//　　　　　　　dec の場合は 2,4,8 のいずれか。
			//　　　　　　　bool の場合は 1。
			//　　　　　　　str / expr / ptr /struct の場合は 0。
			unsigned int isVariableArray : 1;//不定長配列か？　※true で不定長配列。この時、メンバーの実際の
			//　　　　　　　　　　データ型はポインターとなる。
			unsigned int arraySize : 16;	//配列要素数　※配列でない時や不定長の時は 0。
		};

		unsigned int structNameCrc;	//構造体名CRC
		unsigned short membersNum;	//構造体メンバー数
		MEMBER* members;			//構造体メンバー定義の参照
	};

	unsigned int formatNameCrc;	//データフォーマット名CRC
	unsigned short majorVer;		//データフォーマットメジャーバージョン
	unsigned short minorVer;		//データフォーマットマイナーバージョン
	unsigned char ptrSize;		//ポインターサイズ(4 or 8)
	unsigned short structsNum;	//構造体数
	STRUCT* structs;			//構造体定義の参照
};

namespace charaDataDecl
{

	//キャラパラメータ構造定義
	//Name: CharaData
	//Version: 1.0
	//Update: 204.1.10 12:34:56

	//データ構造定義
	static const int s_structMembersNum = 9 + 4 + 2;
	static T_GAME_DATA_DECL::STRUCT::MEMBER s_structMembers[s_structMembersNum] =
	{
		//T_CHARA
		{ 0xe66c3671, 0x00000000, 0, true, 4, false, 0 },	//識別ID:”id”:crc
		{ 0xab8a01a0, 0x00000000, 0, false, 1, false, 0 },	//力:”power”:i8
		{ 0x9c504212, 0x00000000, 0, false, 1, false, 0 },	//アビリティ(Num):”abiriliesNum”:i8
		{ 0x9ec9ce32, 0x00000000, 0, false, 2, false, 0 },	//固定値:”fixed”:i16
		{ 0x5e237e06, 0x00000000, 4, false, 0, false, 0 },	//名前:”name”:str
		{ 0xbdd68843, 0x00000000, 5, false, 0, false, 0 },	//有効化条件:”condition”:expr
		{ 0x0ad84385, 0x00000000, 1, false, 1, false, 10 },	//耐性:”tol”:f32
		{ 0xb8388da4, 0x00000000, 0, true, 4, true, 0 },	//アビリティ:”abilities”:u32*
		{ 0xa4fa7c89, 0x22a2e1dc, 7, false, 0, false, 0 },	//パラメータ:”param”:T_PARAM
		//T_PARAM
		{ 0x27677c27, 0x00000000, 0, false, 2, false, 0 },	//攻撃力:”atk”:i16
		{ 0x0cc4e161, 0x00000000, 0, false, 2, false, 0 },	//防御力:”def”:i16
		{ 0xcd1415d7, 0x00000000, 0, false, 4, false, 0 },	//特殊能力(Num):”specialsNum”:i32
		{ 0x4c6b3fe3, 0x84f96e44, 7, false, 0, true, 0 },	//特殊能力:”specials”:T_SPECIAL_PARAM*
		//T_SPECIAL_PARAM
		{ 0x1b7cbdfb, 0x00000000, 0, true, 4, false, 0 },	//闇:”dark”:u32
		{ 0x076291bf, 0x00000000, 0, true, 4, false, 0 },	//光:”shine”:u32
	};
	static const int s_structsNum = 3;
	static T_GAME_DATA_DECL::STRUCT s_structs[s_structsNum] =
	{
		{ 0x0ed35394, 9, &s_structMembers[0] },	//T_CHARA
		{ 0x22a2e1dc, 4, &s_structMembers[9] },	//T_PARAM
		{ 0x84f96e44, 2, &s_structMembers[13] },	//T_SPECIAL_PARAM
	};
	static T_GAME_DATA_DECL s_decl =
	{
		0xe1e4a645,	//データフォーマット名CRC：CharaData
		1,		//データフォーマットメジャーバージョン
		0,		//データフォーマットマイナーバージョン
		8,		//ポインターサイズ
		s_structsNum,//構造対数
		&s_structs[0]//構造体定義の参照
	};

	//データ構造定義取得関数
	const T_GAME_DATA_DECL* getGameDataDecl(){ return &s_decl; }
}

int sub()
{
	printf("    -> Called!\n");
	return 1;
}

#define TEST(expr) { printf("expr=\"%s\"\n", #expr); const int ret = (expr); printf("  result=%d\n", ret); }

int main(const int argc, const char* argv[])
{
	const T_GAME_DATA_DECL* o = charaDataDecl::getGameDataDecl();

	TEST(1);
	TEST(1 + 1);
	
	TEST(true && sub());
	TEST(false && sub());
	TEST(true || sub());
	TEST(false || sub());
	TEST(sub() && true);
	TEST(sub() && false);
	TEST(sub() || true);
	TEST(sub() || false);
	TEST(true ? sub() : 999);
	TEST(false ? sub() : 999);
	TEST(true ? 999 : sub());
	TEST(false ? 999 : sub());
	TEST(0xffffffff & sub());
	TEST(0x00000000 & sub());
	TEST(0xffffffff | sub());
	TEST(0x00000000 | sub());
	TEST(sub() & 0xffffffff);
	TEST(sub() & 0x00000000);
	TEST(sub() | 0xffffffff);
	TEST(sub() | 0x00000000);
	TEST(1 * sub());
	TEST(0 * sub());
	TEST(1 / sub());
	TEST(0 / sub());
	TEST(sub() * 1);
	TEST(sub() * 0);
	TEST(sub() / 1);
//	TEST(sub() / 0);
	
//【結果】
//	expr = "1"
//	  result = 1
//	expr = "1 + 1"
//	  result = 2
//	expr = "true && sub()"
//	    ->Called!
//	  result = 1
//	expr = "false && sub()"
//	  result = 0
//	expr = "true || sub()"
//	  result = 1
//	expr = "false || sub()"
//	    ->Called!
//	  result = 1
//	expr = "sub() && true"
//	    ->Called!
//	  result = 1
//	expr = "sub() && false"
//	    ->Called!
//	  result = 0
//	expr = "sub() || true"
//	    ->Called!
//	  result = 1
//	expr = "sub() || false"
//	    ->Called!
//	  result = 1
//	expr = "true ? sub() : 999"
//	    ->Called!
//	  result = 1
//	expr = "false ? sub() : 999"
//	  result = 999
//	expr = "true ? 999 : sub()"
//	  result = 999
//	expr = "false ? 999 : sub()"
//	    ->Called!
//	  result = 1
//	expr = "0xffffffff & sub()"
//	    ->Called!
//	  result = 1
//	expr = "0x00000000 & sub()"
//	    ->Called!
//	  result = 0
//	expr = "0xffffffff | sub()"
//	    ->Called!
//	  result = -1
//	expr = "0x00000000 | sub()"
//	    ->Called!
//	  result = 1
//	expr = "sub() & 0xffffffff"
//	    ->Called!
//	  result = 1
//	expr = "sub() & 0x00000000"
//	    ->Called!
//	  result = 0
//	expr = "sub() | 0xffffffff"
//	    ->Called!
//	  result = -1
//	expr = "sub() | 0x00000000"
//	    ->Called!
//	  result = 1
//	expr = "1 * sub()"
//	    ->Called!
//	  result = 1
//	expr = "0 * sub()"
//	    ->Called!
//	  result = 0
//	expr = "1 / sub()"
//	    ->Called!
//	  result = 1
//	expr = "0 / sub()"
//	    ->Called!
//	  result = 0
//	expr = "sub() * 1"
//	    ->Called!
//	  result = 1
//	expr = "sub() * 0"
//	    ->Called!
//	  result = 0
//	expr = "sub() / 1"
//	    ->Called!
//	  result = 1
	
	return EXIT_FAILURE;
}

// End of file

