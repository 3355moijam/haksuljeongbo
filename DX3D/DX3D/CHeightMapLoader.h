#pragma once
#include "cFieldMap.h"

class CHeightMapLoader
{
public:
	CHeightMapLoader();
	~CHeightMapLoader();

private:
	vector<int>				m_vecHeightMap;
	int						m_nMapWidth;
	LPDIRECT3DTEXTURE9		m_pTexture;

public:
	bool	readRawFile(string sRawFileName, string sTextureFileName);
	cFieldMap*	createMap();
};
