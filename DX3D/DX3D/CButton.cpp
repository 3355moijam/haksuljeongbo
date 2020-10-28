#include "stdafx.h"
#include "CButton.h"
#include "CUIManager.h"

LPD3DXSPRITE CButton::m_pSprite = nullptr;

CButton::CButton():
	//m_pSprite(nullptr), 
	isActive(false),
	m_pmatParentWorldTM(nullptr),
	isButton(false),
	m_eStatus(E_DEFAULT), m_pEvent(nullptr)
{
	if (!m_pSprite)
		D3DXCreateSprite(g_pD3DDevice, &m_pSprite);

	D3DXMatrixIdentity(&m_matWorldTM);
	D3DXMatrixIdentity(&m_matTrans);
	D3DXMatrixIdentity(&m_matScale);
}

CButton::~CButton()
{
	SafeRelease(m_pSprite);
	for (auto && p : m_vecChild)
	{
		SafeDelete(p);
	}
}

void CButton::SetActive(bool b)
{
	isActive = b;
	for (auto && p : m_vecChild)
	{
		p->SetActive(b);
	}
}

void CButton::Load(string sFolder, string sFilename, int mode)
{
	string sFullPath = sFolder + "/" + sFilename;

	if (mode & E_DEFAULT)
	{
		g_pUIManager.GetTexture(sFullPath, &m_mapTextureAndInfo[E_DEFAULT]);
	}
	if (mode & E_HOVER)
	{
		g_pUIManager.GetTexture(sFullPath, &m_mapTextureAndInfo[E_HOVER]);
	}
	if (mode & E_DOWN)
	{
		g_pUIManager.GetTexture(sFullPath, &m_mapTextureAndInfo[E_DOWN]);
	}
}

void CButton::SetScale(float x, float y, float z)
{
	D3DXMatrixScaling(&m_matScale, x, y, z);
	//m_matWorldTM = m_matScale * m_matTrans * *m_pmatParentWorldTM;
}

void CButton::SetPosition(float x, float y)
{
	D3DXMatrixTranslation(&m_matTrans, x, y, 0);
	//m_matWorldTM = m_matScale * m_matTrans * *m_pmatParentWorldTM;
	
}

void CButton::Render(int nAlpha)
{
	if (!isActive)
		return;
	RECT rc;
	SetRect(&rc, 0, 0, m_mapTextureAndInfo[m_eStatus].second.Width, m_mapTextureAndInfo[m_eStatus].second.Height);
	m_matWorldTM = m_matScale * m_matTrans;
	if (m_pmatParentWorldTM)
		m_matWorldTM *= *m_pmatParentWorldTM;

	//if (!m_pmatParentWorldTM)
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);

	m_pSprite->SetTransform(&m_matWorldTM);
	m_pSprite->Draw(m_mapTextureAndInfo[m_eStatus].first, &rc, &D3DXVECTOR3(0, 0, 0), &D3DXVECTOR3(0, 0, 0), D3DCOLOR_ARGB(nAlpha, 255, 255, 255));

	//if (!m_pmatParentWorldTM)
		m_pSprite->End();

	for (auto && p : m_vecChild)
	{
		p->Render(nAlpha);
	}


}

bool CButton::IsMouseOn(int x, int y)
{
	RECT rc;
	SetRect(&rc, m_matTrans._41, m_matTrans._42, m_matTrans._41 + GetWidth(), m_matTrans._42 + GetHeight());
	return PtInRect(&rc, POINT{ x,y });
}

CButton* CButton::GetClickedChild(int x, int y)
{
	for (auto * p : m_vecChild)
	{
		if (p->IsMouseOn(x - m_matTrans._41, y - m_matTrans._42))
			return p->GetClickedChild(x - m_matTrans._41, y - m_matTrans._42);
	}

	return this;
}

void CButton::AddChild(CButton* child)
{
	m_vecChild.push_back(child);
	child->SetParentWorld(&m_matWorldTM);
}
