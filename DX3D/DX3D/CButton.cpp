#include "stdafx.h"
#include "CButton.h"
#include "CUIManager.h"

LPD3DXSPRITE CButton::m_pSprite = nullptr;

CButton::CButton(): /*m_pSprite(nullptr), */isActive(false), m_pmatParentWorldTM(nullptr), isButton(false), m_eStatus(E_DEFAULT),
                    m_vecImageInfo(3),
                    m_vecTexture(3)
{
	if(!m_pSprite)
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

void CButton::Load(string sFolder, string sFilename, eStatus e)
{
	string sFullPath = sFolder + "/" + sFilename;
	m_vecTexture[e] = g_pUIManager.GetTexture(sFullPath, &m_vecImageInfo[e]);
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

void CButton::render(int nAlpha)
{
	if (!isActive)
		return;
	RECT rc;
	SetRect(&rc, 0, 0, m_vecImageInfo[m_eStatus].Width, m_vecImageInfo[m_eStatus].Height);
	m_matWorldTM = m_matScale * m_matTrans;
	if (m_pmatParentWorldTM)
		m_matWorldTM *= *m_pmatParentWorldTM;

	//if (!m_pmatParentWorldTM)
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);

	m_pSprite->SetTransform(&m_matWorldTM);
	m_pSprite->Draw(m_vecTexture[m_eStatus], &rc, &D3DXVECTOR3(0, 0, 0), &D3DXVECTOR3(0, 0, 0), D3DCOLOR_ARGB(nAlpha, 255, 255, 255));

	//if (!m_pmatParentWorldTM)
		m_pSprite->End();

	for (auto && p : m_vecChild)
	{
		p->render(nAlpha);
	}


}

bool CButton::IsCollide(int x, int y)
{
	if (!isActive)
		return false;
	return false;
	// 본인 클릭 체크
	// 만약 참이면 자식 클릭 체크
	// 
}

void CButton::AddChild(CButton* child)
{
	m_vecChild.push_back(child);
	child->SetParentWorld(&m_matWorldTM);
}
