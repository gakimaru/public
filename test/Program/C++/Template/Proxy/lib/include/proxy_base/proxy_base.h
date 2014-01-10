#pragma once
#ifndef __PROXY_BASE_H__
#define __PROXY_BASE_H__

//�y�ό`�v���L�V�p�^�[���z
//�E�{���̃v���L�V�p�^�[���́A����Subject�ɃA�N�Z�X���邩�AProxy�i�㗝�l�j��ʂ���Subject�ɃA�N�Z�X���邩����ʂ����Ɉ�����悤�ɂ���ׂ̂��́B
//�@�i�{�����̂܂܂ł����p�\��Subject�ɑ΂��āA�����I��Proxy���@�\�������ւ���悤�ȏꍇ�Ɏg�p����B�j
//�E�����ł́A�K��Proxy��ʂ���Subject�ɃA�N�Z�X������̂Ƃ���B���ׁ̈ASubject�ɂ̓C���^�t�F�[�X�̎����������Ȃ��B
//�E�e�� Subject �ɑ΂��鏈���������܂Ƃ߂�Proxy��p�ӂ��鎖�ŁA��������������Ƃ܂Ƃ߂���̂Ƃ���B
//�E�Ⴆ�΁A�L������}�b�v�Ȃǂɉ����ĈقȂ����ێ�����Subject������A
//�@�����ɑ΂��鎞�ԍX�V�����n�A�`�揈���n�A�^�[�Q�b�g�����n�Ȃǂɉ������e��Proxy�N���X��ʌɗp�ӂ���B
//�@����ɂ��A�eSubject�N���X���剻�������ɁA���A�K�v�ȃC���^�t�F�[�X���ԈႢ�Ȃ��������Ȃ��ƃR���p�C���G���[����������悤�ɂ���B

class CProxyPrint
{
public:
	void printName() const;
	void printMessage(const int par1, const char* par2) const;
protected:
	explicit CProxyPrint(){}
	explicit CProxyPrint(CProxyPrint&){}
public:
	template<class T>
	explicit CProxyPrint(T& me):
		m_this(reinterpret_cast<T*>(&me)),
		m_vtable(&vtable_initializer<T>::m_vtable)
	{
	}
	~CProxyPrint();
	void dispose();
public:
	void cbDispose();

private:
	struct vtable
	{
		void(*pPrintName)(void*);
		void(*pPrintMessage)(void*, const int par1, const char* par2);
		void(*pDispose)(void*);
	};
	template <class T>
	class vtable_initializer
	{
	public:
		static vtable m_vtable;
		static void proxyPrintName(void* me);
		static void proxyPrintMessage(void* me, const int par1, const char* par2);
		static void proxyDispose(void* me);
	};
	void* m_this;
	vtable* m_vtable;
};
template<class derived>
class CProxyPrintCommon : public CProxyPrint
{
protected:
	explicit CProxyPrintCommon(){}
	explicit CProxyPrintCommon(CProxyPrintCommon<derived>&){}
public:
	template<class T>
	explicit CProxyPrintCommon(T& me) :
		CProxyPrint(me)
	{
	}
	~CProxyPrintCommon();
public:
	void cbDispose();
};

class CProxyUpdate
{
public:
	void update(const float elapsed_time) const;
	void animation() const;
protected:
	explicit CProxyUpdate(){}
	explicit CProxyUpdate(CProxyUpdate&){}
public:
	template<class T>
	explicit CProxyUpdate(T& me) :
		m_this(reinterpret_cast<T*>(&me)),
		m_vtable(&vtable_initializer<T>::m_vtable)
	{
	}
	~CProxyUpdate();
	void dispose();
public:
	void cbDispose();

private:
	struct vtable
	{
		void(*pUpdate)(void*, const float);
		void(*pAnimation)(void*);
		void(*pDispose)(void*);
	};
	template <class T>
	class vtable_initializer
	{
	public:
		static vtable m_vtable;
		static void proxyUpdate(void* me, const float elapsed_time);
		static void proxyAnimation(void* me);
		static void proxyDispose(void* me);
	};
	void* m_this;
	vtable* m_vtable;
};
template<class derived>
class CProxyUpdateCommon : public CProxyUpdate
{
protected:
	explicit CProxyUpdateCommon(){}
	explicit CProxyUpdateCommon(CProxyUpdateCommon<derived>&){}
public:
	template<class T>
	explicit CProxyUpdateCommon(T& me) :
		CProxyUpdate(me)
	{
	}
	~CProxyUpdateCommon();
public:
	void cbDispose();
};

class CProxyDraw
{
public:
	void preDraw(const int index, void* data) const;
	void postDraw(const int index, void* data) const;
protected:
	explicit CProxyDraw(){}
	explicit CProxyDraw(CProxyDraw&){}
public:
	template<class T>
	explicit CProxyDraw(T& me) :
		m_this(reinterpret_cast<T*>(&me)),
		m_vtable(&vtable_initializer<T>::m_vtable)
	{
	}
	~CProxyDraw();
	void dispose();
public:
	void cbDispose();

private:
	struct vtable
	{
		void(*pPreDraw)(void*, const int index, void* data);
		void(*pPostDraw)(void*, const int index, void* data);
		void(*pDispose)(void*);
	};
	template <class T>
	class vtable_initializer
	{
	public:
		static vtable m_vtable;
		static void proxyPreDraw(void* me, const int index, void* data);
		static void proxyPostDraw(void* me, const int index, void* data);
		static void proxyDispose(void* me);
	};
	void* m_this;
	vtable* m_vtable;
};
template<class derived>
class CProxyDrawCommon : public CProxyDraw
{
protected:
	explicit CProxyDrawCommon(){}
	explicit CProxyDrawCommon(CProxyDrawCommon<derived>&){}
public:
	template<class T>
	explicit CProxyDrawCommon(T& me) :
		CProxyDraw(me)
	{
	}
	~CProxyDrawCommon();
public:
	void cbDispose();
};

#endif//__PROXY_BASE_H__

// End of file
