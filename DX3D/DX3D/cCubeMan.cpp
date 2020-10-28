#include "stdafx.h"
#include "cCubeMan.h"

#include <vector>


#include "cBody.h"
#include "cGroup.h"
#include "cLeftArm.h"
#include "cRightArm.h"
#include "cLeftLeg.h"
#include "cRightLeg.h"
#include "cHead.h"

cCubeMan::cCubeMan(): m_pRoot(nullptr), m_stMtl(), m_pTexture(nullptr)
{
	//m_vPosition.x = 1;
	//m_vPosition.z = 1;
	m_vPosition.y += 0.9f;
}

cCubeMan::~cCubeMan()
{
	if (m_pRoot)
		m_pRoot->Destroy();
	SafeRelease(m_pTexture);
}

void cCubeMan::setup()
{
	cCharacter::setup();
	D3DXCreateTextureFromFile(g_pD3DDevice, _T("data/texture/riko.png"), &m_pTexture);
	ZeroMemory(&m_stMtl, sizeof D3DMATERIAL9);
	m_stMtl.Ambient = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	m_stMtl.Diffuse = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	m_stMtl.Specular = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);

	cBody* pBody = new cBody;
	pBody->setup();
	pBody->SetParentWorldTM(&m_matWorld);
	{
		//front
		pBody->TextureMapping( 0, QUATER_SQUARE *  5, QUATER_SQUARE *  8);
		pBody->TextureMapping( 1, QUATER_SQUARE *  5, QUATER_SQUARE *  5);
		pBody->TextureMapping( 2, QUATER_SQUARE *  7, QUATER_SQUARE *  5);
							   					   					   
		pBody->TextureMapping( 3, QUATER_SQUARE *  5, QUATER_SQUARE *  8);
		pBody->TextureMapping( 4, QUATER_SQUARE *  7, QUATER_SQUARE *  5);
		pBody->TextureMapping( 5, QUATER_SQUARE *  7, QUATER_SQUARE *  8);
		//back							   					   					   
		pBody->TextureMapping( 6, QUATER_SQUARE *  8, QUATER_SQUARE *  8);
		pBody->TextureMapping( 7, QUATER_SQUARE *  8, QUATER_SQUARE *  5);
		pBody->TextureMapping( 8, QUATER_SQUARE * 10, QUATER_SQUARE *  5);
							   					   					   
		pBody->TextureMapping( 9, QUATER_SQUARE *  8, QUATER_SQUARE *  8);
		pBody->TextureMapping(10, QUATER_SQUARE * 10, QUATER_SQUARE *  5);
		pBody->TextureMapping(11, QUATER_SQUARE * 10, QUATER_SQUARE *  8);
		//left
		pBody->TextureMapping(12, QUATER_SQUARE *  4, QUATER_SQUARE *  8);
		pBody->TextureMapping(13, QUATER_SQUARE *  4, QUATER_SQUARE *  5);
		pBody->TextureMapping(14, QUATER_SQUARE *  5, QUATER_SQUARE *  5);
							   					   					   
		pBody->TextureMapping(15, QUATER_SQUARE *  4, QUATER_SQUARE *  8);
		pBody->TextureMapping(16, QUATER_SQUARE *  5, QUATER_SQUARE *  5);
		pBody->TextureMapping(17, QUATER_SQUARE *  5, QUATER_SQUARE *  8);
		//right
		pBody->TextureMapping(18, QUATER_SQUARE *  7, QUATER_SQUARE *  8);
		pBody->TextureMapping(19, QUATER_SQUARE *  7, QUATER_SQUARE *  5);
		pBody->TextureMapping(20, QUATER_SQUARE *  8, QUATER_SQUARE *  5);
							   					   					   
		pBody->TextureMapping(21, QUATER_SQUARE *  7, QUATER_SQUARE *  8);
		pBody->TextureMapping(22, QUATER_SQUARE *  8, QUATER_SQUARE *  5);
		pBody->TextureMapping(23, QUATER_SQUARE *  8, QUATER_SQUARE *  8);
		//top
		pBody->TextureMapping(24, QUATER_SQUARE *  5, QUATER_SQUARE *  5);
		pBody->TextureMapping(25, QUATER_SQUARE *  5, QUATER_SQUARE *  4);
		pBody->TextureMapping(26, QUATER_SQUARE *  7, QUATER_SQUARE *  4);
							   					   					   
		pBody->TextureMapping(27, QUATER_SQUARE *  5, QUATER_SQUARE *  5);
		pBody->TextureMapping(28, QUATER_SQUARE *  7, QUATER_SQUARE *  4);
		pBody->TextureMapping(29, QUATER_SQUARE *  7, QUATER_SQUARE *  5);
		//bottom
		pBody->TextureMapping(30, QUATER_SQUARE *  7, QUATER_SQUARE *  5);
		pBody->TextureMapping(31, QUATER_SQUARE *  7, QUATER_SQUARE *  4);
		pBody->TextureMapping(32, QUATER_SQUARE *  9, QUATER_SQUARE *  4);
							   					   					   
		pBody->TextureMapping(33, QUATER_SQUARE *  7, QUATER_SQUARE *  5);
		pBody->TextureMapping(34, QUATER_SQUARE *  9, QUATER_SQUARE *  4);
		pBody->TextureMapping(35, QUATER_SQUARE *  9, QUATER_SQUARE *  5);
	}
	m_pRoot = pBody;

	cHead* pHead = new cHead;
	pHead->setup();
	{
		//front
		pHead->TextureMapping( 0, QUATER_SQUARE *  2, QUATER_SQUARE *  4);
		pHead->TextureMapping( 1, QUATER_SQUARE *  2, QUATER_SQUARE *  2);
		pHead->TextureMapping( 2, QUATER_SQUARE *  4, QUATER_SQUARE *  2);
							   					   					   
		pHead->TextureMapping( 3, QUATER_SQUARE *  2, QUATER_SQUARE *  4);
		pHead->TextureMapping( 4, QUATER_SQUARE *  4, QUATER_SQUARE *  2);
		pHead->TextureMapping( 5, QUATER_SQUARE *  4, QUATER_SQUARE *  4);
		//back
		pHead->TextureMapping( 6, QUATER_SQUARE *  6, QUATER_SQUARE *  4);
		pHead->TextureMapping( 7, QUATER_SQUARE *  6, QUATER_SQUARE *  2);
		pHead->TextureMapping( 8, QUATER_SQUARE *  8, QUATER_SQUARE *  2);
							   					   					   
		pHead->TextureMapping( 9, QUATER_SQUARE *  6, QUATER_SQUARE *  4);
		pHead->TextureMapping(10, QUATER_SQUARE *  8, QUATER_SQUARE *  2);
		pHead->TextureMapping(11, QUATER_SQUARE *  8, QUATER_SQUARE *  4);
		//left
		pHead->TextureMapping(12, QUATER_SQUARE *  0, QUATER_SQUARE *  4);
		pHead->TextureMapping(13, QUATER_SQUARE *  0, QUATER_SQUARE *  2);
		pHead->TextureMapping(14, QUATER_SQUARE *  2, QUATER_SQUARE *  2);
							   					   					   
		pHead->TextureMapping(15, QUATER_SQUARE *  0, QUATER_SQUARE *  4);
		pHead->TextureMapping(16, QUATER_SQUARE *  2, QUATER_SQUARE *  2);
		pHead->TextureMapping(17, QUATER_SQUARE *  2, QUATER_SQUARE *  4);
		//right
		pHead->TextureMapping(18, QUATER_SQUARE *  4, QUATER_SQUARE *  4);
		pHead->TextureMapping(19, QUATER_SQUARE *  4, QUATER_SQUARE *  2);
		pHead->TextureMapping(20, QUATER_SQUARE *  6, QUATER_SQUARE *  2);
							   					   					   
		pHead->TextureMapping(21, QUATER_SQUARE *  4, QUATER_SQUARE *  4);
		pHead->TextureMapping(22, QUATER_SQUARE *  6, QUATER_SQUARE *  2);
		pHead->TextureMapping(23, QUATER_SQUARE *  6, QUATER_SQUARE *  4);
		//top
		pHead->TextureMapping(24, QUATER_SQUARE *  2, QUATER_SQUARE *  2);
		pHead->TextureMapping(25, QUATER_SQUARE *  2, QUATER_SQUARE *  0);
		pHead->TextureMapping(26, QUATER_SQUARE *  4, QUATER_SQUARE *  0);
							   					   					   
		pHead->TextureMapping(27, QUATER_SQUARE *  2, QUATER_SQUARE *  2);
		pHead->TextureMapping(28, QUATER_SQUARE *  4, QUATER_SQUARE *  0);
		pHead->TextureMapping(29, QUATER_SQUARE *  4, QUATER_SQUARE *  2);
		//bottom
		pHead->TextureMapping(30, QUATER_SQUARE *  4, QUATER_SQUARE *  2);
		pHead->TextureMapping(31, QUATER_SQUARE *  4, QUATER_SQUARE *  0);
		pHead->TextureMapping(32, QUATER_SQUARE *  6, QUATER_SQUARE *  0);
							   					   					   
		pHead->TextureMapping(33, QUATER_SQUARE *  4, QUATER_SQUARE *  2);
		pHead->TextureMapping(34, QUATER_SQUARE *  6, QUATER_SQUARE *  0);
		pHead->TextureMapping(35, QUATER_SQUARE *  6, QUATER_SQUARE *  2);
	}
	m_pRoot->AddChild(pHead);

	cLeftArm* pLArm = new cLeftArm;
	pLArm->setup();
	pLArm->SetRotDeltaX(0.1f);
	{
		//front
		pLArm->TextureMapping( 0, QUATER_SQUARE * 11, QUATER_SQUARE *  8);
		pLArm->TextureMapping( 1, QUATER_SQUARE * 11, QUATER_SQUARE *  5);
		pLArm->TextureMapping( 2, QUATER_SQUARE * 12, QUATER_SQUARE *  5);
					   					   					   
		pLArm->TextureMapping( 3, QUATER_SQUARE * 11, QUATER_SQUARE *  8);
		pLArm->TextureMapping( 4, QUATER_SQUARE * 12, QUATER_SQUARE *  5);
		pLArm->TextureMapping( 5, QUATER_SQUARE * 12, QUATER_SQUARE *  8);
		//back
		pLArm->TextureMapping( 6, QUATER_SQUARE * 13, QUATER_SQUARE *  8);
		pLArm->TextureMapping( 7, QUATER_SQUARE * 13, QUATER_SQUARE *  5);
		pLArm->TextureMapping( 8, QUATER_SQUARE * 14, QUATER_SQUARE *  5);
						   					   					   
		pLArm->TextureMapping( 9, QUATER_SQUARE * 13, QUATER_SQUARE *  8);
		pLArm->TextureMapping(10, QUATER_SQUARE * 14, QUATER_SQUARE *  5);
		pLArm->TextureMapping(11, QUATER_SQUARE * 14, QUATER_SQUARE *  8);
		//left
		pLArm->TextureMapping(12, QUATER_SQUARE * 10, QUATER_SQUARE *  8);
		pLArm->TextureMapping(13, QUATER_SQUARE * 10, QUATER_SQUARE *  5);
		pLArm->TextureMapping(14, QUATER_SQUARE * 11, QUATER_SQUARE *  5);
						 					   					   
		pLArm->TextureMapping(15, QUATER_SQUARE * 10, QUATER_SQUARE *  8);
		pLArm->TextureMapping(16, QUATER_SQUARE * 11, QUATER_SQUARE *  5);
		pLArm->TextureMapping(17, QUATER_SQUARE * 11, QUATER_SQUARE *  8);
		//right
		pLArm->TextureMapping(18, QUATER_SQUARE * 12, QUATER_SQUARE *  8);
		pLArm->TextureMapping(19, QUATER_SQUARE * 12, QUATER_SQUARE *  5);
		pLArm->TextureMapping(20, QUATER_SQUARE * 13, QUATER_SQUARE *  5);
									   					   
		pLArm->TextureMapping(21, QUATER_SQUARE * 12, QUATER_SQUARE *  8);
		pLArm->TextureMapping(22, QUATER_SQUARE * 13, QUATER_SQUARE *  5);
		pLArm->TextureMapping(23, QUATER_SQUARE * 13, QUATER_SQUARE *  8);
		//top
		pLArm->TextureMapping(24, QUATER_SQUARE * 11, QUATER_SQUARE *  5);
		pLArm->TextureMapping(25, QUATER_SQUARE * 11, QUATER_SQUARE *  4);
		pLArm->TextureMapping(26, QUATER_SQUARE * 12, QUATER_SQUARE *  4);
									   					   
		pLArm->TextureMapping(27, QUATER_SQUARE * 11, QUATER_SQUARE *  5);
		pLArm->TextureMapping(28, QUATER_SQUARE * 12, QUATER_SQUARE *  4);
		pLArm->TextureMapping(29, QUATER_SQUARE * 12, QUATER_SQUARE *  5);
		//bottom
		pLArm->TextureMapping(30, QUATER_SQUARE * 12, QUATER_SQUARE *  5);
		pLArm->TextureMapping(31, QUATER_SQUARE * 12, QUATER_SQUARE *  4);
		pLArm->TextureMapping(32, QUATER_SQUARE * 13, QUATER_SQUARE *  4);
									   					   
		pLArm->TextureMapping(33, QUATER_SQUARE * 12, QUATER_SQUARE *  5);
		pLArm->TextureMapping(34, QUATER_SQUARE * 13, QUATER_SQUARE *  4);
		pLArm->TextureMapping(35, QUATER_SQUARE * 13, QUATER_SQUARE *  5);
	}
	m_pRoot->AddChild(pLArm);

	cRightArm* pRArm = new cRightArm;
	pRArm->setup();
	pRArm->SetRotDeltaX(-0.1f);
	{
		//front
		pRArm->TextureMapping( 0, QUATER_SQUARE *  9, QUATER_SQUARE * 16);
		pRArm->TextureMapping( 1, QUATER_SQUARE *  9, QUATER_SQUARE * 13);
		pRArm->TextureMapping( 2, QUATER_SQUARE * 10, QUATER_SQUARE * 13);
						   					   					   
		pRArm->TextureMapping( 3, QUATER_SQUARE *  9, QUATER_SQUARE * 16);
		pRArm->TextureMapping( 4, QUATER_SQUARE * 10, QUATER_SQUARE * 13);
		pRArm->TextureMapping( 5, QUATER_SQUARE * 10, QUATER_SQUARE * 16);
		//back
		pRArm->TextureMapping( 6, QUATER_SQUARE * 11, QUATER_SQUARE * 16);
		pRArm->TextureMapping( 7, QUATER_SQUARE * 11, QUATER_SQUARE * 13);
		pRArm->TextureMapping( 8, QUATER_SQUARE * 12, QUATER_SQUARE * 13);
						   					   					   
		pRArm->TextureMapping( 9, QUATER_SQUARE * 11, QUATER_SQUARE * 16);
		pRArm->TextureMapping(10, QUATER_SQUARE * 12, QUATER_SQUARE * 13);
		pRArm->TextureMapping(11, QUATER_SQUARE * 12, QUATER_SQUARE * 16);
		//left
		pRArm->TextureMapping(12, QUATER_SQUARE *  8, QUATER_SQUARE * 16);
		pRArm->TextureMapping(13, QUATER_SQUARE *  8, QUATER_SQUARE * 13);
		pRArm->TextureMapping(14, QUATER_SQUARE *  9, QUATER_SQUARE * 13);
						 					   					   
		pRArm->TextureMapping(15, QUATER_SQUARE *  8, QUATER_SQUARE * 16);
		pRArm->TextureMapping(16, QUATER_SQUARE *  9, QUATER_SQUARE * 13);
		pRArm->TextureMapping(17, QUATER_SQUARE *  9, QUATER_SQUARE * 16);
		//right
		pRArm->TextureMapping(18, QUATER_SQUARE * 10, QUATER_SQUARE * 16);
		pRArm->TextureMapping(19, QUATER_SQUARE * 10, QUATER_SQUARE * 13);
		pRArm->TextureMapping(20, QUATER_SQUARE * 11, QUATER_SQUARE * 13);
									   					   
		pRArm->TextureMapping(21, QUATER_SQUARE * 10, QUATER_SQUARE * 16);
		pRArm->TextureMapping(22, QUATER_SQUARE * 11, QUATER_SQUARE * 13);
		pRArm->TextureMapping(23, QUATER_SQUARE * 11, QUATER_SQUARE * 16);
		//top
		pRArm->TextureMapping(24, QUATER_SQUARE *  9, QUATER_SQUARE * 13);
		pRArm->TextureMapping(25, QUATER_SQUARE *  9, QUATER_SQUARE * 12);
		pRArm->TextureMapping(26, QUATER_SQUARE * 10, QUATER_SQUARE * 12);
									   					   
		pRArm->TextureMapping(27, QUATER_SQUARE *  9, QUATER_SQUARE * 13);
		pRArm->TextureMapping(28, QUATER_SQUARE * 10, QUATER_SQUARE * 12);
		pRArm->TextureMapping(29, QUATER_SQUARE * 10, QUATER_SQUARE * 13);
		//bottom
		pRArm->TextureMapping(30, QUATER_SQUARE * 10, QUATER_SQUARE * 13);
		pRArm->TextureMapping(31, QUATER_SQUARE * 10, QUATER_SQUARE * 12);
		pRArm->TextureMapping(32, QUATER_SQUARE * 11, QUATER_SQUARE * 12);
									   					   
		pRArm->TextureMapping(33, QUATER_SQUARE * 10, QUATER_SQUARE * 13);
		pRArm->TextureMapping(34, QUATER_SQUARE * 11, QUATER_SQUARE * 12);
		pRArm->TextureMapping(35, QUATER_SQUARE * 11, QUATER_SQUARE * 13);
	}
	m_pRoot->AddChild(pRArm);

	cLeftLeg* pLLeg = new cLeftLeg;
	pLLeg->setup();
	pLLeg->SetRotDeltaX(-0.1f);
	{
		//front
		pLLeg->TextureMapping( 0, QUATER_SQUARE *  1, QUATER_SQUARE *  8);
		pLLeg->TextureMapping( 1, QUATER_SQUARE *  1, QUATER_SQUARE *  5);
		pLLeg->TextureMapping( 2, QUATER_SQUARE *  2, QUATER_SQUARE *  5);
						   					   					   
		pLLeg->TextureMapping( 3, QUATER_SQUARE *  1, QUATER_SQUARE *  8);
		pLLeg->TextureMapping( 4, QUATER_SQUARE *  2, QUATER_SQUARE *  5);
		pLLeg->TextureMapping( 5, QUATER_SQUARE *  2, QUATER_SQUARE *  8);
		//back
		pLLeg->TextureMapping( 6, QUATER_SQUARE *  3, QUATER_SQUARE *  8);
		pLLeg->TextureMapping( 7, QUATER_SQUARE *  3, QUATER_SQUARE *  5);
		pLLeg->TextureMapping( 8, QUATER_SQUARE *  4, QUATER_SQUARE *  5);
							   					   					   
		pLLeg->TextureMapping( 9, QUATER_SQUARE *  3, QUATER_SQUARE *  8);
		pLLeg->TextureMapping(10, QUATER_SQUARE *  4, QUATER_SQUARE *  5);
		pLLeg->TextureMapping(11, QUATER_SQUARE *  4, QUATER_SQUARE *  8);
		//left
		pLLeg->TextureMapping(12, QUATER_SQUARE *  0, QUATER_SQUARE *  8);
		pLLeg->TextureMapping(13, QUATER_SQUARE *  0, QUATER_SQUARE *  5);
		pLLeg->TextureMapping(14, QUATER_SQUARE *  1, QUATER_SQUARE *  5);
							 					   					   
		pLLeg->TextureMapping(15, QUATER_SQUARE *  0, QUATER_SQUARE *  8);
		pLLeg->TextureMapping(16, QUATER_SQUARE *  1, QUATER_SQUARE *  5);
		pLLeg->TextureMapping(17, QUATER_SQUARE *  1, QUATER_SQUARE *  8);
		//right
		pLLeg->TextureMapping(18, QUATER_SQUARE *  2, QUATER_SQUARE *  8);
		pLLeg->TextureMapping(19, QUATER_SQUARE *  2, QUATER_SQUARE *  5);
		pLLeg->TextureMapping(20, QUATER_SQUARE *  3, QUATER_SQUARE *  5);
										   					   
		pLLeg->TextureMapping(21, QUATER_SQUARE *  2, QUATER_SQUARE *  8);
		pLLeg->TextureMapping(22, QUATER_SQUARE *  3, QUATER_SQUARE *  5);
		pLLeg->TextureMapping(23, QUATER_SQUARE *  3, QUATER_SQUARE *  8);
		//top
		pLLeg->TextureMapping(24, QUATER_SQUARE *  1, QUATER_SQUARE *  5);
		pLLeg->TextureMapping(25, QUATER_SQUARE *  1, QUATER_SQUARE *  4);
		pLLeg->TextureMapping(26, QUATER_SQUARE *  2, QUATER_SQUARE *  4);
										   					   
		pLLeg->TextureMapping(27, QUATER_SQUARE *  1, QUATER_SQUARE *  5);
		pLLeg->TextureMapping(28, QUATER_SQUARE *  2, QUATER_SQUARE *  4);
		pLLeg->TextureMapping(29, QUATER_SQUARE *  2, QUATER_SQUARE *  5);
		//bottom
		pLLeg->TextureMapping(30, QUATER_SQUARE *  2, QUATER_SQUARE *  5);
		pLLeg->TextureMapping(31, QUATER_SQUARE *  2, QUATER_SQUARE *  4);
		pLLeg->TextureMapping(32, QUATER_SQUARE *  3, QUATER_SQUARE *  4);
										   					   
		pLLeg->TextureMapping(33, QUATER_SQUARE *  2, QUATER_SQUARE *  5);
		pLLeg->TextureMapping(34, QUATER_SQUARE *  3, QUATER_SQUARE *  4);
		pLLeg->TextureMapping(35, QUATER_SQUARE *  3, QUATER_SQUARE *  5);
	}
	m_pRoot->AddChild(pLLeg);

	cRightLeg* pRLeg = new cRightLeg;
	pRLeg->setup();
	pRLeg->SetRotDeltaX(0.1f);
	{
		//front
		pRLeg->TextureMapping( 0, QUATER_SQUARE *  5, QUATER_SQUARE * 16);
		pRLeg->TextureMapping( 1, QUATER_SQUARE *  5, QUATER_SQUARE * 13);
		pRLeg->TextureMapping( 2, QUATER_SQUARE *  6, QUATER_SQUARE * 13);
					   					   					   
		pRLeg->TextureMapping( 3, QUATER_SQUARE *  5, QUATER_SQUARE * 16);
		pRLeg->TextureMapping( 4, QUATER_SQUARE *  6, QUATER_SQUARE * 13);
		pRLeg->TextureMapping( 5, QUATER_SQUARE *  6, QUATER_SQUARE * 16);
		//back
		pRLeg->TextureMapping( 6, QUATER_SQUARE *  7, QUATER_SQUARE * 16);
		pRLeg->TextureMapping( 7, QUATER_SQUARE *  7, QUATER_SQUARE * 13);
		pRLeg->TextureMapping( 8, QUATER_SQUARE *  8, QUATER_SQUARE * 13);
						   					   		 			   
		pRLeg->TextureMapping( 9, QUATER_SQUARE *  7, QUATER_SQUARE * 16);
		pRLeg->TextureMapping(10, QUATER_SQUARE *  8, QUATER_SQUARE * 13);
		pRLeg->TextureMapping(11, QUATER_SQUARE *  8, QUATER_SQUARE * 16);
		//left
		pRLeg->TextureMapping(12, QUATER_SQUARE *  4, QUATER_SQUARE * 16);
		pRLeg->TextureMapping(13, QUATER_SQUARE *  4, QUATER_SQUARE * 13);
		pRLeg->TextureMapping(14, QUATER_SQUARE *  5, QUATER_SQUARE * 13);
						 					   					   
		pRLeg->TextureMapping(15, QUATER_SQUARE *  4, QUATER_SQUARE * 16);
		pRLeg->TextureMapping(16, QUATER_SQUARE *  5, QUATER_SQUARE * 13);
		pRLeg->TextureMapping(17, QUATER_SQUARE *  5, QUATER_SQUARE * 16);
		//right
		pRLeg->TextureMapping(18, QUATER_SQUARE *  6, QUATER_SQUARE * 16);
		pRLeg->TextureMapping(19, QUATER_SQUARE *  6, QUATER_SQUARE * 13);
		pRLeg->TextureMapping(20, QUATER_SQUARE *  7, QUATER_SQUARE * 13);
									   				 	   
		pRLeg->TextureMapping(21, QUATER_SQUARE *  6, QUATER_SQUARE * 16);
		pRLeg->TextureMapping(22, QUATER_SQUARE *  7, QUATER_SQUARE * 13);
		pRLeg->TextureMapping(23, QUATER_SQUARE *  7, QUATER_SQUARE * 16);
		//top									   
		pRLeg->TextureMapping(24, QUATER_SQUARE *  5, QUATER_SQUARE * 13);
		pRLeg->TextureMapping(25, QUATER_SQUARE *  5, QUATER_SQUARE * 12);
		pRLeg->TextureMapping(26, QUATER_SQUARE *  6, QUATER_SQUARE * 12);
									   					   
		pRLeg->TextureMapping(27, QUATER_SQUARE *  5, QUATER_SQUARE * 13);
		pRLeg->TextureMapping(28, QUATER_SQUARE *  6, QUATER_SQUARE * 12);
		pRLeg->TextureMapping(29, QUATER_SQUARE *  6, QUATER_SQUARE * 13);
		//bottom								   
		pRLeg->TextureMapping(30, QUATER_SQUARE *  6, QUATER_SQUARE * 13);
		pRLeg->TextureMapping(31, QUATER_SQUARE *  6, QUATER_SQUARE * 12);
		pRLeg->TextureMapping(32, QUATER_SQUARE *  7, QUATER_SQUARE * 12);
									   				 	   
		pRLeg->TextureMapping(33, QUATER_SQUARE *  6, QUATER_SQUARE * 13);
		pRLeg->TextureMapping(34, QUATER_SQUARE *  7, QUATER_SQUARE * 12);
		pRLeg->TextureMapping(35, QUATER_SQUARE *  7, QUATER_SQUARE * 13);
	}
	m_pRoot->AddChild(pRLeg);

}

void cCubeMan::update(const vector<cGroup*>& floor)
{
	cCharacter::update(floor);
	if (m_pRoot)
		m_pRoot->update();
}

void cCubeMan::update(iMap* pMap)
{
	cCharacter::update(pMap);
	if (m_pRoot)
		m_pRoot->update();
}

void cCubeMan::render()
{
	if (g_pD3DDevice)
	{
		g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
		g_pD3DDevice->SetMaterial(&m_stMtl);

		cCharacter::render();

		D3DXMATRIXA16 matWorld;
		D3DXMatrixIdentity(&matWorld);
		g_pD3DDevice->SetTexture(0, m_pTexture);

		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
		if (m_pRoot)
			m_pRoot->render();

		g_pD3DDevice->SetTexture(0, NULL);

	}
}
