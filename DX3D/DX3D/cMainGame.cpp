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
#include "CFrustum.h"
#include "CFrustumCube.h"
#include "cPointLight.h"
#include "cSpotLight.h"
#include "cObjectLoader.h"
#include "cGroup.h"
#include "cGroupNode.h"
#include "CHeightMapLoader.h"
#include "COBB.h"
#include "cObjMap.h"
#include "CObj_X.h"
#include "CRay.h"
#include "CSkinnedMesh.h"
#include "cSphere.h"
#include "CZealot.h"


cMainGame::cMainGame()
	: m_pCubePC(nullptr)
	  , m_pCamera(nullptr)
	  , m_pGrid(nullptr), m_pCubeMan(nullptr), m_pTexture(nullptr), m_PointLight(nullptr), m_DirectionalLight(nullptr),
	  m_SpotLight(nullptr), m_pRoute(nullptr), m_pShort(nullptr), m_pRouteMan(nullptr), m_pShortCutMan(nullptr),
	  m_pCubeObj(nullptr), m_pMap(nullptr), m_pRootFrame(nullptr), m_pFont(nullptr), m_pMeshTeapot(nullptr),
	  m_pMeshSphere(nullptr),
	  m_stMtlTeapot({}), m_stMtlSphere({}), m_pObjMesh(nullptr), m_pcRay(nullptr), m_pFieldMap(nullptr),
	  m_pObj_X(nullptr), m_pSkinnedMesh(nullptr), m_pFrustumCube(nullptr), m_pSphere(nullptr), m_stCullingMtl({}),
	  m_pFrustum(nullptr), m_pHoldZealot(nullptr), m_pMoveZealot(nullptr), m_pFont2(nullptr), m_p3DText(nullptr)
/*, m_stMtlNone({}), m_stMtlPicked({}),
	  m_stMtlPlane({})*/
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
	SafeDelete(m_pFieldMap);

	SafeRelease(m_pFont);
	SafeRelease(m_pFont2);
	SafeRelease(m_p3DText);

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

	if(m_pRootFrame)
		m_pRootFrame->Destroy();

	for (auto* p : m_vecRootFrame)
	{
		p->Destroy();
	}
	m_vecRootFrame.clear();

	for (auto * p : m_vecSphere)
	{
		SafeDelete(p);
	}
	SafeDelete(m_pcRay);

	SafeDelete(m_pObj_X);

	SafeDelete(m_pSkinnedMesh);

	SafeDelete(m_pFrustumCube);
	SafeDelete(m_pFrustum);
	SafeRelease (m_pSphere);


	SafeDelete(m_pHoldZealot);
	SafeDelete(m_pMoveZealot);

	g_pFontManager.Destroy();
	
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
	//m_pCubePC = new cCubePC;
	//m_pCubePC->setup();

	{
		CHeightMapLoader l;
		l.readRawFile("data/HeightMapData/HeightMap.raw", "data/HeightMapData/terrain.jpg");
		m_pFieldMap = l.createMap();
	}
	
	
	m_pCubeMan = new cCubeMan;
	m_pCubeMan->setup();

	m_pCamera = new cCamera2;
	m_pCamera->setup(&m_pCubeMan->getPosition());

	m_pGrid = new cGrid2;
	m_pGrid->setup(15, 1);

	//SetupFrustum();
	//m_pRoute = new cGuideline;
	//m_pRoute->setup(D3DCOLOR_XRGB(0, 255, 0));

	//m_pRouteMan = new cCubeMan2;
	//m_pRouteMan->setup();
	//m_pRouteMan->setGuide(m_pRoute->getRouteNode());

	//m_pShort = new cGuideline;
	//m_pShort->setup(D3DCOLOR_XRGB(255, 0, 0));
	//m_pShort->Interpolation(30);

	//m_pShortCutMan = new cCubeMan2;
	//m_pShortCutMan->setup();
	//m_pShortCutMan->setGuide(m_pShort->getShortCut());

	//m_pCubeObj = new cCubeObj;
	//m_pCubeObj->setup();
	

	SetupOBB();

	CreateFontW();
	//Setup_Obj();
	//Load_Surface();
	Set_Light();

	//SetupPeakingObj();
	//{
	//	cAseLoader2 l;
	//	m_pRootFrame = l.Load("./woman/woman_01_all.ASE");

	//	//for (int i = 0; i < 100; ++i)
	//	//{
	//	//	m_vecRootFrame.push_back(l.Load("./woman/woman_01_all.ASE"));
	//	//}
	//}
	
	//m_pObj_X = new CObj_X;
	//m_pObj_X->open("zealot.X", "data/Zealot");
	//m_pObj_X->open("bigship1.x", "data");

	//m_pSkinnedMesh = new CSkinnedMesh;
	//m_pSkinnedMesh->setup("data/Zealot", "zealot.X");
	
	//m_pFrustumCube = new CFrustumCube;
	

	
	//Setup_MeshObject();
}

