#include "stdafx.h"
#include "cMainGame.h"

#include <array>



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
#include "CGimbalTest.h"
#include "cPointLight.h"
#include "cSpotLight.h"
#include "cObjectLoader.h"
#include "cGroup.h"
#include "cGroupNode.h"
#include "CHeightMapLoader.h"
#include "CMainUI.h"
#include "COBB.h"
#include "cObjMap.h"
#include "CObj_X.h"
#include "CRay.h"
#include "CSkinnedMesh.h"
#include "cSphere.h"
#include "CZealot.h"

inline DWORD FtoDW(float f)
{
	return *((DWORD*)&f);
}
cMainGame::cMainGame() :
	m_pCubePC(nullptr),
	m_pCamera(nullptr),
	m_pGrid(nullptr),
	m_pCubeMan(nullptr),
	m_pTexture(nullptr),
	m_PointLight(nullptr),
	m_DirectionalLight(nullptr),
	m_SpotLight(nullptr),
	m_pRoute(nullptr),
	m_pShort(nullptr),
	m_pRouteMan(nullptr),
	m_pShortCutMan(nullptr),
	m_pCubeObj(nullptr),
	m_pMap(nullptr),
	m_pRootFrame(nullptr),
	m_pFont(nullptr),
	m_pMeshTeapot(nullptr),
	m_pMeshSphere(nullptr),
	m_stMtlTeapot({}),
	m_stMtlSphere({}),
	m_pObjMesh(nullptr),
	m_pcRay(nullptr),
	m_pFieldMap(nullptr),
	m_pObj_X(nullptr),
	m_pSkinnedMesh(nullptr),
	m_pShader(nullptr),
	m_pShaderTexture(nullptr),
	m_pSpecularTexture(nullptr),
	m_pFrustumCube(nullptr),
	m_pSphere(nullptr),
	m_stCullingMtl({}),
	m_pFrustum(nullptr),
	m_pHoldZealot(nullptr),
	m_pMoveZealot(nullptr),
	m_pFont2(nullptr),
	m_p3DText(nullptr),
	m_pSprite(nullptr),
	m_stImageInfo({}),
	m_pTextureUI(nullptr),
	m_pMainUI(nullptr),
	m_pTex0(nullptr),
	m_pTex1(nullptr),
	m_pTex2(nullptr),
	m_pTex3(nullptr),
	m_nType(-1),
	m_pDiffuseMap1(nullptr),
	m_pDiffuseMap2(nullptr),
	m_pAlphaMap(nullptr),
	m_pGimbalTest(nullptr)
/*, m_stMtlNone({}), m_stMtlPicked({}),
	  m_stMtlPlane({})*/
//, player()
{
}

