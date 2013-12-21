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
//	~CProxyPrint();

private:
	class vtable
	{
	public:
		void(*pPrintName)(void*);
		void(*pPrintMessage)(void*, const int par1, const char* par2);
	};
	template <class T>
	class vtable_initializer
	{
	public:
		static vtable m_vtable;
		static void proxyPrintName(void* me);
		static void proxyPrintMessage(void* me, const int par1, const char* par2);
	};
	void* m_this;
	vtable* m_vtable;
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
//	~CProxyUpdate();

private:
	class vtable
	{
	public:
		void(*pUpdate)(void*, const float);
		void(*pAnimation)(void*);
	};
	template <class T>
	class vtable_initializer
	{
	public:
		static vtable m_vtable;
		static void proxyUpdate(void* me, const float elapsed_time);
		static void proxyAnimation(void* me);
	};
	void* m_this;
	vtable* m_vtable;
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
//	~CProxyDraw();

private:
	class vtable
	{
	public:
		void(*pPreDraw)(void*, const int index, void* data);
		void(*pPostDraw)(void*, const int index, void* data);
	};
	template <class T>
	class vtable_initializer
	{
	public:
		static vtable m_vtable;
		static void proxyPreDraw(void* me, const int index, void* data);
		static void proxyPostDraw(void* me, const int index, void* data);
	};
	void* m_this;
	vtable* m_vtable;
};

#endif//__PROXY_BASE_H__

// End of file
