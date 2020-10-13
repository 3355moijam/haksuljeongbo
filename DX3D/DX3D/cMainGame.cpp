#include "stdafx.h"
#include "cMainGame.h"

#include "cCamera2.h"
#include "cCubePC.h"
#include "cGrid2.h"
#include "cCubeMan.h"
#include "cCubeMan2.h"
#include "cCubeObj.h"
#include "cDirectionalLight.h"
#include "cPointLight.h"
#include "cSpotLight.h"
#include "cObjectLoader.h"
#include "cGroup.h"

//#include "cCamera2.h"
//#include "cCubePC.h"
//#include "cGrid2.h"


//LPDIRECT3D9			m_pD3D;
//LPDIRECT3DDEVICE9		m_pD3DDevice;

cMainGame::cMainGame()
	: m_pCubePC(nullptr)
	  , m_pCamera(nullptr)
	  , m_pGrid(nullptr), m_pCubeMan(nullptr), m_pTexture(nullptr), m_PointLight(nullptr), m_DirectionalLight(nullptr),
	  m_SpotLight(nullptr), m_pRoute(nullptr), m_pShort(nullptr), m_pRouteMan(nullptr), m_pShortCutMan(nullptr),
	  m_pCubeObj(nullptr)
//, player()
{
}

cMainGame::~cMainGame()
{
	SafeDelete(m_pCubePC);
	SafeDelete(m_pCamera);
	SafeDelete(m_pGrid);
	SafeDelete(m_pCubeMan);
	SafeRelease(m_pTexture);

	SafeDelete(m_PointLight);
	SafeDelete(m_DirectionalLight);
	SafeDelete(m_SpotLight);

	SafeDelete(m_pRoute);
	SafeDelete(m_pShort);
	SafeDelete(m_pRouteMan);
	SafeDelete(m_pShortCutMan);

	SafeDelete(m_pCubeObj);

	for (auto * p : m_vecGroup)
	{
		SafeRelease(p);
	}
	m_vecGroup.clear();

	for (auto* p : m_vecGroupSurf)
	{
		SafeRelease(p);
	}
	m_vecGroupSurf.clear();
	g_pObjectManager.Destroy();
	
	
	g_pDeviceManager.Destroy();
}

void cMainGame::setup()
{
	//setupLine();
	//setupTriangle();

	m_pCubePC = new cCubePC;
	m_pCubePC->setup();

	m_pCubeMan = new cCubeMan;
	m_pCubeMan->setup();

	m_pCamera = new cCamera2;
	m_pCamera->setup(&m_pCubeMan->getPosition());

	m_pGrid = new cGrid2;
	m_pGrid->setup(15, 1);

	m_pRoute = new cGuideline;
	m_pRoute->setup(D3DCOLOR_XRGB(0, 255, 0));

	m_pRouteMan = new cCubeMan2;
	m_pRouteMan->setup();
	m_pRouteMan->setGuide(m_pRoute->getRouteNode());

	m_pShort = new cGuideline;
	m_pShort->setup(D3DCOLOR_XRGB(255, 0, 0));
	m_pShort->Interpolation(30);

	m_pShortCutMan = new cCubeMan2;
	m_pShortCutMan->setup();
	m_pShortCutMan->setGuide(m_pShort->getShortCut());

	m_pCubeObj = new cCubeObj;
	m_pCubeObj->setup();
	
	// for texture
	//{
	//	D3DXCreateTextureFromFile(g_pD3DDevice, _T("TEXTURES/BRICK/brick_01/brick_01-2.png"), &m_pTexture);
	//	ST_PT_VERTEX v;
	//	v.p = D3DXVECTOR3(0, 0, 0);
	//	v.t = D3DXVECTOR2(0, 1);
	//	m_vecVertex.push_back(v);

	//	v.p = D3DXVECTOR3(0, 1, 0);
	//	v.t = D3DXVECTOR2(0, 0);
	//	m_vecVertex.push_back(v);

	//	v.p = D3DXVECTOR3(1, 1, 0);
	//	v.t = D3DXVECTOR2(1, 0);
	//	m_vecVertex.push_back(v);
	//}
	Setup_Obj();
	Set_Light();
	//g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
}

void cMainGame::update()
{
	RECT rc;
	GetClientRect(g_hWnd, &rc);


	//cube.update();
	//player.update();
	//camera.update(cube);
	

	//if(m_pCubePC)
	//	m_pCubePC->update();
	if (m_pCubeMan)
		m_pCubeMan->update(m_vecGroupSurf);
	
	if(m_pCamera)
		m_pCamera->update();

	//if (m_PointLight)
	//	m_PointLight->update();

	//if (m_DirectionalLight)
	//	m_DirectionalLight->update();

	//if (m_SpotLight)
	//	m_SpotLight->update();

	if (m_pRouteMan)
		m_pRouteMan->update();

	if (m_pShortCutMan)
		m_pShortCutMan->update();

}

void cMainGame::Draw_Texture()
{
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);

	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetTexture(0, m_pTexture);

	g_pD3DDevice->SetFVF(ST_PT_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(
		D3DPT_TRIANGLELIST,
		m_vecVertex.size() / 3,
		&m_vecVertex[0],
		sizeof ST_PT_VERTEX
	);
	g_pD3DDevice->SetTexture(0, NULL);
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

		//grid.render();
		//cube_.render();
		//player.render();
		if (m_pGrid)
			m_pGrid->render();



		if (m_pRoute)
			m_pRoute->render();
		
		if (m_pCubeMan)
			m_pCubeMan->render();

		if (m_pRouteMan)
			m_pRouteMan->render();


		if (m_pShort)
			m_pShort->render();

		if (m_pShortCutMan)
			m_pShortCutMan->render();

		if (m_pCubeObj)
			m_pCubeObj->render();
		
		//if (m_pCubePC)
		//	m_pCubePC->render();

		//Draw_Texture();

		//if (m_PointLight)
		//	m_PointLight->render();

		//if (m_DirectionalLight)
		//	m_DirectionalLight->render();

		//if (m_SpotLight)
		//	m_SpotLight->render();

		Obj_Render();
		
		g_pD3DDevice->EndScene();

		g_pD3DDevice->Present(0, 0, 0, 0);
	}
}


void cMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//camera.WndProc(hWnd, message, wParam, lParam);
	if (m_pCamera)
		m_pCamera->WndProc(hWnd, message, wParam, lParam);
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

void cMainGame::Set_Light()
{
	//m_PointLight = new cPointLight;
	//m_PointLight->setup();

	m_DirectionalLight = new cDirectionalLight;
	m_DirectionalLight->setup();

	//m_SpotLight = new cSpotLight;
	//m_SpotLight->setup();
}

void cMainGame::Setup_Obj()
{
	cObjectLoader l;
	l.Load(m_vecGroup, "data/obj", "map.obj");
	l.Load(m_vecGroupSurf, "data/obj", "map_surface.obj");
}

void cMainGame::Obj_Render()
{
	D3DXMATRIXA16 matWorld, matS, matR;

	D3DXMatrixScaling(&matS, 0.01f, 0.01f, 0.01f);
	D3DXMatrixRotationX(&matR, -D3DX_PI / 2);

	matWorld = matS * matR;

	if(g_pD3DDevice)
	{
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
		for (auto * p : m_vecGroup)
		{
			p->render();
		}

		//for (auto* p : m_vecGroupSurf)
		//{
		//	p->render();
		//}
	}
}
