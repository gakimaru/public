#include <type_traits>//C++11 std::extent用

//[Target machine spec]
//CPU: Intel Core i7 3770K
//URL: http://www.cpu-world.com/CPUs/Core_i7/Intel-Core%20i7-4770.html
//----------------+---------------+----------------+---------------+--------------------------
// Cache:         | L1 data       | L1 instruction | L2            | L3                       
//----------------+---------------+----------------+---------------+--------------------------
// Size:          | 4 x 32KB      | 4 x 32KB       | 4 x 256 KB    | 8 MB                     
// Associativity: | 8-way set     | 8-way set      | 8-way set     | 16-way set               
//                | associative   | associative    | associative   | associative              
// Line size:     | 64 bytes      | 64 bytes       | 64 bytes      | 64 bytes                 
// Comments:      | Direct-mapped | Direct-mapped  | Non-inclusive | Inclusive                
//                |               |                | Direct-mapped | Shared between all cores 
//----------------+---------------+----------------+---------------+--------------------------
//* L1/L2 cache on core
//* 4 cores on cpu

//----------------------------------------
//CPUキャッシュ効率が悪くなる処理の例①：
//【問題】
//・巨大なバッファへのアクセスで、キャッシュの読み替えが頻発。
//【対策】
//・できるだけキャッシュの読み替えが少なくなる処理順序にする。
//　多重ループ処理なら、次数の高い要素を内側のループで処理する。

static int s_hugeBuff1[256][1024];//256 * 1024 * sizoef(int) = 256 * 4KB = 1MB

//初期化
void initCase1()
{
	for (int i = 0; i < std::extent<decltype(s_hugeBuff1), 0>::value; ++i)
		for (int j = 0; j < std::extent<decltype(s_hugeBuff1), 1>::value; ++j)
			s_hugeBuff1[i][j] = 0;
}

//テスト：非効率な処理
void testCase1Bad(int)
{
	int no = 0;
	for (int j = 0; j < std::extent<decltype(s_hugeBuff1), 1>::value; ++j)
		for (int i = 0; i < std::extent<decltype(s_hugeBuff1), 0>::value; ++i)
			s_hugeBuff1[i][j] = no++;
}

//テスト：改善した処理
void testCase1Improved(int)
{
	for (int i = 0; i < std::extent<decltype(s_hugeBuff1), 0>::value; ++i)
	{
		int no = i;
		for (int j = 0; j < std::extent<decltype(s_hugeBuff1), 1>::value; ++j)
		{
			s_hugeBuff1[i][j] = no;
			no += std::extent<decltype(s_hugeBuff1), 0>::value;
		}
	}
}

//----------------------------------------
//CPUキャッシュ効率が悪くなる処理の例②：
//【問題】
//・二つの巨大なバッファへのアクセスで、キャッシュの読み替えが頻発。
//【対策】
//・できるだけキャッシュの読み替えが少なくなるように、
//　局所化した処理を集中的に行うようにする。

static int s_hugeBuff2a[256][256];//256 * 256 * sizoef(int) = 256 * 1KB = 256KB
static int s_hugeBuff2b[256][256];//256 * 256 * sizoef(int) = 256 * 1KB = 256KB

//初期化
void initCase2()
{
	for (int i = 0; i < 256; ++i)
	{
		for (int j = 0; j < 256; ++j)
		{
			s_hugeBuff2a[i][j] = i * std::extent<decltype(s_hugeBuff2a), 0>::value + j;
			s_hugeBuff2b[i][j] = 0;
		}
	}
}

//テスト：非効率な処理
void testCase2Bad(int)
{
	for (int i = 0; i < 256; ++i)
		for (int j = 0; j < 256; ++j)
			s_hugeBuff2b[255 - j][255 - i] = s_hugeBuff2a[i][j];
}

//テスト：改善した処理
void testCase2Improved(int)
{
	for (int k = 0; k < 256; k += 16)//16個ずつ処理を居所化（16*16*sizeof(int)*2=2KB）
	{
		const int begin = k;
		const int end = k + 16;
		for (int i = begin; i < end; ++i)
		{
			for (int j = begin; j < end; ++j)
			{
				s_hugeBuff2b[255 - j][255 - i] = s_hugeBuff2a[i][j];
			}
		}
	}
}

