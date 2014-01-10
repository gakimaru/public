#pragma once
#ifndef __COMPOSITE_BASE_H__
#define __COMPOSITE_BASE_H__

//【コンポジットパターン】
//・シーングラフのような、多様なオブジェクト（クラス）をまとめた階層構造データを扱う為に使用。

class CLeaf;
class CComposite;

class CComponent
{
public:
	CComponent* getNext() const { return this->m_next; }
	void addNext(CComponent* next);
	void remove(CComponent* parent, CComponent* prev);
	void removeNextAll();
	CLeaf* getLeaf() { return this->m_isComposition ? nullptr : reinterpret_cast<CLeaf*>(this); }
	CComposite* getComposition() { return this->m_isComposition ? reinterpret_cast<CComposite*>(this) : nullptr; }
protected:
	explicit CComponent(){}
	explicit CComponent(CComponent&){}
public:
	template<class T>
	explicit CComponent(T& me, const bool is_composition):
		m_isComposition(is_composition),
		m_next(nullptr),
		m_vtable(&vtable_initializer<T>::m_vtable)
	{
	}
	~CComponent();
	void dispose();
public:
	void cbDispose();
	
protected:
	bool m_isComposition;
	CComponent* m_next;

private:
	struct vtable
	{
		void(*pDispose)(void*);
	};
	template <class T>
	class vtable_initializer
	{
	public:
		static CComponent::vtable m_vtable;
		static void proxyDispose(void* me);
	};
	vtable* m_vtable;
};

class CLeaf : public CComponent
{
protected:
	explicit CLeaf(){}
	explicit CLeaf(CLeaf&){}
public:
	template<class T>
	explicit CLeaf(T& me) :
		CComponent(me, false)
	{
	}
	~CLeaf();
public:
	void cbDispose();
};

class CComposite : public CComponent
{
	friend CComponent;
public:
	CComponent* getChildTop()const{ return this->m_childTop; }
	void addChild(CComponent* child);
	void removeChild(CComponent* child);
	void removeChildren();
protected:
	explicit CComposite(){}
	explicit CComposite(CComposite&){}
public:
	template<class T>
	explicit CComposite(T& me) :
		CComponent(me, true),
		m_childTop(nullptr)
	{
	}
	~CComposite();
public:
	void cbDispose();

protected:
	CComponent* m_childTop;
};

#endif//__COMPOSITE_BASE_H__

// End of file