cMainGame::~cMainGame()
{
	SafeDelete(m_pGimbalTest);
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

	SafeRelease(m_pShader);
	for (auto * p : m_vecObjMtltex)
	{
		SafeRelease(p);
	}

	for (auto * x : m_vecX)
	{
		SafeDelete(x);
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
	SafeRelease(m_pShaderTexture);
	SafeRelease(m_pSpecularTexture);

	SafeDelete(m_pFrustumCube);
	SafeDelete(m_pFrustum);
	SafeRelease (m_pSphere);


	SafeDelete(m_pHoldZealot);
	SafeDelete(m_pMoveZealot);

	SafeRelease(m_pSprite);
	SafeRelease(m_pTextureUI);
	SafeDelete(m_pMainUI);

	SafeRelease(m_pTex0);
	SafeRelease(m_pTex1);
	SafeRelease(m_pTex2);
	SafeRelease(m_pTex3);

	SafeRelease(m_pDiffuseMap1);
	SafeRelease(m_pDiffuseMap2);
	SafeRelease(m_pAlphaMap);
	
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

	//{
	//	CHeightMapLoader l;
	//	l.readRawFile("data/HeightMapData/HeightMap.raw", "data/HeightMapData/terrain.jpg");
	//	m_pFieldMap = l.createMap();
	//}
	
	
	//m_pCubeMan = new cCubeMan;
	//m_pCubeMan->setup();

	m_pCamera = new cCamera2;
	m_pCamera->setup(nullptr);

	m_pGrid = new cGrid2;
	m_pGrid->setup(15, 1);

	//m_pGimbalTest = new CGimbalTest;
	
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

	//m_pMainUI = new CMainUI;

	//SetupOBB();

	SetupMultiTexture();
	//CreateFontW();
	//Setup_Obj();
	//Load_Surface();
	//SetupParticle();
	Set_Light();
	//SetupFog();

	//SetupUI();
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
	//m_pObj_X->open("gear1.x", "data/model");

	CObj_X* p;
	//p = new CObj_X; p->open("gear1.x", "data/model", 0.1); m_vecX.push_back(p);
	//p = new CObj_X; p->open("gear2.x", "data/model", 0.1); m_vecX.push_back(p);
	//p = new CObj_X; p->open("bearing.x", "data/model", 0.5); m_vecX.push_back(p);
	//p = new CObj_X; p->open("IronPlan.x", "data/model", 0.5); m_vecX.push_back(p);
	//p = new CObj_X; p->open("1.x", "data/model", 0.5); m_vecX.push_back(p);
	//p = new CObj_X; p->open("2.x", "data/model", 0.5); m_vecX.push_back(p);
	//p = new CObj_X; p->open("3.x", "data/model", 0.5); m_vecX.push_back(p);
	//p = new CObj_X; p->open("MixMch1.x", "data/model", 0.01); m_vecX.push_back(p);
	//p = new CObj_X; p->open("MixMch2.x", "data/model", 0.01); m_vecX.push_back(p);
	
	//p = new CObj_X; p->open("모래돌_벽_타일.x"				, "data/model/타일", 0.01); m_vecX.push_back(p);
	//p = new CObj_X; p->open("모래돌_체크타일.x"				, "data/model/타일", 0.01); m_vecX.push_back(p);
	//p = new CObj_X; p->open("모래돌_타일_계단 일반.x"		, "data/model/타일", 0.01); m_vecX.push_back(p);
	//p = new CObj_X; p->open("모래돌타일.x"					, "data/model/타일", 0.01); m_vecX.push_back(p);
	//p = new CObj_X; p->open("모래돌타일1.x"					, "data/model/타일", 0.01); m_vecX.push_back(p);
	//p = new CObj_X; p->open("모래타일1.x"					, "data/model/타일", 0.01); m_vecX.push_back(p);
	//p = new CObj_X; p->open("모래타일2.x"					, "data/model/타일", 0.0021); m_vecX.push_back(p);
	//p = new CObj_X; p->open("모래타일3.x"					, "data/model/타일", 0.01); m_vecX.push_back(p);
	//p = new CObj_X; p->open("물타일.x"						, "data/model/타일", 0.01); m_vecX.push_back(p);


	//p = new CObj_X; p->open("야자수몸통.x"				, "data/model/타일/장식용", 0.01); m_vecX.push_back(p);
	//p = new CObj_X; p->open("조약돌2.x"					, "data/model/타일/장식용", 0.01); m_vecX.push_back(p);
	//p = new CObj_X; p->open("조약돌3.x"					, "data/model/타일/장식용", 0.01); m_vecX.push_back(p);

	//p = new CObj_X; p->open("모래더미.x"					, "data/model/오브젝트", 0.01); m_vecX.push_back(p);
	//p = new CObj_X; p->open("모래돌_더미.x"					, "data/model/오브젝트", 0.01); m_vecX.push_back(p);
	//p = new CObj_X; p->open("선인장1.x"						, "data/model/오브젝트", 0.01); m_vecX.push_back(p);
	//p = new CObj_X; p->open("선인장2.x"						, "data/model/오브젝트", 0.01); m_vecX.push_back(p);
	//p = new CObj_X; p->open("야자수1.x"						, "data/model/오브젝트", 0.01); m_vecX.push_back(p);
	//p = new CObj_X; p->open("야자수2.x"						, "data/model/오브젝트", 0.01); m_vecX.push_back(p);
	//p = new CObj_X; p->open("파라오관.x"					, "data/model/오브젝트", 0.01); m_vecX.push_back(p);


	//p = new CObj_X; p->open("돌 항아리.x"						, "data/model/오브젝트/장식용", 0.01); m_vecX.push_back(p);
	//p = new CObj_X; p->open("모래 기둥.x"						, "data/model/오브젝트/장식용", 0.01); m_vecX.push_back(p);
	//p = new CObj_X; p->open("모래_윗부분.x"						, "data/model/오브젝트/장식용", 0.01); m_vecX.push_back(p);
	//p = new CObj_X; p->open("모래기둥_꺽임.x"					, "data/model/오브젝트/장식용", 0.01); m_vecX.push_back(p);
	//p = new CObj_X; p->open("모래돌 버튼.x"						, "data/model/오브젝트/장식용", 0.01); m_vecX.push_back(p);
	//p = new CObj_X; p->open("모래돌 탁자.x"						, "data/model/오브젝트/장식용", 0.01); m_vecX.push_back(p);
	//p = new CObj_X; p->open("모래돌_원기둥.x"					, "data/model/오브젝트/장식용", 0.01); m_vecX.push_back(p);
	//p = new CObj_X; p->open("모래돌_하수구4방향.x"				, "data/model/오브젝트/장식용", 0.01); m_vecX.push_back(p);
	//p = new CObj_X; p->open("모래타일위.x"						, "data/model/오브젝트/장식용", 0.01); m_vecX.push_back(p);
	//p = new CObj_X; p->open("사막왕좌.x"						, "data/model/오브젝트/장식용", 0.01); m_vecX.push_back(p);
	//p = new CObj_X; p->open("황금선반.x"						, "data/model/오브젝트/장식용", 0.01); m_vecX.push_back(p);


	//p = new CObj_X; p->open("1단계 조합기 버튼 스위치.x"				, "data/model", 0.01); m_vecX.push_back(p);
	//p = new CObj_X; p->open("2단계 조합기 버튼 스위치.x"				, "data/model", 0.01); m_vecX.push_back(p);
	//p = new CObj_X; p->open("부품 자판기 스위치.x"						, "data/model", 0.01); m_vecX.push_back(p);
	//p = new CObj_X; p->open("testBox.X"						, "data/model", 0.012); m_vecX.push_back(p);

	//p = new CObj_X; p->open("arm_left.X"						, "data/model", 0.03); m_vecX.push_back(p);
	//p = new CObj_X; p->open("arm_right.x"						, "data/model", 0.075); m_vecX.push_back(p);
	//p = new CObj_X; p->open("body.x"							, "data/model", 0.12); m_vecX.push_back(p);
	//p = new CObj_X; p->open("leg1.X"							, "data/model", 0.04); m_vecX.push_back(p);
	//p = new CObj_X; p->open("leg2.X"							, "data/model", 0.04); m_vecX.push_back(p);
	//p = new CObj_X; p->open("leg3.x"							, "data/model", 0.04); m_vecX.push_back(p);
	//p = new CObj_X; p->open("영웅의증표.x"						, "data/model", 0.05); m_vecX.push_back(p);
	//p = new CObj_X; p->open("최후의 수단.X"						, "data/model", 0.012); m_vecX.push_back(p);

	//p = new CObj_X; p->open("모래타일3_1.x"					, "data/model/타일", 10); m_vecX.push_back(p);
	//p = new CObj_X; p->open("굵은 모래 바닥.x"				, "data/model/타일", 0.021); m_vecX.push_back(p);
	//p = new CObj_X; p->open("tornado.x"						, "data/model", 0.1); m_vecX.push_back(p);
	p = new CObj_X; p->open("medusa_skill_3.X"				, "data/model", 0.1); m_vecX.push_back(p);
	
	//m_pSkinnedMesh = new CSkinnedMesh;
	//m_pSkinnedMesh->setup("data/Zealot", "zealot.X");
	//m_pSkinnedMesh = new CSkinnedMesh("data/Zealot", "MTA_CV.X");
	//m_pSkinnedMesh->setup("data/Zealot", "MTA_CV.X");

	//LoadAsset();
	
	
	//m_pFrustumCube = new CFrustumCube;
	

	
	//Setup_MeshObject();
}

void cMainGame::update()
{
	RECT rc;
	GetClientRect(g_hWnd, &rc);
	
	
	m_FrameCounter.update();
	//cube.update();
	//player.update();
	//camera.update(cube);
	
	if(m_pCubePC)
		m_pCubePC->update();
	
	if (m_pCubeMan)
		m_pCubeMan->update(m_pFieldMap);
	
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
	UpdateMultiTexture();
	UpdateParticle();

	g_pTimeManager.update();
	if (m_pSkinnedMesh)
		m_pSkinnedMesh->Update();

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

		if (m_pMainUI)
			m_pMainUI->Render();
		//if (m_pCubeObj)
		//	m_pCubeObj->render();
		
		if (m_pCubePC)
			m_pCubePC->render();

		RenderX();
		
		//Draw_Texture();

		//if (m_PointLight)
		//	m_PointLight->render();
		
		//if (m_DirectionalLight)
		//	m_DirectionalLight->render();

		//if (m_SpotLight)
		//	m_SpotLight->render();

		//Obj_Render();
		//MultiTextureRender();

		if (m_pGimbalTest)
			m_pGimbalTest->Render();
		
		MultiTextureRender99();
		
		ParticleRender();

		if(m_pMeshTeapot)
			Mesh_Render();

		if (m_pFrustumCube)
			m_pFrustumCube->render();

		TextRender();
		SkinnedMesh_Render();

		FrustumRender();

		OBBRender();

		UIRender();
		g_pD3DDevice->EndScene();

		g_pD3DDevice->Present(0, 0, 0, 0);
	}
}


void cMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (m_pCamera)
		m_pCamera->WndProc(hWnd, message, wParam, lParam);
	if (m_pMainUI)
		m_pMainUI->WndProc(hWnd, message, wParam, lParam);
	if (m_pGimbalTest)
		m_pGimbalTest->WndProc(hWnd, message, wParam, lParam);
	
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
	case WM_MOUSEMOVE:

		break;
	case WM_LBUTTONUP:

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
	m_PointLight = new cPointLight;
	m_PointLight->setup();

	m_DirectionalLight = new cDirectionalLight;
	m_DirectionalLight->setup();

	m_SpotLight = new cSpotLight;
	m_SpotLight->setup();
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

	if(m_pShader)
	{
		D3DXMATRIXA16 matView, matProjection;
		g_pD3DDevice->GetTransform(D3DTS_VIEW, &matView);
		g_pD3DDevice->GetTransform(D3DTS_PROJECTION, &matProjection);
		
		m_pShader->SetMatrix("gWorldMatrix", &matWorld);
		m_pShader->SetMatrix("gViewMatrix", &matView);
		m_pShader->SetMatrix("gProjectionMatrix", &matProjection);
		//m_pShader->SetValue("gColor", &D3DXVECTOR4(0.9686f, 0.4078f, 0.3961f, 1.0f), sizeof D3DXVECTOR4);

		D3DXCOLOR	color(1, 1, 1, 1);
		m_pShader->SetValue("gColor", &color, sizeof color);
		m_pShader->SetTexture("DiffuseMap_Tex", m_pShaderTexture);
		m_pShader->SetVector("gLightColor", &D3DXVECTOR4(0.7,0.7,0.7,1));

		static D3DXVECTOR4 vLightPos(0, 20, 0, 1);
		static float RotZ = 0.1f;
		D3DXMATRIXA16 matRotZ;
		D3DXMatrixRotationZ(&matRotZ, RotZ);
		D3DXVec4Transform(&vLightPos, &vLightPos, &matRotZ);
		
		m_pShader->SetVector("gWorldLightPosition", &vLightPos);
		//m_pShader->SetTexture("DiffuseMap_Tex", "filename");
		m_pShader->SetTexture("SpecularMap_Tex", m_pSpecularTexture);

		UINT	numPasses = 0;
		m_pShader->Begin(&numPasses, NULL);
		{
			for (UINT i = 0; i < numPasses; ++i)
			{
				m_pShader->BeginPass(i);
				if (m_pSkinnedMesh)
					m_pSkinnedMesh->render(NULL);
				m_pShader->EndPass();
			}
		}
		m_pShader->End();
	}
	else
	{
		if (m_pSkinnedMesh)
			m_pSkinnedMesh->render(NULL);
	}
}

