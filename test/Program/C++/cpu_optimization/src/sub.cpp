#include "sub.h"

#include <random>//C++11 std::random�p

//----------------------------------------
//�œK���@�F�������A�N�Z�X�̗}���F�ꎞ�ϐ��̊��p

//������
void initOpt01(dataOpt01_t& data)
{
	std::mt19937 rnd_engine;
	std::uniform_int_distribution<int> rnd_dist(0, dataOpt01_t::elem_t::VALUE_RANGE - 1);
	data.sum = 0;
	for (auto& elems : data.elems)
	{
		elems.value = rnd_dist(rnd_engine);
	}
}

//�y�^�C�v�P�z�œK���O
//���P���Ȕz�񃋁[�v�A�N�Z�X
void testOpt01_Type1_Before(dataOpt01_t& data)
{
	for (std::size_t i = 0; i < extentof(data.elems); ++i)
		data.sum += data.elems[i].value;
}

//�y�^�C�v�P�z�œK����P
//���ꎞ�ϐ���p�ӂ��ă��[�v���̃����o�[�ϐ��ւ̃A�N�Z�X�����炷
void testOpt01_Type1_After1(dataOpt01_t& data)
{
	int sum_tmp = 0;
	for (std::size_t i = 0; i < extentof(data.elems); ++i)
		sum_tmp += data.elems[i].value;
	data.sum = sum_tmp;
}

