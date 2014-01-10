#pragma once
#ifndef __PROXY_BASE_H__
#define __PROXY_BASE_H__

//【変形プロキシパターン】
//・本来のプロキシパターンは、直接Subjectにアクセスするか、Proxy（代理人）を通してSubjectにアクセスするかを区別せずに扱えるようにする為のもの。
//　（本来そのままでも利用可能なSubjectに対して、部分的にProxyが機能を差し替えるような場合に使用する。）
//・ここでは、必ずProxyを通してSubjectにアクセスするものとする。その為、Subjectにはインタフェースの実装を持たない。
//・各種 Subject に対する処理だけをまとめたProxyを用意する事で、処理をすっきりとまとめるものとする。
//・例えば、キャラやマップなどに応じて異なる情報を保持するSubjectがあり、
//　それらに対する時間更新処理系、描画処理系、ターゲット処理系などに応じた各種Proxyクラスを別個に用意する。
//　これにより、各Subjectクラスを肥大化させずに、かつ、必要なインタフェースを間違いなく実装しないとコンパイルエラーが発生するようにする。

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
