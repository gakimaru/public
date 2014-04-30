#include <stdio.h>
#include <stdlib.h>

//浮動小数のビット計算テスト
int main(const int argc, const char* argv[])
{
	const int NUM_MAX = 256;
	union float_struct
	{
		float f;
		int i;
		struct
		{
			union
			{
				unsigned int b;
			//	struct {
			//		unsigned int v : 23;
			//		unsigned int e : 8;
			//		unsigned int s : 1;
			//	};
			};
			
			int getAll_bits() const { return 32; }
			int getS_bits() const { return 1; }
			int getE_bits() const { return 8; }
			int getV_bits() const { return getAll_bits() - getS_bits() - getE_bits(); }
			int getS_rshift_bits() const { return getE_bits() + getV_bits(); }
			int getE_rshift_bits() const { return getV_bits(); }
			int getV_rshift_bits() const { return 0; }
			unsigned int getS_mask() const { return 0x1; }
			unsigned int getE_mask()const{ return (1 << getE_bits()) - 1; }
			unsigned int getV_mask() const { return (1 << getV_bits()) - 1; }
			int getE_bias()const{ return static_cast<int>(1 << (getE_bits() - 1)) - 1; }
			unsigned int getV_normal()const{ return 1 << getV_bits(); }

			bool isZero() const { return b == 0; }
			
			unsigned int getS()const{ return static_cast<unsigned int>(b >> getS_rshift_bits()) & getS_mask(); }
			int getE()const{ return static_cast<int>(b >> getE_rshift_bits()) & getE_mask(); }
			unsigned int getV()const{ return static_cast<unsigned int>(b >> getV_rshift_bits()) & getV_mask(); }

			int getE_adjusted()const{ return isZero() ? 0 : getE() - getE_bias(); }
			
			unsigned int getV_normalized()const{ return isZero() ? 0 : getV() | getV_normal(); }
			
			int getV_decimal_bits()const{ return isZero() ? 0 : getE_adjusted() >= getV_bits() ? getV_bits() + 1 : getE_adjusted() < 0 ? 0 : getE_adjusted() + 1; }
			int getV_fraction_bits()const{ return isZero() ? 0 : getE_adjusted() < 0 ? getV_bits() + 1 : getE_adjusted() >= getV_bits() ? 0 : getV_bits() - getE_adjusted(); }
			unsigned int getV_decimal_mask()const{ return (1 << getV_decimal_bits()) - 1; }
			unsigned int getV_fraction_mask()const{ return (1 << getV_fraction_bits()) - 1; }
			int getV_decimal_rshift_bits()const{ return isZero() ? 0 : getV_decimal_bits() > 0 ? (getV_bits() + 1) - getV_decimal_bits() : 0; }
			int getV_decimal_lshift_bits()const{ return isZero() ? 0 : getE_adjusted() > getV_bits() ? getE_adjusted() - getV_bits() : 0; }
			int getV_fraction_rshift_bits()const{ return 0; }
			int getV_fraction_lshift_bits()const{ return isZero() ? 0 : getE_adjusted(); }
			int getV_fraction_lshift_bits_fixed()const{ return isZero() ? 0 : getS_bits() + getE_bits(); }
			int getV_fraction_lshift_bits_adjusted()const{ return getV_fraction_lshift_bits_fixed() <= -getV_fraction_lshift_bits() ? getV_fraction_lshift_bits_fixed() - 1 : getV_fraction_lshift_bits_fixed() - (-getV_fraction_lshift_bits()); }
			int getV_fraction_rshift_bits_adjusted()const{ return getV_fraction_lshift_bits_fixed() <= -getV_fraction_lshift_bits() ? -getV_fraction_lshift_bits() - 1 : 0; }
			
			unsigned int getV_decimal()const{ return ((getV_normalized() >> getV_decimal_rshift_bits()) & getV_decimal_mask()) << getV_decimal_lshift_bits(); }
			unsigned int getV_fraction()const{ return (((getV_normalized() >> getV_fraction_rshift_bits()) & getV_fraction_mask()) << getV_fraction_lshift_bits_adjusted()) >> getV_fraction_rshift_bits_adjusted(); }
		} s;
	} n[NUM_MAX];
	int num = 0;
	{
		n[num++].f = 0.f;
		n[num++].f = 0.125f;
		n[num++].f = 0.25f;
		n[num++].f = 0.5f;
		n[num++].f = 0.75f;
		n[num++].f = 0.875f;
		n[num++].f = 1.f;
		n[num++].f = 1.5f;
		n[num++].f = 2.f;
		n[num++].f = 2.5f;
		n[num++].f = 3.f;
		n[num++].f = 3.5f;
		n[num++].f = 4.f;
		n[num++].f = 8.125f;
		n[num++].f = 15.875f;
		n[num++].f = -0.125f;
		n[num++].f = -0.25f;
		n[num++].f = -0.5f;
		n[num++].f = -0.75f;
		n[num++].f = -0.875f;
		n[num++].f = -1.f;
		n[num++].f = -1.5f;
		n[num++].f = -2.f;
		n[num++].f = -2.5f;
		n[num++].f = -3.f;
		n[num++].f = -3.5f;
		n[num++].f = -4.f;
		n[num++].f = -8.125f;
		n[num++].f = -15.875f;
		n[num++].f = static_cast<float>((1 << 24) - 1);
		n[num++].f = static_cast<float>(-((1 << 24)-1));
		n[num++].f =  0.00000011920928955078125f;
		n[num++].f = -0.00000011920928955078125f;
		n[num++].f =  0.000000059604644775390625f;
		n[num++].f = -0.000000059604644775390625f;
		n[num++].f = 1.00000011920928955078125f;
		n[num++].f = -1.00000011920928955078125f;
		n[num++].f = 1.000000059604644775390625f;
		n[num++].f = -1.000000059604644775390625f;
	}
	for (int i = 0; i < num; ++i)
	{
		printf("%24.14f=0x%08x(s=%1u,e=0x%02x(%4d),v=0x%06x(%2u,0x%08x)\n", n[i].f, n[i].i, n[i].s.getS(), n[i].s.getE(), n[i].s.getE_adjusted(), n[i].s.getV_normalized(), n[i].s.getV_decimal(), n[i].s.getV_fraction());
	}

	//整数の乱数を元に、ビット演算で0.f～0.999...fの乱数を生成
	printf("\n");
	printf("----- Make Random: Int to float -----\n");
	int rnd_cnt[11] = { 0 };
	for (int i = 0; i < 100; ++i)
	{
		unsigned int rnd = rand();
		static const unsigned long long range_rnd = static_cast<unsigned long long>(RAND_MAX) + 1llu;
		static const unsigned long long range_rnd_new = 0x007fffffllu + 1llu;
		unsigned int rnd_new = static_cast<unsigned int>(static_cast<unsigned long long>(rnd) * range_rnd_new / range_rnd);//RAND_MAX + 1 = 0x8000(32768) なので、この場合は、「/range_rnd」の代わりに「>> 15」としてもよい。
		float_struct f;
		f.i = 0x3f800000 | rnd_new;
		f.f -= 1.f;
		printf("f.f=%.9f (0x%08x) : %6u -> %8u\n", f.f, f.i, rnd, rnd_new);
		++rnd_cnt[static_cast<unsigned int>(f.f * 11.f)];
	}
	//
	for (int i = 0; i <= 10; ++i)
	{
		printf("%2d: %5d\n", i, rnd_cnt[i]);
	}
	{
		float_struct f;
		f.i = 0x3fffffff;
		printf("f.f=%.9f (0x%08x)\n", f.f, f.i);
	}

	//おまけテスト：ビット演算
	extern void test_calcBits();
	test_calcBits();
	return EXIT_SUCCESS;
}