//----------------------------------------
//CPUキャッシュ効率が悪くなる処理の例③：
//【問題】
//・同一キャッシュラインに対するアクセスが集中。
//　セット（ウェイ）を超える同一キャッシュラインへの
//　アクセスが繰り返されるため、キャッシュミスが頻発。
//【対策Ａ】
//・セット（ウェイ）を超えない範囲の処理（８個）に分割する。
//【対策Ｂ】
//・各バッファの先頭アドレス（＝キャッシュライン）をずらす。
//　そのために、バッファとバッファの間にキャッシュラインサイズ（64バイト）の
//　ダミーバッファを配置する。

//#define ENABLE_DUMMY//【対策Ｂ】を実施する場合、このマクロを有効化する

#ifndef ENABLE_DUMMY
#define DUMMY(no)
#define DUMMY_USE(no)
#else//ENABLE_DUMMY
#define DUMMY(no) static char s_dummy##no[64]
#define DUMMY_USE(no) for(int i= 0; i < 64; ++i){s_dummy##no[i] = i;}
#endif//ENABLE_DUMMY

//バッファ
static int s_buff01[1024];//1024 * sizoef(int) = 4KB (L1 Cacheの1Wayのサイズ)
DUMMY(01);
static int s_buff02[1024];//1024 * sizoef(int) = 4KB (L1 Cacheの1Wayのサイズ)
DUMMY(02);
static int s_buff03[1024];//1024 * sizoef(int) = 4KB (L1 Cacheの1Wayのサイズ)
DUMMY(03);
static int s_buff04[1024];//1024 * sizoef(int) = 4KB (L1 Cacheの1Wayのサイズ)
DUMMY(04);
static int s_buff05[1024];//1024 * sizoef(int) = 4KB (L1 Cacheの1Wayのサイズ)
DUMMY(05);
static int s_buff06[1024];//1024 * sizoef(int) = 4KB (L1 Cacheの1Wayのサイズ)
DUMMY(06);
static int s_buff07[1024];//1024 * sizoef(int) = 4KB (L1 Cacheの1Wayのサイズ)
DUMMY(07);
static int s_buff08[1024];//1024 * sizoef(int) = 4KB (L1 Cacheの1Wayのサイズ)
DUMMY(08);
static int s_buff09[1024];//1024 * sizoef(int) = 4KB (L1 Cacheの1Wayのサイズ)
DUMMY(09);
static int s_buff10[1024];//1024 * sizoef(int) = 4KB (L1 Cacheの1Wayのサイズ)
DUMMY(10);
static int s_buff11[1024];//1024 * sizoef(int) = 4KB (L1 Cacheの1Wayのサイズ)
DUMMY(11);
static int s_buff12[1024];//1024 * sizoef(int) = 4KB (L1 Cacheの1Wayのサイズ)
DUMMY(12);
static int s_buff13[1024];//1024 * sizoef(int) = 4KB (L1 Cacheの1Wayのサイズ)
DUMMY(13);
static int s_buff14[1024];//1024 * sizoef(int) = 4KB (L1 Cacheの1Wayのサイズ)
DUMMY(14);
static int s_buff15[1024];//1024 * sizoef(int) = 4KB (L1 Cacheの1Wayのサイズ)
DUMMY(15);
static int s_buff16[1024];//1024 * sizoef(int) = 4KB (L1 Cacheの1Wayのサイズ)
DUMMY(16);
static int s_buff17[1024];//1024 * sizoef(int) = 4KB (L1 Cacheの1Wayのサイズ)
DUMMY(17);
static int s_buff18[1024];//1024 * sizoef(int) = 4KB (L1 Cacheの1Wayのサイズ)
DUMMY(18);
static int s_buff19[1024];//1024 * sizoef(int) = 4KB (L1 Cacheの1Wayのサイズ)
DUMMY(19);
static int s_buff20[1024];//1024 * sizoef(int) = 4KB (L1 Cacheの1Wayのサイズ)
DUMMY(20);
static int s_buff21[1024];//1024 * sizoef(int) = 4KB (L1 Cacheの1Wayのサイズ)
DUMMY(21);
static int s_buff22[1024];//1024 * sizoef(int) = 4KB (L1 Cacheの1Wayのサイズ)
DUMMY(22);
static int s_buff23[1024];//1024 * sizoef(int) = 4KB (L1 Cacheの1Wayのサイズ)
DUMMY(23);
static int s_buff24[1024];//1024 * sizoef(int) = 4KB (L1 Cacheの1Wayのサイズ)
DUMMY(24);

