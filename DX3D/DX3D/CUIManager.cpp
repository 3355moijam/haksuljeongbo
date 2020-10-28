#include "stdafx.h"
#include "CUIManager.h"

CUIManager::CUIManager()
{
}

CUIManager::~CUIManager()
{
}

LPDIRECT3DTEXTURE9 CUIManager::GetTexture(string& sFullPath, D3DXIMAGE_INFO* pstInfo)
{
	if(m_mapTexture.find(sFullPath) == m_mapTexture.end())
	{
		D3DXCreateTextureFromFileExA
		(
			g_pD3DDevice,
			sFullPath.c_str(),
			D3DX_DEFAULT_NONPOW2,
			D3DX_DEFAULT_NONPOW2,
			D3DX_DEFAULT,
			0,
			D3DFMT_UNKNOWN,
			D3DPOOL_MANAGED,
			D3DX_FILTER_NONE,
			D3DX_DEFAULT,
			0,
			&m_mapTexture[sFullPath].second,
			nullptr,
			&m_mapTexture[sFullPath].first
		);
	}
	*pstInfo = m_mapTexture[sFullPath].second;
	return m_mapTexture[sFullPath].first;
}

void CUIManager::Destroy()
{
	for (auto && it : m_mapTexture)
	{
		SafeRelease(it.second.first);
	}
}
