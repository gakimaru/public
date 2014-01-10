#pragma once
#ifndef __PROXY_BASE_INL__
#define __PROXY_BASE_INL__

#include "proxy_base.h"

template <class T>
CProxyPrint::vtable CProxyPrint::vtable_initializer<T>::m_vtable =
{
	&CProxyPrint::vtable_initializer<T>::proxyPrintName,
	&CProxyPrint::vtable_initializer<T>::proxyPrintMessage,
	&CProxyPrint::vtable_initializer<T>::proxyDispose
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
void CProxyPrint::vtable_initializer<T>::proxyDispose(void* me)
{
//	reinterpret_cast<T*>(me)->~T();
	reinterpret_cast<T*>(me)->cbDispose();
}

template<class derived>
CProxyPrintCommon<derived>::~CProxyPrintCommon()
{
	std::cout << "CProxyPrintCommon<derived>::~CProxyPrintCommon()" << std::endl;
	this->dispose();
}

template<class derived>
void CProxyPrintCommon<derived>::cbDispose()
{
	std::cout << "CProxyPrintCommon<derived>::cbDispose()" << std::endl;
	this->CProxyPrint::cbDispose();
}

template <class T>
CProxyUpdate::vtable CProxyUpdate::vtable_initializer<T>::m_vtable =
{
	&CProxyUpdate::vtable_initializer<T>::proxyUpdate,
	&CProxyUpdate::vtable_initializer<T>::proxyAnimation,
	&CProxyUpdate::vtable_initializer<T>::proxyDispose
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
void CProxyUpdate::vtable_initializer<T>::proxyDispose(void* me)
{
//	reinterpret_cast<T*>(me)->~T();
	reinterpret_cast<T*>(me)->cbDispose();
}

template<class derived>
CProxyUpdateCommon<derived>::~CProxyUpdateCommon()
{
	std::cout << "CProxyUpdateCommon<derived>::~CProxyUpdateCommon()" << std::endl;
	this->dispose();
}

template<class derived>
void CProxyUpdateCommon<derived>::cbDispose()
{
	std::cout << "CProxyUpdateCommon<derived>::cbDispose()" << std::endl;
	this->CProxyUpdate::cbDispose();
}

template <class T>
CProxyDraw::vtable CProxyDraw::vtable_initializer<T>::m_vtable =
{
	&CProxyDraw::vtable_initializer<T>::proxyPreDraw,
	&CProxyDraw::vtable_initializer<T>::proxyPostDraw,
	&CProxyDraw::vtable_initializer<T>::proxyDispose
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

template<class derived>
CProxyDrawCommon<derived>::~CProxyDrawCommon()
{
	std::cout << "CProxyDrawCommon<derived>::~CProxyDrawCommon()" << std::endl;
	this->dispose();
}

template<class derived>
void CProxyDrawCommon<derived>::cbDispose()
{
	std::cout << "CProxyDrawCommon<derived>::cbDispose()" << std::endl;
	this->CProxyDraw::cbDispose();
}

template <class T>
void CProxyDraw::vtable_initializer<T>::proxyDispose(void* me)
{
//	reinterpret_cast<T*>(me)->~T();
	reinterpret_cast<T*>(me)->cbDispose();
}

#endif//__PROXY_BASE_INL__

// End of file
