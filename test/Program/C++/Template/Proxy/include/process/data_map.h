#pragma once
#ifndef __DATA_MAP_H__
#define __DATA_MAP_H__

class CProxyPrintMap;

class CMapData
{
	friend class CProxyPrintMap;
public:
	const char* getMapName() const {return this->m_MapName; }
private:
	explicit CMapData(){}
	explicit CMapData(CMapData&){}
public:
	explicit CMapData(const char* name);
	~CMapData();
private:
	const char* m_MapName;
};

#endif//__DATA_MAP_H__

// End of file
