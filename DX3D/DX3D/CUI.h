#pragma once

class CButton;

class CUI
{
public:
	CUI();
	virtual ~CUI();

protected:
	CButton*		m_pRootButton;
	D3DXMATRIXA16	m_matWorld;
	D3DXVECTOR2		m_vPosition;
	CButton*		m_pFocused;

public:
	virtual void Render(int nAlpha = 255);
	virtual void Move(int fDeltaX, int fDeltaY);
	virtual int GetWidth();
	virtual int GetHeight();

	virtual bool IsMouseOn(int x, int y);
	virtual CButton* GetTarget(int x, int y);
	virtual void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) = 0;
	
};