//--------------------------------------------------------------------------------
//おまけ：ビット演算

//【ランタイム版】ビット数を数える
#define COUNT_BITS_USE_SSE
#ifndef COUNT_BITS_USE_SSE
inline int _countBits_0x0000ffff(const unsigned int bits){ return                       (bits & 0x0000ffff) + (bits >> 16 & 0x0000ffff); }
inline int _countBits_0x00ff00ff(const unsigned int bits){ return _countBits_0x0000ffff((bits & 0x00ff00ff) + (bits >>  8 & 0x00ff00ff)); }
inline int _countBits_0x0f0f0f0f(const unsigned int bits){ return _countBits_0x00ff00ff((bits & 0x0f0f0f0f) + (bits >>  4 & 0x0f0f0f0f)); }
inline int _countBits_0x33333333(const unsigned int bits){ return _countBits_0x0f0f0f0f((bits & 0x33333333) + (bits >>  2 & 0x33333333)); }
inline int _countBits_0x55555555(const unsigned int bits){ return _countBits_0x33333333((bits & 0x55555555) + (bits >>  1 & 0x55555555)); }
inline int countBits(const unsigned int bits){ return _countBits_0x55555555(bits); }
#else//COUNT_BITS_USE_SSE
//※SSE4.2に、POPCNT 命令というビット数を数える関数があるので、それを使ったほうが速い
//　  - 共通 ... int _mm_popcnt_u32(unsigned int) : #include <nmmintrin.h> ※64bit版もあり
//　  - VC++ ... unsigned int __popcnt(unsigned int) : #include <intrin.h> ※16it版と64bit版もあり
//　  - GCC  ... int __builtin_popcount(unsigned int)
#include <nmmintrin.h>//SSE4.2
inline int countBits(const unsigned int bits){ return _mm_popcnt_u32(bits); }
#endif//COUNT_BITS_USE_SSE

