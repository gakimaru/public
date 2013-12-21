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
