#include "stdafx.h"
#include "CUIManager.h"

CUIManager::CUIManager()
{
}

CUIManager::~CUIManager()
{
}

void CUIManager::GetTexture(string& sFullPath, std::pair<LPDIRECT3DTEXTURE9, D3DXIMAGE_INFO>* pPair)
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
	*pPair = m_mapTexture[sFullPath];
}

void CUIManager::Destroy()
{
	for (auto && it : m_mapTexture)
	{
		SafeRelease(it.second.first);
	}
}