void cMainGame::update()
{
	RECT rc;
	GetClientRect(g_hWnd, &rc);
	g_pTimeManager.update();
	
	m_FrameCounter.update();
	//cube.update();
	//player.update();
	//camera.update(cube);
	
	//if(m_pCubePC)
	//	m_pCubePC->update();
	if (m_pCubeMan)
		m_pCubeMan->update(m_pFieldMap);
	
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

	if (m_pHoldZealot)
		m_pHoldZealot->Update(m_pMap);

	if (m_pMoveZealot)
		m_pMoveZealot->Update(m_pMap);

	for (auto * p : m_vecRootFrame)
	{
		p->update(p->GetKeyFrame(), NULL);
	}

	
	if (m_pSkinnedMesh)
		m_pSkinnedMesh->update();

	if (m_pFrustum)
		m_pFrustum->Update();
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

		RenderPeakingObj();

		if (m_pFieldMap)
			m_pFieldMap->render();

		if (m_pObj_X)
			m_pObj_X->render();
		
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
		if(m_pMeshTeapot)
			Mesh_Render();

		if (m_pFrustumCube)
			m_pFrustumCube->render();

		TextRender();
		SkinnedMesh_Render();

		FrustumRender();

		OBBRender();
		
		g_pD3DDevice->EndScene();

		g_pD3DDevice->Present(0, 0, 0, 0);
	}
}


void cMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (m_pCamera)
		m_pCamera->WndProc(hWnd, message, wParam, lParam);
	switch (message)
	{
	case WM_LBUTTONDOWN:
		if(m_pcRay)
		{
			if (cSphere* target = m_pcRay->getLeftClickCheck(LOWORD(lParam), HIWORD(lParam)))
				target->FlipColor();
		}

		if(m_pSkinnedMesh)
		{
			static int n = 0;
			m_pSkinnedMesh->SetAnimationIndexBlend(n++ % 3);
		}

		if (m_pFrustumCube)
			m_pFrustumCube->culling();

		if (m_pFieldMap)
			m_pFieldMap->setCulling();

		if(m_pFrustum)
		{
			for (int i = 0; i < m_vecCullingSphere.size(); ++i)
			{
				if (m_pFrustum->IsIn(m_vecCullingSphere[i]))
					m_vecCullingSphere[i]->FlipColor();
				
			}
		}
		break;
	case WM_RBUTTONDOWN:
		{
			if(m_pcRay)
			{
				D3DXVECTOR3 vTemp;
				if (m_pcRay->getRightClickCheck(LOWORD(lParam), HIWORD(lParam), vTemp))
					m_vecSphere[0]->setPosition(vTemp);
			}

			

		}
	case WM_KEYDOWN:
		{
			if(m_pSkinnedMesh)
			{
				static int n = 0;
				m_pSkinnedMesh->SetAnimationIndexBlend(3);
				break;
			}
			
		}
	}
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

void cMainGame::SetupPeakingObj()
{
	cSphere* p = new cSphere(0, 0, 0);
	m_vecSphere.emplace_back(p);
	
	for (int i = 1; i < 5; ++i)
	{
		p = new cSphere(i * 3, 0, 0);
		m_vecSphere.emplace_back(p);
		p = new cSphere(i * -3, 0, 0);
		m_vecSphere.emplace_back(p);
	}

	m_pcRay = new CRay;
	m_pcRay->setup(&m_vecSphere, m_pGrid);
}

void cMainGame::RenderPeakingObj()
{
	for (auto * p : m_vecSphere)
	{
		p->render();
	}
	if(m_pcRay)
		m_pcRay->render();
}

