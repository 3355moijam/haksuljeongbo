#pragma once
#include "stdafx.h"
#include "cSquare.h"
#include "cCamera.h"
#include "cGrid.h"

class cMainGame
{
private:
	HDC m_MemDC;
	HBITMAP m_hOldBitmap, m_hBitmap;
	cSquare square_;
	cCamera camera;
	cGrid grid;


	cMatrix matWorld;
	cMatrix matView;
	cMatrix matProj;
	cMatrix matViewport;
	
public:
	cMainGame();
	~cMainGame();
	void setup();
	void update();
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void render(HDC hdc);
};
