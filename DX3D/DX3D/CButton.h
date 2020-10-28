#pragma once

class CButton
{
public:
	enum eStatus
	{
		E_DEFAULT,
		E_HOVER,
		E_DOWN
	};
	CButton();
	~CButton();
private:
	vector<CButton*>			m_vecChild;
	static LPD3DXSPRITE			m_pSprite;
	vector<D3DXIMAGE_INFO>		m_vecImageInfo;
	vector<LPDIRECT3DTEXTURE9>	m_vecTexture;

	bool						isActive;
	
	D3DXMATRIXA16*				m_pmatParentWorldTM;
	D3DXMATRIXA16				m_matScale, m_matTrans, m_matWorldTM;

	Synthesize(bool, isButton, Button);

	eStatus						m_eStatus;
public:

	bool GetActive() { return isActive; }
	void SetActive(bool b);
	void Load(string sFolder, string sFilename, eStatus e = E_DEFAULT);
	void SetScale(float x = 1.0f, float y = 1.0f, float z = 1.0f);
	void SetPosition(float x, float y);
	void render(int nAlpha = 255);

	void SetParentWorld(D3DXMATRIXA16* pmatParentWorld) { m_pmatParentWorldTM = pmatParentWorld; }
	bool IsCollide(int x, int y);
	void AddChild(CButton* child);
	void SetStatus(eStatus e) { m_eStatus = e; }

	int GetWidth() { return m_vecImageInfo[m_eStatus].Width; }
	int GetHeight() { return m_vecImageInfo[m_eStatus].Height; }
};
