#include "stdafx.h"
#include "cMainGame.h"


//LPDIRECT3D9			m_pD3D;
//LPDIRECT3DDEVICE9		m_pD3DDevice;

cMainGame::cMainGame() : cube(), grid(), camera()
{
}

cMainGame::~cMainGame()
{
	g_pDeviceManager.Destroy();
}

void cMainGame::setup()
{
	setupLine();
	setupTriangle();
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
}

void cMainGame::update()
{
	RECT rc;
	GetClientRect(g_hWnd, &rc);

	//D3DXVECTOR3 vEye(15, 5, -10.0f);
	//D3DXVECTOR3 vLookAt(0, 0, 0);
	//D3DXVECTOR3 vUp(0, 1, 0);

	cube.update();
	camera.update(cube);
	
	D3DXMATRIXA16 matView;
	D3DXMatrixLookAtLH(&matView, &camera.vEye, &camera.vLookAt, &camera.vUp);

	g_pD3DDevice->SetTransform(D3DTS_VIEW, &matView);

	D3DXMATRIXA16 matProj;
	D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 4.0f, (float)rc.right / rc.bottom, 1.0f, 1000.0f);
	g_pD3DDevice->SetTransform(D3DTS_PROJECTION, &matProj);
}

void cMainGame::render()
{
	if(g_pD3DDevice)
	{
		
		
		//static int flip = 0;
		//if (flip == 0)
		//{
		//	m_pD3DDevice->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(255,0,0), 1.0f, 0);
		//	flip = 1;
		//	Sleep(50);
		//}
		//else if (flip == 1)
		//{
		//	m_pD3DDevice->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0,0,255), 1.0f, 0);
		//	flip = 0;
		//	Sleep(50);
		//}
		g_pD3DDevice->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(47, 121, 112), 1.0f, 0);

		g_pD3DDevice->BeginScene();

		grid.render();
		drawLine();
		drawTriangle();
		cube.render();
		
		g_pD3DDevice->EndScene();

		g_pD3DDevice->Present(0, 0, 0, 0);
	}
}

void cMainGame::setupLine()
{
	ST_PC_VERTEX v;
	v.c = D3DCOLOR_XRGB(255, 0, 0);
	v.p = D3DXVECTOR3(0, 0, 0);
	m_vecLineVertex.emplace_back(v);

	v.p = D3DXVECTOR3(10, 0, 0);
	m_vecLineVertex.emplace_back(v);

	v.c = D3DCOLOR_XRGB(0, 255, 0);
	v.p = D3DXVECTOR3(0, 0, 0);
	m_vecLineVertex.emplace_back(v);

	v.p = D3DXVECTOR3(0, 10, 0);
	m_vecLineVertex.emplace_back(v);

	v.c = D3DCOLOR_XRGB(0, 0, 255);
	v.p = D3DXVECTOR3(0, 0, 0);
	m_vecLineVertex.emplace_back(v);

	v.p = D3DXVECTOR3(0, 0, 10);
	m_vecLineVertex.emplace_back(v);
}

void cMainGame::drawLine()
{
	//D3DXMATRIXA16 matWorld;
	//D3DXMatrixIdentity(&matWorld);
	//g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	//g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	//g_pD3DDevice->DrawPrimitiveUP
	//(
	//	D3DPT_LINELIST, 
	//	m_vecLineVertex.size() * 0.5, 
	//	&m_vecLineVertex[0], 
	//	sizeof ST_PC_VERTEX
	//);
}

void cMainGame::setupTriangle()
{
	ST_PC_VERTEX v;
	v.c = D3DCOLOR_XRGB(0, 255, 0);
	//v.c = D3DCOLOR_XRGB(rand()%256, rand() % 256, rand() % 256);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 0.0f);
	m_vecTriangleVertex.emplace_back(v);

	v.p = D3DXVECTOR3(-1.0f, 1.0f, 0.0f);
	m_vecTriangleVertex.emplace_back(v);

	v.p = D3DXVECTOR3(1.0f, 1.0f, 0.0f);
	m_vecTriangleVertex.emplace_back(v);
}

void cMainGame::drawTriangle()
{
	return;
	D3DXMATRIXA16 matWorld, matScale, matPos;
	D3DXMatrixIdentity(&matWorld);
	D3DXVECTOR3 vScale(1, 1, 1);
	D3DXMatrixScaling(&matScale, vScale.x, vScale.y, vScale.z);

	D3DXVECTOR3 vPosition(0, 0, 5);
	D3DXMatrixTranslation(&matPos, vPosition.x, vPosition.y, vPosition.z);
	matWorld = matScale * matPos;
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP
	(
		D3DPT_TRIANGLELIST, 
		m_vecTriangleVertex.size() / 3, 
		&m_vecTriangleVertex[0],
		sizeof ST_PC_VERTEX
	);
}


void cMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static float x = 0, y = 0;
	switch (message)
	{
	case WM_RBUTTONDOWN:
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		break;
	case WM_RBUTTONUP:
		x = 0; y = 0;
		break;
	case WM_MOUSEMOVE:
		switch (wParam)
		{
		case MK_RBUTTON:
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