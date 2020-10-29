#include "stdafx.h"
#include "CUI.h"

#include "CButton.h"

CUI::CUI() : m_pRootButton(nullptr), m_vPosition(0, 0), m_pFocused(nullptr)
{
	D3DXMatrixTranslation(&m_matWorld, m_vPosition.x, m_vPosition.y, 0);
}

CUI::~CUI()
{
	SafeDelete(m_pRootButton);
}

void CUI::Render(int nAlpha)
{
	if (m_pRootButton)
		m_pRootButton->Render(nAlpha);
}

void CUI::Move(int fDeltaX, int fDeltaY)
{
	m_vPosition.x += fDeltaX;
	m_vPosition.y += fDeltaY;
	D3DXMatrixTranslation(&m_matWorld, m_vPosition.x, m_vPosition.y, 0);
}

int CUI::GetWidth()
{
	return m_pRootButton->GetWidth();
}

int CUI::GetHeight()
{
	return m_pRootButton->GetHeight();
}

bool CUI::IsMouseOn(int x, int y)
{
	RECT rc;
	SetRect(&rc, m_vPosition.x, m_vPosition.y, m_vPosition.x + m_pRootButton->GetWidth(), m_vPosition.y + m_pRootButton->GetHeight());
	return PtInRect(&rc, POINT{ x, y });
}

CButton* CUI::GetTarget(int x, int y)
{
	if (!IsMouseOn(x, y))
		return nullptr;
	
	return m_pRootButton->GetClickedChild(x - m_vPosition.x, y - m_vPosition.y);
}