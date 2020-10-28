#pragma once

#define g_pFontManager CFontManager::getInstance()

class CFontManager
{
public:
	enum eFontType
	{
		E_DEFAULT,
		E_QUEST
	};
	Singletone(CFontManager);
private:
	map<eFontType, LPD3DXFONT> m_mapFont;
	
public:
	LPD3DXFONT GetFont(eFontType e);
	void Destroy();
};
