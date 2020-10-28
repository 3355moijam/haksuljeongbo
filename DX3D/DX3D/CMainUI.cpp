#include "stdafx.h"
#include "CMainUI.h"
#include "CButton.h"

CMainUI::CMainUI(): m_pRootButton(nullptr), m_vPosition(0, 0)
{
	D3DXMatrixTranslation(&m_matWorld, m_vPosition.x, m_vPosition.y, 0);
	
	CButton* button = new CButton;
	button->Load("data/UI", "panel-info.png");
	button->SetParentWorld(&m_matWorld);
	m_pRootButton = button;

	button = new CButton;
	button->Load("data/UI", "btn-main-menu.png");
	button->SetPosition(381, 90);
	m_pRootButton->AddChild(button);

	button = new CButton;
	button->Load("data/UI", "btn-med-up.png", CButton::E_DEFAULT);
	button->Load("data/UI", "btn-med-over.png", CButton::E_HOVER);
	button->Load("data/UI", "btn-med-down.png", CButton::E_DOWN);
	button->SetPosition(m_pRootButton->GetWidth() * 0.5f - button->GetWidth() * 0.5f, 300);
	m_pRootButton->AddChild(button);

	button = new CButton;
	button->Load("data/UI", "btn-med-up.png", CButton::E_DEFAULT);
	button->Load("data/UI", "btn-med-over.png", CButton::E_HOVER);
	button->Load("data/UI", "btn-med-down.png", CButton::E_DOWN);
	button->SetPosition(m_pRootButton->GetWidth() * 0.5f - button->GetWidth() * 0.5f, 364);
	m_pRootButton->AddChild(button);


	m_pRootButton->SetActive(true);

}

CMainUI::~CMainUI()
{
}

void CMainUI::Render(int nAlpha)
{
	if (m_pRootButton)
		m_pRootButton->render(nAlpha);
}

void CMainUI::Move(int fDeltaX, int fDeltaY)
{
	m_vPosition.x += fDeltaX;
	m_vPosition.y += fDeltaY;
	D3DXMatrixTranslation(&m_matWorld, m_vPosition.x, m_vPosition.y, 0);
}

int CMainUI::GetWidth()
{
	return m_pRootButton->GetWidth();
}

int CMainUI::GetHeight()
{
	return m_pRootButton->GetHeight();
}

bool CMainUI::IsMouseOn(int x, int y)
{
	RECT rc;
	SetRect(&rc, m_vPosition.x, m_vPosition.y, m_vPosition.x + m_pRootButton->GetWidth(), m_vPosition.y + m_pRootButton->GetHeight());
	bool isClickSelf = PtInRect(&rc, POINT{ x, y });

	//if(isClickSelf)
		// 자기는 클릭, 자식이 없거나 클릭X면 자신이 target.아아아아

	return isClickSelf;
}

void CMainUI::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int nBeforeX = 0;
	static int nBeforeY = 0;
	static bool isDrag = false;
	switch (message)
	{
	case WM_LBUTTONDOWN:
		{
			// if target == this
			if (IsMouseOn(LOWORD(lParam), HIWORD(lParam)))
			{
				isDrag = true;
				nBeforeX = LOWORD(lParam);
				nBeforeY = HIWORD(lParam);
			}
			// else
			// target.SetStatus(CButton::E_DOWN);
		}
		break;
	case WM_MOUSEMOVE:
		if (isDrag)
		{
			Move((int)LOWORD(lParam) - nBeforeX, (int)HIWORD(lParam) - nBeforeY);
			nBeforeX = LOWORD(lParam);
			nBeforeY = HIWORD(lParam);
		}
		// gettarget
		break;
	case WM_LBUTTONUP:
		if(isDrag)
			isDrag = false;
		else
		{
			//target.event();
			//target.setStatus(CButton::E_DEFAULT);
		}
		break;
	default:
		break;
	}
}