bool cMainGame::LoadAsset()
{
	m_pShader = LoadShader("data/shader/Splatting.fx");
	if (!m_pShader) return false;
	m_pShaderTexture = LoadTexture("data/Zealot/Zealot_Diffuse.bmp");
	if (!m_pShaderTexture) return false;
	m_pSpecularTexture = LoadTexture("data/Zealot/white.png");
	if (!m_pSpecularTexture) return false;
	return true;
}

LPD3DXEFFECT cMainGame::LoadShader(const char* szFilename)
{
	LPD3DXEFFECT ret = NULL;

	LPD3DXBUFFER pError = NULL;
	DWORD dwShaderFlags = 0;

#if _DEBUG
	dwShaderFlags |= D3DXSHADER_DEBUG;
#endif

	D3DXCreateEffectFromFileA(g_pD3DDevice, szFilename,
		NULL, NULL, dwShaderFlags, NULL, &ret, &pError);

	// 쉐이더 로딩에 실패한 경우 output창에 쉐이더
	// 컴파일 에러를 출력한다.
	if (!ret && pError)
	{
		int size = pError->GetBufferSize();
		void *ack = pError->GetBufferPointer();

		if (ack)
		{
			char* str = new char[size];
			sprintf(str, (const char*)ack, size);
			OutputDebugStringA(str);
			delete[] str;
		}
	}

	return ret;
}

