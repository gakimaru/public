#pragma once
#ifndef __SUB_H_
#define __SUB_H_

#define _VALUE_RANGE (10 + 1)//�l�̕��@�����z�W�v���̃��[�v�����ɉe������
//#define _VALUE_RANGE (1000 + 1)//�l�̕��@���i����j

//#define _ELEMENT_SIZE 100//�z��v�f���@���W�v���̃��[�v�����ɉe������
#define _ELEMENT_SIZE 10000//�z��v�f���@���i����j

#include <cstddef>//std::szie_t�p

//----------------------------------------
//�œK���@�F�������A�N�Z�X�̗}���F�ꎞ�ϐ��̊��p

//�e�X�g�p�\����
struct dataOpt01_t
{
	struct elem_t
	{
		static const std::size_t VALUE_RANGE = _VALUE_RANGE;
		int value;
	};
	
	int sum;
	elem_t elems[_ELEMENT_SIZE];
};

//������
void initOpt01(dataOpt01_t& data);
//�y�^�C�v�P�z�œK���O
void testOpt01_Type1_Before(dataOpt01_t& data);
//�y�^�C�v�P�z�œK����P
void testOpt01_Type1_After1(dataOpt01_t& data);
//�y�^�C�v�P�z�œK����Q
void testOpt01_Type1_After2(dataOpt01_t& data);
//�y�^�C�v�P�z�y�Q�l�zC++11�ł����Ƃ��Ȍ��ȋL�q
void testOpt01_Type1_Appendix(dataOpt01_t& data);

//----------------------------------------
//�œK���A�F�������A�N�Z�X�̗}���F�A�h���X�v�Z�̍팸

//�e�X�g�p�\����
struct dataOpt02_t
{
	struct elem_t
	{
		static const std::size_t VALUE_RANGE = _VALUE_RANGE;
		int value;
	};
	elem_t elems[_ELEMENT_SIZE];
};

//������
void initOpt02(dataOpt02_t& data);
//�y�^�C�v�P�z�œK���O
int testOpt02_Type1_Before(dataOpt02_t& data);
//�y�^�C�v�P�z�œK����P
int testOpt02_Type1_After1(dataOpt02_t& data);
//�y�^�C�v�P�z�œK����Q
int testOpt02_Type1_After2(dataOpt02_t& data);

//----------------------------------------
//�œK���B�F�������A�N�Z�X�̗}���F�֐��Ăяo���̍팸

//�e�X�g�p�\����
struct dataOpt03_t
{
	static const std::size_t VALUE_RANGE = _VALUE_RANGE;
	int values[_ELEMENT_SIZE];
};

//�y�^�C�v�P�z�œK���O
int testOpt03_Type1_Before(int a, int b, int c);
//�y�^�C�v�P�z�œK����
inline int testOpt03_Type1_After(int a, int b, int c)
{
	return a * b + c;
}

//�y�^�C�v�Q�z�œK���O
int testOpt03_Type2_Before(int a, int b, int c, int d, int e, int f, int g, int h);
//�y�^�C�v�Q�z�œK����
inline int testOpt03_Type2_After(int a, int b, int c, int d, int e, int f, int g, int h)
{
	return a * b + c - d * e + f - g * h;
}

//�y�^�C�v�R�z������
void initOpt03_Type3(dataOpt03_t& data);
//�y�^�C�v�R�z�œK���O
int testOpt03_Type3_Before(dataOpt03_t& data);
//�y�^�C�v�R�z�œK����
int testOpt03_Type3_After(dataOpt03_t& data);

//----------------------------------------
//�œK���C�F���Z�̗}���F��Z�ɕύX

//�e�X�g�p�\����
struct dataOpt04_t
{
	struct elem_t
	{
		static const std::size_t VALUE_RANGE = _VALUE_RANGE;
		int value;
		float ratio;
	};
	elem_t elems[_ELEMENT_SIZE];
};

//������
void initOpt04(dataOpt04_t& data);

//�y�^�C�v�P�z�œK���O
void testOpt04_Type1_Before(dataOpt04_t& data);
//�y�^�C�v�P�z�œK����P
void testOpt04_Type1_After1(dataOpt04_t& data);
//�y�^�C�v�P�z�œK����Q
void testOpt04_Type1_After2(dataOpt04_t& data);

//----------------------------------------
//���ʊ֐�

//�z����擾
template<typename T> inline std::size_t rankof(const T& data){ return 0; }
template<typename T> inline std::size_t esizeof(const T& data){ return sizeof(T); }
template<typename T> inline std::size_t extentof(const T& data){ return 0; }
template<typename T> inline std::size_t extent1of(const T& data){ return 0; }
template<typename T> inline std::size_t extent2of(const T& data){ return 0; }
template<typename T> inline std::size_t extent3of(const T& data){ return 0; }
template<typename T> inline std::size_t extent4of(const T& data){ return 0; }

