#pragma once

//class cTextureManager;
#define g_pTextureManager cTextureManager::getInstance()
class cTextureManager
{
private:
	Singletone(cTextureManager);
	
	std::map<string, LPDIRECT3DTEXTURE9> m_mapTexture;

public:
	LPDIRECT3DTEXTURE9 GetTexture(char* szFullPath);
	LPDIRECT3DTEXTURE9 GetTexture(string &sFullPath);
	void Destroy();
};
