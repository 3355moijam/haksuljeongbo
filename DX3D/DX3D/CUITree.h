#pragma once

class CUITree
{
public:
	CUITree();
	virtual ~CUITree();

private:
	vector<CUITree*>			m_vecChild;
	D3DXMATRIXA16*				m_pmatParentWorldTM;
	D3DXMATRIXA16				m_matScale, m_matTrans, m_matWorldTM;

public:
	void SetScale(float x = 1.0f, float y = 1.0f, float z = 1.0f);
	void SetPosition(float x, float y);
	void Render(int nAlpha = 255);
	void SetParentWorld(D3DXMATRIXA16* pmatParentWorld) { m_pmatParentWorldTM = pmatParentWorld; }
	
};