template<typename T, std::size_t N1> inline std::size_t rankof(const T(&data)[N1]){ return 1; }
template<typename T, std::size_t N1> inline std::size_t esizeof(const T(&data)[N1]){ return sizeof(T); }
template<typename T, std::size_t N1> inline std::size_t extentof(const T(&data)[N1]){ return N1; }
template<typename T, std::size_t N1> inline std::size_t extent1of(const T(&data)[N1]){ return N1; }
template<typename T, std::size_t N1> inline std::size_t extent2of(const T(&data)[N1]){ return 0; }
template<typename T, std::size_t N1> inline std::size_t extent3of(const T(&data)[N1]){ return 0; }
template<typename T, std::size_t N1> inline std::size_t extent4of(const T(&data)[N1]){ return 0; }

template<typename T, std::size_t N1, std::size_t N2> inline std::size_t rankof(const T(&data)[N1][N2]){ return 2; }
template<typename T, std::size_t N1, std::size_t N2> inline std::size_t esizeof(const T(&data)[N1][N2]){ return sizeof(T); }
template<typename T, std::size_t N1, std::size_t N2> inline std::size_t extentof(const T(&data)[N1][N2]){ return N1 * N2; }
template<typename T, std::size_t N1, std::size_t N2> inline std::size_t extent1of(const T(&data)[N1][N2]){ return N1; }
template<typename T, std::size_t N1, std::size_t N2> inline std::size_t extent2of(const T(&data)[N1][N2]){ return N2; }
template<typename T, std::size_t N1, std::size_t N2> inline std::size_t extent3of(const T(&data)[N1][N2]){ return 0; }
template<typename T, std::size_t N1, std::size_t N2> inline std::size_t extent4of(const T(&data)[N1][N2]){ return 0; }

template<typename T, std::size_t N1, std::size_t N2, std::size_t N3> inline std::size_t rankof(const T(&data)[N1][N2][N3]){ return 3; }
template<typename T, std::size_t N1, std::size_t N2, std::size_t N3> inline std::size_t esizeof(const T(&data)[N1][N2][N3]){ return sizeof(T); }
template<typename T, std::size_t N1, std::size_t N2, std::size_t N3> inline std::size_t extentof(const T(&data)[N1][N2][N3]){ return N1 * N2 * N3; }
template<typename T, std::size_t N1, std::size_t N2, std::size_t N3> inline std::size_t extent1of(const T(&data)[N1][N2][N3]){ return N1; }
template<typename T, std::size_t N1, std::size_t N2, std::size_t N3> inline std::size_t extent2of(const T(&data)[N1][N2][N3]){ return N2; }
template<typename T, std::size_t N1, std::size_t N2, std::size_t N3> inline std::size_t extent3of(const T(&data)[N1][N2][N3]){ return N3; }
template<typename T, std::size_t N1, std::size_t N2, std::size_t N3> inline std::size_t extent4of(const T(&data)[N1][N2][N3]){ return 0; }

template<typename T, std::size_t N1, std::size_t N2, std::size_t N3, std::size_t N4> inline std::size_t rankof(const T(&data)[N1][N2][N3][N4]){ return 4; }
template<typename T, std::size_t N1, std::size_t N2, std::size_t N3, std::size_t N4> inline std::size_t esizeof(const T(&data)[N1][N2][N3][N4]){ return sizeof(T); }
template<typename T, std::size_t N1, std::size_t N2, std::size_t N3, std::size_t N4> inline std::size_t extentof(const T(&data)[N1][N2][N3][N4]){ return N1 * N2 * N3 * N4; }
template<typename T, std::size_t N1, std::size_t N2, std::size_t N3, std::size_t N4> inline std::size_t extent1of(const T(&data)[N1][N2][N3][N4]){ return N1; }
template<typename T, std::size_t N1, std::size_t N2, std::size_t N3, std::size_t N4> inline std::size_t extent2of(const T(&data)[N1][N2][N3][N4]){ return N2; }
template<typename T, std::size_t N1, std::size_t N2, std::size_t N3, std::size_t N4> inline std::size_t extent3of(const T(&data)[N1][N2][N3][N4]){ return N3; }
template<typename T, std::size_t N1, std::size_t N2, std::size_t N3, std::size_t N4> inline std::size_t extent4of(const T(&data)[N1][N2][N3][N4]){ return N4; }

#endif//__SUB_H_

// End of file
