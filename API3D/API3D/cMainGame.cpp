#include "stdafx.h"

#include "cVector3.h"
#include "cMatrix.h"	
#include "cMainGame.h"
extern HWND g_hWnd;
cMainGame::cMainGame():
	m_hBitmap(NULL),
	square_(), grid()
{
	
}

cMainGame::~cMainGame()
{
	SelectObject(m_MemDC, m_hOldBitmap);
	DeleteObject(m_hBitmap);
	DeleteDC(m_MemDC);
}

void cMainGame::setup()
{
	HDC hdc = GetDC(g_hWnd);
	m_MemDC = CreateCompatibleDC(hdc);

	RECT rc;
	GetClientRect(g_hWnd, &rc);
	m_hBitmap = CreateCompatibleBitmap(hdc, rc.right, rc.bottom);

	m_hOldBitmap = (HBITMAP)SelectObject(m_MemDC, m_hBitmap);
	ReleaseDC(g_hWnd, hdc);

	matWorld = cMatrix::identity(4);
	matView = cMatrix::identity(4);
	matProj = cMatrix::identity(4);
	matViewport = cMatrix::identity(4);

}

void cMainGame::update()
{
	if (GetKeyState('a') & 0x8000 || GetKeyState('A') & 0x8000)
		square_.rotate.Y -= 10;
	else if (GetKeyState('d') & 0x8000 || GetKeyState('D') & 0x8000)
		square_.rotate.Y += 10;

	if (GetKeyState('w') & 0x8000 || GetKeyState('W') & 0x8000)
	{
		cVector3 move_dir = square_.move(-1);
		camera.vLookAt += move_dir;
		camera.vEye += move_dir;
	}
	else if (GetKeyState('s') & 0x8000 || GetKeyState('S') & 0x8000)
	{
		cVector3 move_dir = square_.move(1);
		camera.vLookAt += move_dir;
		camera.vEye += move_dir;
	}

	if (GetKeyState('o') & 0x8000 || GetKeyState('O') & 0x8000)
	{
		square_.scaleControl(-1);
	}
	else if (GetKeyState('p') & 0x8000 || GetKeyState('P') & 0x8000)
	{
		square_.scaleControl(1);
	}

	
	camera.update();
	RECT rc;
	GetClientRect(g_hWnd, &rc);


	matView = cMatrix::view(camera.vEye, camera.vLookAt, camera.vUp);
	matProj = cMatrix::projection(camera.fFovY, camera.fAspect, camera.fNearZ, camera.fFarZ);
	matViewport = cMatrix::viewport(0, 0, rc.right, rc.bottom);

	//if (GetKeyState('a') & 0x8000 || GetKeyState('A') & 0x8000)
	//	square_.rotate.Y -= 10;
	//else if (GetKeyState('d') & 0x8000 || GetKeyState('D') & 0x8000)
	//	square_.rotate.Y += 10;

	//if (GetKeyState('w') & 0x8000 || GetKeyState('W') & 0x8000)
	//	square_.move(1);
	//else if (GetKeyState('s') & 0x8000 || GetKeyState('S') & 0x8000)
	//	square_.move(-1);
}

void cMainGame::render(HDC hdc)
{
	RECT rc;
	GetClientRect(g_hWnd, &rc);

	PatBlt(m_MemDC, rc.left, rc.top, rc.right, rc.bottom, WHITENESS);

	cMatrix matWVP = matWorld * matView * matProj;
	grid.render(m_MemDC, matWVP, matViewport);
	//BitBlt(hdc, 0, 0, rc.right, rc.bottom, m_MemDC, 0, 0, SRCCOPY);
	matWVP = square_.get_world_matrix() * matView * matProj;
	cVector3 look = (camera.vLookAt - camera.vEye).normalize();
	square_.render(m_MemDC, matWVP, matViewport, look);
	//square_.render(m_MemDC, square_.get_world_matrix() * matView, matProj * matViewport, camera.vLookAt - camera.vEye);
	
	BitBlt(hdc, 0, 0, rc.right, rc.bottom, m_MemDC, 0, 0, SRCCOPY);
}

void cMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static float x = 0, y = 0;
	switch (message)
	{
	case WM_KEYDOWN:
		//if (GetKeyState('a') & 0x8000 || GetKeyState('A') & 0x8000)
		//	square_.rotate.Y -= 10;
		//else if (GetKeyState('d') & 0x8000 || GetKeyState('D') & 0x8000)
		//	square_.rotate.Y += 10;

		//if (GetKeyState('w') & 0x8000 || GetKeyState('W') & 0x8000)
		//{
		//	cVector3 move_dir = square_.move(-1);
		//	camera.vLookAt += move_dir;
		//	camera.vEye += move_dir;
		//}
		//else if (GetKeyState('s') & 0x8000 || GetKeyState('S') & 0x8000)
		//{
		//	cVector3 move_dir = square_.move(1);
		//	camera.vLookAt += move_dir;
		//	camera.vEye += move_dir;
		//}

		//if (GetKeyState('o') & 0x8000 || GetKeyState('O') & 0x8000)
		//{
		//	square_.scaleControl(-1);
		//}
		//else if (GetKeyState('p') & 0x8000 || GetKeyState('P') & 0x8000)
		//{
		//	square_.scaleControl(1);
		//}
		break;
	case WM_LBUTTONDOWN:
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		break;
	case WM_LBUTTONUP:
		x = 0; y = 0;
		break;
	case WM_MOUSEMOVE:
		switch (wParam)
		{
		case MK_LBUTTON:
			//camera.move(x - LOWORD(lParam), HIWORD(lParam) - y);
			camera.move(LOWORD(lParam) - x, HIWORD(lParam) - y);
			x = LOWORD(lParam);
			y = HIWORD(lParam);
			break;
		}
		break;
	case WM_MOUSEWHEEL:
		GET_WHEEL_DELTA_WPARAM(wParam);
		camera.zoom(GET_WHEEL_DELTA_WPARAM(wParam));
		break;
	default:
		break;
	}
}