LPDIRECT3DTEXTURE9 cMainGame::LoadTexture(const char* szFilename)
{
	LPDIRECT3DTEXTURE9 ret = NULL;
	if (FAILED(D3DXCreateTextureFromFileA(g_pD3DDevice, szFilename, &ret)))
	{
		OutputDebugStringA("텍스처 로딩 실패: ");
		OutputDebugStringA(szFilename);
		OutputDebugStringA("\n");
	}

		return ret;
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
	if (!m_pHoldZealot)
		return;
	
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
	if (m_p3DText == nullptr)
		return;
	
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

void cMainGame::SetupUI()
{
	D3DXCreateSprite(g_pD3DDevice, &m_pSprite);

	//m_pTextureUI = g_pTextureManager.GetTexture("data/UI/수지.png");
	//m_pTextureUI = g_pTextureManager.GetTexture("data/UI/김태희.jpg");

	D3DXCreateTextureFromFileEx
	(
		g_pD3DDevice,
		L"data/UI/김태희.jpg",
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_DEFAULT,
		0,
		&m_stImageInfo,
		nullptr,
		&m_pTextureUI

	);
}

void cMainGame::UIRender()
{
	if (m_pSprite == nullptr)
		return;
	
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);

	RECT rc;
	SetRect(&rc, m_stImageInfo.Width * 0.25f, 0, m_stImageInfo.Width * 0.75f, m_stImageInfo.Height);

	D3DXMATRIXA16 matT, matS, matR, matWorld;
	D3DXMatrixIdentity(&matR);
	D3DXMatrixTranslation(&matT, 100, 100, 0);
	static float fAngle = 0.0f;
	fAngle += 0.001f;
	//D3DXMatrixRotationY(&matR, fAngle);
	matWorld = matR * matT;

	m_pSprite->SetTransform(&matWorld);
	
	m_pSprite->Draw(m_pTextureUI, &rc, &D3DXVECTOR3(0, 0, 0), &D3DXVECTOR3(0, 0, 0), D3DCOLOR_ARGB(255, 255, 255, 255));

	m_pSprite->End();
}

void cMainGame::SetupParticle()
{
	m_vecVertexParticle.resize(1000);
	for (int i = 0; i < m_vecVertexParticle.size(); ++i)
	{
		float fRadius = rand() % 100 * 0.1f;
		fRadius = 50.f;

		m_vecVertexParticle[i].p = D3DXVECTOR3(0, 0, fRadius);
		D3DXVECTOR3	vAngle = D3DXVECTOR3(
			D3DXToRadian(rand() % 3600 * 0.1f), 
			D3DXToRadian(rand() % 3600 * 0.1f), 
			D3DXToRadian(rand() % 3600 * 0.1f));

		D3DXMATRIX matRx, matRy, matRz, matWorld;

		D3DXMatrixRotationX(&matRx, vAngle.x);
		D3DXMatrixRotationY(&matRy, vAngle.y);
		D3DXMatrixRotationZ(&matRz, vAngle.z);
		matWorld = matRx * matRy * matRz;

		D3DXVec3TransformCoord(&m_vecVertexParticle[i].p, &m_vecVertexParticle[i].p, &matWorld);
		m_vecVertexParticle[i].c = D3DCOLOR_ARGB(255, 180, 70, 20);
	}
}

void cMainGame::UpdateParticle()
{
	static int nAlpha = 0;
	static int nDelta = 4;
	nAlpha += nDelta;

	if(nAlpha > 255)
	{
		nAlpha = 255;
		nDelta *= -1;
	}
	if(nAlpha < 0)
	{
		nAlpha = 0;
		nDelta *= -1;
	}

	for (int i = 0; i < m_vecVertexParticle.size(); ++i)
	{
		if (i % 2) continue;
		m_vecVertexParticle[i].c = D3DCOLOR_ARGB(nAlpha, 180, 70, 20);
	}
}

