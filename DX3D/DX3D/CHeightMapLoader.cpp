#include "stdafx.h"
#include "CHeightMapLoader.h"
#include <fstream>

CHeightMapLoader::CHeightMapLoader(): m_nMapWidth(0), m_pTexture(nullptr)
{
}

CHeightMapLoader::~CHeightMapLoader()
{
}

bool CHeightMapLoader::readRawFile(string sRawFileName, string sTextureFileName)
{
	using std::ifstream;
	ifstream is(sRawFileName.c_str(), std::ios_base::binary);

	if (!is.is_open())
		return false;

	is.seekg(0, is.end);
	int nFileSize = is.tellg();
	m_nMapWidth = sqrt(nFileSize) + 0.0001f;
	is.seekg(0, is.beg);

	m_vecHeightMap.clear();
	
	for(int i = 0; i < m_nMapWidth; i++)
	{
		vector<BYTE> in(m_nMapWidth);
		is.read((char*)&in[0], m_nMapWidth);

		m_vecHeightMap.insert(m_vecHeightMap.end(), in.begin(), in.end());
	}

	m_pTexture = g_pTextureManager.GetTexture(sTextureFileName);

	return true;
}

cFieldMap* CHeightMapLoader::createMap()
{
	cFieldMap* pMap = new cFieldMap;
	pMap->createMap(m_vecHeightMap, 0.1f, m_nMapWidth, m_nMapWidth, 1, 1, m_pTexture);
	return pMap;
}
