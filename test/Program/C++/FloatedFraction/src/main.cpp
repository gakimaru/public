#include <stdio.h>
#include <stdlib.h>

//浮動小数のビット計算テスト
int main(const int argc, const char* argv[])
{
	const int NUM_MAX = 256;
	union
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
	return EXIT_SUCCESS;
}

// End of file
