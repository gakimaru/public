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

void CComponent::destructor()
{
	std::cout << "CComponent::destructor()" << std::endl;
}

CComponent::~CComponent()
{
	std::cout << "CComponent::~CComponent()" << std::endl;
	this->m_vtable->pDestructor(reinterpret_cast<void*>(this));
}

void CLeaf::destructor()
{
	std::cout << "CLeaf::destructor()" << std::endl;
	CComponent::destructor();
}

CLeaf::~CLeaf()
{
	std::cout << "CLeaf::~CLeaf()" << std::endl;
	this->destructor();
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

void CComposite::destructor()
{
	std::cout << "CComposite::destructor()" << std::endl;
	this->removeChildren();
	CComponent::destructor();
}

CComposite::~CComposite()
{
	std::cout << "CComposite::~CComposite()" << std::endl;
	this->destructor();
}

// End of file