//【ランタイム版】MSB(Most Significant Bit)を取得
inline int _getMSB_s16(const unsigned int bits){ return             bits | (bits >> 16);  }
inline int _getMSB_s08(const unsigned int bits){ return _getMSB_s16(bits | (bits >>  8)); }
inline int _getMSB_s04(const unsigned int bits){ return _getMSB_s08(bits | (bits >>  4)); }
inline int _getMSB_s02(const unsigned int bits){ return _getMSB_s04(bits | (bits >>  2)); }
inline int _getMSB_s01(const unsigned int bits){ return _getMSB_s02(bits | (bits >>  1)); }
inline int getMSB(const unsigned int bits){ return bits == 0x0u ? -1 : countBits(_getMSB_s01(bits)) - 1; }

//【ランタイム版】LSB(Least Significant Bit)を取得
inline int _getLSB_s16(const unsigned int bits){ return             bits | (bits << 16); }
inline int _getLSB_s08(const unsigned int bits){ return _getLSB_s16(bits | (bits << 8)); }
inline int _getLSB_s04(const unsigned int bits){ return _getLSB_s08(bits | (bits << 4)); }
inline int _getLSB_s02(const unsigned int bits){ return _getLSB_s04(bits | (bits << 2)); }
inline int _getLSB_s01(const unsigned int bits){ return _getLSB_s02(bits | (bits << 1)); }
inline int getLSB(const unsigned int bits){ return bits == 0x0u ? -1 : countBits(~_getLSB_s01(bits)); }

//【ランタイム版】指定の値以上（Greater than or Equal）で最も小さい２のべき乗を取得
inline unsigned int getNearPow2GE(const unsigned int val){ return val == 0 ? 0 : 1 << (getMSB(val - 1) + 1); }

//【ランタイム版】指定の値以下（Less than or Equal）で最も大きい２のべき乗を取得
inline unsigned int getNearPow2LE(const unsigned int val){ return val == 0 ? 0 : 1 << getMSB(val); }

//【メタプログラミング版】ビット数を数える
template<unsigned int BITS> struct _countBitsMeta_0x0000ffff{ static const int value =                           (BITS & 0x0000ffff) + (BITS >> 16 & 0x0000ffff);         };
template<unsigned int BITS> struct _countBitsMeta_0x00ff00ff{ static const int value = _countBitsMeta_0x0000ffff<(BITS & 0x00ff00ff) + (BITS >>  8 & 0x00ff00ff)>::value; };
template<unsigned int BITS> struct _countBitsMeta_0x0f0f0f0f{ static const int value = _countBitsMeta_0x00ff00ff<(BITS & 0x0f0f0f0f) + (BITS >>  4 & 0x0f0f0f0f)>::value; };
template<unsigned int BITS> struct _countBitsMeta_0x33333333{ static const int value = _countBitsMeta_0x0f0f0f0f<(BITS & 0x33333333) + (BITS >>  2 & 0x33333333)>::value; };
template<unsigned int BITS> struct _countBitsMeta_0x55555555{ static const int value = _countBitsMeta_0x33333333<(BITS & 0x55555555) + (BITS >>  1 & 0x55555555)>::value; };
template<unsigned int BITS> struct countBitsMeta{	          static const int value = _countBitsMeta_0x55555555<BITS>::value;                                            };

