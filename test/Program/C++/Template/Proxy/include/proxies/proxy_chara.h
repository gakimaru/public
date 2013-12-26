#pragma once
#ifndef __PROXY_CHARA_H__
#define __PROXY_CHARA_H__

#include "proxy_base/proxy_base.h"
#include "process/data_chara.h"
#include "process/composite.h"

class CCompositeChara;

class CProxyPrintChara : public CProxyPrintCommon<CProxyPrintChara>
{
	friend class CCompositeChara;
public:
	void cbPrintName() const;
	void cbPrintMessage(const int par1, const char* par2) const;
private:
//	explicit CProxyPrintChara(){}
	explicit CProxyPrintChara(CProxyPrintChara&){}
public:
	explicit CProxyPrintChara() :
		m_this(nullptr),
		CProxyPrintCommon<CProxyPrintChara>(*this)
	{
	}
	void destructor();
	~CProxyPrintChara();
private:
	CCharaData* m_this;
};

class CProxyUpdateChara : public CProxyUpdateCommon<CProxyUpdateChara>
{
	friend class CCompositeChara;
public:
	void cbUpdate(const float elapsed_time) const;
	void cbAnimation() const;
private:
//	explicit CProxyUpdateChara(){}
	explicit CProxyUpdateChara(CProxyUpdateChara&){}
public:
	explicit CProxyUpdateChara() :
		m_this(nullptr),
		CProxyUpdateCommon<CProxyUpdateChara>(*this)
	{
	}
	void destructor();
	~CProxyUpdateChara();
private:
	CCharaData* m_this;
};

class CProxyDrawChara : public CProxyDrawCommon<CProxyDrawChara>
{
	friend class CCompositeChara;
public:
	void cbPreDraw(const int index, void* data) const;
	void cbPostDraw(const int index, void* data) const;
private:
//	explicit CProxyDrawChara(){}
	explicit CProxyDrawChara(CProxyDrawChara&){}
public:
	explicit CProxyDrawChara() :
		m_this(nullptr),
		CProxyDrawCommon<CProxyDrawChara>(*this)
	{
	}
	void destructor();
	~CProxyDrawChara();
private:
	CCharaData* m_this;
};

class CCompositeChara : public CCompositeProcess
{
public:
	CCompositeChara(CCharaData* me) :
		CCompositeProcess(*this, &this->m_proxyPrint, &this->m_proxyUpdate, &this->m_proxyDraw),
		m_this(me)
	{
		this->m_proxyPrint.m_this = me;
		this->m_proxyUpdate.m_this = me;
		this->m_proxyDraw.m_this = me;
	}
	void destructor();
	~CCompositeChara();
private:
	CCharaData* m_this;
	CProxyPrintChara m_proxyPrint;
	CProxyUpdateChara m_proxyUpdate;
	CProxyDrawChara m_proxyDraw;
};

#endif//__PROXY_CHARA_H__

// End of file