void cMainGame::ParticleRender()
{
	if (m_vecVertexParticle.empty()) return;
	//return;
	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	g_pD3DDevice->SetRenderState(D3DRS_ZWRITEENABLE, false);

	g_pD3DDevice->SetRenderState(D3DRS_POINTSCALEENABLE, true);
	g_pD3DDevice->SetRenderState(D3DRS_POINTSIZE, FtoDW(5.0f));

	g_pD3DDevice->SetRenderState(D3DRS_POINTSCALE_A, FtoDW(0.0f));
	g_pD3DDevice->SetRenderState(D3DRS_POINTSCALE_B, FtoDW(0.0f));
	g_pD3DDevice->SetRenderState(D3DRS_POINTSCALE_C, FtoDW(1.0f));

	g_pD3DDevice->SetRenderState(D3DRS_POINTSPRITEENABLE, true);
	g_pD3DDevice->SetRenderState(D3DRS_POINTSIZE_MIN, FtoDW(0.0f));
	g_pD3DDevice->SetRenderState(D3DRS_POINTSIZE_MAX, FtoDW(10.0f));

	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

	g_pD3DDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_DIFFUSE);

	g_pD3DDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	g_pD3DDevice->SetTexture(0, g_pTextureManager.GetTexture("data/particle/alpha_tex.tga"));
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_POINTLIST, m_vecVertexParticle.size(), &m_vecVertexParticle[0], sizeof ST_PC_VERTEX);

	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	g_pD3DDevice->SetRenderState(D3DRS_ZWRITEENABLE, true);

	g_pD3DDevice->SetTexture(0, NULL);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_COLORARG0, D3DTA_DIFFUSE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);

}

void cMainGame::SetupMultiTexture()
{
	//D3DXCreateTextureFromFileA()
	m_pTex0 = g_pTextureManager.GetTexture("data/texture/stones.png");
	m_pTex1 = g_pTextureManager.GetTexture("data/texture/env0.png");
	m_pTex2 = g_pTextureManager.GetTexture("data/texture/env1.png");
	m_pTex3 = g_pTextureManager.GetTexture("data/texture/Albedo00.jpg");

	m_pDiffuseMap1 = g_pTextureManager.GetTexture("data/texture/Albedo00.jpg");
	m_pDiffuseMap2 = g_pTextureManager.GetTexture("data/texture/stones.png");
	m_pAlphaMap = g_pTextureManager.GetTexture("data/texture/AlphaMap256.png");

	ST_PT_VERTEX v;
	v.p = D3DXVECTOR3(0, 0, 0); v.t = D3DXVECTOR2(0, 1); m_vecVertex_Multi.push_back(v);
	v.p = D3DXVECTOR3(0, 2, 0); v.t = D3DXVECTOR2(0, 0); m_vecVertex_Multi.push_back(v);
	v.p = D3DXVECTOR3(2, 0, 0); v.t = D3DXVECTOR2(1, 1); m_vecVertex_Multi.push_back(v);

	v.p = D3DXVECTOR3(2, 2, 0); v.t = D3DXVECTOR2(1, 0); m_vecVertex_Multi.push_back(v);
	v.p = D3DXVECTOR3(2, 0, 0); v.t = D3DXVECTOR2(1, 1); m_vecVertex_Multi.push_back(v);
	v.p = D3DXVECTOR3(0, 2, 0); v.t = D3DXVECTOR2(0, 0); m_vecVertex_Multi.push_back(v);
}

void cMainGame::UpdateMultiTexture()
{
	if (::GetAsyncKeyState('1') & 0x8000) m_nType = 1;
	if (::GetAsyncKeyState('2') & 0x8000) m_nType = 2;
	if (::GetAsyncKeyState('3') & 0x8000) m_nType = 3;
	if (::GetAsyncKeyState('4') & 0x8000) m_nType = 4;
	if (::GetAsyncKeyState('5') & 0x8000) m_nType = 5;
	if (::GetAsyncKeyState('6') & 0x8000) m_nType = 6;
	if (::GetAsyncKeyState('7') & 0x8000) m_nType = 7;
	if (::GetAsyncKeyState('8') & 0x8000) m_nType = 8;
	if (::GetAsyncKeyState('9') & 0x8000) m_nType = 9;
	if (::GetAsyncKeyState('0') & 0x8000) m_nType = 0;
	if (::GetAsyncKeyState('R') & 0x8000) m_nType = -1;
}

