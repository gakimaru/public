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

void CProxyPrintChara::destructor()
{
	std::cout << "CProxyDrawChara::destructor()" << std::endl;
	this->CProxyPrintCommon<CProxyPrintChara>::destructor();
}

CProxyPrintChara::~CProxyPrintChara()
{
	std::cout << "CProxyPrintChara::~CProxyPrintChara()" << std::endl;
	this->destructor();
}

void CProxyUpdateChara::cbUpdate(const float elapsed_time) const
{
	std::cout << "CProxyUpdateChara::ppdate(elapsed_time=" << elapsed_time << ")" << std::endl;
}

void CProxyUpdateChara::cbAnimation() const
{
	std::cout << "CProxyUpdateChara::animation()" << std::endl;
}

void CProxyUpdateChara::destructor()
{
	std::cout << "CProxyUpdateChara::destructor()" << std::endl;
	this->CProxyUpdateCommon<CProxyUpdateChara>::destructor();
}

CProxyUpdateChara::~CProxyUpdateChara()
{
	std::cout << "CProxyUpdateChara::~CProxyUpdateChara()" << std::endl;
	this->destructor();
}

void CProxyDrawChara::cbPreDraw(const int index, void* data) const
{
	std::cout << "CProxyUpdateChara::preDraw(index=" << index << ", data=" << data << ")" << std::endl;
}

void CProxyDrawChara::cbPostDraw(const int index, void* data) const
{
	std::cout << "CProxyUpdateChara::postDraw(index=" << index << ", data=" << data << ")" << std::endl;
}

void CProxyDrawChara::destructor()
{
	std::cout << "CProxyDrawChara::destructor()" << std::endl;
	this->CProxyDrawCommon<CProxyDrawChara>::destructor();
}

CProxyDrawChara::~CProxyDrawChara()
{
	std::cout << "CProxyDrawChara::~CProxyDrawChara()" << std::endl;
	this->destructor();
}

void CCompositeChara::destructor()
{
	std::cout << "CCompositeChara::destructor()" << std::endl;
	this->CCompositeProcess::destructor();
}

CCompositeChara::~CCompositeChara()
{
	std::cout << "CCompositeChara::~CCompositeChara()" << std::endl;
	this->destructor();
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
