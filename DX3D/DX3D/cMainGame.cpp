#include "stdafx.h"
#include "cMainGame.h"


//#include "cCamera2.h"
//#include "cCubePC.h"
//#include "cGrid2.h"


//LPDIRECT3D9			m_pD3D;
//LPDIRECT3DDEVICE9		m_pD3DDevice;

cMainGame::cMainGame() : cube(), grid(), camera()
	//, m_pCubePC(nullptr)
	//, m_pCamera(nullptr)
	//, m_pGrid(nullptr)
	, player()
{
}

cMainGame::~cMainGame()
{
	//SafeDelete(m_pCubePC);
	//SafeDelete(m_pCamera);
	//SafeDelete(m_pGrid);

	g_pDeviceManager.Destroy();
}

void cMainGame::setup()
{
	//setupLine();
	//setupTriangle();

	//m_pCubePC = new cCubePC;
	//m_pCubePC->setup();

	//m_pCamera = new cCamera2;
	//m_pCamera->setup(&m_pCubePC->getPosition());

	//m_pGrid = new cGrid2;
	//m_pGrid->setup();
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
}

void cMainGame::update()
{
	RECT rc;
	GetClientRect(g_hWnd, &rc);


	cube.update();
	player.update();
	camera.update(cube);
	

	//if(m_pCubePC)
	//	m_pCubePC->update();
	//if(m_pCamera)
	//	m_pCamera->update();

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
		//cube_.render();
		player.render();
		//if (m_pGrid)
		//	m_pGrid->render();
		//if (m_pCubePC)
		//	m_pCubePC->render();
		
		g_pD3DDevice->EndScene();

		g_pD3DDevice->Present(0, 0, 0, 0);
	}
}


void cMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	camera.WndProc(hWnd, message, wParam, lParam);
	//if (m_pCamera)
	//	m_pCamera->WndProc(hWnd, message, wParam, lParam);
	//static float x = 0, y = 0;
	//switch (message)
	//{
	//case WM_RBUTTONDOWN:
	//	x = LOWORD(lParam);
	//	y = HIWORD(lParam);
	//	break;
	//case WM_RBUTTONUP:
	//	x = 0; y = 0;
	//	break;
	//case WM_MOUSEMOVE:
	//	switch (wParam)
	//	{
	//	case MK_RBUTTON:
	//		//camera.move(x - LOWORD(lParam), HIWORD(lParam) - y);
	//		camera.move(LOWORD(lParam) - x, HIWORD(lParam) - y);
	//		x = LOWORD(lParam);
	//		y = HIWORD(lParam);
	//		break;
	//	}
	//	break;
	//case WM_MOUSEWHEEL:
	//	GET_WHEEL_DELTA_WPARAM(wParam);
	//	camera.zoom(GET_WHEEL_DELTA_WPARAM(wParam));
	//	break;
	//default:
	//	break;
	//}
}