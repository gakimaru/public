#include <stdio.h>
#include <stdlib.h>

//ゲームデータ定義
struct T_GDBIN_DECL
{
	//型情報
	struct TYPE_INFO
	{
		unsigned int dataNameCrc;	//構造体名CRC　※型種別 = struct の場合に指定。
		unsigned char baseType : 3;	//型種別　※0 = int, 1 = float, 2 = dec, 3 = bool, 4 = str、
		//　　　　　5 = expr, 6 = ptr, 7 = struct。
		unsigned char isUnsigned : 1;	//符号無し型か？　※型種別 = int の場合のみ指定可。
		unsigned char size : 4;		//型のサイズ　※int の場合は、1,2,4,8 のいずれか。
		//　　　　　　　float の場合は、2,4,8 のいずれか。
		//　　　　　　　dec の場合は 2,4,8 のいずれか。
		//　　　　　　　bool の場合は 1。
		//　　　　　　　str / expr / ptr /struct の場合は 0。
		unsigned char padding[3];	//パディング　※0xdbで埋める
	};

	//ゲームデータ構造体定義
	struct STRUCT
	{
		//ゲームデータ構造体メンバー定義
		struct MEMBER
		{
			TYPE_INFO type;			//型情報
			unsigned int memberNameCrc;	//メンバー名CRC
			unsigned int isVariableArray : 1;//不定長配列か？　※true で不定長配列。この時、メンバーの実際の
			//　　　　　　　　　　データ型はポインターとなる。
			unsigned int arraySize : 31;	//配列要素数　※配列でない時や不定長の時は 0。
		};

		unsigned int structNameCrc;	//構造体名CRC
		unsigned short membersNum;	//構造体メンバー数
		MEMBER* members;			//構造体メンバー定義の参照
	};

	//不定長データ情報
	struct VARIABLE_DATA_INFO
	{
		TYPE_INFO type;			//型情報
		unsigned int recotdSize;	//不定長データのレコードサイズ（１件あたりのデータサイズ）
	};

	unsigned int formatNameCrc;	//データフォーマット名CRC
	unsigned short majorVer;		//データフォーマットメジャーバージョン
	unsigned short minorVer;		//データフォーマットマイナーバージョン

	unsigned short structsNum;				//構造体数
	unsigned short structMembersNum;		//全構造体の全メンバー数
	unsigned short variableDataInfosNum;	//不定長データ情報数
	unsigned char padding[2];				//パディング　※0xdbで埋める
	
	unsigned int recotdSize;				//基本構造体のレコードサイズ（１件あたりのデータサイズ）
	unsigned int primaryKeyNameCrc;			//主キーメンバー名CRC
	
	STRUCT* structs;						//構造体定義の参照
	VARIABLE_DATA_INFO* variableDataInfos;	//不定長データ情報の参照
};

namespace charaDataDecl
{

	//キャラパラメータ構造定義
	//Name: CharaData
	//Version: 1.0
	//Update: 204.1.10 12:34:56

	//データ構造定義

