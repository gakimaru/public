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

void CProxyUpdateMap::cbUpdate(const float elapsed_time) const
{
	std::cout << "CProxyUpdateMap::ppdate(elapsed_time=" << elapsed_time << ")" << std::endl;
}

void CProxyUpdateMap::cbAnimation() const
{
	std::cout << "CProxyUpdateMap::animation()" << std::endl;
}

void CProxyDrawMap::cbPreDraw(const int index, void* data) const
{
	std::cout << "CProxyUpdateMap::preDraw(index=" << index << ", data=" << data << ")" << std::endl;
}

void CProxyDrawMap::cbPostDraw(const int index, void* data) const
{
	std::cout << "CProxyUpdateMap::postDraw(index=" << index << ", data=" << data << ")" << std::endl;
}

//明示的なインスタンス化
#include "proxy_base/proxy_base.inl"
template class CProxyPrint::vtable_initializer<CProxyPrintMap>;
template class CProxyUpdate::vtable_initializer<CProxyUpdateMap>;
template class CProxyDraw::vtable_initializer<CProxyDrawMap>;

// End of file
