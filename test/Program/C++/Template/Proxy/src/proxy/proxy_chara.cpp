#include "proxies/proxy_chara.h"

#include <iostream>

void CProxyPrintChara::cbPrintName() const
{
	std::cout << "CProxyPrintChara::printName() Name=\"" << this->m_this->m_CharaName << "\"" << std::endl;
}

void CProxyPrintChara::cbPrintMessage(const int par1, const char* par2) const
{
	std::cout << "CProxyPrintChara::printMessage(par1=" << par1 << ", par2=\"" << par2 << "\")" << std::endl;
}

void CProxyUpdateChara::cbUpdate(const float elapsed_time) const
{
	std::cout << "CProxyUpdateChara::ppdate(elapsed_time=" << elapsed_time << ")" << std::endl;
}

void CProxyUpdateChara::cbAnimation() const
{
	std::cout << "CProxyUpdateChara::animation()" << std::endl;
}

void CProxyDrawChara::cbPreDraw(const int index, void* data) const
{
	std::cout << "CProxyUpdateChara::preDraw(index=" << index << ", data=" << data << ")" << std::endl;
}

void CProxyDrawChara::cbPostDraw(const int index, void* data) const
{
	std::cout << "CProxyUpdateChara::postDraw(index=" << index << ", data=" << data << ")" << std::endl;
}

//明示的なインスタンス化
#include "proxy_base/proxy_base.inl"
template class CProxyPrint::vtable_initializer<CProxyPrintChara>;
template class CProxyUpdate::vtable_initializer<CProxyUpdateChara>;
template class CProxyDraw::vtable_initializer<CProxyDrawChara>;

// End of file
