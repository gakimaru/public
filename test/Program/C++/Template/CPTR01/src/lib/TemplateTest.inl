//�e���v���[�g�֐��^�e���v���[�g�N���X�̎���
//�y���z���̃t�@�C���́A�e���v���[�g�������̃\�[�X�R�[�h�����A���ڃR���p�C������Ȃ��̂ŁA�K�v�ɉ����ăC���N���[�h���Ďg�p����B
//�@�@�@���̃t�@�C���́A�e���v���[�g���̉���p�̃\�[�X�R�[�h����̂݃C���N���[�h���Ďg�p���邱�ƁB

#pragma once
#ifndef __TEMPLATE_TEST_INL__
#define __TEMPLATE_TEST_INL__

#include <iostream>

#include "TemplateTest.h"

template<typename T>T min(const T l, const T r){ return l <= r ? l : r; }//���F���̒��x�̓��e�Ȃ�w�b�_�[��ɃR�[�h�𒼐ڋL�q����ׂ������A����̓e�X�g�̈�
template<typename T>T max(const T l, const T r){ return l >= r ? l : r; }//�i����j

template<class T>
template_class<T>::template_class(const T par):
	var(par)
{
	std::cout << "template_class::constructor()" << std::endl;
}

template<class T>
template_class<T>::~template_class()
{
	std::cout << "template_class::destructor()" << std::endl;
}

template<class T>
void template_class<T>::test() const
{
	std::cout << "template_class<T>::test var" << this->var << ", sizeof(var)=" << sizeof(this->var) << std::endl;
}
template<class T>
int template_class<T>::test1(const int num) const
{
	std::cout << "template_class<T>::test1 var=" << this->var << ", num=" << num << std::endl;
	return 0;
}
template<class T>
int template_class<T>::test2(const int num) const
{
	std::cout << "template_class<T>::test2 var=" << this->var << ", num=" << num << std::endl;
	return 0;
}

template<class T>
void base3<T>::base_foo() const
{
	static_cast<const T&>(*this).foo();
}

#endif//__TEMPLATE_TEST_INL__

// End of file
