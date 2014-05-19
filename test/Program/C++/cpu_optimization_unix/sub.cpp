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
