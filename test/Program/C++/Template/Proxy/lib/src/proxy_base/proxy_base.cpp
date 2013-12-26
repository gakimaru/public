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

void CProxyPrint::destructor()
{
	std::cout << "CProxyPrint::destructor()" << std::endl;
	this->m_vtable->pDestructor(m_this);
}

CProxyPrint::~CProxyPrint()
{
	std::cout << "CProxyPrint::~CProxyPrint()" << std::endl;
	this->destructor();
}

void CProxyUpdate::update(const float elapsed_time) const
{
	this->m_vtable->pUpdate(m_this, elapsed_time);
}

void CProxyUpdate::animation() const
{
	this->m_vtable->pAnimation(m_this);
}

void CProxyUpdate::destructor()
{
	std::cout << "CProxyUpdate::destructor()" << std::endl;
	this->m_vtable->pDestructor(m_this);
}

CProxyUpdate::~CProxyUpdate()
{
	std::cout << "CProxyUpdate::~CProxyUpdate()" << std::endl;
	this->destructor();
}

void CProxyDraw::preDraw(const int index, void* data) const
{
	this->m_vtable->pPreDraw(m_this, index, data);
}

void CProxyDraw::postDraw(const int index, void* data) const
{
	this->m_vtable->pPostDraw(m_this, index, data);
}

void CProxyDraw::destructor()
{
	std::cout << "CProxyUpdate::destructor()" << std::endl;
	this->m_vtable->pDestructor(m_this);
}

CProxyDraw::~CProxyDraw()
{
	std::cout << "CProxyUpdate::~CProxyDraw()" << std::endl;
	this->destructor();
}

// End of file