//�y�^�C�v�P�z�œK����Q
//���|�C���^�v�Z�ɒu�������ă��[�v�J�E���^�𖳂���
void testOpt01_Type1_After2(dataOpt01_t& data)
{
	int sum_tmp = 0;
	const dataOpt01_t::elem_t* end = data.elems + extentof(data.elems);
	for (dataOpt01_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
		sum_tmp += elem_p->value;
	data.sum = sum_tmp;
}

//�y�^�C�v�P�z�y�Q�l�zC++11�ł����Ƃ��Ȍ��ȋL�q
//��C++11�͈̔͂Ɋ�Â�for���[�v���g�p���A�ł��Ȍ��ɋL�q�����R�[�h�i�x���j
void testOpt01_Type1_Appendix(dataOpt01_t& data)
{
	for (auto elems : data.elems)
		data.sum += elems.value;
}

//----------------------------------------
//�œK���A�F�������A�N�Z�X�̗}���F�A�h���X�v�Z�̍팸

//������
void initOpt02(dataOpt02_t& data)
{
	std::mt19937 rnd_engine;
	std::uniform_int_distribution<int> rnd_dist(0, dataOpt02_t::elem_t::VALUE_RANGE - 1);
	for (auto& elems : data.elems)
	{
		elems.value = rnd_dist(rnd_engine);
	}
}

//�y�^�C�v�P�z�œK���O
//�����[�v�����Ŕz��v�f�𒼐ڎw��
int testOpt02_Type1_Before(dataOpt02_t& data)
{
	//���z�W�v�p�\����
	struct dist_t
	{
		int value;
		int count;
	};
	//���z�W�v�p�ϐ�������
	dist_t dist[dataOpt02_t::elem_t::VALUE_RANGE];
	for (int value = 0; value < dataOpt02_t::elem_t::VALUE_RANGE; ++value)
	{
		dist[value].value = value;
		dist[value].count = 0;
	}
	//���z�W�v
	for (std::size_t i = 0; i < extentof(data.elems); ++i)
		++dist[data.elems[i].value].count;
	//�ő啪�z�擾
	const dist_t* top_dist_p = &dist[0];
	for (std::size_t i = 1; i < dataOpt02_t::elem_t::VALUE_RANGE; ++i)
	{
		if (top_dist_p->count < dist[i].count)
			top_dist_p = &dist[i];
	}
	return (top_dist_p->count << 16) | top_dist_p->value;
}

//�y�^�C�v�P�z�œK����P
//�����z�W�v�����|�C���^�v�Z�ɕύX
int testOpt02_Type1_After1(dataOpt02_t& data)
{
	//���z�W�v�p�\����
	struct dist_t
	{
		int value;
		int count;
	};
	//���z�W�v�p�ϐ�������
	dist_t dist[dataOpt02_t::elem_t::VALUE_RANGE];
	for (int value = 0; value < dataOpt02_t::elem_t::VALUE_RANGE; ++value)
	{
		dist[value].value = value;
		dist[value].count = 0;
	}
	//���z�W�v
	{
		const dataOpt02_t::elem_t* end = data.elems + extentof(data.elems);
		for (const dataOpt02_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
			++dist[elem_p->value].count;
	}
	//�ő啪�z�擾
	const dist_t* top_dist_p = &dist[0];
	for (std::size_t i = 1; i < dataOpt02_t::elem_t::VALUE_RANGE; ++i)
	{
		if (top_dist_p->count < dist[i].count)
			top_dist_p = &dist[i];
	}
	return (top_dist_p->count << 16) | top_dist_p->value;
}

//�y�^�C�v�P�z�œK����Q
//���O��I�Ƀ|�C���^�v�Z�ɕύX
int testOpt02_Type1_After2(dataOpt02_t& data)
{
	//���z�W�v�p�\����
	struct dist_t
	{
		int value;
		int count;
	};
	//���z�W�v�p�ϐ�������
	dist_t dist[dataOpt02_t::elem_t::VALUE_RANGE];
	const dist_t* dist_end = dist + dataOpt02_t::elem_t::VALUE_RANGE;
	{
		int value = 0;
		for (dist_t* dist_p = dist; dist_p < dist_end; ++dist_p)
		{
			dist_p->value = value++;
			dist_p->count = 0;
		}
	}
	//���z�W�v
	{
		const dataOpt02_t::elem_t* end = data.elems + extentof(data.elems);
		for (const dataOpt02_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
			++dist[elem_p->value].count;
	}
	//�ő啪�z�擾
	const dist_t* top_dist_p = dist;
	{
		for (const dist_t* dist_p = top_dist_p + 1; dist_p < dist_end; ++dist_p)
		{
			if (top_dist_p->count < dist_p->count)
				top_dist_p = dist_p;
		}
	}
	return (top_dist_p->count << 16) | top_dist_p->value;
}

//----------------------------------------
//�œK���B�F�������A�N�Z�X�̗}���F�֐��Ăяo���̍팸

//�y�^�C�v�P�z�œK���O
//���ʏ�֐�
int testOpt03_Type1_Before(int a, int b, int c)
{
	return a * b + c;
}

//�y�^�C�v�P�z�œK����
//���C�����C���֐�
//inline int testOpt03_Type1_Before(int a, int b, int c)
//��sub.h�ɒ�`

//�y�^�C�v�Q�z�œK���O
//�������̑����ʏ�֐�
int testOpt03_Type2_Before(int a, int b, int c, int d, int e, int f, int g, int h)
{
	return a * b + c - d * e + f - g * h;
}

//�y�^�C�v�Q�z�œK����
//���C�����C���֐�
//inline int testOpt03_Type2_Before(int a, int b, int c, int d, int e, int f, int g, int h)
//��sub.h�ɒ�`

//�y�^�C�v�R�z������
void initOpt03_Type3(dataOpt03_t& data)
{
	std::mt19937 rnd_engine;
	std::uniform_int_distribution<int> rnd_dist(0, dataOpt03_t::VALUE_RANGE - 1);
	for (auto& value : data.values)
	{
		value = rnd_dist(rnd_engine);
	}
}

//�y�^�C�v�R�z�œK���O�F���ʊ֐�
//���I�u�U�[�o�[�i�R�[���o�b�N�j�� std::function �^�Ŏ󂯎��
#include <functional>//C++11 std::function�p
template <typename T, std::size_t N>
void commonProc_testOpt03_Type3_Before(T(&values)[N], const T find, std::function<void(int&)> observer)
{
	//�z�񂩂�l���������A��������I�u�U�[�o�[���Ăяo��
	const T* end = values + N;
	for (T* value_p = values; value_p < end; ++value_p)
	{
		if (*value_p == find)
			observer(*value_p);
	}
}

//�y�^�C�v�R�z�œK����F���ʊ֐�
//���I�u�U�[�o�[�i�R�[���o�b�N�j���e���v���[�g�Ō^�W�J���Ď󂯎��istd::sort �ȂǂƓ��������j
template < typename T, std::size_t N, class OBSERVER>
void commonProc_testOpt03_Type3_After(T(&values)[N], const T find, OBSERVER observer)
{
	//�z�񂩂�l���������A��������I�u�U�[�o�[���Ăяo��
	const T* end = values + N;
	for (T* value_p = values; value_p < end; ++value_p)
	{
		if (*value_p == find)
			observer(*value_p);
	}
}

//�y�^�C�v�R�z�œK���O
//���œK���O�̋��ʊ֐����g�p
int testOpt03_Type3_Before(dataOpt03_t& data)
{
	//�z����̒l���������ĕʂ̒l�ɒu�������郉���_��
	//���ϐ�data/exchange���L���v�`�������N���\�W���Ƃ��ĐU�镑��
	auto exchangeData = [&data](const int find, const int exchange)
	{
		commonProc_testOpt03_Type3_Before(data.values, 0,
			[&exchange](int& value)
			{
				value = exchange;
			}
		);
	};
	//�z����̒l���������ďo�������Z�o���郉���_��
	//���ϐ�data/count���L���v�`�������N���\�W���Ƃ��ĐU�镑��
	auto countData = [&data](const int find) -> int
	{
		int count = 0;
		commonProc_testOpt03_Type3_Before(data.values, find,
			[&count](int& value)
			{
				++count;
			}
		);
		return count;
	};
	//�l�̒u������
	exchangeData(0, 1);
	//�l�̏o�����̍��v��Ԃ�
	return countData(1) + countData(2) + countData(3);
}

//�y�^�C�v�R�z�œK����
//���œK����̋��ʊ֐����g�p
int testOpt03_Type3_After(dataOpt03_t& data)
{
	//�z����̒l���������ĕʂ̒l�ɒu�������郉���_��
	//���ϐ�data/exchange���L���v�`�������N���\�W���Ƃ��ĐU�镑��
	auto exchangeData = [&data](const int find, const int exchange)
	{
		commonProc_testOpt03_Type3_After(data.values, 0,
			[&exchange](int& value)
			{
				value = exchange;
			}
		);
	};
	//�z����̒l���������ďo�������Z�o���郉���_��
	//���ϐ�data/count���L���v�`�������N���\�W���Ƃ��ĐU�镑��
	auto countData = [&data](const int find) -> int
	{
		int count = 0;
		commonProc_testOpt03_Type3_After(data.values, find,
			[&count](int& value)
			{
				++count;
			}
		);
		return count;
	};
	//�l�̒u������
	exchangeData(0, 1);
	//�l�̏o�����̍��v��Ԃ�
	return countData(1) + countData(2) + countData(3);
}

//----------------------------------------
//�œK���C�F���Z�̗}���F��Z�ɕύX

//������
void initOpt04(dataOpt04_t& data)
{
	std::mt19937 rnd_engine;
	std::uniform_int_distribution<int> rnd_dist(0, dataOpt04_t::elem_t::VALUE_RANGE - 1);
	for (auto& elems : data.elems)
	{
		elems.value = rnd_dist(rnd_engine);
		elems.ratio = 0.f;
	}
}

//�y�^�C�v�P�z�œK���O
//���f���ȕ��������_�f�[�^���Z�A����сA���Z
void testOpt04_Type1_Before(dataOpt04_t& data)
{
	//���v�l�Z�o
	float sum = 0.f;
	const dataOpt04_t::elem_t* end = data.elems + extentof(data.elems);
	for (dataOpt04_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
		sum += static_cast<float>(elem_p->value);
	//�e�v�f�̕��z�䗦���Z�o
	for (dataOpt04_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
		elem_p->ratio = static_cast<float>(elem_p->value) / sum;
}

//�y�^�C�v�P�z�œK����P
//�����Z����Z�ɕύX
void testOpt04_Type1_After1(dataOpt04_t& data)
{
	//���v�l�Z�o
	float sum = 0.f;
	const dataOpt04_t::elem_t* end = data.elems + extentof(data.elems);
	for (dataOpt04_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
		sum += static_cast<float>(elem_p->value);
	//�e�v�f�̕��z�䗦���Z�o
	const float base_ratio = 1.f / sum;
	for (dataOpt04_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
		elem_p->ratio = static_cast<float>(elem_p->value) * base_ratio;
}

//�y�^�C�v�P�z�œK����Q
//�����������_���Z�̐������炷�i�������Z�̂܂܂ł悢�Ƃ���͐������Z����j
void testOpt04_Type1_After2(dataOpt04_t& data)
{
	//���v�l�Z�o
	int sum = 0;
	const dataOpt04_t::elem_t* end = data.elems + extentof(data.elems);
	for (dataOpt04_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
		sum += elem_p->value;
	//�e�v�f�̕��z�䗦���Z�o
	const float base_ratio = 1.f / static_cast<float>(sum);
	for (dataOpt04_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
		elem_p->ratio = static_cast<float>(elem_p->value) * base_ratio;
}

//----------------------------------------
//�œK���D�F��Z�^���Z�̗}���F�V�t�g���Z������Z�ɕύX

//�y�^�C�v�P�z�œK���O
template<int N>
inline int intMul(const int val){ return val * N; }
template<int N>
inline int intDiv(const int val){ return val / N; }
template<int N>
inline int intMod(const int val){ return val % N; }
int testOpt05_Type1_Before(const int val, 
                           int& m2, int& m3, int& m4, int& m5, int& m10, int& m16, int& m24,
						   int& d2, int& d3, int& d4, int& d5, int& d10, int& d16, int& d24,
						   int& r2, int& r3, int& r4, int& r5, int& r10, int& r16, int& r24)
{
	m2 = intMul<2>(val);
	m3 = intMul<3>(val);
	m4 = intMul<4>(val);
	m5 = intMul<5>(val);
	m10 = intMul<10>(val);
	m16 = intMul<16>(val);
	m24 = intMul<24>(val);
	d2 = intDiv<2>(val);
	d3 = intDiv<3>(val);
	d4 = intDiv<4>(val);
	d5 = intDiv<5>(val);
	d10 = intDiv<10>(val);
	d16 = intDiv<16>(val);
	d24 = intDiv<24>(val);
	r2 = intMod<2>(val);
	r3 = intMod<3>(val);
	r4 = intMod<4>(val);
	r5 = intMod<5>(val);
	r10 = intMod<10>(val);
	r16 = intMod<16>(val);
	r24 = intMod<24>(val);
	return m2 + m3 + m4 + m5 + m10 + m16 + m24 +
	       d2 + d3 + d4 + d5 + d10 + d16 + d24 + 
	       r2 + r3 + r4 + r5 + r10 + r16 + r24;
}
//�y�^�C�v�P�z�œK����
#include <iostream>
#include <exception>
//����Z�̃��C�e���V��5�Ɖ��肵�A�V�t�g���Z��1���Z��1�Ƃ��āA�v5�����Ȃ�V�t�g���Z�Ɖ��Z�ɓW�J�������ꉻ��K�p����
template<int N> inline int intMulOpt(const int val){ return val * N; }
template<>      inline int intMulOpt<0>(const int val){ return 0; }
template<>      inline int intMulOpt<1>(const int val){ return val; }
template<>      inline int intMulOpt<2>(const int val){ return val << 1; }
template<>      inline int intMulOpt<3>(const int val){ return (val << 1) + val; }
template<>      inline int intMulOpt<4>(const int val){ return val << 2; }
template<>      inline int intMulOpt<5>(const int val){ return (val << 2) + val; }
template<>      inline int intMulOpt<6>(const int val){ return (val << 2) + (val << 1); }
template<>      inline int intMulOpt<7>(const int val){ return (val << 2) + (val << 1) + val; }
template<>      inline int intMulOpt<8>(const int val){ return val << 3; }
template<>      inline int intMulOpt<9>(const int val){ return (val << 3) + val; }
template<>      inline int intMulOpt<10>(const int val){ return (val << 3) + (val << 1); }
template<>      inline int intMulOpt<11>(const int val){ return (val << 3) + (val << 1) + val; }
template<>      inline int intMulOpt<12>(const int val){ return (val << 3) + (val << 2); }
template<>      inline int intMulOpt<13>(const int val){ return (val << 3) + (val << 2) + val; }
template<>      inline int intMulOpt<16>(const int val){ return val << 4; }
template<>      inline int intMulOpt<20>(const int val){ return (val << 4) + (val << 2); }
template<>      inline int intMulOpt<24>(const int val){ return (val << 4) + (val << 3); }
template<>      inline int intMulOpt<32>(const int val){ return val << 5; }
template<>      inline int intMulOpt<64>(const int val){ return val << 6; }
template<>      inline int intMulOpt<128>(const int val){ return val << 7; }
template<>      inline int intMulOpt<256>(const int val){ return val << 8; }
template<>      inline int intMulOpt<512>(const int val){ return val << 9; }
template<>      inline int intMulOpt<1024>(const int val){ return val << 10; }
//template<int N> inline int intDivOpt(const int val){ return (static_cast<long long>(val) * (0xffffffffll / static_cast<long long>(N)) + 32) >> 32; }//�t����萔�����Đ������Z
//template<int N> constexpr int getReciprocalDivisor(){ return static_cast<int>(0xffffffffll / static_cast<long long>(N)); }
//template<int N> inline int intDivOpt(const int val)//�t����萔�����Đ������Z�i�C�����C���A�Z���u���Łj
//{
//	//return (static_cast<long long>(val) * (0xffffffffll / static_cast<long long>(N)) + 32) >> 32;
//	const int rec = getReciprocalDivisor<N>();
//	__asm
//	{
//		mov     eax, rec	//eax �� rec
//		mul     val			//edx:eax �� eax * val
//		add     eax, 32		//eax �� eax + 32
//		adc     edx, 0		//edx �� edx + 0 + �L�����[�t���O
//		mov     eax, edx	//eax �� edx ���߂�l
//	}
//}
//template<int N> inline int intDivOpt(const int val){ return static_cast<int>(static_cast<float>(val) * (1.f / (static_cast<float>(N)))); }//�t����萔�����ĕ��������_���Z������ɐ�����
template<int N> inline int intDivOpt(const int val){ return val / N; }//���̂܂܉��Z
template<>      inline int intDivOpt<0>(const int val){ throw std::overflow_error("Integer division by zero");	return 0; }
template<>      inline int intDivOpt<1>(const int val){ return val; }
template<>      inline int intDivOpt<2>(const int val){ return val >> 1; }
template<>      inline int intDivOpt<4>(const int val){ return val >> 2; }
template<>      inline int intDivOpt<8>(const int val){ return val >> 3; }
template<>      inline int intDivOpt<16>(const int val){ return val >> 4; }
template<>      inline int intDivOpt<32>(const int val){ return val >> 5; }
template<>      inline int intDivOpt<64>(const int val){ return val >> 6; }
template<>      inline int intDivOpt<128>(const int val){ return val >> 7; }
template<>      inline int intDivOpt<256>(const int val){ return val >> 8; }
template<>      inline int intDivOpt<512>(const int val){ return val >> 9; }
template<>      inline int intDivOpt<1024>(const int val){ return val >> 10; }
//template<int N> inline int intModOpt(const int val){ return (((static_cast<long long>(val) * (0xffffffffll / static_cast<long long>(N)) + 32) & 0xffffffffll) * static_cast<long long>(N)) >> 32; }//�t����萔�����Đ������Z
//template<int N> inline int intModOpt(const int val)//�t����萔�����Đ������Z�i�C�����C���A�Z���u���Łj
//{
//	//return (((static_cast<long long>(val) * (0xffffffffll / static_cast<long long>(N)) + 32) & 0xffffffffll) * static_cast<long long>(N)) >> 32;
//	const int rec = getReciprocalDivisor<N>();
//	const int n = N;
//	__asm
//	{
//		mov     eax, rec	//eax �� rec
//		mul     val			//edx:eax �� eax * val
//		add     eax, 32		//eax �� eax + 32
//		mul     n           //edx:eax �� eax * N
//		mov     eax, edx	//eax �� edx ���߂�l
//	}
//}
//template<int N> inline int intModOpt(const int val){ return val - static_cast<int>(static_cast<float>(val)* (1.f / (static_cast<float>(N)))) * N; }//�t����萔�����ĕ��������_���Z������ɐ�����
template<int N> inline int intModOpt(const int val){ return val % N; }//���̂܂܉��Z
template<>      inline int intModOpt<0>(const int val){ throw std::overflow_error("Integer division by zero");	return 0; }
template<>      inline int intModOpt<1>(const int val){ return 0; }
template<>      inline int intModOpt<2>(const int val){ return val & (2 - 1); }
template<>      inline int intModOpt<4>(const int val){ return val & (4 - 1); }
template<>      inline int intModOpt<8>(const int val){ return val & (8 - 1); }
template<>      inline int intModOpt<16>(const int val){ return val & (16 - 1); }
template<>      inline int intModOpt<32>(const int val){ return val & (32 - 1); }
template<>      inline int intModOpt<64>(const int val){ return val & (64 - 1); }
template<>      inline int intModOpt<128>(const int val){ return val & (128 - 1); }
template<>      inline int intModOpt<256>(const int val){ return val & (256 - 1); }
template<>      inline int intModOpt<512>(const int val){ return val & (512 - 1); }
template<>      inline int intModOpt<1024>(const int val){ return val & (1024 - 1); }
int testOpt05_Type1_After(const int val,
                          int& m2, int& m3, int& m4, int& m5, int& m10, int& m16, int& m24,
						  int& d2, int& d3, int& d4, int& d5, int& d10, int& d16, int& d24,
						  int& r2, int& r3, int& r4, int& r5, int& r10, int& r16, int& r24)
{
	m2 = intMulOpt<2>(val);
	m3 = intMulOpt<3>(val);
	m4 = intMulOpt<4>(val);
	m5 = intMulOpt<5>(val);
	m10 = intMulOpt<10>(val);
	m16 = intMulOpt<16>(val);
	m24 = intMulOpt<24>(val);
	d2 = intDivOpt<2>(val);
	d3 = intDivOpt<3>(val);
	d4 = intDivOpt<4>(val);
	d5 = intDivOpt<5>(val);
	d10 = intDivOpt<10>(val);
	d16 = intDivOpt<16>(val);
	d24 = intDivOpt<24>(val);
	r2 = intModOpt<2>(val);
	r3 = intModOpt<3>(val);
	r4 = intModOpt<4>(val);
	r5 = intModOpt<5>(val);
	r10 = intModOpt<10>(val);
	r16 = intModOpt<16>(val);
	r24 = intModOpt<24>(val);
	return m2 + m3 + m4 + m5 + m10 + m16 + m24 +
	       d2 + d3 + d4 + d5 + d10 + d16 + d24 +
	       r2 + r3 + r4 + r5 + r10 + r16 + r24;
}

//----------------------------------------
//�œK���E�F��Z�^���Z�̗}���F���Z�̋��ʉ�

//������
void initOpt06(dataOpt06_t& data)
{
	std::mt19937 rnd_engine;
	std::uniform_real_distribution<float> rnd_dist(0.f, static_cast<float>(dataOpt06_t::elem_t::VALUE_RANGE));
	for (auto& elems : data.elems)
	{
		elems.value = rnd_dist(rnd_engine);
		elems.result = 0.f;
	}
}

//�y�^�C�v�P�z�œK���O
//���f���ȏ揜�Z
void testOpt06_Type1_Before(dataOpt06_t& data, const float mul1, const float mul2, const float div)
{
	//�e�v�f���v�Z
	const dataOpt06_t::elem_t* end = data.elems + extentof(data.elems);
	for (dataOpt06_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
		elem_p->result = elem_p->value * mul1 * mul2 / div;
}

//�y�^�C�v�P�z�œK����
//�����Z�����ʉ�����
void testOpt06_Type1_After(dataOpt06_t& data, const float mul1, const float mul2, const float div)
{
	//�e�v�f���v�Z
	const float calc = mul1 * mul2 / div;
	const dataOpt06_t::elem_t* end = data.elems + extentof(data.elems);
	for (dataOpt06_t::elem_t* elem_p = data.elems; elem_p < end; ++elem_p)
		elem_p->result = elem_p->value * calc;
}

//----------------------------------------
//�œK���F�FSIMD���Z�����p����
#include <memory.h>//memset�p

//�y�^�C�v�P�z�œK���O

//----------
//�s����Z
//���P�����[�v��
template<std::size_t N, std::size_t M>
void addMatrix(matrix<N, M>& mat0, const matrix<N, M>& mat1, const matrix<N, M>& mat2)
{
	for (int n = 0; n < N; ++n)
		for (int m = 0; m < M; ++m)
			mat0(n, m) = mat1(n, m) + mat2(n, m);
}
//----------
//�s��X�J���[��Z
//���P�����[�v��
template<std::size_t N, std::size_t M>
void mulMatrixScalar(matrix<N, M>& mat0, const matrix<N, M>& mat1, const float scalar)
{
	for (int n = 0; n < N; ++n)
		for (int m = 0; m < M; ++m)
			mat0(n, m) = mat1(n, m) * scalar;
}
//----------
//�s��ώZ
//���P�����[�v��
template<std::size_t N, std::size_t M, std::size_t NM>
void mulMatrix(matrix<N, M>& mat0, const matrix<N, NM>& mat1, const matrix<NM, M>& mat2)
{
	memset(mat0.value, 0, sizeof(mat0.value));
	for (int n = 0; n < N; ++n)
		for (int m = 0; m < M; ++m)
			for (int nm = 0; nm < NM; ++nm)
				mat0(n, m) += (mat1(n, nm) * mat2(nm, m));
}
//----------
//�e�X�g
template<std::size_t N, std::size_t M, std::size_t NM>
void testOpt07_Type1_Before(const int dummy, matrix<N, M>& add0, matrix<N, M>& mul0a, matrix<N, M>& mul0b, const matrix<N, M>& add1, const matrix<N, M>& add2, const matrix<N, M>& mul1a, const float mul2a, const matrix<N, NM>& mul1b, const matrix<NM, M>& mul2b)
{
	addMatrix(add0, add1, add2);
	mulMatrixScalar(mul0a, mul1a, mul2a);
	mulMatrix(mul0b, mul1b, mul2b);
}

//�y�^�C�v�P�z�œK����

//----------
//�s����Z
#if 1
//���P�����[�v��
template<std::size_t N, std::size_t M>
void addMatrixOpt(matrix<N, M>& mat0, const matrix<N, M>& mat1, const matrix<N, M>& mat2)
{
	for (int n = 0; n < N; ++n)
		for (int m = 0; m < M; ++m)
			mat0(n, m) = mat1(n, m) + mat2(n, m);
}
#else
//���ċA�e���v���[�g��
//�@���S�ȃC�����C���W�J�ɂ�郋�[�v�����ȏ�̍œK�������҂���R�[�h�Ȃ̂ŁA�W�J����Ȃ��ƒx��
template<std::size_t N, std::size_t M, std::size_t NOW_N, std::size_t NOW_M>
struct _addMatrixOpt{
	inline static void calc(matrix<N, M>& mat0, const matrix<N, M>& mat1, const matrix<N, M>& mat2)
	{
		mat0(NOW_N, NOW_M) = mat1(NOW_N, NOW_M) + mat2(NOW_N, NOW_M);
		_addMatrixOpt<N, M, NOW_N, NOW_M - 1>::calc(mat0, mat1, mat2);
	}
};
template<std::size_t N, std::size_t M, std::size_t NOW_N>
struct _addMatrixOpt<N, M, NOW_N, 0>{
	inline static void calc(matrix<N, M>& mat0, const matrix<N, M>& mat1, const matrix<N, M>& mat2)
	{
		mat0(NOW_N, 0) = mat1(NOW_N, 0) + mat2(NOW_N, 0);
		_addMatrixOpt<N, M, NOW_N - 1, M - 1>::calc(mat0, mat1, mat2);
	}
};
template<std::size_t N, std::size_t M, std::size_t NOW_M>
struct _addMatrixOpt<N, M, 0, NOW_M>{
	inline static void calc(matrix<N, M>& mat0, const matrix<N, M>& mat1, const matrix<N, M>& mat2)
	{
		mat0(0, NOW_M) = mat1(0, NOW_M) + mat2(0, NOW_M);
		_addMatrixOpt<N, M, N - 1, NOW_M - 1>::calc(mat0, mat1, mat2);
	}
};
template<std::size_t N, std::size_t M>
struct _addMatrixOpt<N, M, 0, 0>{
	inline static void calc(matrix<N, M>& mat0, const matrix<N, M>& mat1, const matrix<N, M>& mat2)
	{
		mat0(0, 0) = mat1(0, 0) + mat2(0, 0);
	}
};
template<std::size_t N, std::size_t M>
void addMatrixOpt(matrix<N, M>& mat0, const matrix<N, M>& mat1, const matrix<N, M>& mat2)
{
	_addMatrixOpt<N, M, N - 1, M - 1>::calc(mat0, mat1, mat2);
}
#endif
#if 1
//��4�~4�s��p���ꉻ
#include <smmintrin.h>//SSE4.1�p
template<>
void addMatrixOpt<4, 4>(matrix<4, 4>& mat0, const matrix<4, 4>& mat1, const matrix<4, 4>& mat2)
{
	//mat1�����[�h
	//��16�o�C�g�A���C�������g����Ă��邱�Ƃ�O��ɁA_mm_load_ps ���g�p�i_mm_loadu_ps �͎g��Ȃ��j
	const __m128 _mat1[4] = { _mm_load_ps(mat1.value[0]), _mm_load_ps(mat1.value[1]), _mm_load_ps(mat1.value[2]), _mm_load_ps(mat1.value[3]) };
	//mat2�����[�h
	const __m128 _mat2[4] = { _mm_load_ps(mat2.value[0]), _mm_load_ps(mat2.value[1]), _mm_load_ps(mat2.value[2]), _mm_load_ps(mat2.value[3]) };
	//�s������Z����mat0�ɃX�g�A
	_mm_store_ps(mat0.value[0], _mm_add_ps(_mat1[0], _mat2[0]));
	_mm_store_ps(mat0.value[1], _mm_add_ps(_mat1[1], _mat2[1]));
	_mm_store_ps(mat0.value[2], _mm_add_ps(_mat1[2], _mat2[2]));
	_mm_store_ps(mat0.value[3], _mm_add_ps(_mat1[3], _mat2[3]));
}
#endif

//----------
//�s��X�J���[��Z
#if 1
//���P�����[�v��
template<std::size_t N, std::size_t M>
void mulMatrixScalarOpt(matrix<N, M>& mat0, const matrix<N, M>& mat1, const float scalar)
{
	for (int n = 0; n < N; ++n)
		for (int m = 0; m < M; ++m)
			mat0(n, m) = mat1(n, m) * scalar;
}
#else
//���ċA�e���v���[�g��
//�@���S�ȃC�����C���W�J�ɂ�郋�[�v�����ȏ�̍œK�������҂���R�[�h�Ȃ̂ŁA�W�J����Ȃ��ƒx��
template<std::size_t N, std::size_t M, std::size_t NOW_N, std::size_t NOW_M>
struct _mulMatrixScalarOpt{
	inline static void calc(matrix<N, M>& mat0, const matrix<N, M>& mat1, const float scalar)
	{
		mat0(NOW_N, NOW_M) = mat1(NOW_N, NOW_M) * scalar;
		_mulMatrixScalarOpt<N, M, NOW_N, NOW_M - 1>::calc(mat0, mat1, scalar);
	}
};
template<std::size_t N, std::size_t M, std::size_t NOW_N>
struct _mulMatrixScalarOpt<N, M, NOW_N, 0>{
	inline static void calc(matrix<N, M>& mat0, const matrix<N, M>& mat1, const float scalar)
	{
		mat0(NOW_N, 0) = mat1(NOW_N, 0) * scalar;
		_mulMatrixScalarOpt<N, M, NOW_N - 1, M - 1>::calc(mat0, mat1, scalar);
	}
};
template<std::size_t N, std::size_t M, std::size_t NOW_M>
struct _mulMatrixScalarOpt<N, M, 0, NOW_M>{
	inline static void calc(matrix<N, M>& mat0, const matrix<N, M>& mat1, const float scalar)
	{
		mat0(0, NOW_M) = mat1(0, NOW_M) * scalar;
		_mulMatrixScalarOpt<N, M, N - 1, NOW_M - 1>::calc(mat0, mat1, scalar);
	}
};
template<std::size_t N, std::size_t M>
struct _mulMatrixScalarOpt<N, M, 0, 0>{
	inline static void calc(matrix<N, M>& mat0, const matrix<N, M>& mat1, const float scalar)
	{
		mat0(0, 0) = mat1(0, 0) * scalar;
	}
};
template<std::size_t N, std::size_t M>
void mulMatrixScalarOpt(matrix<N, M>& mat0, const matrix<N, M>& mat1, const float scalar)
{
	_mulMatrixScalarOpt<N, M, N - 1, M - 1>::calc(mat0, mat1, scalar);
}
#endif
#if 1
//��4�~4�s��p���ꉻ
#include <smmintrin.h>//SSE4.1�p
template<>
void mulMatrixScalarOpt<4, 4>(matrix<4, 4>& mat0, const matrix<4, 4>& mat1, const float scalar)
{
	//mat1�����[�h
	//��16�o�C�g�A���C�������g����Ă��邱�Ƃ�O��ɁA_mm_load_ps ���g�p�i_mm_loadu_ps �͎g��Ȃ��j
	const __m128 _mat1[4] = { _mm_load_ps(mat1.value[0]), _mm_load_ps(mat1.value[1]), _mm_load_ps(mat1.value[2]), _mm_load_ps(mat1.value[3]) };
	//mat2�����[�h
	const __m128 _mat2 = _mm_set1_ps(scalar);
	//�s�����Z����mat0�ɃX�g�A
	_mm_store_ps(mat0.value[0], _mm_mul_ps(_mat1[0], _mat2));
	_mm_store_ps(mat0.value[1], _mm_mul_ps(_mat1[1], _mat2));
	_mm_store_ps(mat0.value[2], _mm_mul_ps(_mat1[2], _mat2));
	_mm_store_ps(mat0.value[3], _mm_mul_ps(_mat1[3], _mat2));
}
#endif

//----------
//�s��ώZ
#if 1
//���P�����[�v��
template<std::size_t N, std::size_t M, std::size_t NM>
void mulMatrixOpt(matrix<N, M>& mat0, const matrix<N, NM>& mat1, const matrix<NM, M>& mat2)
{
	memset(mat0.value, 0, sizeof(mat0.value));
	for (int n = 0; n < N; ++n)
		for (int m = 0; m < M; ++m)
			for (int nm = 0; nm < NM; ++nm)
				mat0(n, m) += (mat1(n, nm) * mat2(nm, m));
}
#else
//���ċA�e���v���[�g��
//�@���S�ȃC�����C���W�J�ɂ�郋�[�v�����ȏ�̍œK�������҂���R�[�h�Ȃ̂ŁA�W�J����Ȃ��ƒx��
template<std::size_t N, std::size_t M, std::size_t NM, std::size_t NOW_N, std::size_t NOW_M, std::size_t NOW_NM>
struct _mulMatrixOpt{
	inline static void calc(matrix<N, M>& mat0, const matrix<N, NM>& mat1, const matrix<NM, M>& mat2)
	{
		mat0(NOW_N, NOW_M) += (mat1(NOW_N, NOW_NM) * mat2(NOW_NM, NOW_M));
		_mulMatrixOpt<N, M, NM, NOW_N, NOW_M, NOW_NM - 1>::calc(mat0, mat1, mat2);
	}
};
template<std::size_t N, std::size_t M, std::size_t NM, std::size_t NOW_N, std::size_t NOW_M>
struct _mulMatrixOpt<N, M, NM, NOW_N, NOW_M, 0>{
	inline static void calc(matrix<N, M>& mat0, const matrix<N, NM>& mat1, const matrix<NM, M>& mat2)
	{
		mat0(NOW_N, NOW_M) += (mat1(NOW_N, 0) * mat2(0, NOW_M));
		_mulMatrixOpt<N, M, NM, NOW_N, NOW_M - 1, NM - 1>::calc(mat0, mat1, mat2);
	}
};
template<std::size_t N, std::size_t M, std::size_t NM, std::size_t NOW_N>
struct _mulMatrixOpt<N, M, NM, NOW_N, 0, 0>{
	inline static void calc(matrix<N, M>& mat0, const matrix<N, NM>& mat1, const matrix<NM, M>& mat2)
	{
		mat0(NOW_N, 0) += (mat1(NOW_N, 0) * mat2(0, 0));
		_mulMatrixOpt<N, M, NM, NOW_N - 1, M - 1, NM - 1>::calc(mat0, mat1, mat2);
	}
};
template<std::size_t N, std::size_t M, std::size_t NM>
struct _mulMatrixOpt<N, M, NM, 0, 0, 0>{
	inline static void calc(matrix<N, M>& mat0, const matrix<N, NM>& mat1, const matrix<NM, M>& mat2)
	{
		mat0(0, 0) += (mat1(0, 0) * mat2(0, 0));
	}
};
template<std::size_t N, std::size_t M, std::size_t NM>
void mulMatrixOpt(matrix<N, M>& mat0, const matrix<N, NM>& mat1, const matrix<NM, M>& mat2)
{
	memset(mat0.value, 0, sizeof(mat0.value));
	_mulMatrixOpt<N, M, NM, N - 1, M - 1, NM - 1>::calc(mat0, mat1, mat2);
}
#endif
#if 1
//��4�~4�s��p���ꉻ
#include <smmintrin.h>//SSE4.1�p
template<>
void mulMatrixOpt<4, 4, 4>(matrix<4, 4>& mat0, const matrix<4, 4>& mat1, const matrix<4, 4>& mat2)
{
	//mat1�����[�h
	//��16�o�C�g�A���C�������g����Ă��邱�Ƃ�O��ɁA_mm_load_ps ���g�p�i_mm_loadu_ps �͎g��Ȃ��j
	const __m128 _mat1[4] = { _mm_load_ps(mat1.value[0]), _mm_load_ps(mat1.value[1]), _mm_load_ps(mat1.value[2]), _mm_load_ps(mat1.value[3]) };
#if 0
	//mat2�����[�h���ē]�u�iSIMD���Z���Ղ��悤�Ɂj���x�^�ȏ���
	const float alignas(16) _mat2t_tmp[4][4] =
	{
		{ mat2.value[0][0], mat2.value[1][0], mat2.value[2][0], mat2.value[3][0] },
		{ mat2.value[0][1], mat2.value[1][1], mat2.value[2][1], mat2.value[3][1] },
		{ mat2.value[0][2], mat2.value[1][2], mat2.value[2][2], mat2.value[3][2] },
		{ mat2.value[0][3], mat2.value[1][3], mat2.value[2][3], mat2.value[3][3] },
	};
	const __m128 _mat2t[4] = { _mm_load_ps(_mat2t_tmp[0]), _mm_load_ps(_mat2t_tmp[1]), _mm_load_ps(_mat2t_tmp[2]), _mm_load_ps(_mat2t_tmp[3]) };
#else
	//mat2�����[�h���ē]�u�iSIMD���Z���Ղ��悤�Ɂj���V���b�t�����p
	const __m128 _mat2t_tmp1[4] =
	{
		_mm_load_ps(mat2.value[0]),
		_mm_load_ps(mat2.value[1]),
		_mm_load_ps(mat2.value[2]),
		_mm_load_ps(mat2.value[3])
	};
	const __m128 _mat2t_tmp2[4] =
	{
		_mm_unpacklo_ps(_mat2t_tmp1[0], _mat2t_tmp1[1]),
		_mm_unpacklo_ps(_mat2t_tmp1[2], _mat2t_tmp1[3]),
		_mm_unpackhi_ps(_mat2t_tmp1[0], _mat2t_tmp1[1]),
		_mm_unpackhi_ps(_mat2t_tmp1[2], _mat2t_tmp1[3])
	};
	const __m128 _mat2t[4] =
	{
		_mm_shuffle_ps(_mat2t_tmp2[0], _mat2t_tmp2[1], 0x44),
		_mm_shuffle_ps(_mat2t_tmp2[0], _mat2t_tmp2[1], 0xee),
		_mm_shuffle_ps(_mat2t_tmp2[2], _mat2t_tmp2[3], 0x44),
		_mm_shuffle_ps(_mat2t_tmp2[2], _mat2t_tmp2[3], 0xee)
	};
#endif
#if 0
	//�s���ώZ����mat0�ɃX�g�A�iSSE4.1�̓��ϖ��ߎg�p�j���x�^�ȏ���
	_mm_store_ss(&mat0.value[0][0], _mm_dp_ps(_mat1[0], _mat2t[0], 0xf1));
	_mm_store_ss(&mat0.value[0][1], _mm_dp_ps(_mat1[0], _mat2t[1], 0xf1));
	_mm_store_ss(&mat0.value[0][2], _mm_dp_ps(_mat1[0], _mat2t[2], 0xf1));
	_mm_store_ss(&mat0.value[0][3], _mm_dp_ps(_mat1[0], _mat2t[3], 0xf1));
	_mm_store_ss(&mat0.value[1][0], _mm_dp_ps(_mat1[1], _mat2t[0], 0xf1));
	_mm_store_ss(&mat0.value[1][1], _mm_dp_ps(_mat1[1], _mat2t[1], 0xf1));
	_mm_store_ss(&mat0.value[1][2], _mm_dp_ps(_mat1[1], _mat2t[2], 0xf1));
	_mm_store_ss(&mat0.value[1][3], _mm_dp_ps(_mat1[1], _mat2t[3], 0xf1));
	_mm_store_ss(&mat0.value[2][0], _mm_dp_ps(_mat1[2], _mat2t[0], 0xf1));
	_mm_store_ss(&mat0.value[2][1], _mm_dp_ps(_mat1[2], _mat2t[1], 0xf1));
	_mm_store_ss(&mat0.value[2][2], _mm_dp_ps(_mat1[2], _mat2t[2], 0xf1));
	_mm_store_ss(&mat0.value[2][3], _mm_dp_ps(_mat1[2], _mat2t[3], 0xf1));
	_mm_store_ss(&mat0.value[3][0], _mm_dp_ps(_mat1[3], _mat2t[0], 0xf1));
	_mm_store_ss(&mat0.value[3][1], _mm_dp_ps(_mat1[3], _mat2t[1], 0xf1));
	_mm_store_ss(&mat0.value[3][2], _mm_dp_ps(_mat1[3], _mat2t[2], 0xf1));
	_mm_store_ss(&mat0.value[3][3], _mm_dp_ps(_mat1[3], _mat2t[3], 0xf1));
#else
	//�s���ώZ����mat0�ɃX�g�A�iSSE4.1�̓��ϖ��ߎg�p�j���V���b�t�����p
	_mm_store_ps(mat0.value[0], _mm_shuffle_ps(_mm_unpacklo_ps(_mm_dp_ps(_mat1[0], _mat2t[0], 0xf1),
	                                                           _mm_dp_ps(_mat1[0], _mat2t[1], 0xf1)),
	                                           _mm_unpacklo_ps(_mm_dp_ps(_mat1[0], _mat2t[2], 0xf1),
	                                                           _mm_dp_ps(_mat1[0], _mat2t[3], 0xf1)), 0x44));
	_mm_store_ps(mat0.value[1], _mm_shuffle_ps(_mm_unpacklo_ps(_mm_dp_ps(_mat1[1], _mat2t[0], 0xf1),
	                                                           _mm_dp_ps(_mat1[1], _mat2t[1], 0xf1)),
	                                           _mm_unpacklo_ps(_mm_dp_ps(_mat1[1], _mat2t[2], 0xf1),
	                                                           _mm_dp_ps(_mat1[1], _mat2t[3], 0xf1)), 0x44));
	_mm_store_ps(mat0.value[2], _mm_shuffle_ps(_mm_unpacklo_ps(_mm_dp_ps(_mat1[2], _mat2t[0], 0xf1),
	                                                           _mm_dp_ps(_mat1[2], _mat2t[1], 0xf1)),
	                                           _mm_unpacklo_ps(_mm_dp_ps(_mat1[2], _mat2t[2], 0xf1),
	                                                           _mm_dp_ps(_mat1[2], _mat2t[3], 0xf1)), 0x44));
	_mm_store_ps(mat0.value[3], _mm_shuffle_ps(_mm_unpacklo_ps(_mm_dp_ps(_mat1[3], _mat2t[0], 0xf1),
	                                                           _mm_dp_ps(_mat1[3], _mat2t[1], 0xf1)),
	                                           _mm_unpacklo_ps(_mm_dp_ps(_mat1[3], _mat2t[2], 0xf1),
	                                                           _mm_dp_ps(_mat1[3], _mat2t[3], 0xf1)), 0x44));
#endif
}
#endif

//----------
//�e�X�g
template<std::size_t N, std::size_t M, std::size_t NM>
void testOpt07_Type1_After(const int dummy, matrix<N, M>& add0, matrix<N, M>& mul0a, matrix<N, M>& mul0b, const matrix<N, M>& add1, const matrix<N, M>& add2, const matrix<N, M>& mul1a, const float mul2a, const matrix<N, NM>& mul1b, const matrix<NM, M>& mul2b)
{
	addMatrixOpt(add0, add1, add2);
	mulMatrixScalarOpt(mul0a, mul1a, mul2a);
	mulMatrixOpt(mul0b, mul1b, mul2b);
}

//----------
//�e�X�g�֐����C���X�^���X��
template
void testOpt07_Type1_Before<4, 4, 4>(const int dummy, matrix4x4& add0, matrix4x4& mul0a, matrix4x4& mul0b, const matrix4x4& add1, const matrix4x4& add2, const matrix4x4& mul1a, const float mul2a, const matrix4x4& mul1b, const matrix4x4& mul2b);
template
void testOpt07_Type1_After<4, 4, 4>(const int dummy, matrix4x4& add0, matrix4x4& mul0a, matrix4x4& mul0b, const matrix4x4& add1, const matrix4x4& add2, const matrix4x4& mul1a, const float mul2a, const matrix4x4& mul1b, const matrix4x4& mul2b);
template
void testOpt07_Type1_Before<1, 4, 3>(const int dummy, matrix1x4& add0, matrix1x4& mul0a, matrix1x4& mul0b, const matrix1x4& add1, const matrix1x4& add2, const matrix1x4& mul1a, const float mul2a, const matrix1x3& mul1b, const matrix3x4& mul2b);
template
void testOpt07_Type1_After<1, 4, 3>(const int dummy, matrix1x4& add0, matrix1x4& mul0a, matrix1x4& mul0b, const matrix1x4& add1, const matrix1x4& add2, const matrix1x4& mul1a, const float mul2a, const matrix1x3& mul1b, const matrix3x4& mul2b);

//�y�^�C�v�Q�z�œK���O
#pragma warning(disable: 4996)//strcpy, strncpy�p
#include <string.h>//strlen, strcmp, strncmp, strchr, strrchr, strcpy, strncpy�p
std::size_t testOpt07_Type2_strlen_Before(const int dummy, const char* str)
{
	return strlen(str);
}
int testOpt07_Type2_strcmp_Before(const int dummy, const char* str1, const char* str2)
{
	return strcmp(str1, str2);
}
int testOpt07_Type2_strncmp_Before(const int dummy, const char* str1, const char* str2, const std::size_t max_len)
{
	return strncmp(str1, str2, max_len);
}
const char* testOpt07_Type2_strchr_Before(const int dummy, const char* str, const char c)
{
	return strchr(str, c);
}
const char* testOpt07_Type2_strrchr_Before(const int dummy, const char* str, const char c)
{
	return strrchr(str, c);
}
const char* testOpt07_Type2_strstr_Before(const int dummy, const char* str1, const char* str2)
{
	return strstr(str1, str2);
}
const char* testOpt07_Type2_strcpy_Before(const int dummy, char* dst, const char* src)
{
	return strcpy(dst, src);
}
const char* testOpt07_Type2_strncpy_Before(const int dummy, char* dst, const char* src, const std::size_t max_len)
{
	return strncpy(dst, src, max_len);
}
//�y�^�C�v�Q�z�œK����
#include <nmmintrin.h>//SSE4.2�p
#include <cstdint>//intptr_t�p
//----------
//SSE��strlen
std::size_t _strlen_fast(const char* str)
{
//null�`�F�b�N���Ȃ�
//	if (!str)
//		return 0;
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	static const __m128i null = _mm_setzero_si128();
	const char* p = str;
	const std::size_t str_over = reinterpret_cast<intptr_t>(str) & 0xf;
	if (str_over != 0)
	{
		//��16�o�C�g�A���C�����g��
		const __m128i str16 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p));
		const int zf          = _mm_cmpistrz(null, str16, flags);//�����̓�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
		const std::size_t pos = _mm_cmpistri(null, str16, flags);
		if (zf)
			return pos;
		p += (16 - str_over);
	}
	//16�o�C�g�A���C�����g��
	const __m128i* p128 = reinterpret_cast<const __m128i*>(p);
	while (true)
	{
		const __m128i str16 = _mm_load_si128(p128);
		const int zf          = _mm_cmpistrz(null, str16, flags);//�����̓�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
		const std::size_t pos = _mm_cmpistri(null, str16, flags);
		if (zf)
			return (reinterpret_cast<const char*>(p128) - str) + pos;
		++p128;
	}
	return 0;//dummy
}
//----------
//SSE��strcmp�⏕�֐�
static inline int _str_case(const char* str1, const char* str2)
{
	return (((reinterpret_cast<intptr_t>(str1) & 0xf) != 0) << 0) |
	       (((reinterpret_cast<intptr_t>(str2) & 0xf) != 0) << 1);
}
static inline int _strcmp_compare(const int val1, const int val2)
{
	const int val = val1 - val2;
	return (val >> 31) | (val != 0);
}
//SSE��strcmp:16�o�C�g�A���C�����g�{16�o�C�g�A���C�����g��
static int _strcmp_fast_case0(const char* str1, const char* str2)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_NEGATIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const __m128i* p1 = reinterpret_cast<const __m128i*>(str1);
	const __m128i* p2 = reinterpret_cast<const __m128i*>(str2);
	while (true)
	{
		const __m128i str16_1 = _mm_load_si128(p1);
		const __m128i str16_2 = _mm_load_si128(p2);
		const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//�����̎O�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
		const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
		const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
		if (cf)
		{
			const char c1 = *(reinterpret_cast<const char*>(p1)+pos);
			const char c2 = *(reinterpret_cast<const char*>(p2)+pos);
			return _strcmp_compare(c1, c2);
		}
		if (zf)
			return 0;
		++p1;
		++p2;
	}
	return 0;//dummy
}
//SSE��strcmp:��16�o�C�g�A���C�����g�{16�o�C�g�A���C�����g��
static int _strcmp_fast_case1(const char* str1, const char* str2)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_NEGATIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const char* p1 = str1;
	const __m128i* p2 = reinterpret_cast<const __m128i*>(str2);
	while (true)
	{
		const __m128i str16_1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p1));
		const __m128i str16_2 = _mm_load_si128(p2);
		const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//�����̎O�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
		const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
		const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
		if (cf)
		{
			const char c1 = *(p1 + pos);
			const char c2 = *(reinterpret_cast<const char*>(p2)+pos);
			return _strcmp_compare(c1, c2);
		}
		if (zf)
			return 0;
		p1 += 16;
		++p2;
	}
	return 0;//dummy
}
//SSE��strcmp:16�o�C�g�A���C�����g�{��16�o�C�g�A���C�����g��
static int _strcmp_fast_case2(const char* str1, const char* str2)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_NEGATIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const __m128i* p1 = reinterpret_cast<const __m128i*>(str1);
	const char* p2 = str2;
	while (true)
	{
		const __m128i str16_1 = _mm_load_si128(p1);
		const __m128i str16_2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p2));
		const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//�����̎O�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
		const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
		const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
		if (cf)
		{
			const char c1 = *(reinterpret_cast<const char*>(p1)+pos);
			const char c2 = *(p2 + pos);
			return _strcmp_compare(c1, c2);
		}
		if (zf)
			return 0;
		++p1;
		p2 += 16;
	}
	return 0;//dummy
}
//SSE��strcmp:16�o�C�g�A���C�����g�{��16�o�C�g�A���C�����g��
static int _strcmp_fast_case3(const char* str1, const char* str2)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_NEGATIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const char* p1 = str1;
	const char* p2 = str2;
	while (true)
	{
		const __m128i str16_1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p1));
		const __m128i str16_2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p2));
		const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//�����̎O�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
		const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
		const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
		if (cf)
		{
			const char c1 = *(reinterpret_cast<const char*>(p1)+pos);
			const char c2 = *(reinterpret_cast<const char*>(p2)+pos);
			return _strcmp_compare(c1, c2);
		}
		if (zf)
			return 0;
		p1 += 16;
		p2 += 16;
	}
	return 0;//dummy
}
//SSE��strcmp:�֐��e�[�u��
typedef int (*_strcmp_fast_casex_t)(const char* str1, const char* str2);
static const _strcmp_fast_casex_t _strcmp_fast_casex[] =
{
	_strcmp_fast_case0,
	_strcmp_fast_case1,
	_strcmp_fast_case2,
	_strcmp_fast_case3
};
//SSE��strcmp
int _strcmp_fast(const char* str1, const char* str2)
{
//null�`�F�b�N���Ȃ�
//	if (!str1) if (!str2) return 0;
//	           else       return -1;
//	else       if (!str2) return 1;
//	//         else       continue...
	return _strcmp_fast_casex[_str_case(str1, str2)](str1, str2);
}
//----------
//SSE��strncmp:16�o�C�g�A���C�����g�{16�o�C�g�A���C�����g��
static int _strncmp_fast_case0(const char* str1, const char* str2, const std::size_t max_len)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_NEGATIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	static const __m128i null = _mm_setzero_si128();
	const __m128i* p1 = reinterpret_cast<const __m128i*>(str1);
	const __m128i* p2 = reinterpret_cast<const __m128i*>(str2);
	const char* p1_end = str1 + max_len;
	const char* p1_end_16 = p1_end - 16;
	while (reinterpret_cast<const char*>(p1) <= p1_end_16)
	{
		const __m128i str16_1 = _mm_load_si128(p1);
		const __m128i str16_2 = _mm_load_si128(p2);
		const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//�����̎O�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
		const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
		const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
		if (cf)
		{
			const char c1 = *(reinterpret_cast<const char*>(p1) + pos);
			const char c2 = *(reinterpret_cast<const char*>(p2) + pos);
			return _strcmp_compare(c1, c2);
		}
		if (zf)
			return 0;
		++p1;
		++p2;
	}
	{
		const std::size_t remain = p1_end - reinterpret_cast<const char*>(p1);
		if (remain > 0)
		{
			const __m128i str16_1 = _mm_load_si128(p1);
			const __m128i str16_2 = _mm_load_si128(p2);
			const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//�����̎O�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
			//const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
			const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
			if (cf)
			{
				if (pos >= remain)
					return 0;
				const char c1 = *(reinterpret_cast<const char*>(p1) + pos);
				const char c2 = *(reinterpret_cast<const char*>(p2) + pos);
				return _strcmp_compare(c1, c2);
			}
			//if (zf)
			//	return 0;
		}
	}
	return 0;
}
//SSE��strncmp:��16�o�C�g�A���C�����g�{16�o�C�g�A���C�����g��
static int _strncmp_fast_case1(const char* str1, const char* str2, const std::size_t max_len)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_NEGATIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	static const __m128i null = _mm_setzero_si128();
	const char* p1 = str1;
	const __m128i* p2 = reinterpret_cast<const __m128i*>(str2);
	const char* p1_end = str1 + max_len;
	const char* p1_end_16 = p1_end - 16;
	while (p1 <= p1_end_16)
	{
		const __m128i str16_1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p1));
		const __m128i str16_2 = _mm_load_si128(p2);
		const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//�����̎O�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
		const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
		const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
		if (cf)
		{
			const char c1 = *(p1 + pos);
			const char c2 = *(reinterpret_cast<const char*>(p2) + pos);
			return _strcmp_compare(c1, c2);
		}
		if (zf)
			return 0;
		p1 += 16;
		++p2;
	}
	{
		const std::size_t remain = p1_end - p1;
		if (remain > 0)
		{
			const __m128i str16_1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p1));
			const __m128i str16_2 = _mm_load_si128(p2);
			const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//�����̎O�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
			//const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
			const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
			if (cf)
			{
				if (pos >= remain)
					return 0;
				const char c1 = *(p1 + pos);
				const char c2 = *(reinterpret_cast<const char*>(p2) + pos);
				return _strcmp_compare(c1, c2);
			}
			//if (zf)
			//	return 0;
		}
	}
	return 0;
}
//SSE��strncmp:16�o�C�g�A���C�����g�{��16�o�C�g�A���C�����g��
static int _strncmp_fast_case2(const char* str1, const char* str2, const std::size_t max_len)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_NEGATIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	static const __m128i null = _mm_setzero_si128();
	const __m128i* p1 = reinterpret_cast<const __m128i*>(str1);
	const char* p2 = str2;
	const char* p1_end = str1 + max_len;
	const char* p1_end_16 = p1_end - 16;
	while (reinterpret_cast<const char*>(p1) <= p1_end_16)
	{
		const __m128i str16_1 = _mm_load_si128(p1);
		const __m128i str16_2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p2));
		const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//�����̎O�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
		const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
		const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
		if (cf)
		{
			const char c1 = *(reinterpret_cast<const char*>(p1) + pos);
			const char c2 = *(p2 + pos);
			return _strcmp_compare(c1, c2);
		}
		if (zf)
			return 0;
		++p1;
		p2 += 16;
	}
	{
		const std::size_t remain = p1_end - reinterpret_cast<const char*>(p1);
		if (remain > 0)
		{
			const __m128i str16_1 = _mm_load_si128(p1);
			const __m128i str16_2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p2));
			const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//�����̎O�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
			//const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
			const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
			if (cf)
			{
				if (pos >= remain)
					return 0;
				const char c1 = *(reinterpret_cast<const char*>(p1)+pos);
				const char c2 = *(p2 + pos);
				return _strcmp_compare(c1, c2);
			}
			//if (zf)
			//	return 0;
		}
	}
	return 0;
}
//SSE��strncmp:16�o�C�g�A���C�����g�{��16�o�C�g�A���C�����g��
static int _strncmp_fast_case3(const char* str1, const char* str2, const std::size_t max_len)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_NEGATIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	static const __m128i null = _mm_setzero_si128();
	const char* p1 = str1;
	const char* p2 = str2;
	const char* p1_end = str1 + max_len;
	const char* p1_end_16 = p1_end - 16;
	while (p1 <= p1_end_16)
	{
		const __m128i str16_1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p1));
		const __m128i str16_2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p2));
		const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//�����̎O�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
		const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
		const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
		if (cf)
		{
			const char c1 = *(p1 + pos);
			const char c2 = *(p2 + pos);
			return _strcmp_compare(c1, c2);
		}
		if (zf)
			return 0;
		p1 += 16;
		p2 += 16;
	}
	{
		const std::size_t remain = p1_end - p1;
		if (remain > 0)
		{
			const __m128i str16_1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p1));
			const __m128i str16_2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p2));
			const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//�����̎O�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
			//const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
			const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
			if (cf)
			{
				if (pos >= remain)
					return 0;
				const char c1 = *(p1 + pos);
				const char c2 = *(p2 + pos);
				return _strcmp_compare(c1, c2);
			}
			//if (zf)
			//	return 0;
		}
	}
	return 0;
}
//SSE��strncmp:�֐��e�[�u��
typedef int (*_strncmp_fast_casex_t)(const char* str1, const char* str2, const std::size_t max_len);
static const _strncmp_fast_casex_t _strncmp_fast_casex[] =
{
	_strncmp_fast_case0,
	_strncmp_fast_case1,
	_strncmp_fast_case2,
	_strncmp_fast_case3
};
//SSE��strncmp
int _strncmp_fast(const char* str1, const char* str2, const std::size_t max_len)
{
//null�`�F�b�N���Ȃ�
//	if (!str1) if (!str2) return 0;
//	           else       return -1;
//	else       if (!str2) return 1;
//	//         else       continue...
	return _strncmp_fast_casex[_str_case(str1, str2)](str1, str2, max_len);
}
//----------
//SSE��strchr
const char* _strchr_fast(const char* str, const char c)
{
//null�`�F�b�N���Ȃ�
//	if (!str)
//		return 0;
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const __m128i c16 = _mm_set1_epi8(c);
	const char* p = str;
	const std::size_t str_over = reinterpret_cast<intptr_t>(str) & 0xf;
	if (str_over != 0)
	{
		//��16�o�C�g�A���C�����g��
		const __m128i str16 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p));
		const int cf          = _mm_cmpistrc(c16, str16, flags);//�����̎O�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
		const int zf          = _mm_cmpistrz(c16, str16, flags);
		const std::size_t pos = _mm_cmpistri(c16, str16, flags);
		if (cf)
			return reinterpret_cast<const char*>(p) + pos;
		if (zf)
			return nullptr;
		p += (16 - str_over);
	}
	//16�o�C�g�A���C�����g��
	const __m128i* p128 = reinterpret_cast<const __m128i*>(p);
	while (true)
	{
		const __m128i str16 = _mm_load_si128(p128);
		const int cf          = _mm_cmpistrc(c16, str16, flags);//�����̎O�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
		const int zf          = _mm_cmpistrz(c16, str16, flags);
		const std::size_t pos = _mm_cmpistri(c16, str16, flags);
		if (cf)
			return reinterpret_cast<const char*>(p128) + pos;
		if (zf)
			return nullptr;
		++p128;
	}
	return nullptr;//dummy
}
//----------
//SSE��strrchr
const char* _strrchr_fast(const char* str, const char c)
{
//null�`�F�b�N���Ȃ�
//	if (!str)
//		return 0;
	const char* found_p = nullptr;
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_MOST_SIGNIFICANT;
	const __m128i c16 = _mm_set1_epi8(c);
	const char* p = str;
	const std::size_t str_over = reinterpret_cast<intptr_t>(str) & 0xf;
	if (str_over != 0)
	{
		//��16�o�C�g�A���C�����g��
		const __m128i str16 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p));
		const int cf          = _mm_cmpistrc(c16, str16, flags);//�����̎O�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
		const int zf          = _mm_cmpistrz(c16, str16, flags);
		const std::size_t pos = _mm_cmpistri(c16, str16, flags);
		if (cf)
			found_p = p + pos;
		if (zf)
			return found_p;
		p += (16 - str_over);
	}
	//16�o�C�g�A���C�����g��
	const __m128i* p128 = reinterpret_cast<const __m128i*>(p);
	while (true)
	{
		const __m128i str16 = _mm_load_si128(p128);
		const int cf          = _mm_cmpistrc(c16, str16, flags);//�����̎O�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
		const int zf          = _mm_cmpistrz(c16, str16, flags);
		const std::size_t pos = _mm_cmpistri(c16, str16, flags);
		if (cf)
			found_p = reinterpret_cast<const char*>(p128) + pos;
		if (zf)
			return found_p;
		++p128;
	}
	return nullptr;//dummy
}
//----------
//SSE��strstr�p�⏕�֐�:�p�^�[����2������p
static const char* _strstr_fast_2(const char* str, const char* pattern)
{
//	if (*str == '\0' || *(str + 1) == '\0')//�����̔���͌Ăяo�����ōs���Ă���
//		return nullptr;
	const char pattern_top_c = *pattern;//�擪�̕���
	const char pattern_2nd_c = *(pattern + 1);//2�����ڂ̕���
	const __m128i pattern_top_c16 = _mm_set1_epi8(pattern_top_c);
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const char* p = str;
	const std::size_t str_over = reinterpret_cast<intptr_t>(p) & 0xf;
	if (str_over != 0)
	{
		//��16�o�C�g�A���C�����g��
		const __m128i str16 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p));
		const int zf = _mm_cmpistrz(pattern_top_c16, str16, flags);//�����̓�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
		const int cf = _mm_cmpistrc(pattern_top_c16, str16, flags);
		if (cf)
		{
			const __m128i mask = _mm_cmpistrm(pattern_top_c16, str16, flags);
			unsigned int found_bits = *reinterpret_cast<const int*>(&mask);
			const char* _p = p;
			while (found_bits)
			{
				if ((found_bits & 1) && *_p == pattern_top_c && *(_p + 1) == pattern_2nd_c)
					return _p;
				found_bits >>= 1;
				++_p;
			}
		}
		if (zf)
			return nullptr;
		p += (16 - str_over);
	}
	//16�o�C�g�A���C�����g��
	const __m128i* p128 = reinterpret_cast<const __m128i*>(p);
	while (true)
	{
		const __m128i str16 = _mm_load_si128(p128);
		const int zf = _mm_cmpistrz(pattern_top_c16, str16, flags);//�����̓�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
		const int cf = _mm_cmpistrc(pattern_top_c16, str16, flags);
		if (cf)
		{
			const __m128i mask = _mm_cmpistrm(pattern_top_c16, str16, flags);
			unsigned int found_bits = *reinterpret_cast<const int*>(&mask);
			const char* _p = reinterpret_cast<const char*>(p128);
			while (found_bits)
			{
				if ((found_bits & 1) && *_p == pattern_top_c && *(_p + 1) == pattern_2nd_c)
					return _p;
				found_bits >>= 1;
				++_p;
			}
		}
		if (zf)
			return nullptr;
		++p128;
	}
	return nullptr;//dummy
}
//SSE��strstr�⏕�֐�:16�o�C�g�A���C�����g�{16�o�C�g�A���C�����g��
//�߂�l: 0 ... �s��v, 1 ... ��v, 2 ... str�̕����Z��
static int _strstr_fast_cmp_case0(const char* str, const char* pattern)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_NEGATIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const __m128i* p1 = reinterpret_cast<const __m128i*>(str);
	const __m128i* p2 = reinterpret_cast<const __m128i*>(pattern);
	while (true)
	{
		const __m128i str16_1 = _mm_load_si128(p1);
		const __m128i str16_2 = _mm_load_si128(p2);
		const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//�����̎O�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
		const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
		const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
		if (cf)
		{
			const char c1 = *(reinterpret_cast<const char*>(p1) + pos);
			const char c2 = *(reinterpret_cast<const char*>(p2) + pos);
			return (c2 == '\0') | ((c1 == '\0') << 1);
		}
		if (zf)
			return 1;
		++p1;
		++p2;
	}
	return 0;//dummy
}
//SSE��strstr�⏕�֐�:��16�o�C�g�A���C�����g�{16�o�C�g�A���C�����g��
//�߂�l: 0 ... �s��v, 1 ... ��v, 2 ... str�̕����Z��
static int _strstr_fast_cmp_case1(const char* str, const char* pattern)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_NEGATIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const char* p1 = str;
	const __m128i* p2 = reinterpret_cast<const __m128i*>(pattern);
	while (true)
	{
		const __m128i str16_1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p1));
		const __m128i str16_2 = _mm_load_si128(p2);
		const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//�����̎O�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
		const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
		const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
		if (cf)
		{
			const char c1 = *(p1 + pos);
			const char c2 = *(reinterpret_cast<const char*>(p2)+pos);
			return (c2 == '\0') | ((c1 == '\0') << 1);
		}
		if (zf)
			return 1;
		p1 += 16;
		++p2;
	}
	return 0;//dummy
}
//SSE��strstr�⏕�֐�:16�o�C�g�A���C�����g�{��16�o�C�g�A���C�����g��
//�߂�l: 0 ... �s��v, 1 ... ��v, 2 ... str�̕����Z��
static int _strstr_fast_cmp_case2(const char* str, const char* pattern)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_NEGATIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const __m128i* p1 = reinterpret_cast<const __m128i*>(str);
	const char* p2 = pattern;
	while (true)
	{
		const __m128i str16_1 = _mm_load_si128(p1);
		const __m128i str16_2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p2));
		const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//�����̎O�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
		const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
		const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
		if (cf)
		{
			const char c1 = *(reinterpret_cast<const char*>(p1)+pos);
			const char c2 = *(p2 + pos);
			return (c2 == '\0') | ((c1 == '\0') << 1);
		}
		if (zf)
			return 1;
		++p1;
		p2 += 16;
	}
	return 0;//dummy
}
//SSE��strstr�⏕�֐�:16�o�C�g�A���C�����g�{��16�o�C�g�A���C�����g��
//�߂�l: 0 ... �s��v, 1 ... ��v, 2 ... str�̕����Z��
static int _strstr_fast_cmp_case3(const char* str, const char* pattern)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_NEGATIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const char* p1 = str;
	const char* p2 = pattern;
	while (true)
	{
		const __m128i str16_1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p1));
		const __m128i str16_2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p2));
		const int cf          = _mm_cmpistrc(str16_1, str16_2, flags);//�����̎O�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
		const int zf          = _mm_cmpistrz(str16_1, str16_2, flags);
		const std::size_t pos = _mm_cmpistri(str16_1, str16_2, flags);
		if (cf)
		{
			const char c1 = *(reinterpret_cast<const char*>(p1)+pos);
			const char c2 = *(reinterpret_cast<const char*>(p2)+pos);
			return (c2 == '\0') | ((c1 == '\0') << 1);
		}
		if (zf)
			return 1;
		p1 += 16;
		p2 += 16;
	}
	return 0;//dummy
}
//SSE��strstr:�⏕�֐��e�[�u��
typedef int(*_strstr_fast_cmp_casex_t)(const char* str, const char* pattern);
static const _strstr_fast_cmp_casex_t _strstr_fast_cmp_casex[] =
{
	_strstr_fast_cmp_case0,
	_strstr_fast_cmp_case1,
	_strstr_fast_cmp_case2,
	_strstr_fast_cmp_case3
};
//SSE��strstr�⏕�֐�
//�߂�l: 0 ... �s��v, 1 ... ��v, 2 ... str�̕����Z��
static inline int _strstr_fast_cmp(const char* str, const char* pattern)
{
	return _strstr_fast_cmp_casex[_str_case(str, pattern)](str, pattern);
}
//SSE��strstr
const char* _strstr_fast(const char* str, const char* pattern)
{
#if 0//strchr_fast()��strncmp_fast()�����p�����P���ȏ����i�x���̂�NG�j
	const std::size_t pattern_len = strlen_fast(pattern);
	const char pattern_c = *pattern;
	const char* p = str;
	while(true)
	{
		const char* found = strchr_fast(p, pattern_c);
		if (!found)
			return nullptr;
		if(strncmp_fast(found, pattern, pattern_len) == 0)
			return found;
		p = found + 1;
	}
	return nullptr;//dummy
#else
//null�`�F�b�N���Ȃ�
//	if (!str)
//		return 0;
	//pattern�̒����Ɋ�Â��āA������U�蕪����
	if (*pattern == '\0')//�p�^�[����0�����̎�
		return str;
	if (*(pattern + 1) == '\0')//�p�^�[����1�����̎�
	{
		if (*str == '\0')
			return nullptr;
		return strchr(str, *pattern);
	}
	if (*(pattern + 2) == '\0')//�p�^�[����2�����̎�
	{
		if (*str == '\0' || *(str + 1) == '\0')
			return nullptr;
		return _strstr_fast_2(str, pattern);
	}
	const char pattern_top_c = *pattern;//�擪�̕���
	const char pattern_2nd_c = *(pattern + 1);//2�����ڂ̕���
	const __m128i pattern_top_c16 = _mm_set1_epi8(pattern_top_c);
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	const char* p = str;
	const std::size_t str_over = reinterpret_cast<intptr_t>(p) & 0xf;
	if (str_over != 0)
	{
		//��16�o�C�g�A���C�����g��
		const __m128i str16 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(p));
		const int zf = _mm_cmpistrz(pattern_top_c16, str16, flags);//�����̓�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
		const int cf = _mm_cmpistrc(pattern_top_c16, str16, flags);
		if (cf)
		{
			const __m128i mask = _mm_cmpistrm(pattern_top_c16, str16, flags);
			unsigned int found_bits = *reinterpret_cast<const int*>(&mask);
			const char* _p = p;
			while (found_bits)
			{
				if (found_bits & 1)
				{
					if (*_p == pattern_top_c && *(_p + 1) == pattern_2nd_c)
					{
						const int cmp = _strstr_fast_cmp(_p, pattern);
						if (cmp != 0)
						{
							if (cmp == 1)
								return _p;
							else
								return nullptr;
						}
					}
				}
				found_bits >>= 1;
				++_p;
			}
		}
		if (zf)
			return nullptr;
		p += (16 - str_over);
	}
	//16�o�C�g�A���C�����g��
	const __m128i* p128 = reinterpret_cast<const __m128i*>(p);
	while (true)
	{
		const __m128i str16 = _mm_load_si128(p128);
		const int zf = _mm_cmpistrz(pattern_top_c16, str16, flags);//�����̓�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
		const int cf = _mm_cmpistrc(pattern_top_c16, str16, flags);
		if (cf)
		{
			const __m128i mask = _mm_cmpistrm(pattern_top_c16, str16, flags);
			unsigned int found_bits = *reinterpret_cast<const int*>(&mask);
			const char* _p = reinterpret_cast<const char*>(p128);
			while (found_bits)
			{
				if (found_bits & 1)
				{
					if (*_p == pattern_top_c && *(_p + 1) == pattern_2nd_c)
					{
						const int cmp = _strstr_fast_cmp(_p, pattern);
						if (cmp != 0)
						{
							if (cmp == 1)
								return _p;
							else
								return nullptr;
						}
					}
				}
				found_bits >>= 1;
				++_p;
			}
		}
		if (zf)
			return nullptr;
		++p128;
	}
	return nullptr;//dummy
