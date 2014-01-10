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

CProxyPrintChara::~CProxyPrintChara()
{
	std::cout << "CProxyPrintChara::~CProxyPrintChara()" << std::endl;
	this->dispose();
}

void CProxyPrintChara::cbDispose()
{
	std::cout << "CProxyPrintChara::cbDispose()" << std::endl;
	this->CProxyPrintCommon<CProxyPrintChara>::cbDispose();
}

void CProxyUpdateChara::cbUpdate(const float elapsed_time) const
{
	std::cout << "CProxyUpdateChara::ppdate(elapsed_time=" << elapsed_time << ")" << std::endl;
}

void CProxyUpdateChara::cbAnimation() const
{
	std::cout << "CProxyUpdateChara::animation()" << std::endl;
}

CProxyUpdateChara::~CProxyUpdateChara()
{
	std::cout << "CProxyUpdateChara::~CProxyUpdateChara()" << std::endl;
	this->dispose();
}

void CProxyUpdateChara::cbDispose()
{
	std::cout << "CProxyUpdateChara::cbDispose()" << std::endl;
	this->CProxyUpdateCommon<CProxyUpdateChara>::cbDispose();
}

void CProxyDrawChara::cbPreDraw(const int index, void* data) const
{
	std::cout << "CProxyUpdateChara::preDraw(index=" << index << ", data=" << data << ")" << std::endl;
}

void CProxyDrawChara::cbPostDraw(const int index, void* data) const
{
	std::cout << "CProxyUpdateChara::postDraw(index=" << index << ", data=" << data << ")" << std::endl;
}

CProxyDrawChara::~CProxyDrawChara()
{
	std::cout << "CProxyDrawChara::~CProxyDrawChara()" << std::endl;
	this->dispose();
}

void CProxyDrawChara::cbDispose()
{
	std::cout << "CProxyDrawChara::cbDispose()" << std::endl;
	this->CProxyDrawCommon<CProxyDrawChara>::cbDispose();
}

CCompositeChara::~CCompositeChara()
{
	std::cout << "CCompositeChara::~CCompositeChara()" << std::endl;
	this->dispose();
}

void CCompositeChara::cbDispose()
{
	std::cout << "CCompositeChara::cbDispose()" << std::endl;
	this->CCompositeProcess::cbDispose();
}

//明示的なインスタンス化
#include "proxy_base/proxy_base.inl"
template class CProxyPrint::vtable_initializer<CProxyPrintChara>;
template class CProxyUpdate::vtable_initializer<CProxyUpdateChara>;
template class CProxyDraw::vtable_initializer<CProxyDrawChara>;
template class CProxyPrintCommon<CProxyPrintChara>;
template class CProxyUpdateCommon<CProxyUpdateChara>;
template class CProxyDrawCommon<CProxyDrawChara>;

//明示的なインスタンス化
#include "composite_base/composite_base.inl"
template class CComponent::vtable_initializer<CCompositeChara>;

// End of file