void cMainGame::MultiTextureRender()
{
	if (m_pTex0 == nullptr) return;
	//return;
	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
	for (int i = 0; i < 4; ++i)
	{
		g_pD3DDevice->SetSamplerState(i, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);
		g_pD3DDevice->SetSamplerState(i, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP);
		g_pD3DDevice->SetSamplerState(i, D3DSAMP_ADDRESSW, D3DTADDRESS_WRAP);
		
		g_pD3DDevice->SetSamplerState(i, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
		g_pD3DDevice->SetSamplerState(i, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
		g_pD3DDevice->SetSamplerState(i, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);
	}
	
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_TEXCOORDINDEX, 0);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_TEXCOORDINDEX, 0);
	g_pD3DDevice->SetTextureStageState(3, D3DTSS_TEXCOORDINDEX, 0);

	switch (m_nType)
	{
	case 1: MultiTextureRender1(); break;
	case 2: MultiTextureRender2(); break;
	case 3: MultiTextureRender3(); break;
	case 4: MultiTextureRender4(); break;
	case 5: MultiTextureRender5(); break;
	case 6: MultiTextureRender6(); break;
	case 7: MultiTextureRender7(); break;
	case 8: MultiTextureRender8(); break;
	case 9: MultiTextureRender9(); break;
	case 0: MultiTextureRender0(); break;
	case -1: MultiTextureRender_default(); break;
	}

	SetBillboard();
	
	g_pD3DDevice->SetFVF(ST_PT_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(
		D3DPT_TRIANGLELIST,
		m_vecVertex_Multi.size() / 3,
		&m_vecVertex_Multi[0],
		sizeof ST_PT_VERTEX);

	g_pD3DDevice->SetTexture(0, NULL);
	g_pD3DDevice->SetTexture(1, NULL);
	g_pD3DDevice->SetTexture(2, NULL);

	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_DISABLE);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLOROP, D3DTOP_DISABLE);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_RESULTARG, D3DTA_CURRENT);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_RESULTARG, D3DTA_CURRENT);

	for (int i = 0; i < 4; ++i)
	{
		g_pD3DDevice->SetSamplerState(i, D3DSAMP_MAGFILTER, D3DTEXF_NONE);
		g_pD3DDevice->SetSamplerState(i, D3DSAMP_MINFILTER, D3DTEXF_NONE);
		g_pD3DDevice->SetSamplerState(i, D3DSAMP_MIPFILTER, D3DTEXF_NONE);
	}

	
}

void cMainGame::MultiTextureRender99()
{
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

	if (m_pShader)
	{
		D3DXMATRIXA16 matView, matProjection;
		g_pD3DDevice->GetTransform(D3DTS_VIEW, &matView);
		g_pD3DDevice->GetTransform(D3DTS_PROJECTION, &matProjection);

		m_pShader->SetMatrix("gWorldMatrix", &matWorld);
		m_pShader->SetMatrix("gViewMatrix", &matView);
		m_pShader->SetMatrix("gProjectionMatrix", &matProjection);
		m_pShader->SetVector("gWorldCameraPosition", &D3DXVECTOR4(m_pCamera->GetPosition(), 1));

		D3DXCOLOR	color(0.7f, 0.7f, 0.7f, 1);
		//m_pShader->SetValue("gColor", &color, sizeof color);
		m_pShader->SetVector("gLightColor", &D3DXVECTOR4(color));
		m_pShader->SetTexture("DiffuseMap_Tex1", m_pDiffuseMap1);
		m_pShader->SetTexture("DiffuseMap_Tex2", m_pDiffuseMap2);
		m_pShader->SetTexture("AlphaMap_Tex", m_pAlphaMap);

		SetBillboard(); // -> 이녀석의 matWorld를 쉐이더에 넘겨줘야 돌아감
		
		UINT	numPasses = 0;
		m_pShader->Begin(&numPasses, NULL);
		{
			for (UINT i = 0; i < numPasses; ++i)
			{
				m_pShader->BeginPass(i);
				
				g_pD3DDevice->SetFVF(ST_PT_VERTEX::FVF);
				g_pD3DDevice->DrawPrimitiveUP(
					D3DPT_TRIANGLELIST,
					m_vecVertex_Multi.size() / 3,
					&m_vecVertex_Multi[0],
					sizeof ST_PT_VERTEX);

				m_pShader->EndPass();
			}
		}
		m_pShader->End();
	}




}

void cMainGame::SetupFog()
{
	g_pD3DDevice->SetRenderState(D3DRS_FOGENABLE, true);
	g_pD3DDevice->SetRenderState(D3DRS_FOGCOLOR, D3DXCOLOR(255, 0, 0, 125));
	g_pD3DDevice->SetRenderState(D3DRS_FOGVERTEXMODE, D3DFOG_LINEAR);
	g_pD3DDevice->SetRenderState(D3DRS_FOGSTART, FtoDW(10.0f));
	g_pD3DDevice->SetRenderState(D3DRS_FOGEND, FtoDW(200.f));
	g_pD3DDevice->SetRenderState(D3DRS_RANGEFOGENABLE, true);
}

void cMainGame::RenderX()
{
	for (auto && x : m_vecX)
	{
		x->render();
	}
}