void cMainGame::SkinnedMesh_Render()
{
	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	if (m_pSkinnedMesh)
		m_pSkinnedMesh->render(NULL);
}

void cMainGame::SetupFrustum()
{
	D3DXCreateSphere(g_pD3DDevice, 0.5f, 10, 10, &m_pSphere, nullptr);

	for (int i = -20; i <= 20; ++i)
	{
		for (int j = -20; j <= 20; ++j)
		{
			for (int k = -20; k <= 20; ++k)
			{
				cSphere* s = new cSphere(i,j,k);
				m_vecCullingSphere.emplace_back(s);
			}
		}
	}

	m_stCullingMtl.Ambient  = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	m_stCullingMtl.Diffuse  = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	m_stCullingMtl.Specular = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);

	m_pFrustum = new CFrustum;
	m_pFrustum->Setup();
}

void cMainGame::FrustumRender()
{
	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

	for (auto && sphere : m_vecCullingSphere)
	{
		//D3DXMatrixIdentity(&matWorld);
		//matWorld._41 = sphere->getPosition().x;
		//matWorld._42 = sphere->getPosition().y;
		//matWorld._43 = sphere->getPosition().z;
		//g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
		//g_pD3DDevice->SetMaterial(&m_stCullingMtl);
		sphere->render();
		
	}
}

void cMainGame::SetupOBB()
{
	m_pHoldZealot = new CZealot;
	m_pHoldZealot->Setup();
	
	m_pMoveZealot = new CZealot;
	m_pMoveZealot->Setup();

	cCharacter* pCharacter = new cCharacter;
	m_pMoveZealot->SetCharacterController(pCharacter);
	SafeRelease(pCharacter);
}

void cMainGame::OBBRender()
{
	D3DCOLOR c = COBB::IsCollision(m_pHoldZealot->GetOBB(), m_pMoveZealot->GetOBB()) ? D3DCOLOR_XRGB(255, 0, 0) : D3DCOLOR_XRGB(255, 255, 255);

	if (m_pHoldZealot)
		m_pHoldZealot->Render(c);
	if (m_pMoveZealot)
		m_pMoveZealot->Render(c);
}

void cMainGame::CreateFontW()
{
	D3DXFONT_DESC fd{};
	fd.Height = 50;
	fd.Width = 25;
	fd.Weight = FW_MEDIUM;
	fd.Italic = false;
	fd.CharSet = DEFAULT_CHARSET;
	fd.OutputPrecision = OUT_DEFAULT_PRECIS;
	fd.PitchAndFamily = FF_DONTCARE;

	//wcscpy_s(fd.FaceName, L"굴림체");
	AddFontResource(L"data/font/umberto.ttf");
	wcscpy_s(fd.FaceName, L"Umberto");

	

	D3DXCreateFontIndirect(g_pD3DDevice, &fd, &m_pFont2);



	HDC hdc = CreateCompatibleDC(0);
	LOGFONT lf{};
	lf.lfHeight = 25;
	lf.lfWidth = 12;
	lf.lfWeight = 500;
	lf.lfItalic = false;
	lf.lfUnderline = false;
	lf.lfStrikeOut = false;
	lf.lfCharSet = DEFAULT_CHARSET;

	wcscpy_s(lf.lfFaceName, L"Umberto");

	HFONT hFont;
	HFONT hOldFont;

	hFont = CreateFontIndirect(&lf);
	hOldFont = (HFONT)SelectObject(hdc, hFont);
	D3DXCreateText(g_pD3DDevice, hdc, L"Direct3D", 0.001f, 0.01f, &m_p3DText, 0, 0);

	SelectObject(hdc, hOldFont);
	DeleteObject(hFont);
	DeleteDC(hdc);
}

