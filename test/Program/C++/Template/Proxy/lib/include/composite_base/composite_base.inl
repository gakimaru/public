#pragma once
#ifndef __COMPOSITE_INL__
#define __COMPOSITE_INL__

#include "composite_base.h"

template <class T>
CComponent::vtable CComponent::vtable_initializer<T>::m_vtable =
{
	&CComponent::vtable_initializer<T>::proxyDestructor
};

template <class T>
void CComponent::vtable_initializer<T>::proxyDestructor(void* me)
{
	reinterpret_cast<T*>(me)->destructor();
}

#endif//__COMPOSITE_INL__

// End of file
