//C++11用の constexpr / ユーザー定義リテラルを使ったコンパイル時CRC計算およびSSE4.2を使用したCRC計算

//--------------------
//コンパイラスイッチ用マクロ
#define USE_CONSTEXPR//constexprを使用する時はこのマクロを有効にする
#define ENABLE_USER_DEFINED_LITERALS//ユーザー定義リテラルを有効にする時はこのマクロを有効にする
#define ENABLE_RUNTIME_FUNC//ランタイム関数を有効にする時はこのマクロを有効にする

#define USE_SSE//SSE4.2命令を使用する時はこのマクロを有効にする ※CRC32C専用になるので注意 ※ランタイム時計算専用

#define USE_CRC32C//IEEE標準のCRC-32生成多項式ではなく、CRC-32C(Castagnoli)生成多項式使用を使用する時はこのマクロを有効にする ※SSE使用時は強制的に設定
                  //※本来は、CRC-32系関数と CRC-32C 系関数の両方を、それぞれ別名の関数で定義したほうがよい
                  //　本サンプルでは、少しでもコードを理解し易くするために、両者を切り替えるスタイルとする

#define USE_STATIC_TABLE//CRC計算の際に、事前計算済みのCRC多項式テーブルを使用する時はこのマクロを有効にする ※通常は有効にしたほうがよい
//#define ENABLE_MAKE_STATIC_TABLE//CRC多項式テーブル作成関数を有効にする時はこのマクロを有効にする ※CRC多項式テーブル未使用時のみ指定可

//--------------------
//コンパイラスイッチ調整
#ifdef USE_SSE
#ifndef USE_CRC32C
#define USE_CRC32C//CRC-32C(Castagnoli)生成多項式使用 ※SSE4.2命令使用時はCRC32C生成多項式で確定
#endif//USE_CRC32C
#endif//USE_SSE

#ifdef USE_CONSTEXPR
#ifndef MAKE_CRC_INSTANCE
#define MAKE_CRC_INSTANCE//※constexp使用時は、ヘッダーで関数を実体化する
#endif//MAKE_CRC_INSTANCE
#endif//USE_CONSTEXPR

#ifdef USE_STATIC_TABLE
#ifdef ENABLE_MAKE_STATIC_TABLE
#undef ENABLE_MAKE_STATIC_TABLE//※CRC多項式テーブル使用時は、CRC多項式テーブルを作成（表示）できない
#endif//ENABLE_MAKE_STATIC_TABLE
#endif//USE_STATIC_TABLE

//--------------------
//C++11互換用マクロ
#ifdef USE_CONSTEXPR
#define CONSTEXPR constexpr//※constexprを使用（コンパイル時計算が有効になる）
#else//USE_CONSTEXPR
#define CONSTEXPR const//※constexprの代わりにconstを使用（コンパイル時計算はできない）
#endif//USE_CONSTEXPR

//--------------------
#include <cstddef>//std::size_t用

//--------------------------------------------------------------------------------
//CRC算出

//--------------------
//型
typedef unsigned int crc32_t;//CRC32型

