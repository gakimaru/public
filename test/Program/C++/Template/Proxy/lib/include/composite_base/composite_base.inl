#pragma once
#ifndef __COMPOSITE_INL__
#define __COMPOSITE_INL__

#include "composite_base.h"

//�e���v���[�g�R���X�g���N�^�̖����I�ȃC���X�^���X�������܂������Ȃ������̂ŁA.h �t�@�C���ɒ��ڏ���
/*
template<class T>
CComponent::CComponent(const bool is_composition, T* me) :
m_isComposition(is_composition),
m_This(me),
m_next(nullptr)
{
}

template<class T>
CLeaf::CLeaf(T* me) :
CComponent(false, me)
{
}

template<class T>
CComposite::CComposite(T* me) :
CComponent(true, me),
m_childTop(nullptr)
{
}
*/

#endif//__COMPOSITE_INL__

// End of file
