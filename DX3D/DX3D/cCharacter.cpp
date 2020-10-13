#include "stdafx.h"
#include "cCharacter.h"
#include "cGroup.h"

cCharacter::cCharacter()
	: m_fRotY(D3DX_PI)
	, m_vDirection(0,0,-1)
	, m_vPosition(0,0.9f,0)
{
	D3DXMatrixIdentity(&m_matWorld);
}

cCharacter::~cCharacter()
{
}

void cCharacter::setup()
{
}

void cCharacter::update(const vector<cGroup*>& floor)
{
	if (GetKeyState('K') & 0x0001)
		return;
	if (GetKeyState('L') & 0x0001)
		return;
	D3DXVECTOR3 vTempPos = m_vPosition;
	bool bPush = false;
	if (GetKeyState('A') & 0x8000)
	{
		m_fRotY += -0.1f;
	}
	if (GetKeyState('D') & 0x8000)
	{
		m_fRotY += 0.1f;
	}

	if (GetKeyState('W') & 0x8000)
	{
		vTempPos += (m_vDirection*0.1f);
		bPush = true;
	}
	if (GetKeyState('S') & 0x8000)
	{
		vTempPos -= (m_vDirection*0.1f);
		bPush = true;
	}


	if (floor.empty() || !bPush)
		m_vPosition = vTempPos;
	else
	{
		D3DXVECTOR3 vRayPos = vTempPos;
		vRayPos.y += 1;
		D3DXVECTOR3 vRayDir(0, -1, 0);
		float fTemp = 0, fDist = -1.0f;
		BOOL bIsCollide = false;
		
		D3DXMATRIXA16 matWorld, matS, matR;

		D3DXMatrixScaling(&matS, 0.01f, 0.01f, 0.01f);
		D3DXMatrixRotationX(&matR, -D3DX_PI / 2);

		matWorld = matS * matR;
		for (auto* group : floor)
		{
			vector<ST_PNT_VERTEX>& vertex = group->GetVertex();
			for (int i = 0; i < vertex.size(); i += 3)
			{
				D3DXVECTOR3 vTempVertex1, vTempVertex2, vTempVertex3;
				D3DXVec3TransformCoord(&vTempVertex1, &vertex[i].p, &matWorld);
				D3DXVec3TransformCoord(&vTempVertex2, &vertex[i + 1].p, &matWorld);
				D3DXVec3TransformCoord(&vTempVertex3, &vertex[i + 2].p, &matWorld);
				if (bIsCollide = D3DXIntersectTri(&vTempVertex1, &vTempVertex2, &vTempVertex3, &vRayPos, &vRayDir, &fTemp, &fTemp, &fDist))
				//if (bIsCollide = D3DXIntersectTri(&vertex[i].p, &vertex[i + 1].p, &vertex[i + 2].p, &vRayPos, &vRayDir, &fTemp, &fTemp, &fDist))
				{
					vTempPos.y += 1.0f - fDist + 0.9f;
					m_vPosition = vTempPos;
					break;
				}
			}
			if (bIsCollide)
				break;
			
		}
	}
	
	RECT rc;
	GetClientRect(g_hWnd, &rc);
	D3DXMATRIXA16 matR, matT;
	D3DXMatrixRotationY(&matR, m_fRotY);

	m_vDirection = D3DXVECTOR3(0, 0, -1);
	D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);
	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y, m_vPosition.z);

	m_matWorld = matR * matT;
}

void cCharacter::render()
{
}

D3DXVECTOR3& cCharacter::getPosition()
{
	return m_vPosition;
}