//【メタプログラミング版】MSB(Most Significant Bit)を取得
template<unsigned int BITS> struct _getMSBMeta_s16{ static const int value =                 BITS | (BITS >> 16);         };
template<unsigned int BITS> struct _getMSBMeta_s08{ static const int value = _getMSBMeta_s16<BITS | (BITS >>  8)>::value; };
template<unsigned int BITS> struct _getMSBMeta_s04{ static const int value = _getMSBMeta_s08<BITS | (BITS >>  4)>::value; };
template<unsigned int BITS> struct _getMSBMeta_s02{ static const int value = _getMSBMeta_s04<BITS | (BITS >>  2)>::value; };
template<unsigned int BITS> struct _getMSBMeta_s01{ static const int value = _getMSBMeta_s02<BITS | (BITS >>  1)>::value; };
template<unsigned int BITS> struct getMSBMeta{ static const int value = countBitsMeta<_getMSBMeta_s01<BITS>::value>::value - 1; };
template<>                  struct getMSBMeta<0>{ static const int value = -1; };

//【メタプログラミング版】LSB(Least Significant Bit)を取得
template<unsigned int BITS> struct _getLSBMeta_s16{ static const int value =                 BITS | (BITS << 16); };
template<unsigned int BITS> struct _getLSBMeta_s08{ static const int value = _getLSBMeta_s16<BITS | (BITS <<  8)>::value; };
template<unsigned int BITS> struct _getLSBMeta_s04{ static const int value = _getLSBMeta_s08<BITS | (BITS <<  4)>::value; };
template<unsigned int BITS> struct _getLSBMeta_s02{ static const int value = _getLSBMeta_s04<BITS | (BITS <<  2)>::value; };
template<unsigned int BITS> struct _getLSBMeta_s01{ static const int value = _getLSBMeta_s02<BITS | (BITS <<  1)>::value; };
template<unsigned int BITS> struct getLSBMeta{ static const int value = countBitsMeta<~_getLSBMeta_s01<BITS>::value>::value; };
template<>                  struct getLSBMeta<0>{ static const int value = -1; };

//【メタプログラミング版】指定の値以上（Greater than or Equal）で最も小さい２のべき乗を取得
template<unsigned int VAL> struct getNearPow2GEMeta{ static const int value = 1 << (getMSBMeta<VAL - 1>::value + 1); };
template<>                 struct getNearPow2GEMeta<0>{ static const int value = 0; };

//【メタプログラミング版】指定の値以下（Less than or Equal）で最も大きい２のべき乗を取得
template<unsigned int VAL> struct getNearPow2LEMeta{ static const int value = 1 << getMSBMeta<VAL>::value; };
template<>                 struct getNearPow2LEMeta<0>{ static const int value = 0; };

//テスト
void test_calcBits()
{
	printf("\n");
	printf("----- Bit control -----\n");
	static const unsigned int val = 0x20000002;
	printf("count bits   (0x%08x)=%d(%d)\n", val, countBits(val), countBitsMeta<val>::value);
	printf("get MSB      (0x%08x)=%d(%d)\n", val, getMSB(val), getMSBMeta<val>::value);
	printf("get LSB      (0x%08x)=%d(%d)\n", val, getLSB(val), getLSBMeta<val>::value);
	printf("get NearPow2GE (0x%08x)=0x%08x(0x%08x)\n", val, getNearPow2GE(val), getNearPow2GEMeta<val>::value);
	printf("get NearPow2LE (0x%08x)=0x%08x(0x%08x)\n", val, getNearPow2LE(val), getNearPow2LEMeta<val>::value);
}

// End of file
