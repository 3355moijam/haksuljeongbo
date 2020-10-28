#pragma once
//#include <functional>

#include "CUI.h"

class CButton
{
public:
	enum eStatus
	{
		E_DEFAULT = 1,
		E_HOVER = 2,
		E_DOWN = 4
	};
	CButton();
	~CButton();
private:
	vector<CButton*>			m_vecChild;
	static LPD3DXSPRITE			m_pSprite;
	map<eStatus, std::pair<LPDIRECT3DTEXTURE9, D3DXIMAGE_INFO>>	m_mapTextureAndInfo;

	bool						isActive;
	
	D3DXMATRIXA16*				m_pmatParentWorldTM;
	D3DXMATRIXA16				m_matScale, m_matTrans, m_matWorldTM;

	Synthesize(bool, isButton, Button);

	eStatus						m_eStatus;

	void (*m_pEvent)(CUI*);
	//std::function<void(CUI*)>	m_funcEvent;
public:

	bool GetActive() { return isActive; }
	void SetActive(bool b);
	void Load(string sFolder, string sFilename, int mode = E_DEFAULT | E_HOVER | E_DOWN);
	void SetScale(float x = 1.0f, float y = 1.0f, float z = 1.0f);
	void SetPosition(float x, float y);
	void Render(int nAlpha = 255);

	void SetParentWorld(D3DXMATRIXA16* pmatParentWorld) { m_pmatParentWorldTM = pmatParentWorld; }
	bool IsMouseOn(int x, int y);
	CButton* GetClickedChild(int x, int y);
	void AddChild(CButton* child);
	void SetStatus(eStatus e) { m_eStatus = e; }

	int GetWidth() { return m_mapTextureAndInfo[m_eStatus].second.Width; }
	int GetHeight() { return m_mapTextureAndInfo[m_eStatus].second.Height; }

	void SetEvent(void(*p)(CUI*)) { m_pEvent = p; }
	void Event(CUI* pUI) { if(m_pEvent) m_pEvent(pUI); }
};
