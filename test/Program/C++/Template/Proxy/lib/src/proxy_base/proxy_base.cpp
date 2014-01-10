#include <iostream>

#include "proxy_base/proxy_base.h"

void CProxyPrint::printName() const
{
	this->m_vtable->pPrintName(m_this);
}

void CProxyPrint::printMessage(const int par1, const char* par2) const
{
	this->m_vtable->pPrintMessage(m_this, par1, par2);
}

CProxyPrint::~CProxyPrint()
{
	std::cout << "CProxyPrint::~CProxyPrint()" << std::endl;
	this->dispose();
}

void CProxyPrint::dispose()
{
	std::cout << "CProxyPrint::dispose()" << std::endl;
	this->m_vtable->pDispose(m_this);
}

void CProxyPrint::cbDispose()
{
	std::cout << "CProxyPrint::cbDispose()" << std::endl;
}

void CProxyUpdate::update(const float elapsed_time) const
{
	this->m_vtable->pUpdate(m_this, elapsed_time);
}

void CProxyUpdate::animation() const
{
	this->m_vtable->pAnimation(m_this);
}

CProxyUpdate::~CProxyUpdate()
{
	std::cout << "CProxyUpdate::~CProxyUpdate()" << std::endl;
	this->dispose();
}

void CProxyUpdate::dispose()
{
	std::cout << "CProxyUpdate::dispose()" << std::endl;
	this->m_vtable->pDispose(m_this);
}

void CProxyUpdate::cbDispose()
{
	std::cout << "CProxyUpdate::cbDispose()" << std::endl;
}

void CProxyDraw::preDraw(const int index, void* data) const
{
	this->m_vtable->pPreDraw(m_this, index, data);
}

void CProxyDraw::postDraw(const int index, void* data) const
{
	this->m_vtable->pPostDraw(m_this, index, data);
}

CProxyDraw::~CProxyDraw()
{
	std::cout << "CProxyDraw::~CProxyDraw()" << std::endl;
	this->dispose();
}

void CProxyDraw::dispose()
{
	std::cout << "CProxyDraw::dispose()" << std::endl;
	this->m_vtable->pDispose(m_this);
}

void CProxyDraw::cbDispose()
{
	std::cout << "CProxyDraw::cbDispose()" << std::endl;
}

// End of file
