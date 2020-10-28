#pragma once

class CButton;

class CMainUI
{
public:
	CMainUI();
	~CMainUI();
private:
	CButton*		m_pRootButton;
	D3DXMATRIXA16	m_matWorld;
	D3DXVECTOR2		m_vPosition;

public:
	void Render(int nAlpha = 255);
	void Move(int fDeltaX, int fDeltaY);
	void Move(float fDeltaX, float fDeltaY);

	int GetWidth();
	int GetHeight();

	bool IsMouseOn(int x, int y);
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

};
