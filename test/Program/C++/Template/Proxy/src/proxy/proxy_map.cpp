#include "proxies/proxy_map.h"

#include <iostream>

void CProxyPrintMap::cbPrintName() const
{
	std::cout << "CProxyPrintMap::printName() Name=\"" << this->m_this->m_MapName << "\"" << std::endl;
}

void CProxyPrintMap::cbPrintMessage(const int par1, const char* par2) const
{
	std::cout << "CProxyPrintMap::printMessage(par1=" << par1 << ", par2=\"" << par2 << "\")" << std::endl;
}

CProxyPrintMap::~CProxyPrintMap()
{
	std::cout << "CProxyPrintMap::~CProxyPrintMap()" << std::endl;
	this->dispose();
}

void CProxyPrintMap::cbDispose()
{
	std::cout << "CProxyPrintMap::cbDispose()" << std::endl;
	this->CProxyPrintCommon<CProxyPrintMap>::cbDispose();
}

void CProxyUpdateMap::cbUpdate(const float elapsed_time) const
{
	std::cout << "CProxyUpdateMap::ppdate(elapsed_time=" << elapsed_time << ")" << std::endl;
}

void CProxyUpdateMap::cbAnimation() const
{
	std::cout << "CProxyUpdateMap::animation()" << std::endl;
}

CProxyUpdateMap::~CProxyUpdateMap()
{
	std::cout << "CProxyUpdateMap::~CProxyUpdateMap()" << std::endl;
	this->dispose();
}

void CProxyUpdateMap::cbDispose()
{
	std::cout << "CProxyUpdateMap::cbDispose()" << std::endl;
	this->CProxyUpdateCommon<CProxyUpdateMap>::cbDispose();
}

void CProxyDrawMap::cbPreDraw(const int index, void* data) const
{
	std::cout << "CProxyUpdateMap::preDraw(index=" << index << ", data=" << data << ")" << std::endl;
}

void CProxyDrawMap::cbPostDraw(const int index, void* data) const
{
	std::cout << "CProxyUpdateMap::postDraw(index=" << index << ", data=" << data << ")" << std::endl;
}

CProxyDrawMap::~CProxyDrawMap()
{
	std::cout << "CProxyDrawMap::~CProxyDrawMap()" << std::endl;
	this->dispose();
}

void CProxyDrawMap::cbDispose()
{
	std::cout << "CProxyDrawMap::cbDispose()" << std::endl;
	this->CProxyDrawCommon<CProxyDrawMap>::cbDispose();
}

CCompositeMap::~CCompositeMap()
{
	std::cout << "CCompositeMap::~CCompositeMap()" << std::endl;
	this->dispose();
}

void CCompositeMap::cbDispose()
{
	std::cout << "CCompositeMap::cbDispose()" << std::endl;
	this->CCompositeProcess::cbDispose();
}

//明示的なインスタンス化
#include "proxy_base/proxy_base.inl"
template class CProxyPrint::vtable_initializer<CProxyPrintMap>;
template class CProxyUpdate::vtable_initializer<CProxyUpdateMap>;
template class CProxyDraw::vtable_initializer<CProxyDrawMap>;
template class CProxyPrintCommon<CProxyPrintMap>;
template class CProxyUpdateCommon<CProxyUpdateMap>;
template class CProxyDrawCommon<CProxyDrawMap>;

//明示的なインスタンス化
#include "composite_base/composite_base.inl"
template class CComponent::vtable_initializer<CCompositeMap>;

// End of file
