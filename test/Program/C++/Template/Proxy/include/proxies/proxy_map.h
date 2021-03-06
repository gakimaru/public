#pragma once
#ifndef __PROXY_MAP_H__
#define __PROXY_MAP_H__

#include "proxy_base/proxy_base.h"
#include "process/data_map.h"
#include "process/composite.h"

class CCompositeMap;

class CProxyPrintMap : public CProxyPrintCommon<CProxyPrintMap>
{
	friend class CCompositeMap;
public:
	void cbPrintName() const;
	void cbPrintMessage(const int par1, const char* par2) const;
private:
//	explicit CProxyPrintMap(){}
	explicit CProxyPrintMap(CProxyPrintMap&){}
public:
	explicit CProxyPrintMap() :
		m_this(nullptr),
		CProxyPrintCommon<CProxyPrintMap>(*this)
	{
	}
	~CProxyPrintMap();
public:
	void cbDispose();
	
private:
	CMapData* m_this;
};

class CProxyUpdateMap : public CProxyUpdateCommon<CProxyUpdateMap>
{
	friend class CCompositeMap;
public:
	void cbUpdate(const float elapsed_time) const;
	void cbAnimation() const;
private:
//	explicit CProxyUpdateMap(){}
	explicit CProxyUpdateMap(CProxyUpdateMap&){}
public:
	explicit CProxyUpdateMap() :
		m_this(nullptr),
		CProxyUpdateCommon<CProxyUpdateMap>(*this)
	{
	}
	~CProxyUpdateMap();
public:
	void cbDispose();
	
private:
	CMapData* m_this;
};

class CProxyDrawMap : public CProxyDrawCommon<CProxyDrawMap>
{
	friend class CCompositeMap;
public:
	void cbPreDraw(const int index, void* data) const;
	void cbPostDraw(const int index, void* data) const;
private:
//	explicit CProxyDrawMap(){}
	explicit CProxyDrawMap(CProxyDrawMap&){}
public:
	explicit CProxyDrawMap() :
		m_this(nullptr),
		CProxyDrawCommon<CProxyDrawMap>(*this)
	{
	}
	~CProxyDrawMap();
public:
	void cbDispose();
	
private:
	CMapData* m_this;
};

class CCompositeMap : public CCompositeProcess
{
public:
	CCompositeMap(CMapData* me) :
		CCompositeProcess(*this, &this->m_proxyPrint, &this->m_proxyUpdate, &this->m_proxyDraw),
		m_this(me)
	{
		this->m_proxyPrint.m_this = me;
		this->m_proxyUpdate.m_this = me;
		this->m_proxyDraw.m_this = me;
	}
	~CCompositeMap();
public:
	void cbDispose();
	
private:
	CMapData* m_this;
	CProxyPrintMap m_proxyPrint;
	CProxyUpdateMap m_proxyUpdate;
	CProxyDrawMap m_proxyDraw;
};

#endif//__PROXY_MAP_H__

// End of file
