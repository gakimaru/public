#pragma once
#ifndef __COMPOSITE_INL__
#define __COMPOSITE_INL__

#include "composite_base.h"

//テンプレートコンストラクタの明示的なインスタンス化がうまくいかなかったので、.h ファイルに直接書く
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
