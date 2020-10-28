#pragma once

#define g_pUIManager CUIManager::getInstance()

class CUIManager
{
	Singletone(CUIManager);
private:
	map<string, std::pair<LPDIRECT3DTEXTURE9, D3DXIMAGE_INFO>> m_mapTexture;
public:
	void GetTexture(string& sFullPath, std::pair<LPDIRECT3DTEXTURE9, D3DXIMAGE_INFO>* pPair);
	void Destroy();
	
};


