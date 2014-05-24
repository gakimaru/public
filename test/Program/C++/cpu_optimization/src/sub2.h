#pragma once
#ifndef __SUB2_H_
#define __SUB2_H_

//#include "sub.h"
#include <cstddef>

//�y�^�C�v�R�z�œK���O�F���ʊ֐�
//���I�u�U�[�o�[�i�R�[���o�b�N�j���֐��|�C���^�^�Ŏ󂯎��
void commonProc_testOpt03_Type3_Before(int* values, std::size_t n, const int find, void(*observer)(int&));

//�y�^�C�v�R�z�œK����F���ʊ֐�
//���I�u�U�[�o�[�i�R�[���o�b�N�j���e���v���[�g�Ō^�W�J���Ď󂯎��istd::sort �ȂǂƓ��������j
template < typename T, std::size_t N, class OBSERVER>
void commonProc_testOpt03_Type3_After(T(&values)[N], const T find, OBSERVER observer)
{
	//�z�񂩂�l���������A��������I�u�U�[�o�[���Ăяo��
	for (int i = 0; i < N; ++i)
	{
		T& value = values[i];
		if (value == find)
			observer(value);
	}
}

//�y�^�C�v�R�z�y�Q�l�z���ʊ֐�
//���I�u�U�[�o�[�i�R�[���o�b�N�j�� std::function �^�Ŏ󂯎��
#include <functional>//C++11 std::function�p
template <typename T, std::size_t N>
void commonProc_testOpt03_Type3_Appendix(T(&values)[N], const T find, std::function<void(int&)> observer)//��std::function<void(T&)> �Ƃ���ƃR���p�C�����ʂ�Ȃ��iVC++2013�j
{
	//�z�񂩂�l���������A��������I�u�U�[�o�[���Ăяo��
	for (int i = 0; i < N; ++i)
	{
		T& value = values[i];
		if (value == find)
			observer(value);
	}
}

#endif//__SUB_H_

// End of file
