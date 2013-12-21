#pragma once
#ifndef __DATA_CHARA_H__
#define __DATA_CHARA_H__

class CProxyPrintChara;

class CCharaData
{
	friend class CProxyPrintChara;
public:
	const char* getCharaName() const { return this->m_CharaName; }
private:
	explicit CCharaData(){}
	explicit CCharaData(CCharaData&){}
public:
	explicit CCharaData(const char* name);
	~CCharaData();
private:
	const char* m_CharaName;
};

#endif//__DATA_CHARA_H__

// End of file
