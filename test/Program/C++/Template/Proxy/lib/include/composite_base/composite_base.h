#pragma once
#ifndef __COMPOSITE_BASE_H__
#define __COMPOSITE_BASE_H__

//�y�R���|�W�b�g�p�^�[���z
//�E�V�[���O���t�̂悤�ȁA���l�ȃI�u�W�F�N�g�i�N���X�j���܂Ƃ߂��K�w�\���f�[�^�������ׂɎg�p�B

class CLeaf;
class CComposite;

class CComponent
{
public:
	CComponent* getNext() const { return this->m_next; }
	void addNext(CComponent* next);
	void remove(CComponent* parent, CComponent* prev);
	CLeaf* getLeaf() { return this->m_isComposition ? nullptr : reinterpret_cast<CLeaf*>(this); }
	CComposite* getComposition() { return this->m_isComposition ? reinterpret_cast<CComposite*>(this) : nullptr; }
protected:
	explicit CComponent(){}
	explicit CComponent(CComponent&){}
public:
	explicit CComponent(const bool is_composition):
		m_isComposition(is_composition),
		m_next(nullptr)
	{
	}
	~CComponent();
protected:
	bool m_isComposition;
	CComponent* m_next;
};

class CLeaf : public CComponent
{
private:
//	explicit CLeaf(){}
	explicit CLeaf(CLeaf&){}
public:
	explicit CLeaf():
		CComponent(false)
	{
	}
	~CLeaf();
private:
};

class CComposite : public CComponent
{
	friend CComponent;
public:
	CComponent* getChildTop()const{ return this->m_childTop; }
	void addChild(CComponent* child);
	void removeChild(CComponent* child);
	void removeChildren();
private:
//	explicit CComposite(){}
	explicit CComposite(CComposite&){}
public:
	explicit CComposite() :
		CComponent(true),
		m_childTop(nullptr)
	{
	}
	~CComposite();
private:
	CComponent* m_childTop;
};

#endif//__COMPOSITE_BASE_H__

// End of file