void cMainGame::MultiTextureRender1()
{
	g_pD3DDevice->SetTexture(0, m_pTex0);
	g_pD3DDevice->SetTexture(1, m_pTex1);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_CURRENT);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_MODULATE);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLOROP, D3DTOP_DISABLE);

}

void cMainGame::MultiTextureRender2()
{
	g_pD3DDevice->SetTexture(0, m_pTex0);
	g_pD3DDevice->SetTexture(1, m_pTex1);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_CURRENT);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_MODULATE2X);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLOROP, D3DTOP_DISABLE);
}

void cMainGame::MultiTextureRender3()
{
	g_pD3DDevice->SetTexture(0, m_pTex0);
	g_pD3DDevice->SetTexture(1, m_pTex1);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_CURRENT);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_MODULATE4X);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLOROP, D3DTOP_DISABLE);
}

void cMainGame::MultiTextureRender4()
{
	g_pD3DDevice->SetTexture(0, m_pTex0);
	g_pD3DDevice->SetTexture(1, m_pTex1);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_CURRENT);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_ADD);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLOROP, D3DTOP_DISABLE);
}

void cMainGame::MultiTextureRender5()
{
	g_pD3DDevice->SetTexture(0, m_pTex0);
	g_pD3DDevice->SetTexture(1, m_pTex1);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_CURRENT);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_SUBTRACT);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLOROP, D3DTOP_DISABLE);
}

void cMainGame::MultiTextureRender6()
{
	g_pD3DDevice->SetTexture(0, m_pTex0);
	g_pD3DDevice->SetTexture(1, m_pTex3);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_CURRENT);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_ADDSIGNED);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLOROP, D3DTOP_DISABLE);
}

void cMainGame::MultiTextureRender7()
{
	g_pD3DDevice->SetTexture(0, m_pTex0);
	g_pD3DDevice->SetTexture(1, m_pTex3);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_CURRENT);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_ADDSIGNED2X);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLOROP, D3DTOP_DISABLE);
}

void cMainGame::MultiTextureRender8()
{
	g_pD3DDevice->SetTexture(0, m_pTex0);
	g_pD3DDevice->SetTexture(1, m_pTex3);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_CURRENT);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_ADDSMOOTH);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLOROP, D3DTOP_DISABLE);
}

void cMainGame::MultiTextureRender9()
{
	g_pD3DDevice->SetTexture(0, m_pTex0);
	g_pD3DDevice->SetTexture(1, m_pTex2);
	g_pD3DDevice->SetTexture(2, m_pTex3);

	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_RESULTARG, D3DTA_TEMP);

	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLORARG0, D3DTA_CURRENT);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLORARG1, D3DTA_TEMP);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLORARG2, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLOROP, D3DTOP_MULTIPLYADD);

	
	g_pD3DDevice->SetTextureStageState(3, D3DTSS_COLOROP, D3DTOP_DISABLE);
}

void cMainGame::MultiTextureRender0()
{
	g_pD3DDevice->SetTexture(0, m_pTex0);
	g_pD3DDevice->SetTexture(1, m_pTex2);
	g_pD3DDevice->SetTexture(2, m_pTex3);

	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_RESULTARG, D3DTA_TEMP);

	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLORARG0, D3DTA_CURRENT);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLORARG1, D3DTA_TEMP);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLORARG2, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLOROP, D3DTOP_LERP);


	g_pD3DDevice->SetTextureStageState(3, D3DTSS_COLOROP, D3DTOP_DISABLE);
}

void cMainGame::MultiTextureRender_default()
{
	g_pD3DDevice->SetTexture(0, m_pTex0);
	g_pD3DDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_DISABLE);
	g_pD3DDevice->SetTextureStageState(2, D3DTSS_COLOROP, D3DTOP_DISABLE);
}

void cMainGame::SetBillboard()
{
	D3DXMATRIXA16 matBillboard, matView;
	D3DXMatrixIdentity(&matBillboard);
	g_pD3DDevice->GetTransform(D3DTS_VIEW, &matView);


	//y축만 회전
	matBillboard._11 = matView._11;
	matBillboard._13 = matView._13;
	matBillboard._31 = matView._31;
	matBillboard._33 = matView._33;

	//이동
	D3DXMATRIXA16 matT;
	D3DXMatrixIdentity(&matT);
	D3DXMatrixTranslation(&matT, 1, 0, 0);
	matBillboard *= matT;


	D3DXMatrixInverse(&matBillboard, NULL, &matBillboard);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matBillboard);

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
