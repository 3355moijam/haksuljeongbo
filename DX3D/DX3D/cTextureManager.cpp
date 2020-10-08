#include "stdafx.h"
#include "cTextureManager.h"

cTextureManager::cTextureManager()
{
}

cTextureManager::~cTextureManager()
{
}

LPDIRECT3DTEXTURE9 cTextureManager::GetTexture(char* szFullPath)
{
	if(m_mapTexture.find(szFullPath) == m_mapTexture.end())
	{
		D3DXCreateTextureFromFileA(g_pD3DDevice, szFullPath, &m_mapTexture[szFullPath]);
	}

	return m_mapTexture[szFullPath];
}

LPDIRECT3DTEXTURE9 cTextureManager::GetTexture(string& sFullPath)
{
	if (m_mapTexture.find(sFullPath) == m_mapTexture.end())
	{
		D3DXCreateTextureFromFileA(g_pD3DDevice, sFullPath.c_str(), &m_mapTexture[sFullPath]);
	}

	return m_mapTexture[sFullPath];
	
	//return GetTexture((char*)sFullPath.c_str());
}

void cTextureManager::Destroy()
{
	for (auto & it : m_mapTexture)
	{
		SafeRelease(it.second);
	}
	m_mapTexture.clear();
}