//--------------------
//CRC算出関数
//※コンパイル時に処理するため、ヘッダーに処理を記述する
namespace crc_sub//直接使用しない処理を隠ぺいするためのネームスペース
{
#ifndef USE_STATIC_TABLE
	//--------------------
	//CRC多項式計算
	//※constexpr関数内では変数/定数が使えないため、定数にマクロを使用
	//※constexpr関数内ではラムダ式が使えないため、関数を分割（ラムダ式を使用するとコンパイル時に評価されなくなる）
	CONSTEXPR inline crc32_t calcPoly_core(const crc32_t poly)
	{
		//生成多項式
	#ifndef USE_CRC32C
		//IEEE勧告の一般的なCRC32
		//#define POLYNOMIAL 0x04c11db7u//（標準）
		#define POLYNOMIAL 0xedb88320u//（反転）
	#else//USE_CRC32C
		//CRC-32C(Castagnoli) ※SSE4.2命令準拠 ※こちらの方が優れている
		//#define POLYNOMIAL 0x1edc6f41u//（標準）
		#define POLYNOMIAL 0x82f63b78u//（反転）
	#endif//USE_CRC32C
		return poly & 1 ? POLYNOMIAL ^ (poly >> 1) : (poly >> 1);
		#undef POLYNOMIAL
	}
	CONSTEXPR inline crc32_t calcPoly(const crc32_t poly)
	{
		//多項式計算
		return calcPoly_core(
		         calcPoly_core(
		           calcPoly_core(
		             calcPoly_core(
		               calcPoly_core(
		                 calcPoly_core(
		                   calcPoly_core(
		                     calcPoly_core(poly)
		                   )
		                 )
		               )
		             )
		           )
		         )
		       );
	}
#else//USE_STATIC_TABLE
	//--------------------
	//CRC多項式計算済みテーブル
#ifdef MAKE_CRC_INSTANCE
	CONSTEXPR crc32_t s_polyTable[256] =
	{
	#ifndef USE_CRC32C
		0x00000000u, 0x77073096u, 0xee0e612cu, 0x990951bau, 0x076dc419u, 0x706af48fu, 0xe963a535u, 0x9e6495a3u,
		0x0edb8832u, 0x79dcb8a4u, 0xe0d5e91eu, 0x97d2d988u, 0x09b64c2bu, 0x7eb17cbdu, 0xe7b82d07u, 0x90bf1d91u,
		0x1db71064u, 0x6ab020f2u, 0xf3b97148u, 0x84be41deu, 0x1adad47du, 0x6ddde4ebu, 0xf4d4b551u, 0x83d385c7u,
		0x136c9856u, 0x646ba8c0u, 0xfd62f97au, 0x8a65c9ecu, 0x14015c4fu, 0x63066cd9u, 0xfa0f3d63u, 0x8d080df5u,
		0x3b6e20c8u, 0x4c69105eu, 0xd56041e4u, 0xa2677172u, 0x3c03e4d1u, 0x4b04d447u, 0xd20d85fdu, 0xa50ab56bu,
		0x35b5a8fau, 0x42b2986cu, 0xdbbbc9d6u, 0xacbcf940u, 0x32d86ce3u, 0x45df5c75u, 0xdcd60dcfu, 0xabd13d59u,
		0x26d930acu, 0x51de003au, 0xc8d75180u, 0xbfd06116u, 0x21b4f4b5u, 0x56b3c423u, 0xcfba9599u, 0xb8bda50fu,
		0x2802b89eu, 0x5f058808u, 0xc60cd9b2u, 0xb10be924u, 0x2f6f7c87u, 0x58684c11u, 0xc1611dabu, 0xb6662d3du,
		0x76dc4190u, 0x01db7106u, 0x98d220bcu, 0xefd5102au, 0x71b18589u, 0x06b6b51fu, 0x9fbfe4a5u, 0xe8b8d433u,
		0x7807c9a2u, 0x0f00f934u, 0x9609a88eu, 0xe10e9818u, 0x7f6a0dbbu, 0x086d3d2du, 0x91646c97u, 0xe6635c01u,
		0x6b6b51f4u, 0x1c6c6162u, 0x856530d8u, 0xf262004eu, 0x6c0695edu, 0x1b01a57bu, 0x8208f4c1u, 0xf50fc457u,
		0x65b0d9c6u, 0x12b7e950u, 0x8bbeb8eau, 0xfcb9887cu, 0x62dd1ddfu, 0x15da2d49u, 0x8cd37cf3u, 0xfbd44c65u,
		0x4db26158u, 0x3ab551ceu, 0xa3bc0074u, 0xd4bb30e2u, 0x4adfa541u, 0x3dd895d7u, 0xa4d1c46du, 0xd3d6f4fbu,
		0x4369e96au, 0x346ed9fcu, 0xad678846u, 0xda60b8d0u, 0x44042d73u, 0x33031de5u, 0xaa0a4c5fu, 0xdd0d7cc9u,
		0x5005713cu, 0x270241aau, 0xbe0b1010u, 0xc90c2086u, 0x5768b525u, 0x206f85b3u, 0xb966d409u, 0xce61e49fu,
		0x5edef90eu, 0x29d9c998u, 0xb0d09822u, 0xc7d7a8b4u, 0x59b33d17u, 0x2eb40d81u, 0xb7bd5c3bu, 0xc0ba6cadu,
		0xedb88320u, 0x9abfb3b6u, 0x03b6e20cu, 0x74b1d29au, 0xead54739u, 0x9dd277afu, 0x04db2615u, 0x73dc1683u,
		0xe3630b12u, 0x94643b84u, 0x0d6d6a3eu, 0x7a6a5aa8u, 0xe40ecf0bu, 0x9309ff9du, 0x0a00ae27u, 0x7d079eb1u,
		0xf00f9344u, 0x8708a3d2u, 0x1e01f268u, 0x6906c2feu, 0xf762575du, 0x806567cbu, 0x196c3671u, 0x6e6b06e7u,
		0xfed41b76u, 0x89d32be0u, 0x10da7a5au, 0x67dd4accu, 0xf9b9df6fu, 0x8ebeeff9u, 0x17b7be43u, 0x60b08ed5u,
		0xd6d6a3e8u, 0xa1d1937eu, 0x38d8c2c4u, 0x4fdff252u, 0xd1bb67f1u, 0xa6bc5767u, 0x3fb506ddu, 0x48b2364bu,
		0xd80d2bdau, 0xaf0a1b4cu, 0x36034af6u, 0x41047a60u, 0xdf60efc3u, 0xa867df55u, 0x316e8eefu, 0x4669be79u,
		0xcb61b38cu, 0xbc66831au, 0x256fd2a0u, 0x5268e236u, 0xcc0c7795u, 0xbb0b4703u, 0x220216b9u, 0x5505262fu,
		0xc5ba3bbeu, 0xb2bd0b28u, 0x2bb45a92u, 0x5cb36a04u, 0xc2d7ffa7u, 0xb5d0cf31u, 0x2cd99e8bu, 0x5bdeae1du,
		0x9b64c2b0u, 0xec63f226u, 0x756aa39cu, 0x026d930au, 0x9c0906a9u, 0xeb0e363fu, 0x72076785u, 0x05005713u,
		0x95bf4a82u, 0xe2b87a14u, 0x7bb12baeu, 0x0cb61b38u, 0x92d28e9bu, 0xe5d5be0du, 0x7cdcefb7u, 0x0bdbdf21u,
		0x86d3d2d4u, 0xf1d4e242u, 0x68ddb3f8u, 0x1fda836eu, 0x81be16cdu, 0xf6b9265bu, 0x6fb077e1u, 0x18b74777u,
		0x88085ae6u, 0xff0f6a70u, 0x66063bcau, 0x11010b5cu, 0x8f659effu, 0xf862ae69u, 0x616bffd3u, 0x166ccf45u,
		0xa00ae278u, 0xd70dd2eeu, 0x4e048354u, 0x3903b3c2u, 0xa7672661u, 0xd06016f7u, 0x4969474du, 0x3e6e77dbu,
		0xaed16a4au, 0xd9d65adcu, 0x40df0b66u, 0x37d83bf0u, 0xa9bcae53u, 0xdebb9ec5u, 0x47b2cf7fu, 0x30b5ffe9u,
		0xbdbdf21cu, 0xcabac28au, 0x53b39330u, 0x24b4a3a6u, 0xbad03605u, 0xcdd70693u, 0x54de5729u, 0x23d967bfu,
		0xb3667a2eu, 0xc4614ab8u, 0x5d681b02u, 0x2a6f2b94u, 0xb40bbe37u, 0xc30c8ea1u, 0x5a05df1bu, 0x2d02ef8du
	#else//USE_CRC32C
		0x00000000u, 0xf26b8303u, 0xe13b70f7u, 0x1350f3f4u, 0xc79a971fu, 0x35f1141cu, 0x26a1e7e8u, 0xd4ca64ebu,
		0x8ad958cfu, 0x78b2dbccu, 0x6be22838u, 0x9989ab3bu, 0x4d43cfd0u, 0xbf284cd3u, 0xac78bf27u, 0x5e133c24u,
		0x105ec76fu, 0xe235446cu, 0xf165b798u, 0x030e349bu, 0xd7c45070u, 0x25afd373u, 0x36ff2087u, 0xc494a384u,
		0x9a879fa0u, 0x68ec1ca3u, 0x7bbcef57u, 0x89d76c54u, 0x5d1d08bfu, 0xaf768bbcu, 0xbc267848u, 0x4e4dfb4bu,
		0x20bd8edeu, 0xd2d60dddu, 0xc186fe29u, 0x33ed7d2au, 0xe72719c1u, 0x154c9ac2u, 0x061c6936u, 0xf477ea35u,
		0xaa64d611u, 0x580f5512u, 0x4b5fa6e6u, 0xb93425e5u, 0x6dfe410eu, 0x9f95c20du, 0x8cc531f9u, 0x7eaeb2fau,
		0x30e349b1u, 0xc288cab2u, 0xd1d83946u, 0x23b3ba45u, 0xf779deaeu, 0x05125dadu, 0x1642ae59u, 0xe4292d5au,
		0xba3a117eu, 0x4851927du, 0x5b016189u, 0xa96ae28au, 0x7da08661u, 0x8fcb0562u, 0x9c9bf696u, 0x6ef07595u,
		0x417b1dbcu, 0xb3109ebfu, 0xa0406d4bu, 0x522bee48u, 0x86e18aa3u, 0x748a09a0u, 0x67dafa54u, 0x95b17957u,
		0xcba24573u, 0x39c9c670u, 0x2a993584u, 0xd8f2b687u, 0x0c38d26cu, 0xfe53516fu, 0xed03a29bu, 0x1f682198u,
		0x5125dad3u, 0xa34e59d0u, 0xb01eaa24u, 0x42752927u, 0x96bf4dccu, 0x64d4cecfu, 0x77843d3bu, 0x85efbe38u,
		0xdbfc821cu, 0x2997011fu, 0x3ac7f2ebu, 0xc8ac71e8u, 0x1c661503u, 0xee0d9600u, 0xfd5d65f4u, 0x0f36e6f7u,
		0x61c69362u, 0x93ad1061u, 0x80fde395u, 0x72966096u, 0xa65c047du, 0x5437877eu, 0x4767748au, 0xb50cf789u,
		0xeb1fcbadu, 0x197448aeu, 0x0a24bb5au, 0xf84f3859u, 0x2c855cb2u, 0xdeeedfb1u, 0xcdbe2c45u, 0x3fd5af46u,
		0x7198540du, 0x83f3d70eu, 0x90a324fau, 0x62c8a7f9u, 0xb602c312u, 0x44694011u, 0x5739b3e5u, 0xa55230e6u,
		0xfb410cc2u, 0x092a8fc1u, 0x1a7a7c35u, 0xe811ff36u, 0x3cdb9bddu, 0xceb018deu, 0xdde0eb2au, 0x2f8b6829u,
		0x82f63b78u, 0x709db87bu, 0x63cd4b8fu, 0x91a6c88cu, 0x456cac67u, 0xb7072f64u, 0xa457dc90u, 0x563c5f93u,
		0x082f63b7u, 0xfa44e0b4u, 0xe9141340u, 0x1b7f9043u, 0xcfb5f4a8u, 0x3dde77abu, 0x2e8e845fu, 0xdce5075cu,
		0x92a8fc17u, 0x60c37f14u, 0x73938ce0u, 0x81f80fe3u, 0x55326b08u, 0xa759e80bu, 0xb4091bffu, 0x466298fcu,
		0x1871a4d8u, 0xea1a27dbu, 0xf94ad42fu, 0x0b21572cu, 0xdfeb33c7u, 0x2d80b0c4u, 0x3ed04330u, 0xccbbc033u,
		0xa24bb5a6u, 0x502036a5u, 0x4370c551u, 0xb11b4652u, 0x65d122b9u, 0x97baa1bau, 0x84ea524eu, 0x7681d14du,
		0x2892ed69u, 0xdaf96e6au, 0xc9a99d9eu, 0x3bc21e9du, 0xef087a76u, 0x1d63f975u, 0x0e330a81u, 0xfc588982u,
		0xb21572c9u, 0x407ef1cau, 0x532e023eu, 0xa145813du, 0x758fe5d6u, 0x87e466d5u, 0x94b49521u, 0x66df1622u,
		0x38cc2a06u, 0xcaa7a905u, 0xd9f75af1u, 0x2b9cd9f2u, 0xff56bd19u, 0x0d3d3e1au, 0x1e6dcdeeu, 0xec064eedu,
		0xc38d26c4u, 0x31e6a5c7u, 0x22b65633u, 0xd0ddd530u, 0x0417b1dbu, 0xf67c32d8u, 0xe52cc12cu, 0x1747422fu,
		0x49547e0bu, 0xbb3ffd08u, 0xa86f0efcu, 0x5a048dffu, 0x8ecee914u, 0x7ca56a17u, 0x6ff599e3u, 0x9d9e1ae0u,
		0xd3d3e1abu, 0x21b862a8u, 0x32e8915cu, 0xc083125fu, 0x144976b4u, 0xe622f5b7u, 0xf5720643u, 0x07198540u,
		0x590ab964u, 0xab613a67u, 0xb831c993u, 0x4a5a4a90u, 0x9e902e7bu, 0x6cfbad78u, 0x7fab5e8cu, 0x8dc0dd8fu,
		0xe330a81au, 0x115b2b19u, 0x020bd8edu, 0xf0605beeu, 0x24aa3f05u, 0xd6c1bc06u, 0xc5914ff2u, 0x37faccf1u,
		0x69e9f0d5u, 0x9b8273d6u, 0x88d28022u, 0x7ab90321u, 0xae7367cau, 0x5c18e4c9u, 0x4f48173du, 0xbd23943eu,
		0xf36e6f75u, 0x0105ec76u, 0x12551f82u, 0xe03e9c81u, 0x34f4f86au, 0xc69f7b69u, 0xd5cf889du, 0x27a40b9eu,
		0x79b737bau, 0x8bdcb4b9u, 0x988c474du, 0x6ae7c44eu, 0xbe2da0a5u, 0x4c4623a6u, 0x5f16d052u, 0xad7d5351u
	#endif//USE_CRC32C
	};
#endif//MAKE_CRC_INSTANCE
#endif//USE_STATIC_TABLE
	//--------------------
	//文字列からCRC算出用（再帰処理）
	//※constexpr関数内ではSSE命令に非対応（使用するとコンパイル時に評価されなくなる）
	CONSTEXPR crc32_t calcStr(const crc32_t crc, const char* str)
#ifdef MAKE_CRC_INSTANCE
	{
	#ifndef USE_STATIC_TABLE
		return *str == '\0' ? crc : calcStr(calcPoly(static_cast<crc32_t>((crc ^ *str) & 0xffu)) ^ (crc >> 8), str + 1);//CRC多項式(生成多項式から計算)を合成
	#else//USE_STATIC_TABLE
		return *str == '\0' ? crc : calcStr(s_polyTable[(crc ^ *str) & 0xffu] ^ (crc >> 8), str + 1);//CRC多項式(計算済みテーブルの値)を合成
	#endif//USE_STATIC_TABLE
	}
#else//MAKE_CRC_INSTANCE
	;
#endif//MAKE_CRC_INSTANCE
	//--------------------
	//データ長を指定してCRC算出用（再帰処理）
	//※constexpr関数内ではSSE命令に非対応（使用するとコンパイル時に評価されなくなる）
	CONSTEXPR crc32_t calcData(const crc32_t crc, const char* data, const std::size_t len)
#ifdef MAKE_CRC_INSTANCE
	{
	#ifndef USE_STATIC_TABLE
		return len == 0 ? crc : calcData(calcPoly(static_cast<crc32_t>((crc ^ *data) & 0xffu)) ^ (crc >> 8), data + 1, len - 1);//CRC多項式(生成多項式から計算)を合成
	#else//USE_STATIC_TABLE
		return len == 0 ? crc : calcData(s_polyTable[(crc ^ *data) & 0xffu] ^ (crc >> 8), data + 1, len - 1);//CRC多項式(計算済みテーブルの値)を合成
	#endif//USE_STATIC_TABLE
	}
#else//MAKE_CRC_INSTANCE
	;
#endif//MAKE_CRC_INSTANCE
}//namespace crc_sub

