#include "stdafx.h"
#include "cMainGame.h"


#include "cAseLoader.h"
#include "cAseLoader2.h"
#include "cCamera2.h"
#include "cCubePC.h"
#include "cGrid2.h"
#include "cCubeMan.h"
#include "cCubeMan2.h"
#include "cCubeObj.h"
#include "cDirectionalLight.h"
#include "cFrame.h"
#include "cPointLight.h"
#include "cSpotLight.h"
#include "cObjectLoader.h"
#include "cGroup.h"
#include "cGroupNode.h"
#include "cObjMap.h"

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
	  m_pCubeObj(nullptr), m_pMap(nullptr), m_pRootFrame(nullptr), m_pFont(nullptr), m_pMeshTeapot(nullptr),
	  m_pMeshSphere(nullptr),
	  m_stMtlTeapot(), m_stMtlSphere(), m_pObjMesh(nullptr)
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

	SafeDelete(m_pMap);

	SafeRelease(m_pMeshTeapot);
	SafeRelease(m_pMeshSphere);
	SafeRelease(m_pObjMesh);

	for (auto * p : m_vecObjMtltex)
	{
		SafeRelease(p);
	}
	

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

	for (auto* p : m_vecGroupNode)
	{
		SafeRelease(p);
	}
	m_vecGroupNode.clear();

	m_pRootFrame->Destroy();

	for (auto* p : m_vecRootFrame)
	{
		p->Destroy();
	}
	m_vecRootFrame.clear();
	g_pObjectManager.Destroy();
	
	g_pDeviceManager.Destroy();
}

void cMainGame::setup()
{
	//setupLine();
	//setupTriangle();
	{
		//폰트 생성
		D3DXFONT_DESC fd;
		ZeroMemory(&fd, sizeof(D3DXFONT_DESC));
		fd.Height = 45;
		fd.Width = 28;
		fd.Weight = FW_MEDIUM;
		fd.Italic = false;
		fd.CharSet = DEFAULT_CHARSET;
		fd.OutputPrecision = OUT_DEFAULT_PRECIS;
		fd.PitchAndFamily = FF_DONTCARE;
		//strcpy_s(fd.FaceName, "궁서체");   //글꼴 스타일
		AddFontResource(L"umberto.ttf");
		wcscpy(fd.FaceName, L"umberto");

		D3DXCreateFontIndirect(g_pD3DDevice, &fd, &m_pFont);
	}
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
	

	Setup_Obj();
	//Load_Surface();
	Set_Light();

	{
		cAseLoader2 l;
		m_pRootFrame = l.Load("./woman/woman_01_all.ASE");

		//for (int i = 0; i < 100; ++i)
		//{
		//	m_vecRootFrame.push_back(l.Load("./woman/woman_01_all.ASE"));
		//}
	}

	Setup_MeshObject();
}

void cMainGame::update()
{
	RECT rc;
	GetClientRect(g_hWnd, &rc);

	m_FrameCounter.update();
	//cube.update();
	//player.update();
	//camera.update(cube);
	

	//if(m_pCubePC)
	//	m_pCubePC->update();
	if (m_pCubeMan)
		m_pCubeMan->update(m_pMap);
	
	if(m_pCamera)
		m_pCamera->update();

	//if (m_PointLight)
	//	m_PointLight->update();

	if (m_DirectionalLight)
		m_DirectionalLight->update();

	//if (m_SpotLight)
	//	m_SpotLight->update();

	if (m_pRouteMan)
		m_pRouteMan->update();

	if (m_pShortCutMan)
		m_pShortCutMan->update();

	if (m_pRootFrame)
		m_pRootFrame->update(m_pRootFrame->GetKeyFrame(), NULL);

	for (auto * p : m_vecRootFrame)
	{
		p->update(p->GetKeyFrame(), NULL);
	}

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

		if (m_pRootFrame)
			m_pRootFrame->render();

		if (m_pFont)
		{
			RECT rc;
			SetRect(&rc, 100, 100, 103, 103);
			char szTemp[1024];
			sprintf(szTemp, "FPS = %d", m_FrameCounter.GetFPS());
			m_pFont->DrawTextA(nullptr,
				szTemp,
				strlen(szTemp),
				&rc,
				DT_LEFT | DT_TOP | DT_NOCLIP,
				D3DCOLOR_XRGB(255, 0, 0));
		}

		for (auto * p : m_vecRootFrame)
		{
			p->render();
		}
		//if (m_pCubeObj)
		//	m_pCubeObj->render();
		
		//if (m_pCubePC)
		//	m_pCubePC->render();

		//Draw_Texture();

		//if (m_PointLight)
		//	m_PointLight->render();

		//if (m_DirectionalLight)
		//	m_DirectionalLight->render();

		//if (m_SpotLight)
		//	m_SpotLight->render();

		//Obj_Render();

		Mesh_Render();
		
		g_pD3DDevice->EndScene();

		g_pD3DDevice->Present(0, 0, 0, 0);
	}
}


void cMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (m_pCamera)
		m_pCamera->WndProc(hWnd, message, wParam, lParam);
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
	//l.Load(m_vecGroupSurf, "data/obj", "map_surface.obj");
	Load_Surface();

	cAseLoader al;
	al.Load(m_vecGroupNode, "data/woman", "woman_01_all.ASE");
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
		m_vecGroupNode[0]->render();
	}
}

void cMainGame::Load_Surface()
{
	D3DXMATRIXA16 matWorld, matS, matR;

	D3DXMatrixScaling(&matS, 0.01f, 0.01f, 0.01f);
	D3DXMatrixRotationX(&matR, -D3DX_PI / 2);

	matWorld = matS * matR;

	m_pMap = new cObjMap("data/obj", "map_surface.obj", &matWorld);
	
}

void cMainGame::Setup_MeshObject()
{
	D3DXCreateTeapot(g_pD3DDevice, &m_pMeshTeapot, NULL);
	D3DXCreateSphere(g_pD3DDevice, 0.5f, 10, 10, &m_pMeshSphere, NULL);

	ZeroMemory(&m_stMtlTeapot, sizeof D3DMATERIAL9);
	m_stMtlTeapot.Ambient  = D3DXCOLOR(0.0f, 0.7f, 0.7f, 1.0f);
	m_stMtlTeapot.Diffuse  = D3DXCOLOR(0.0f, 0.7f, 0.7f, 1.0f);
	m_stMtlTeapot.Specular = D3DXCOLOR(0.0f, 0.7f, 0.7f, 1.0f);

	ZeroMemory(&m_stMtlSphere, sizeof D3DMATERIAL9);
	m_stMtlSphere.Ambient  = D3DXCOLOR(0.7f, 0.7f, 0.0f, 1.0f);
	m_stMtlSphere.Diffuse  = D3DXCOLOR(0.7f, 0.7f, 0.0f, 1.0f);
	m_stMtlSphere.Specular = D3DXCOLOR(0.7f, 0.7f, 0.0f, 1.0f);

	cObjectLoader l;
	m_pObjMesh = l.LoadMesh(m_vecObjMtltex, "data/obj", "map.obj");
}

void cMainGame::Mesh_Render()
{
	D3DXMATRIXA16 matWorld, matS, matR;
	if(g_pD3DDevice)
	{
		g_pD3DDevice->SetTexture(0, NULL);
		D3DXMatrixIdentity(&matS);
		D3DXMatrixIdentity(&matR);
		matWorld = matS * matR;
		D3DXMatrixTranslation(&matWorld, 0, 0, 10);
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
		g_pD3DDevice->SetMaterial(&m_stMtlTeapot);
		m_pMeshTeapot->DrawSubset(0);


		D3DXMatrixTranslation(&matWorld, 10, 0, 0);
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
		g_pD3DDevice->SetMaterial(&m_stMtlSphere);
		m_pMeshSphere->DrawSubset(0);
	}

	//D3DXMATRIXA16 matWorld, matS, matR;

	D3DXMatrixScaling(&matS, 0.01f, 0.01f, 0.01f);
	D3DXMatrixRotationX(&matR, -D3DX_PI / 2);

	matWorld = matS * matR;

	if (g_pD3DDevice)
	{
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
		for (int i = 0; i < m_vecObjMtltex.size(); ++i)
		{
			g_pD3DDevice->SetMaterial(&m_vecObjMtltex[i]->GetMaterial());
			g_pD3DDevice->SetTexture(0, m_vecObjMtltex[i]->GetTexture());
			m_pObjMesh->DrawSubset(i);
		}
		
	}
}
