#include "stdafx.h"
#include "CMainUI.h"

#include <iostream>


#include "CButton.h"

CMainUI::CMainUI(): m_nBeforeX(0), m_nBeforeY(0), m_isDrag(false)
{
	CButton* button = new CButton;
	button->Load("data/UI", "panel-info.png");
	button->SetParentWorld(&m_matWorld);
	m_pRootButton = button;

	button = new CButton;
	button->Load("data/UI", "btn-main-menu.png");
	button->SetPosition(381, 90);
	button->SetEvent([](CUI* pUI)
		{
			CMainUI* pMainUI = dynamic_cast<CMainUI*>(pUI);
			if (!pMainUI)
				return;
			pMainUI->m_pRootButton->SetActive(false);
		});
	m_pRootButton->AddChild(button);

	button = new CButton;
	button->Load("data/UI", "btn-med-up.png", CButton::E_DEFAULT);
	button->Load("data/UI", "btn-med-over.png", CButton::E_HOVER);
	button->Load("data/UI", "btn-med-down.png", CButton::E_DOWN);
	button->SetPosition(m_pRootButton->GetWidth() * 0.5f - button->GetWidth() * 0.5f, 300);
	//button->SetEvent([]() { std::cout << "hello\n"; });
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

void CMainUI::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
		{
			if (!m_pRootButton->GetActive())
				return;
			
			if(m_pFocused == m_pRootButton)
			{
				if (IsMouseOn(LOWORD(lParam), HIWORD(lParam)))
				{
					m_isDrag = true;
					m_nBeforeX = LOWORD(lParam);
					m_nBeforeY = HIWORD(lParam);
				}
			}
			else if(m_pFocused)
			{
				m_pFocused->SetStatus(CButton::E_DOWN);
			}
		}
		break;
	case WM_MOUSEMOVE:
		{
			if (!m_pRootButton->GetActive())
				return;
			
			int nCurrentX = LOWORD(lParam);
			int nCurrentY = HIWORD(lParam);
			if (m_isDrag)
			{
				Move(nCurrentX - m_nBeforeX, nCurrentY - m_nBeforeY);
				m_nBeforeX = nCurrentX;
				m_nBeforeY = nCurrentY;
			}
			else
			{
				if (GetKeyState(VK_LBUTTON) & 0x8000)
					break;
				
				CButton* pFocused = GetTarget(nCurrentX, nCurrentY);
				if (m_pFocused != pFocused)
				{
					if(m_pFocused)
					{
						m_pFocused->SetStatus(CButton::E_DEFAULT);
						m_pFocused = pFocused;
						if(pFocused)
							m_pFocused->SetStatus(CButton::E_HOVER);
					}
					else
					{
						m_pFocused = pFocused;
						m_pFocused->SetStatus(CButton::E_HOVER);
					}

				}
			}
		}
		break;
	case WM_LBUTTONUP:
		if (!m_pRootButton->GetActive())
			return;

		if(m_isDrag)
			m_isDrag = false;
		else if(m_pFocused)
		{
			m_pFocused->SetStatus(CButton::E_HOVER);


			CButton* pFocused = GetTarget(LOWORD(lParam), HIWORD(lParam));
			if(m_pFocused == pFocused)
			{
				// 이벤트 실행
				m_pFocused->Event(this);
			}
			else if (m_pFocused != pFocused)
			{
				if (m_pFocused)
				{
					m_pFocused->SetStatus(CButton::E_DEFAULT);
					m_pFocused = pFocused;
					if (pFocused)
						m_pFocused->SetStatus(CButton::E_HOVER);
				}
			}
		}
		break;
	default:
		break;
	}
}
