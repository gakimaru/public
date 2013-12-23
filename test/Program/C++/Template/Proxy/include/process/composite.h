#pragma once
#ifndef __COMPOSITE_H__
#define __COMPOSITE_H__

#include "composite_base/composite_base.h"
#include "proxy_base/proxy_base.h"

class CCompositeProcess : public CComposite
{
public:
	CProxyPrint* getProxyPrint() const{ return this->m_proxyPrint; }
	CProxyUpdate* getProxyUpdate() const{ return this->m_proxyUpdate; }
	CProxyDraw* getProxyDraw() const{ return this->m_proxyDraw; }
public:
	template<class T1, class T2, class T3>
	void setProxy(T1* proxy_print, T2* proxy_update, T3* proxy_draw)
	{
		this->m_proxyPrint = proxy_print;
		this->m_proxyUpdate = proxy_update;
		this->m_proxyDraw = proxy_draw;
	}
private:
	explicit CCompositeProcess();
	explicit CCompositeProcess(CCompositeProcess&);
public:
	template<class T>
	explicit CCompositeProcess(T& me, CProxyPrint* proxy_print, CProxyUpdate* proxy_update, CProxyDraw* proxy_draw):
		CComposite(me),
		m_proxyPrint(proxy_print),
		m_proxyUpdate(proxy_update),
		m_proxyDraw(proxy_draw)
	{
	}
	void destructor();
	~CCompositeProcess();
private:
	CProxyPrint* m_proxyPrint;
	CProxyUpdate* m_proxyUpdate;
	CProxyDraw* m_proxyDraw;
};

#endif//__COMPOSITE_H__

// End of file
