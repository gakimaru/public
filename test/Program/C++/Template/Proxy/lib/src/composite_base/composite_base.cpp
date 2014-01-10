#include <iostream>

#include "composite_base/composite_base.h"

void CComponent::addNext(CComponent* next)
{
	if (!next)
		return;
	CComponent* now;
	now = this;
	while (now->m_next)
	{
		now = now->m_next;
	}
	now->m_next = next;
	next->m_next = nullptr;
}

void CComponent::remove(CComponent* parent, CComponent* prev)
{
	if (parent)
	{
		CComposite* composition = parent->getComposition();
		if (composition)
		{
			composition->m_childTop = this->m_next;
		}
	}
	if (prev)
	{
		prev->m_next = this->m_next;
	}
	delete this;
}

void CComponent::removeNextAll()
{
	if (this->m_next)
	{
		this->m_next->removeNextAll();
		delete this->m_next;
		this->m_next = nullptr;
	}
}

CComponent::~CComponent()
{
	std::cout << "CComponent::~CComponent()" << std::endl;
	this->dispose();
}

void CComponent::dispose()
{
	std::cout << "CComponent::dispose()" << std::endl;
	this->m_vtable->pDispose(reinterpret_cast<void*>(this));
}

void CComponent::cbDispose()
{
	std::cout << "CComponent::cbDispose()" << std::endl;
}

CLeaf::~CLeaf()
{
	std::cout << "CLeaf::~CLeaf()" << std::endl;
	this->dispose();
}

void CLeaf::cbDispose()
{
	std::cout << "CLeaf::cbDispose()" << std::endl;
	this->CComponent::cbDispose();
}

void CComposite::addChild(CComponent* child)
{
	if (!child)
		return;
	if (this->m_childTop)
	{
		this->m_childTop->addNext(child);
	}
	else
	{
		this->m_childTop = child;
	}
}

void CComposite::removeChild(CComponent* child)
{
	if (!child)
		return;
	CComponent* now = this->m_childTop;
	if (!now)
		return;
	CComponent* prev = nullptr;
	while (now != child)
	{
		prev = now;
		now = now->getNext();
		if (!now)
			break;
	}
	if (now)
	{
		now->remove(this, prev);
	}
}

void CComposite::removeChildren()
{
	CComponent* now = this->m_childTop;
	if (!now)
		return;
	while (now)
	{
		CComponent* next = now->getNext();
		delete now;
		now = next;
	}
	this->m_childTop = nullptr;
}

CComposite::~CComposite()
{
	std::cout << "CComposite::~CComposite()" << std::endl;
	this->dispose();
}

void CComposite::cbDispose()
{
	std::cout << "CComposite::cbDispose()" << std::endl;
	this->removeChildren();
	this->CComponent::cbDispose();
}

// End of file