//--------------------
//【constexpr版】文字列からCRC算出
CONSTEXPR inline crc32_t calcConstCRC32(const char* str)
{
	return ~crc_sub::calcStr(~0u, str);
}
//--------------------
//【constexpr版】データ長を指定してCRC算出
CONSTEXPR inline crc32_t calcConstCRC32(const char* data, const std::size_t len)
{
	return ~crc_sub::calcData(~0u, data, len);
}
#ifdef ENABLE_USER_DEFINED_LITERALS
//--------------------
//【ユーザー定義リテラル版】文字列と文字列長を指定してCRC算出
//※operator "" の後に空白が必要なことに注意
CONSTEXPR inline crc32_t operator "" _crc32(const char* str, const std::size_t len)
{
	return calcConstCRC32(str, len);
}
#endif//ENABLE_USER_DEFINED_LITERALS

#ifdef ENABLE_RUNTIME_FUNC
//--------------------
//【通常関数版】文字列からCRC算出
crc32_t calcCRC32(const char* str);
//--------------------
//【通常関数版】データ長を指定してCRC算出
crc32_t calcCRC32(const char* data, const std::size_t len);
#endif//ENABLE_RUNTIME_FUNC
#ifdef ENABLE_MAKE_STATIC_TABLE
//--------------------
//CRC多項式テーブルを作成
void makePolyTable();
#endif//ENABLE_MAKE_STATIC_TABLE

// End of file
