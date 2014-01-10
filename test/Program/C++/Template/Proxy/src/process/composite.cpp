#include <iostream>

#include "process/composite.h"

void CCompositeProcess::cbDispose()
{
	std::cout << "CCompositeProcess::cbDispose()" << std::endl;
	m_proxyPrint->dispose();
	m_proxyUpdate->dispose();
	m_proxyDraw->dispose();
	this->CComposite::cbDispose();
}

CCompositeProcess::~CCompositeProcess()
{
	std::cout << "CCompositeProcess::~CCompositeProcess()" << std::endl;
	this->dispose();
}

// End of file