	//構造体のメンバー定義
	static const int s_structMembersNum = 9 + 4 + 2; //全構造体の全メンバー数
	static T_GDBIN_DECL::STRUCT::MEMBER s_structMembers[s_structMembersNum] =
	{
		//T_CHARA構造体
		{ { 0x00000000, 0, true, 4, { 0xdb,0xdb,0xdb } }, 0xe66c3671, false, 0 },	//識別ID:”id”:crc
		{ { 0x00000000, 0, false, 1, { 0xdb,0xdb,0xdb } }, 0xab8a01a0, false, 0 },	//力:”power”:i8
		{ { 0x00000000, 0, false, 1, { 0xdb,0xdb,0xdb } }, 0x9c504212, false, 0 },	//アビリティ(Num):”abiriliesNum”:i8
		{ { 0x00000000, 0, false, 2, { 0xdb,0xdb,0xdb } }, 0x9ec9ce32, false, 0 },	//固定値:”fixed”:i16
		{ { 0x00000000, 4, false, 0, { 0xdb,0xdb,0xdb } }, 0x5e237e06, false, 0 },	//名前:”name”:str
		{ { 0x00000000, 5, false, 0, { 0xdb,0xdb,0xdb } }, 0xbdd68843, false, 0 },	//有効化条件:”condition”:expr
		{ { 0x00000000, 1, false, 4, { 0xdb,0xdb,0xdb } }, 0x0ad84385, false, 10 },	//耐性:”tol”:f32[10]
		{ { 0x00000000, 0, true, 4, { 0xdb,0xdb,0xdb } }, 0xb8388da4, true, 0 },	//アビリティ:”abilities”:u32*
		{ { 0x22a2e1dc, 7, false, 0, { 0xdb,0xdb,0xdb } }, 0xa4fa7c89, false, 0 },	//パラメータ:”param”:T_PARAM
		//T_PARAM構造体
		{ { 0x00000000, 0, false, 2, { 0xdb,0xdb,0xdb } }, 0x27677c27, false, 0 },	//攻撃力:”atk”:i16
		{ { 0x00000000, 0, false, 2, { 0xdb,0xdb,0xdb } }, 0x0cc4e161, false, 0 },	//防御力:”def”:i16
		{ { 0x00000000, 0, false, 4, { 0xdb,0xdb,0xdb } }, 0xcd1415d7, false, 0 },	//特殊能力(Num):”specialsNum”:i32
		{ { 0x84f96e44, 7, false, 0, { 0xdb,0xdb,0xdb } }, 0x4c6b3fe3, true, 0 },	//特殊能力:”specials”:T_SPECIAL_PARAM*
		//T_SPECIAL_PARAM構造体
		{ { 0x00000000, 0, true, 4, { 0xdb,0xdb,0xdb } }, 0x1b7cbdfb, false, 0 },	//闇:”dark”:u32
		{ { 0x00000000, 0, true, 4, { 0xdb,0xdb,0xdb } }, 0x076291bf, false, 0 },	//光:”shine”:u32
	};

	//構造体の定義
	static const int s_structsNum = 3; //全構造体数
	static T_GDBIN_DECL::STRUCT s_structs[s_structsNum] =
	{
		{ 0x0ed35394, 9, &s_structMembers[0] },	//T_CHARA
		{ 0x22a2e1dc, 4, &s_structMembers[9] },	//T_PARAM
		{ 0x84f96e44, 2, &s_structMembers[13] },	//T_SPECIAL_PARAM
	};

	//不定長データ情報
	static const int s_variableDataInfoNum = 2; //不定長データ情報数
	static T_GDBIN_DECL::VARIABLE_DATA_INFO s_variableDataInfos[s_variableDataInfoNum] =
	{
		{ { 0x00000000, 0, true, 4, { 0xdb,0xdb,0xdb } }, 4 },	//u32
		{ { 0x84f96e44, 7, false, 0, { 0xdb,0xdb,0xdb } }, 8 },	//T_SPECIAL_PARAM
	};

	//フォーマット情報定義（バージョンを含む）
	static T_GDBIN_DECL s_decl =
	{
		0xe1e4a645,	//フォーマット名CRC：CharaData
		1,		//フォーマットメジャーバージョン
		0,		//フォーマットマイナーバージョン

		s_structsNum,			//構造体数
		s_structMembersNum,		//全構造体の全メンバー数
		s_variableDataInfoNum,	//不定長データ情報数
		{ 0xdb,0xdb },			//パディング
		
		72,						//基本構造体のレコードサイズ（１件あたりのデータサイズ）
		0xe66c3671,				//主キーメンバー名CRC：id
		
		&s_structs[0],			//構造体定義の参照
		&s_variableDataInfos[0]	//不定長データ情報の参照
	};

	//データ構造定義取得関数
	const T_GDBIN_DECL* getDecl(){ return &s_decl; }

}//charaDataDecl

int main(const int argc, const char* argv[])
{
	const T_GDBIN_DECL* decl = charaDataDecl::getDecl();
	printf("Ver=%d.%d\n", decl->majorVer, decl->majorVer);
	return EXIT_SUCCESS;
}

// End of file