#endif
}
//----------
//SSE��strcpy�p�⏕�֐�
#define _MEMCPY_M128I_TYPE 2// 0 ... memcpy() �g�p
                            // 1 ... �R�s�[�T�C�Y�ƃA���C�������g���Ƃ̊֐�
                            // 2 ... �R�s�[�T�C�Y���Ƃ̊֐��i�A���C�������g�����^16�o�C�g�̎������A���C�����g�ŐU�蕪���j
                            // 3 ... _mm_maskmoveu_si128() �g�p
//SSE��strcpy�p�⏕�֐�:_m128i���烁�����ւ̃R�s�[�p�֐�
//�yOK�z�R�s�[�T�C�Y���Ƃ̊֐���p�ӂ�������́Amemcpy()���g��������������
static void _memcpy_m128i_00_a(char* dst, const __m128i src)
{
	//�Ȃɂ����Ȃ�
}
static void _memcpy_m128i_00_u(char* dst, const __m128i src)
{
	//�Ȃɂ����Ȃ�
}
static void _memcpy_m128i_01_a(char* dst, const __m128i src)
{
	*dst = *reinterpret_cast<const char*>(&src);
}
static void _memcpy_m128i_01_u(char* dst, const __m128i src)
{
	*dst = *reinterpret_cast<const char*>(&src);
}
static void _memcpy_m128i_02_a(char* dst, const __m128i src)
{
	*reinterpret_cast<short*>(dst) = *reinterpret_cast<const short*>(&src);
}
static void _memcpy_m128i_02_u(char* dst, const __m128i src)
{
	const char* src_p = reinterpret_cast<const char*>(&src);
	*(dst++) = *(src_p++);
	*dst = *src_p;
}
static void _memcpy_m128i_03_a(char* dst, const __m128i src)
{
	*reinterpret_cast<short*>(dst) = *reinterpret_cast<const short*>(&src);
	*reinterpret_cast<char*>(reinterpret_cast<short*>(dst)+1) = *reinterpret_cast<const char*>(reinterpret_cast<const short*>(&src) + 1);
}
static void _memcpy_m128i_03_u(char* dst, const __m128i src)
{
	const char* src_p = reinterpret_cast<const char*>(&src);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*dst = *src_p;
}
static void _memcpy_m128i_04_a(char* dst, const __m128i src)
{
	*reinterpret_cast<int*>(dst) = *reinterpret_cast<const int*>(&src);
}
static void _memcpy_m128i_04_u(char* dst, const __m128i src)
{
	const char* src_p = reinterpret_cast<const char*>(&src);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*dst = *src_p;
}
static void _memcpy_m128i_05_a(char* dst, const __m128i src)
{
	*reinterpret_cast<int*>(dst) = *reinterpret_cast<const int*>(&src);
	*reinterpret_cast<char*>(reinterpret_cast<int*>(dst)+1) = *reinterpret_cast<const char*>(reinterpret_cast<const int*>(&src) + 1);
}
static void _memcpy_m128i_05_u(char* dst, const __m128i src)
{
	const char* src_p = reinterpret_cast<const char*>(&src);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*dst = *src_p;
}
static void _memcpy_m128i_06_a(char* dst, const __m128i src)
{
	*reinterpret_cast<int*>(dst) = *reinterpret_cast<const int*>(&src);
	*reinterpret_cast<short*>(reinterpret_cast<int*>(dst)+1) = *reinterpret_cast<const short*>(reinterpret_cast<const int*>(&src) + 1);
}
static void _memcpy_m128i_06_u(char* dst, const __m128i src)
{
	const char* src_p = reinterpret_cast<const char*>(&src);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*dst = *src_p;
}
static void _memcpy_m128i_07_a(char* dst, const __m128i src)
{
	*reinterpret_cast<int*>(dst) = *reinterpret_cast<const int*>(&src);
	*reinterpret_cast<short*>(reinterpret_cast<int*>(dst)+1) = *reinterpret_cast<const short*>(reinterpret_cast<const int*>(&src) + 1);
	*reinterpret_cast<char*>(reinterpret_cast<short*>(reinterpret_cast<int*>(dst)+1) + 1) = *reinterpret_cast<const char*>(reinterpret_cast<const short*>(reinterpret_cast<const int*>(&src) + 1) + 1);
}
static void _memcpy_m128i_07_u(char* dst, const __m128i src)
{
	const char* src_p = reinterpret_cast<const char*>(&src);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*dst = *src_p;
}
static void _memcpy_m128i_08_a(char* dst, const __m128i src)
{
	*reinterpret_cast<long long*>(dst) = *reinterpret_cast<const long long*>(&src);
}
static void _memcpy_m128i_08_u(char* dst, const __m128i src)
{
	const char* src_p = reinterpret_cast<const char*>(&src);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*dst = *src_p;
}
static void _memcpy_m128i_09_a(char* dst, const __m128i src)
{
	*reinterpret_cast<long long*>(dst) = *reinterpret_cast<const long long*>(&src);
	*reinterpret_cast<char*>(reinterpret_cast<long long*>(dst)+1) = *reinterpret_cast<const char*>(reinterpret_cast<const long long*>(&src) + 1);
}
static void _memcpy_m128i_09_u(char* dst, const __m128i src)
{
	const char* src_p = reinterpret_cast<const char*>(&src);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*dst = *src_p;
}
static void _memcpy_m128i_10_a(char* dst, const __m128i src)
{
	*reinterpret_cast<long long*>(dst) = *reinterpret_cast<const long long*>(&src);
	*reinterpret_cast<short*>(reinterpret_cast<long long*>(dst)+1) = *reinterpret_cast<const short*>(reinterpret_cast<const long long*>(&src) + 1);
}
static void _memcpy_m128i_10_u(char* dst, const __m128i src)
{
	const char* src_p = reinterpret_cast<const char*>(&src);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*dst = *src_p;
}
static void _memcpy_m128i_11_a(char* dst, const __m128i src)
{
	*reinterpret_cast<long long*>(dst) = *reinterpret_cast<const long long*>(&src);
	*reinterpret_cast<short*>(reinterpret_cast<long long*>(dst)+1) = *reinterpret_cast<const short*>(reinterpret_cast<const long long*>(&src) + 1);
	*reinterpret_cast<char*>(reinterpret_cast<short*>(reinterpret_cast<long long*>(dst)+1) + 1) = *reinterpret_cast<const char*>(reinterpret_cast<const short*>(reinterpret_cast<const long long*>(&src) + 1) + 1);
}
static void _memcpy_m128i_11_u(char* dst, const __m128i src)
{
	const char* src_p = reinterpret_cast<const char*>(&src);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*dst = *src_p;
}
static void _memcpy_m128i_12_a(char* dst, const __m128i src)
{
	*reinterpret_cast<long long*>(dst) = *reinterpret_cast<const long long*>(&src);
	*reinterpret_cast<int*>(reinterpret_cast<long long*>(dst)+1) = *reinterpret_cast<const int*>(reinterpret_cast<const long long*>(&src) + 1);
}
static void _memcpy_m128i_12_u(char* dst, const __m128i src)
{
	const char* src_p = reinterpret_cast<const char*>(&src);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*dst = *src_p;
}
static void _memcpy_m128i_13_a(char* dst, const __m128i src)
{
	*reinterpret_cast<long long*>(dst) = *reinterpret_cast<const long long*>(&src);
	*reinterpret_cast<int*>(reinterpret_cast<long long*>(dst)+1) = *reinterpret_cast<const int*>(reinterpret_cast<const long long*>(&src) + 1);
	*reinterpret_cast<char*>(reinterpret_cast<int*>(reinterpret_cast<long long*>(dst)+1) + 1) = *reinterpret_cast<const char*>(reinterpret_cast<const int*>(reinterpret_cast<const long long*>(&src) + 1) + 1);
}
static void _memcpy_m128i_13_u(char* dst, const __m128i src)
{
	const char* src_p = reinterpret_cast<const char*>(&src);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*dst = *src_p;
}
static void _memcpy_m128i_14_a(char* dst, const __m128i src)
{
	*reinterpret_cast<long long*>(dst) = *reinterpret_cast<const long long*>(&src);
	*reinterpret_cast<int*>(reinterpret_cast<long long*>(dst)+1) = *reinterpret_cast<const int*>(reinterpret_cast<const long long*>(&src) + 1);
	*reinterpret_cast<short*>(reinterpret_cast<int*>(reinterpret_cast<long long*>(dst)+1) + 1) = *reinterpret_cast<const short*>(reinterpret_cast<const int*>(reinterpret_cast<const long long*>(&src) + 1) + 1);
}
static void _memcpy_m128i_14_u(char* dst, const __m128i src)
{
	const char* src_p = reinterpret_cast<const char*>(&src);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*dst = *src_p;
}
static void _memcpy_m128i_15_a(char* dst, const __m128i src)
{
	*reinterpret_cast<long long*>(dst) = *reinterpret_cast<const long long*>(&src);
	*reinterpret_cast<int*>(reinterpret_cast<long long*>(dst)+1) = *reinterpret_cast<const int*>(reinterpret_cast<const long long*>(&src) + 1);
	*reinterpret_cast<short*>(reinterpret_cast<int*>(reinterpret_cast<long long*>(dst)+1) + 1) = *reinterpret_cast<const short*>(reinterpret_cast<const int*>(reinterpret_cast<const long long*>(&src) + 1) + 1);
	*reinterpret_cast<char*>(reinterpret_cast<short*>(reinterpret_cast<int*>(reinterpret_cast<long long*>(dst)+1) + 1) + 1) = *reinterpret_cast<const char*>(reinterpret_cast<const short*>(reinterpret_cast<const int*>(reinterpret_cast<const long long*>(&src) + 1) + 1) + 1);
}
static void _memcpy_m128i_15_u(char* dst, const __m128i src)
{
	const char* src_p = reinterpret_cast<const char*>(&src);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*(dst++) = *(src_p++);
	*dst = *src_p;
}
static void _memcpy_m128i_16_a(char* dst, const __m128i src)
{
	_mm_store_si128(reinterpret_cast<__m128i*>(dst), src);
}
static void _memcpy_m128i_16_u(char* dst, const __m128i src)
{
	_mm_storeu_si128(reinterpret_cast<__m128i*>(dst), src);
}
//SSE��strcpy�p�⏕�֐�:_m128i���烁�����ւ̃R�s�[�p�֐��e�[�u��
typedef void(*_memcpy_m128i_x_t)(char* dst, const __m128i src);
static const _memcpy_m128i_x_t _memcpy_m128i_a_x[17] =
{
	_memcpy_m128i_00_a,
	_memcpy_m128i_01_a,
	_memcpy_m128i_02_a,
	_memcpy_m128i_03_a,
	_memcpy_m128i_04_a,
	_memcpy_m128i_05_a,
	_memcpy_m128i_06_a,
	_memcpy_m128i_07_a,
	_memcpy_m128i_08_a,
	_memcpy_m128i_09_a,
	_memcpy_m128i_10_a,
	_memcpy_m128i_11_a,
	_memcpy_m128i_12_a,
	_memcpy_m128i_13_a,
	_memcpy_m128i_14_a,
	_memcpy_m128i_15_a,
	_memcpy_m128i_16_a,
};
#if _MEMCPY_M128I_TYPE == 1
static const _memcpy_m128i_x_t _memcpy_m128i_u_x[17] =
{
	_memcpy_m128i_00_u,
	_memcpy_m128i_01_u,
	_memcpy_m128i_02_u,
	_memcpy_m128i_03_u,
	_memcpy_m128i_04_u,
	_memcpy_m128i_05_u,
	_memcpy_m128i_06_u,
	_memcpy_m128i_07_u,
	_memcpy_m128i_08_u,
	_memcpy_m128i_09_u,
	_memcpy_m128i_10_u,
	_memcpy_m128i_11_u,
	_memcpy_m128i_12_u,
	_memcpy_m128i_13_u,
	_memcpy_m128i_14_u,
	_memcpy_m128i_15_u,
	_memcpy_m128i_16_u,
};
#elif _MEMCPY_M128I_TYPE == 2
static const _memcpy_m128i_x_t _memcpy_m128i_u_x[17] =
{
	_memcpy_m128i_00_a,
	_memcpy_m128i_01_a,
	_memcpy_m128i_02_a,
	_memcpy_m128i_03_a,
	_memcpy_m128i_04_a,
	_memcpy_m128i_05_a,
	_memcpy_m128i_06_a,
	_memcpy_m128i_07_a,
	_memcpy_m128i_08_a,
	_memcpy_m128i_09_a,
	_memcpy_m128i_10_a,
	_memcpy_m128i_11_a,
	_memcpy_m128i_12_a,
	_memcpy_m128i_13_a,
	_memcpy_m128i_14_a,
	_memcpy_m128i_15_a,
	_memcpy_m128i_16_u,
};
#elif _MEMCPY_M128I_TYPE == 3
//SSE��strcpy�p�⏕�֐�:_m128i���烁�����ւ̃R�s�[�p�萔�F_mm_maskmoveu_si128()�p
//�yNG�z_mm_maskmoveu_si128()���g�p���������́Amemcpy()���g�������x������
static const __m128i _memcpy_m128i_flags[17] =
{
	_mm_set_epi8(0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u),
	_mm_set_epi8(0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x80u),
	_mm_set_epi8(0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x80u, 0x80u),
	_mm_set_epi8(0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x80u, 0x80u, 0x80u),
	_mm_set_epi8(0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x80u, 0x80u, 0x80u, 0x80u),
	_mm_set_epi8(0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u),
	_mm_set_epi8(0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u),
	_mm_set_epi8(0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u),
	_mm_set_epi8(0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u),
	_mm_set_epi8(0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u),
	_mm_set_epi8(0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u),
	_mm_set_epi8(0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u),
	_mm_set_epi8(0x00u, 0x00u, 0x00u, 0x00u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u),
	_mm_set_epi8(0x00u, 0x00u, 0x00u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u),
	_mm_set_epi8(0x00u, 0x00u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u),
	_mm_set_epi8(0x00u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u),
	_mm_set_epi8(0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u, 0x80u),
};
#endif
//SSE��strcpy�p�⏕�֐�:_m128i���烁�����ւ̃R�s�[�p�֐�
static inline void _memcpy_m128i_a(__m128i* dst, const __m128i src, const std::size_t len)
{
#if _MEMCPY_M128I_TYPE == 1//������
	_memcpy_m128i_a_x[len](reinterpret_cast<char*>(dst), src);
#elif _MEMCPY_M128I_TYPE == 2//���ő�
	_memcpy_m128i_a_x[len](reinterpret_cast<char*>(dst), src);
#elif _MEMCPY_M128I_TYPE == 3//�����Ȃ�x��
	_mm_maskmoveu_si128(src, _memcpy_m128i_flags[len], reinterpret_cast<const char*>(dst));
#else//_MEMCPY_M128I_TYPE == 0//�����Ƒ���
	memcpy(reinterpret_cast<const char*>(dst), reinterpret_cast<const char*>(&src), len);
#endif
}
static inline void _memcpy_m128i_u(char* dst, const __m128i src, const std::size_t len)
{
#if _MEMCPY_M128I_TYPE == 1//������
	_memcpy_m128i_u_x[len](dst, src);
#elif _MEMCPY_M128I_TYPE == 2//���ő�
	_memcpy_m128i_u_x[len](dst, src);
#elif _MEMCPY_M128I_TYPE == 4//�����Ȃ�x��
	_mm_maskmoveu_si128(src, _memcpy_m128i_flags[len], dst);
#else//_MEMCPY_M128I_TYPE == 0//�����Ƒ���
	memcpy(dst, reinterpret_cast<const char*>(&src), len);
#endif
}
//SSE��strcpy:16�o�C�g�A���C�����g�{16�o�C�g�A���C�����g��
static const char* _strcpy_fast_case0(char* dst, const char* src)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	static const __m128i null = _mm_setzero_si128();
	__m128i* dst_p = reinterpret_cast<__m128i*>(dst);
	const __m128i* src_p = reinterpret_cast<const __m128i*>(src);
	while (true)
	{
		const __m128i str16 = _mm_load_si128(src_p);
		const int zf          = _mm_cmpistrz(null, str16, flags);//�����̓�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
		const std::size_t pos = _mm_cmpistri(null, str16, flags);
		if (zf)
		{
			_memcpy_m128i_a(dst_p, str16, pos + 1);
			return dst;
		}
		_mm_store_si128(dst_p, str16);
		++dst_p;
		++src_p;
	}
	return nullptr;//dummy
}
//SSE��strcpy:��16�o�C�g�A���C�����g�{16�o�C�g�A���C�����g��
static const char* _strcpy_fast_case1(char* dst, const char* src)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	static const __m128i null = _mm_setzero_si128();
	char* dst_p = dst;
	const __m128i* src_p = reinterpret_cast<const __m128i*>(src);
	while (true)
	{
		const __m128i str16 = _mm_load_si128(src_p);
		const int zf          = _mm_cmpistrz(null, str16, flags);//�����̓�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
		const std::size_t pos = _mm_cmpistri(null, str16, flags);
		if (zf)
		{
			_memcpy_m128i_u(dst_p, str16, pos + 1);
			return dst;
		}
		_mm_storeu_si128(reinterpret_cast<__m128i*>(dst_p), str16);
		dst_p += 16;
		++src_p;
	}
	return nullptr;//dummy
}
//SSE��strcpy:16�o�C�g�A���C�����g�{��16�o�C�g�A���C�����g��
static const char* _strcpy_fast_case2(char* dst, const char* src)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	static const __m128i null = _mm_setzero_si128();
	__m128i* dst_p = reinterpret_cast<__m128i*>(dst);
	const char* src_p = src;
	while (true)
	{
		const __m128i str16 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src_p));
		const int zf          = _mm_cmpistrz(null, str16, flags);//�����̓�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
		const std::size_t pos = _mm_cmpistri(null, str16, flags);
		if (zf)
		{
			_memcpy_m128i_a(dst_p, str16, pos + 1);
			return dst;
		}
		_mm_store_si128(dst_p, str16);
		++dst_p;
		src_p += 16;
	}
	return nullptr;//dummy
}
//SSE��strcpy:16�o�C�g�A���C�����g�{��16�o�C�g�A���C�����g��
static const char* _strcpy_fast_case3(char* dst, const char* src)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	static const __m128i null = _mm_setzero_si128();
	char* dst_p = dst;
	const char* src_p = src;
	while (true)
	{
		const __m128i str16 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src_p));
		const int zf          = _mm_cmpistrz(null, str16, flags);//�����̓�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
		const std::size_t pos = _mm_cmpistri(null, str16, flags);
		if (zf)
		{
			_memcpy_m128i_u(dst_p, str16, pos + 1);
			return dst;
		}
		_mm_storeu_si128(reinterpret_cast<__m128i*>(dst_p), str16);
		dst_p += 16;
		src_p += 16;
	}
	return nullptr;//dummy
}
//SSE��strcpy:�֐��e�[�u��
typedef const char* (*_strcpy_fast_casex_t)(char* dst, const char* src);
static const _strcpy_fast_casex_t _strcpy_fast_casex[] =
{
	_strcpy_fast_case0,
	_strcpy_fast_case1,
	_strcpy_fast_case2,
	_strcpy_fast_case3
};
//SSE��strcpy
const char* _strcpy_fast(char* dst, const char* src)
{
#if 0//strlen_fast�����p���ĒP�������������i�x���̂�NG�j
	//�������Amemcpy��sse�̃X�g�A���������ł���Ȃ炱�̕��������i��������Ȃ��j
	memcpy(dst, src, strlen_fast(src));
	return dst;
#else
//null�`�F�b�N���Ȃ�
//	if (!dst || !src)
//		return nullptr;
	return _strcpy_fast_casex[_str_case(dst, src)](dst, src);
#endif
}
//----------
//SSE��strncpy�p�⏕�֐�
//���O��F���̏����́Amax_len > len �̎��ɂ����Ăяo����Ȃ����̂Ƃ���B
//�@�@�@�@max_len >= len �̎��́A_memcpy_m128i() ���g�p����B
#ifdef STRNCPY_PADDING_ZERO
static inline void _memncpy_m128i_a(__m128i* dst, const __m128i src, const std::size_t len, const std::size_t max_len)
{
	_memcpy_m128i_a(dst, src, len);
	memset(reinterpret_cast<char*>(dst) + len, '\0', max_len - len);
}
static inline void _memncpy_m128i_u(char* dst, const __m128i src, const std::size_t len, const std::size_t max_len)
{
	_memcpy_m128i_u(dst, src, len);
	memset(dst + len, '\0', max_len - len);
}
#else//STRNCPY_PADDING_ZERO
static inline void _memncpy_m128i_a(__m128i* dst, const __m128i src, const std::size_t len)
{
	_memcpy_m128i_a(dst, src, len);
	*(reinterpret_cast<char*>(dst) + len) = '\0';
}
static inline void _memncpy_m128i_u(char* dst, const __m128i src, const std::size_t len)
{
	_memcpy_m128i_u(dst, src, len);
	dst[len] = '\0';
}
#endif//STRNCPY_PADDING_ZERO
//SSE��strncpy:16�o�C�g�A���C�����g�{16�o�C�g�A���C�����g��
static const char* _strncpy_fast_case0(char* dst, const char* src, const std::size_t max_len)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	static const __m128i null = _mm_setzero_si128();
	__m128i* dst_p = reinterpret_cast<__m128i*>(dst);
	const __m128i* src_p = reinterpret_cast<const __m128i*>(src);
	const char* src_end = src + max_len;
	const char* src_end_16 = src_end - 16;
	while (reinterpret_cast<const char*>(src_p) <= src_end_16)
	{
		const __m128i str16 = _mm_load_si128(src_p);
		const int zf          = _mm_cmpistrz(null, str16, flags);//�����̓�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
		const std::size_t pos = _mm_cmpistri(null, str16, flags);
		if (zf)
		{
		#ifdef STRNCPY_PADDING_ZERO
			const std::size_t remain = src_end - reinterpret_cast<const char*>(src_p);
			_memncpy_m128i_a(dst_p, str16, pos, remain);
		#else//STRNCPY_PADDING_ZERO
			_memncpy_m128i_a(dst_p, str16, pos);
		#endif//STRNCPY_PADDING_ZERO
			return dst;
		}
		_mm_store_si128(dst_p, str16);
		++dst_p;
		++src_p;
	}
	{
		const std::size_t remain = src_end - reinterpret_cast<const char*>(src_p);
		if (remain > 0)
		{
			const __m128i str16 = _mm_load_si128(src_p);
			_memcpy_m128i_a(dst_p, str16, remain);
		}
	}
	return dst;
}
//SSE��strncpy:��16�o�C�g�A���C�����g�{16�o�C�g�A���C�����g��
static const char* _strncpy_fast_case1(char* dst, const char* src, const std::size_t max_len)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	static const __m128i null = _mm_setzero_si128();
	char* dst_p = dst;
	const __m128i* src_p = reinterpret_cast<const __m128i*>(src);
	const char* src_end = src + max_len;
	const char* src_end_16 = src_end - 16;
	while (reinterpret_cast<const char*>(src_p) <= src_end_16)
	{
		const __m128i str16 = _mm_load_si128(src_p);
		const int zf          = _mm_cmpistrz(null, str16, flags);//�����̓�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
		const std::size_t pos = _mm_cmpistri(null, str16, flags);
		if (zf)
		{
		#ifdef STRNCPY_PADDING_ZERO
			const std::size_t remain = src_end - reinterpret_cast<const char*>(src_p);
			_memncpy_m128i_u(dst_p, str16, pos, remain);
		#else//STRNCPY_PADDING_ZERO
			_memncpy_m128i_u(dst_p, str16, pos);
		#endif//STRNCPY_PADDING_ZERO
			return dst;
		}
		_mm_storeu_si128(reinterpret_cast<__m128i*>(dst_p), str16);
		dst_p += 16;
		++src_p;
	}
	{
		const std::size_t remain = src_end - reinterpret_cast<const char*>(src_p);
		if (remain > 0)
		{
			const __m128i str16 = _mm_load_si128(src_p);
			_memcpy_m128i_u(dst_p, str16, remain);
		}
	}
	return dst;
}
//SSE��strncpy:16�o�C�g�A���C�����g�{��16�o�C�g�A���C�����g��
static const char* _strncpy_fast_case2(char* dst, const char* src, const std::size_t max_len)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	static const __m128i null = _mm_setzero_si128();
	__m128i* dst_p = reinterpret_cast<__m128i*>(dst);
	const char* src_p = src;
	const char* src_end = src + max_len;
	const char* src_end_16 = src_end - 16;
	while (src_p <= src_end_16)
	{
		const __m128i str16 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src_p));
		const int zf          = _mm_cmpistrz(null, str16, flags);//�����̓�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
		const std::size_t pos = _mm_cmpistri(null, str16, flags);
		if (zf)
		{
		#ifdef STRNCPY_PADDING_ZERO
			const std::size_t remain = src_end - src_p;
			_memncpy_m128i_a(dst_p, str16, pos, remain);
		#else//STRNCPY_PADDING_ZERO
			_memncpy_m128i_a(dst_p, str16, pos);
		#endif//STRNCPY_PADDING_ZERO
			return dst;
		}
		_mm_store_si128(dst_p, str16);
		++dst_p;
		src_p += 16;
	}
	{
		const std::size_t remain = src_end - src_p;
		if (remain > 0)
		{
			const __m128i str16 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src_p));
			_memcpy_m128i_a(dst_p, str16, remain);
		}
	}
	return dst;
}
//SSE��strncpy:��16�o�C�g�A���C�����g�{��16�o�C�g�A���C�����g��
static const char* _strncpy_fast_case3(char* dst, const char* src, const std::size_t max_len)
{
	static const int flags = _SIDD_SBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_POSITIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
	static const __m128i null = _mm_setzero_si128();
	char* dst_p = dst;
	const char* src_p = src;
	const char* src_end = src + max_len;
	const char* src_end_16 = src_end - 16;
	while (src_p <= src_end_16)
	{
		const __m128i str16 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src_p));
		const int zf          = _mm_cmpistrz(null, str16, flags);//�����̓�s�́A�R���p�C�����1��� cmpistri �ɂȂ�i�͂��j
		const std::size_t pos = _mm_cmpistri(null, str16, flags);
		if (zf)
		{
		#ifdef STRNCPY_PADDING_ZERO
			const std::size_t remain = src_end - src_p;
			_memncpy_m128i_u(dst_p, str16, pos, remain);
		#else//STRNCPY_PADDING_ZERO
			_memncpy_m128i_u(dst_p, str16, pos);
		#endif//STRNCPY_PADDING_ZERO
			return dst;
		}
		_mm_storeu_si128(reinterpret_cast<__m128i*>(dst_p), str16);
		dst_p += 16;
		src_p += 16;
	}
	{
		const std::size_t remain = src_end - src_p;
		if (remain > 0)
		{
			const __m128i str16 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(src_p));
			_memcpy_m128i_u(dst_p, str16, remain);
		}
	}
	return dst;
}
//SSE��strncpy:�֐��e�[�u��
typedef const char* (*_strncpy_fast_casex_t)(char* dst, const char* src, const std::size_t max_len);
static const _strncpy_fast_casex_t _strncpy_fast_casex[] =
{
	_strncpy_fast_case0,
	_strncpy_fast_case1,
	_strncpy_fast_case2,
	_strncpy_fast_case3
};
//SSE��strncpy
const char* _strncpy_fast(char* dst, const char* src, const std::size_t max_len)
{
#if 0//strlen_fast�����p���ĒP�������������i�x���̂�NG�j
	//�������Amemcpy��sse�̃X�g�A���������ł���Ȃ炱�̕��������i��������Ȃ��j
	const std::size_t len = strlen_fast(src);
	if (len >= max_len)
	{
		memcpy(dst, src, max_len);
		return dst;
	}
	else
	{
		memcpy(dst, src, len);
		//memset(dst + len, '\0', max_len - len);//strncpy�{���̎d�l
		dst[len] = '\0';//����ł��\��
		return dst;
	}
	return nullptr;//dummy
#else
//null�`�F�b�N���Ȃ�
//	if (!dst || !src)
//		return nullptr;
	return _strncpy_fast_casex[_str_case(dst, src)](dst, src, max_len);
#endif
}
//�e�X�g
void testOpt07_Type2_After_1time()
{
#if 1
	{
		#define LEN(s) printf("len(\"%s\")=%d(%d)\n", s, strlen_fast(s), strlen(s));
		LEN("");
		LEN("a");
		LEN("ab");
		LEN("abc");
		LEN("abcd");
		LEN("abcde");
		LEN("a\0b");
		LEN("\0a");
		LEN("1234567890abcde");
		LEN("1234567890abcdef");
		LEN("1234567890abcdefg");
		LEN("12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");
		#undef LEN
	}
#endif
#if 1
	{
		#define CMP(s1, s2) printf("cmp(\"%s\", \"%s\")=%d(%d)\n", s1, s2, strcmp_fast(s1, s2), strcmp(s1, s2));
		CMP("a", "a");
		CMP("a", "b");
		CMP("b", "a");
		CMP("aba", "aaa");
		CMP("aaa", "aba");
		CMP("abc", "acb");
		CMP("acb", "abc");
		CMP("1234567890abcdef", "1234567890abcdef");
		CMP("1234567890abcdef", "1234567890abcdefg");
		CMP("1234567890abcdefg", "1234567890abcdef");
		CMP("1234567890abcde", "1234567890abcdef");
		CMP("1234567890abcdef", "1234567890abcde");
		CMP("1234567890abcdef1234567890abcdef", "1234567890abcdef1234567890abcdef");
		CMP("1234567890abcdef1234567890abcde0", "1234567890abcdef1234567890abcdef");
		CMP("1234567890abcdef1234567890abcdef", "1234567890abcdef1234567890abcde0");
		CMP("1234567890abcdef1234567890abcdef", "1234567890abcdef1234567890abcde");
		CMP("1234567890abcdef1234567890abcdef", "1234567890abcdef1234567890abcdef1");
		CMP("1234567890abcdef1234567890abcde", "1234567890abcdef1234567890abcdef");
		CMP("1234567890abcdef1234567890abcdef1", "1234567890abcdef1234567890abcdef");
		CMP("1234567890abcdef1234567890abcdef1", "1234567890abcdef1234567890abcdef1");
		CMP("1234567890abcdef1234567890abcdef0", "1234567890abcdef1234567890abcdef1");
		CMP("1234567890abcdef1234567890abcdef1", "1234567890abcdef1234567890abcdef0");
		CMP("\0a", "\0b");
		#undef CMP
	}
#endif
#if 1
	{
		#define NCMP(s1, s2, n) printf("ncmp(\"%s\", \"%s\", %d)=%d(%d)\n", s1, s2, n, strncmp_fast(s1, s2, n), strncmp(s1, s2, n));
		NCMP("a", "a", 16);
		NCMP("a", "b", 16);
		NCMP("b", "a", 16);
		NCMP("aaa", "aaa", 16);
		NCMP("aab", "aaa", 16);
		NCMP("aaa", "aab", 16);
		NCMP("aba", "aaa", 16);
		NCMP("aaa", "aba", 16);
		NCMP("abc", "acb", 16);
		NCMP("acb", "abc", 16);
		NCMP("a", "a", 2);
		NCMP("a", "b", 2);
		NCMP("b", "a", 2);
		NCMP("aaa", "aaa", 2);
		NCMP("aab", "aaa", 2);
		NCMP("aaa", "aab", 2);
		NCMP("aba", "aaa", 2);
		NCMP("aaa", "aba", 2);
		NCMP("abc", "acb", 2);
		NCMP("acb", "abc", 2);
		NCMP("1234567890abcdef", "1234567890abcdef", 16);
		NCMP("1234567890abcdef", "1234567890abcdefg", 16);
		NCMP("1234567890abcdefg", "1234567890abcdef", 16);
		NCMP("1234567890abcde", "1234567890abcdef", 16);
		NCMP("1234567890abcdef", "1234567890abcde", 16);
		NCMP("\0a", "\0b", 16);
		NCMP("1234567890abcdef", "1234567890abcdef", 15);
		NCMP("1234567890abcdef", "1234567890abcdefg", 15);
		NCMP("1234567890abcdefg", "1234567890abcdef", 15);
		NCMP("1234567890abcde", "1234567890abcdef", 15);
		NCMP("1234567890abcdef", "1234567890abcde", 15);
		NCMP("\0a", "\0b", 15);
		NCMP("1234567890abcdef1234567890abcdef1", "1234567890abcdef1234567890abcdef1", 33);
		NCMP("1234567890abcdef1234567890abcdef12", "1234567890abcdef1234567890abcdef1", 33);
		NCMP("1234567890abcdef1234567890abcdef1", "1234567890abcdef1234567890abcdef12", 33);
		NCMP("1234567890abcdef1234567890abcdef1", "1234567890abcdef1234567890abcdef", 33);
		NCMP("1234567890abcdef1234567890abcdef", "1234567890abcdef1234567890abcdef1", 33);
		NCMP("1234567890abcdef1234567890abcdef1", "1234567890abcdef1234567890abcdef2", 33);
		NCMP("1234567890abcdef1234567890abcdef2", "1234567890abcdef1234567890abcdef1", 33);
		NCMP("1034567890abcdef1234567890abcdef1", "0234567890abcdef1234567890abcdef1", 33);
		NCMP("0234567890abcdef1234567890abcdef1", "1034567890abcdef1234567890abcdef1", 33);
		NCMP("1234567890abcdef1034567890abcdef1", "1234567890abcdef0234567890abcdef1", 33);
		NCMP("1234567890abcdef0234567890abcdef1", "1234567890abcdef1034567890abcdef1", 33);
		#undef NCMP
	}
#endif
#if 1
	{
		#define CHR(s, c) printf("chr(\"%s\", \'%c\')=\"%s\"(\"%s\")\n", s, c, strchr_fast(s, c), strchr(s, c));
		CHR("1", '1');
		CHR("12", '1');
		CHR("123", '1');
		CHR("1234", '1');
		CHR("12341", '1');
		CHR("123412", '1');
		CHR("123132", '1');
		CHR("123132", '2');
		CHR("123132", '3');
		CHR("123132", '4');
		CHR("123x\0x123", 'x');
		CHR("1234567890abcdef1234567890abcdef", '0');
		CHR("1234567890abcdef", 'f');
		CHR("1234567890abcdef", 'x');
		CHR("1234567890abcdefx", 'f');
		CHR("1234567890abcdefx", 'x');
		CHR("1234567890abcdefx", 'z');
		CHR("1234567890abcdefxy", 'x');
		CHR("1234567890abcdefxy", 'z');
		#undef CHR
	}
#endif
#if 1
	{
		#define CHRR(s, c) printf("rchr(\"%s\", \'%c\')=\"%s\"(\"%s\")\n", s, c, strrchr_fast(s, c), strrchr(s, c));
		CHRR("1", '1');
		CHRR("12", '1');
		CHRR("123", '1');
		CHRR("1234", '1');
		CHRR("12341", '1');
		CHRR("123412", '1');
		CHRR("123132", '1');
		CHRR("123132", '2');
		CHRR("123132", '3');
		CHRR("123132", '4');
		CHRR("123x\0x123", 'x');
		CHRR("1234567890abcdef1234567890abcdef", '0');
		CHRR("1234567890abcdef", 'f');
		CHRR("1234567890abcdef", 'x');
		CHRR("1234567890abcdefx", 'f');
		CHRR("1234567890abcdefx", 'x');
		CHRR("1234567890abcdefx", 'z');
		CHRR("1234567890abcdefxy", 'x');
		CHRR("1234567890abcdefxy", 'z');
		#undef CHRR
	}
#endif
#if 1
	{
		#define STR(s1, s2) printf("str(\"%s\", \"%s\")=\"%s\"(\"%s\")\n", s1, s2, strstr_fast(s1, s2), strstr(s1, s2));
		STR("1", "23");
		STR("12", "23");
		STR("123", "23");
		STR("1234", "23");
		STR("12341", "23");
		STR("123412", "23");
		STR("1234123", "23");
		STR("12341234", "x23");
		STR("12312312313132132123x23123132", "x23");
		STR("12341234", "4");
		STR("12341234", "");
		STR("12312312313132132123x123123132", "x");
		STR("12312312313132132123x123123132", "");
		STR("12312312313132132123x123123132", "123x123");
		STR("1234567890abcdef1234567890abcdefx234567890abcdef", "x234567890abcdef");
		STR("1234567890abcdef1234567890abcdefx234567890abcdef", "x234567890abcdefg");
		STR("1234567890abcdef1234567890abcdefx234567890abcdefg", "x234567890abcdefg");
		STR("1234567890abcdef1234567890abcdefx234567890abcdefgh", "x234567890abcdefg");
		STR("1234567890abcdef1234567890abcdefx234567890abcdefg", "x234567890abcdefx");
		STR("1234567890abcdef1234567890abcdefx234567890abcdefx", "x234567890abcdefx");
		STR("1234567890abcdef1234567890abcdefx234567890abcdefxy", "x234567890abcdefx");
		STR("1234567890abcde!!234567890abcdef", "!!");
		STR("!1234567890!abcdef!!1234567890!abcdef!", "!!");
		STR("1234567890abcdef", "1234567890abcdef");
		STR("1234567890abcdefgh", "1234567890abcdefg");
		STR("1234567890abcdef1234567890abcdefgh", "1234567890abcdefg");
		STR("10234567890abcdefgh1234567890abcdefgh", "1234567890abcdefg");
		STR("aaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzzabcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz");
		STR("abcdefghijklmnopqrstuvwxyzaaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzzabcdefghijklmnopqrstuvwxyz", "bbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmmooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyyzzzzabc");
#undef STR
	}
#endif
#if 1
	{
		char alignas(16) buff[20];
		char dummy_for_align = 123;
		char buffu[20];
		const __m128i str16 = _mm_setr_epi8('0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f');
		printf("(dummy_for_align=%d)\n", dummy_for_align);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16,  0); printf("_memcpy_m128i_a(buff, str16,  0)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16,  1); printf("_memcpy_m128i_a(buff, str16,  1)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16,  2); printf("_memcpy_m128i_a(buff, str16,  2)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16,  3); printf("_memcpy_m128i_a(buff, str16,  3)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16,  4); printf("_memcpy_m128i_a(buff, str16,  4)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16,  5); printf("_memcpy_m128i_a(buff, str16,  5)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16,  6); printf("_memcpy_m128i_a(buff, str16,  6)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16,  7); printf("_memcpy_m128i_a(buff, str16,  7)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16,  8); printf("_memcpy_m128i_a(buff, str16,  8)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16,  9); printf("_memcpy_m128i_a(buff, str16,  9)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16, 10); printf("_memcpy_m128i_a(buff, str16, 10)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16, 11); printf("_memcpy_m128i_a(buff, str16, 11)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16, 12); printf("_memcpy_m128i_a(buff, str16, 12)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16, 13); printf("_memcpy_m128i_a(buff, str16, 13)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16, 14); printf("_memcpy_m128i_a(buff, str16, 14)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16, 15); printf("_memcpy_m128i_a(buff, str16, 15)=\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_a(reinterpret_cast<__m128i*>(buff), str16, 16); printf("_memcpy_m128i_a(buff, str16, 16)=\"%s\"\n", buff);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16,  0); printf("_memcpy_m128i_u(buffu, str16,  0)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16,  1); printf("_memcpy_m128i_u(buffu, str16,  1)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16,  2); printf("_memcpy_m128i_u(buffu, str16,  2)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16,  3); printf("_memcpy_m128i_u(buffu, str16,  3)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16,  4); printf("_memcpy_m128i_u(buffu, str16,  4)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16,  5); printf("_memcpy_m128i_u(buffu, str16,  5)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16,  6); printf("_memcpy_m128i_u(buffu, str16,  6)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16,  7); printf("_memcpy_m128i_u(buffu, str16,  7)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16,  8); printf("_memcpy_m128i_u(buffu, str16,  8)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16,  9); printf("_memcpy_m128i_u(buffu, str16,  9)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16, 10); printf("_memcpy_m128i_u(buffu, str16, 10)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16, 11); printf("_memcpy_m128i_u(buffu, str16, 11)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16, 12); printf("_memcpy_m128i_u(buffu, str16, 12)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16, 13); printf("_memcpy_m128i_u(buffu, str16, 13)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16, 14); printf("_memcpy_m128i_u(buffu, str16, 14)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16, 15); printf("_memcpy_m128i_u(buffu, str16, 15)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_u(buffu, str16, 16); printf("_memcpy_m128i_u(buffu, str16, 16)=\"%s\"\n", buffu);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_00_a(buff, str16); printf("_memcpy_m128i_00_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_01_a(buff, str16); printf("_memcpy_m128i_01_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_02_a(buff, str16); printf("_memcpy_m128i_02_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_03_a(buff, str16); printf("_memcpy_m128i_03_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_04_a(buff, str16); printf("_memcpy_m128i_04_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_05_a(buff, str16); printf("_memcpy_m128i_05_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_06_a(buff, str16); printf("_memcpy_m128i_06_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_07_a(buff, str16); printf("_memcpy_m128i_07_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_08_a(buff, str16); printf("_memcpy_m128i_08_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_09_a(buff, str16); printf("_memcpy_m128i_09_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_10_a(buff, str16); printf("_memcpy_m128i_10_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_11_a(buff, str16); printf("_memcpy_m128i_11_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_12_a(buff, str16); printf("_memcpy_m128i_12_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_13_a(buff, str16); printf("_memcpy_m128i_13_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_14_a(buff, str16); printf("_memcpy_m128i_14_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_15_a(buff, str16); printf("_memcpy_m128i_15_a(buff, str16) =\"%s\"\n", buff);
		memset(buff, 0, sizeof(buff)); _memcpy_m128i_16_a(buff, str16); printf("_memcpy_m128i_16_a(buff, str16) =\"%s\"\n", buff);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_00_u(buffu, str16); printf("_memcpy_m128i_00_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_01_u(buffu, str16); printf("_memcpy_m128i_01_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_02_u(buffu, str16); printf("_memcpy_m128i_02_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_03_u(buffu, str16); printf("_memcpy_m128i_03_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_04_u(buffu, str16); printf("_memcpy_m128i_04_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_05_u(buffu, str16); printf("_memcpy_m128i_05_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_06_u(buffu, str16); printf("_memcpy_m128i_06_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_07_u(buffu, str16); printf("_memcpy_m128i_07_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_08_u(buffu, str16); printf("_memcpy_m128i_08_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_09_u(buffu, str16); printf("_memcpy_m128i_09_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_10_u(buffu, str16); printf("_memcpy_m128i_10_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_11_u(buffu, str16); printf("_memcpy_m128i_11_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_12_u(buffu, str16); printf("_memcpy_m128i_12_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_13_u(buffu, str16); printf("_memcpy_m128i_13_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_14_u(buffu, str16); printf("_memcpy_m128i_14_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_15_u(buffu, str16); printf("_memcpy_m128i_15_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_16_u(buffu, str16); printf("_memcpy_m128i_16_u(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_00_a(buffu, str16); printf("_memcpy_m128i_00_a(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_01_a(buffu, str16); printf("_memcpy_m128i_01_a(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_02_a(buffu, str16); printf("_memcpy_m128i_02_a(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_03_a(buffu, str16); printf("_memcpy_m128i_03_a(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_04_a(buffu, str16); printf("_memcpy_m128i_04_a(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_05_a(buffu, str16); printf("_memcpy_m128i_05_a(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_06_a(buffu, str16); printf("_memcpy_m128i_06_a(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_07_a(buffu, str16); printf("_memcpy_m128i_07_a(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_08_a(buffu, str16); printf("_memcpy_m128i_08_a(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_09_a(buffu, str16); printf("_memcpy_m128i_09_a(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_10_a(buffu, str16); printf("_memcpy_m128i_10_a(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_11_a(buffu, str16); printf("_memcpy_m128i_11_a(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_12_a(buffu, str16); printf("_memcpy_m128i_12_a(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_13_a(buffu, str16); printf("_memcpy_m128i_13_a(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_14_a(buffu, str16); printf("_memcpy_m128i_14_a(buffu, str16)=\"%s\"\n", buffu);
		memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_15_a(buffu, str16); printf("_memcpy_m128i_15_a(buffu, str16)=\"%s\"\n", buffu);
		//memset(buffu, 0, sizeof(buffu)); _memcpy_m128i_16_a(buffu, str16); printf("_memcpy_m128i_16_a(buffu, str16)=\"%s\"\n", buffu);//���G���[
	}
#endif
#if 1
	{
		char alignas(16) buff1[32] = { 0 };
		char dummy_for_align = 123;
		char buff2[32] = { 0 };
		#define CPY(d, s) printf("cpy(%p, \"%s\")=\"%s\"\n", d, s, strcpy_fast(d, s));
		printf("(dummy_for_align=%d)\n", dummy_for_align);
		CPY(buff1, "");
		CPY(buff1, "a");
		CPY(buff1, "ab");
		CPY(buff1, "abc");
		CPY(buff1, "abcd");
		CPY(buff1, "abcde");
		CPY(buff1, "a\0b");
		CPY(buff1, "\0a");
		CPY(buff1, "1234567890abcde");
		CPY(buff1, "1234567890abcdef");
		CPY(buff1, "1234567890abcdefg");
		CPY(buff1, "1234567890abcdef1234567890abcde");
		CPY(buff2, "1234567890abcde");
		CPY(buff2, "1234567890abcdef");
		CPY(buff2, "1234567890abcdefg");
		CPY(buff2, "1234567890abcdef1234567890abcde");
		#undef CPY
	}
#endif
#if 1
	{
		char alignas(16) buff1[34] = { 0 };
		char dummy_for_align = 123;
		char buff2[34] = { 0 };
		#define NCPY(d, s, n) printf("ncpy(%p, \"%s\", %d)=\"%s\"\n", d, s, n, strncpy_fast(d, s, n));
		printf("(dummy_for_align=%d)\n", dummy_for_align);
		NCPY(buff1, "", 16);
		NCPY(buff1, "a", 16);
		NCPY(buff1, "ab", 16);
		NCPY(buff1, "abc", 16);
		NCPY(buff1, "abcd", 16);
		NCPY(buff1, "abcde", 16);
		NCPY(buff1, "a\0b", 16);
		NCPY(buff1, "\0a", 16);
		NCPY(buff1, "", 2);
		NCPY(buff1, "z", 2);
		NCPY(buff1, "zy", 2);
		NCPY(buff1, "zyx", 2);
		NCPY(buff1, "zyxw", 2);
		NCPY(buff1, "zyxwv", 2);
		NCPY(buff1, "A\0B", 2);
		NCPY(buff1, "\0C", 2);
		NCPY(buff1, "1234567890abcde", 16);
		NCPY(buff1, "1234567890abcdef", 16);
		NCPY(buff1, "1234567890abcdefg", 16);
		NCPY(buff1, "1234567890abcdef1234567890abcde", 16);
		NCPY(buff2, "1234567890abcde", 16);
		NCPY(buff2, "1234567890abcdef", 16);
		NCPY(buff2, "1234567890abcdefg", 16);
		NCPY(buff2, "1234567890abcdef1234567890abcde", 16);
		NCPY(buff1, "1234567890abcdef1234567890abcdef", 33);
		NCPY(buff1, "1234567890abcdef1234567890abcdef1", 33);
		NCPY(buff1, "1234567890abcdef1234567890abcdef12", 33);
		NCPY(buff1, "abc", 1);
		NCPY(buff2, "1234567890abcdef1234567890abcdef", 33);
		NCPY(buff2, "1234567890abcdef1234567890abcdef1", 33);
		NCPY(buff2, "1234567890abcdef1234567890abcdef12", 33);
		NCPY(buff2, "abc", 1);
		#undef NCPY
	}
#endif
}
std::size_t testOpt07_Type2_strlen_After(const int dummy, const char* str)
{
	return strlen_fast(str);
}
int testOpt07_Type2_strcmp_After(const int dummy, const char* str1, const char* str2)
{
	return strcmp_fast(str1, str2);
}
int testOpt07_Type2_strncmp_After(const int dummy, const char* str1, const char* str2, const std::size_t max_len)
{
	return strncmp_fast(str1, str2, max_len);
}
const char* testOpt07_Type2_strchr_After(const int dummy, const char* str, const char c)
{
	return strchr_fast(str, c);
}
const char* testOpt07_Type2_strrchr_After(const int dummy, const char* str, const char c)
{
	return strrchr_fast(str, c);
}
const char* testOpt07_Type2_strstr_After(const int dummy, const char* str1, const char* str2)
{
	return strstr_fast(str1, str2);
}
const char* testOpt07_Type2_strcpy_After(const int dummy, char* dst, const char* src)
{
	return strcpy_fast(dst, src);
}
const char* testOpt07_Type2_strncpy_After(const int dummy, char* dst, const char* src, const std::size_t max_len)
{
	return strncpy_fast(dst, src, max_len);
}

//----------------------------------------
//�ǉ��e�X�g�F���_���_���̃L���v�`���[�e�X�g�i�N���[�W���Ƃ��Ăǂ��܂Ŏg���邩�H�j
#include <stdio.h>//printf�p
#include <functional>//C++11 std::function�p
std::function<int()> s_lambda1 = nullptr;
std::function<int()> s_lambda2 = nullptr;
std::function<int()> s_lambda3 = nullptr;
void callLambda123()
{
	printf("lambda1()=%d, lambda2()=%d, lambda3()=%d\n", s_lambda1(), s_lambda2(), s_lambda3());
}
void callLambda13()
{
	printf("lambda1()=%d, lambda2()=NG!, lambda3()=%d\n", s_lambda1(), s_lambda3());
}
void setLambda(int& external_counter)
//external_counter ... �O���ϐ��i��ʂ̃��[�J���ϐ��̉\������j�Flambda1�ŃL���v�`���^�N���[�W���̃��L�V�J���ϐ�
{
	if (!s_lambda1 || !s_lambda2)
	{
		int local_counter = 0;//���[�J���ϐ��Flambda2�ŃL���v�`���^�N���[�W���̃��L�V�J���ϐ�
		static int static_counter = 0;//���[�J���ÓI�ϐ��Flambda3�Ŏg�p�i�L���v�`���s�v�j�^�N���[�W���̃��L�V�J���ϐ��ƌĂ�ō����x���Ȃ��H
		printf("for lambda1: external_counter=%d\n", external_counter);
		printf("for lambda2: local_counter=%d\n", local_counter);
		printf("for lambda3: static_counter=%d\n", static_counter);
		s_lambda1 = [&external_counter]() -> int { return ++external_counter; };
		s_lambda2 = [&local_counter]() -> int { return ++local_counter; };
		s_lambda3 = []() -> int { return ++static_counter; };
		printf("Call lambda in block with counter in setLambda().\n");
		callLambda123();
		callLambda123();
		callLambda123();
	}
	{
		int dummy = 999;
		printf("dummy=%d\n", dummy);
		printf("Call lambda in block without counter in setLambda().\n");
		callLambda123();
		callLambda123();
		callLambda123();
	}
}
auto getLambda1() -> decltype(s_lambda1)
{
	return s_lambda1;
}
auto getLambda2() -> decltype(s_lambda2)
{
	return s_lambda1;
}

// End of file
