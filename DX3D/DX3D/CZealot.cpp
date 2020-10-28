#include "stdafx.h"
#include "CZealot.h"

#include "COBB.h"
#include "CSkinnedMesh.h"

CZealot::CZealot(): m_pSkinnedMesh(nullptr), m_pOBB(nullptr), m_pCharacterController(nullptr)
{
}

CZealot::~CZealot()
{
	SafeRelease(m_pCharacterController);
	SafeDelete(m_pSkinnedMesh);
	SafeDelete(m_pOBB);
}

void CZealot::Setup()
{
	m_pSkinnedMesh = new CSkinnedMesh("data/Zealot", "zealot.X");
	m_pSkinnedMesh->SetRandomTrackPosition();

	m_pOBB = new COBB;
	m_pOBB->Setup(m_pSkinnedMesh);

}

void CZealot::Update(iMap* pMap)
{
	if (m_pCharacterController)
		m_pCharacterController->update(pMap);

	if (m_pOBB)
		m_pOBB->Update(m_pCharacterController ? m_pCharacterController->GetTransform() : nullptr);
}

void CZealot::Render(D3DXCOLOR c)
{
	if (m_pCharacterController)
		m_pSkinnedMesh->SetTransform(m_pCharacterController->GetTransform());

	m_pSkinnedMesh->UpdateAndRender();

	if (m_pOBB)
		m_pOBB->OBBBOX_Render(c);
}

COBB* CZealot::GetOBB()
{
	return m_pOBB;
}