//初期化
void initCase3()
{
	for (int i = 0; i < std::extent<decltype(s_buff01), 0>::value; ++i)
	{
		s_buff01[i] = 0;
		s_buff02[i] = 0;
		s_buff03[i] = 0;
		s_buff04[i] = 0;
		s_buff05[i] = 0;
		s_buff06[i] = 0;
		s_buff07[i] = 0;
		s_buff08[i] = 0;
		s_buff09[i] = 0;
		s_buff10[i] = 0;
		s_buff11[i] = 0;
		s_buff12[i] = 0;
		s_buff13[i] = 0;
		s_buff14[i] = 0;
		s_buff15[i] = 0;
		s_buff16[i] = 0;
		s_buff17[i] = 0;
		s_buff18[i] = 0;
		s_buff19[i] = 0;
		s_buff20[i] = 0;
		s_buff21[i] = 0;
		s_buff22[i] = 0;
		s_buff23[i] = 0;
		s_buff24[i] = 0;
	}

	DUMMY_USE(01);
	DUMMY_USE(02);
	DUMMY_USE(03);
	DUMMY_USE(04);
	DUMMY_USE(05);
	DUMMY_USE(06);
	DUMMY_USE(07);
	DUMMY_USE(08);
	DUMMY_USE(09);
	DUMMY_USE(10);
	DUMMY_USE(11);
	DUMMY_USE(12);
	DUMMY_USE(13);
	DUMMY_USE(14);
	DUMMY_USE(15);
	DUMMY_USE(16);
	DUMMY_USE(17);
	DUMMY_USE(18);
	DUMMY_USE(19);
	DUMMY_USE(20);
	DUMMY_USE(21);
	DUMMY_USE(22);
	DUMMY_USE(23);
	DUMMY_USE(24);
}

//テスト：非効率な処理
void testCase3Bad(int)
{
	for (int i = 0; i < std::extent<decltype(s_buff01), 0>::value; ++i)
	{
		s_buff01[i] += 1;
		s_buff02[i] += s_buff01[i];
		s_buff03[i] += s_buff02[i];
		s_buff04[i] += s_buff03[i];
		s_buff05[i] += s_buff04[i];
		s_buff06[i] += s_buff05[i];
		s_buff07[i] += s_buff06[i];
		s_buff08[i] += s_buff07[i];
		s_buff09[i] += s_buff08[i];
		s_buff10[i] += s_buff09[i];
		s_buff11[i] += s_buff10[i];
		s_buff12[i] += s_buff11[i];
		s_buff13[i] += s_buff12[i];
		s_buff14[i] += s_buff13[i];
		s_buff15[i] += s_buff14[i];
		s_buff16[i] += s_buff15[i];
		s_buff17[i] += s_buff16[i];
		s_buff18[i] += s_buff17[i];
		s_buff19[i] += s_buff18[i];
		s_buff20[i] += s_buff19[i];
		s_buff21[i] += s_buff20[i];
		s_buff22[i] += s_buff21[i];
		s_buff23[i] += s_buff22[i];
		s_buff24[i] += s_buff23[i];
	}
}

//テスト：改善した処理
void testCase3Improved(int)
{
	for (int i = 0; i < std::extent<decltype(s_buff01), 0>::value; ++i)
	{
		s_buff01[i] += 1;
		s_buff02[i] += s_buff01[i];
		s_buff03[i] += s_buff02[i];
		s_buff04[i] += s_buff03[i];
		s_buff05[i] += s_buff04[i];
		s_buff06[i] += s_buff05[i];
		s_buff07[i] += s_buff06[i];
		s_buff08[i] += s_buff07[i];
	}
	for (int i = 0; i < std::extent<decltype(s_buff01), 0>::value; ++i)
	{
		s_buff09[i] += s_buff08[i];
		s_buff10[i] += s_buff09[i];
		s_buff11[i] += s_buff10[i];
		s_buff12[i] += s_buff11[i];
		s_buff13[i] += s_buff12[i];
		s_buff14[i] += s_buff13[i];
		s_buff15[i] += s_buff14[i];
	}
	for (int i = 0; i < std::extent<decltype(s_buff01), 0>::value; ++i)
	{
		s_buff16[i] += s_buff15[i];
		s_buff17[i] += s_buff16[i];
		s_buff18[i] += s_buff17[i];
		s_buff19[i] += s_buff18[i];
		s_buff20[i] += s_buff19[i];
		s_buff21[i] += s_buff20[i];
		s_buff22[i] += s_buff21[i];
	}
	for (int i = 0; i < std::extent<decltype(s_buff01), 0>::value; ++i)
	{
		s_buff23[i] += s_buff22[i];
		s_buff24[i] += s_buff23[i];
	}
}

// End of file
