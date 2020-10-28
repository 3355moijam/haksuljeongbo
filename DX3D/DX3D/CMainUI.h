#pragma once
#include "CUI.h"

class CButton;

class CMainUI : public CUI
{
public:
	CMainUI();
	~CMainUI();
private:
	int m_nBeforeX;
	int m_nBeforeY;
	bool m_isDrag;

public:
	//void Render(int nAlpha = 255);
	//void Move(int fDeltaX, int fDeltaY);

	//int GetWidth();
	//int GetHeight();

	//bool IsMouseOn(int x, int y);
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

};
