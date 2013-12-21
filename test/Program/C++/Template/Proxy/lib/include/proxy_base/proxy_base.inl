#pragma once
#ifndef __PROXY_BASE_INL__
#define __PROXY_BASE_INL__

#include "proxy_base.h"

template <class T>
CProxyPrint::vtable CProxyPrint::vtable_initializer<T>::m_vtable =
{
	&CProxyPrint::vtable_initializer<T>::proxyPrintName,
	&CProxyPrint::vtable_initializer<T>::proxyPrintMessage
};

template <class T>
void CProxyPrint::vtable_initializer<T>::proxyPrintName(void* me)
{
	reinterpret_cast<T*>(me)->cbPrintName();
}

template <class T>
void CProxyPrint::vtable_initializer<T>::proxyPrintMessage(void* me, const int par1, const char* par2)
{
	reinterpret_cast<T*>(me)->cbPrintMessage(par1, par2);
}

template <class T>
CProxyUpdate::vtable CProxyUpdate::vtable_initializer<T>::m_vtable =
{
	&CProxyUpdate::vtable_initializer<T>::proxyUpdate,
	&CProxyUpdate::vtable_initializer<T>::proxyAnimation
};

template <class T>
void CProxyUpdate::vtable_initializer<T>::proxyUpdate(void* me, const float elapsed_time)
{
	reinterpret_cast<T*>(me)->cbUpdate(elapsed_time);
}

template <class T>
void CProxyUpdate::vtable_initializer<T>::proxyAnimation(void* me)
{
	reinterpret_cast<T*>(me)->cbAnimation();
}

template <class T>
CProxyDraw::vtable CProxyDraw::vtable_initializer<T>::m_vtable =
{
	&CProxyDraw::vtable_initializer<T>::proxyPreDraw,
	&CProxyDraw::vtable_initializer<T>::proxyPostDraw
};

template <class T>
void CProxyDraw::vtable_initializer<T>::proxyPreDraw(void* me, const int index, void* data)
{
	reinterpret_cast<T*>(me)->cbPreDraw(index, data);
}

template <class T>
void CProxyDraw::vtable_initializer<T>::proxyPostDraw(void* me, const int index, void* data)
{
	reinterpret_cast<T*>(me)->cbPostDraw(index, data);
}

#endif//__PROXY_BASE_INL__

// End of file
