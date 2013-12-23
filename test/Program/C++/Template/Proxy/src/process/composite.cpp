#include <iostream>

#include "process/composite.h"

void CCompositeProcess::destructor()
{
	std::cout << "CCompositeProcess::destructor()" << std::endl;
	m_proxyPrint->destructor();
	m_proxyUpdate->destructor();
	m_proxyDraw->destructor();
	this->CComposite::destructor();
}

CCompositeProcess::~CCompositeProcess()
{
	std::cout << "CCompositeProcess::~CCompositeProcess()" << std::endl;
	this->destructor();
}

// End of file