void cMainGame::TextRender()
{
	string sText("ABC abc 123 !@#$ 가나다라 ㅁㄴㅇㄹ");
	RECT rc;
	SetRect(&rc, 100, 100, 301, 200);

	LPD3DXFONT pFont = g_pFontManager.GetFont(CFontManager::E_DEFAULT);
	
	pFont->DrawTextA
	(
		nullptr, 
		sText.c_str(), 
		sText.size(), 
		&rc, 
		DT_LEFT | DT_TOP | DT_NOCLIP, 
		D3DCOLOR_XRGB(255, 255, 0)
	);


	D3DXMATRIXA16 matWorld, matS, matR, matT;
	D3DXMatrixScaling(&matS, 1.0f, 1.0f, 5.0f);
	D3DXMatrixRotationX(&matR, -D3DX_PI * 0.25f);
	D3DXMatrixTranslation(&matT, -2.0f, 1.0f, 0.0f);
	matWorld = matS * matR * matT;

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	m_p3DText->DrawSubset(0);
	
}

//
//void cMainGame::Setup_MeshObjectT()
//{
//}
//
//void cMainGame::Mesh_RenderT()
//{
//}
//
//void cMainGame::Setup_PickingObj()
//{
//	for (int i = 0; i <= 10; ++i)
//	{
//		ST_SPHERE s;
//		s.fRaidus = 0.5f;
//		s.vCenter = D3DXVECTOR3(0, 0, -10 + 2 * i);
//		m_vecSphereT.push_back(s);
//	}
//
//	m_stMtlNone.Ambient  = D3DXCOLOR(0.7f, 0.7f, 0.0f, 1.0f);
//	m_stMtlNone.Diffuse  = D3DXCOLOR(0.7f, 0.7f, 0.0f, 1.0f);
//	m_stMtlNone.Specular = D3DXCOLOR(0.7f, 0.7f, 0.0f, 1.0f);
//
//	m_stMtlPicked.Ambient  = D3DXCOLOR(0.7f, 0.0f, 0.0f, 1.0f);
//	m_stMtlPicked.Diffuse  = D3DXCOLOR(0.7f, 0.0f, 0.0f, 1.0f);
//	m_stMtlPicked.Specular = D3DXCOLOR(0.7f, 0.0f, 0.0f, 1.0f);
//
//	m_stMtlPlane.Ambient  = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
//	m_stMtlPlane.Diffuse  = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
//	m_stMtlPlane.Specular = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
//
//	ST_PN_VERTEX v;
//	v.n = D3DXVECTOR3(0, 1, 0);
//	v.p = D3DXVECTOR3(-10, 0, -10); m_vecPlaneVertex.push_back(v);
//	v.p = D3DXVECTOR3(-10, 0,  10); m_vecPlaneVertex.push_back(v);
//	v.p = D3DXVECTOR3( 10, 0,  10); m_vecPlaneVertex.push_back(v);
//
//	v.p = D3DXVECTOR3(-10, 0, -10); m_vecPlaneVertex.push_back(v);
//	v.p = D3DXVECTOR3( 10, 0,  10); m_vecPlaneVertex.push_back(v);
//	v.p = D3DXVECTOR3( 10, 0, -10); m_vecPlaneVertex.push_back(v);
//}
//
//void cMainGame::PickingObj_Render()
//{
//	D3DXMATRIXA16 matWorld;
//	g_pD3DDevice->SetFVF(ST_PN_VERTEX::FVF);
//	g_pD3DDevice->SetMaterial(&m_stMtlPlane);
//	D3DXMatrixIdentity(&matWorld);
//
//	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
//	g_pD3DDevice->SetTexture(0, 0);
//	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 2, &m_vecPlaneVertex[0], sizeof ST_PN_VERTEX);
//
//	for (int i = 0; i < m_vecSphereT.size(); ++i)
//	{
//		D3DXMatrixIdentity(&matWorld);
//		matWorld._41 = m_vecSphereT[i].vCenter.x;
//		matWorld._42 = m_vecSphereT[i].vCenter.y;
//		matWorld._43 = m_vecSphereT[i].vCenter.z;
//		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
//		g_pD3DDevice->SetMaterial(m_vecSphereT[i].isPicked ? &m_stMtlPicked : &m_stMtlNone);
//		m_pMeshSphere->DrawSubset(0);
//
//		g_pD3DDevice->SetMaterial(&m_stMtlNone);
//		D3DXMatrixTranslation(&matWorld,
//			m_vPickedPosition.x,
//			m_vPickedPosition.y,
//			m_vPickedPosition.z);
//
//		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
//		m_pMeshSphere->DrawSubset(0);
//	}
//}
