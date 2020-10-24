#include "stdafx.h"
#include "CRay.h"
#include "cSphere.h"
#include "cGrid2.h"

CRay::CRay(): m_vecLeftTarget(nullptr), m_RightTarget(nullptr)
{
}

CRay::~CRay()
{
}

void CRay::setup(vector<cSphere*>* left, cGrid2* right)
{
	m_vecLeftTarget = left;
	m_RightTarget = right;
}

void CRay::SetPosDir(float _x, float _y)
{
	D3DXMATRIXA16 matProj, matViewInv;
	D3DVIEWPORT9 viewport;
	g_pD3DDevice->GetViewport(&viewport);
	g_pD3DDevice->GetTransform(D3DTS_PROJECTION, &matProj);
	//D3DXMatrixInverse(&matProjInv, NULL, &matProjInv);
	g_pD3DDevice->GetTransform(D3DTS_VIEW, &matViewInv);
	D3DXMatrixInverse(&matViewInv, NULL, &matViewInv);

	
	float px = (((2 * _x) / viewport.Width) - 1.0f) / matProj._11;
	float py = (((-2 * _y) / viewport.Height) + 1.0f) / matProj._22;
	float pz = 1.0f;

	//D3DXVECTOR3 vTemp(px, py, pz);
	//D3DXVec3TransformCoord(&m_vDir, &vTemp, &matProjInv);
	
	m_vPos = D3DXVECTOR3(0, 0, 0);
	m_vDir = D3DXVECTOR3(px, py, pz);
	
	D3DXVec3TransformCoord(&m_vPos, &m_vPos, &matViewInv);
	D3DXVec3TransformNormal(&m_vDir, &m_vDir, &matViewInv);
	D3DXVec3Normalize(&m_vDir, &m_vDir);

	//D3DXVec3Unproject()
}

bool CRay::SphereIntersect(cSphere* sphere)
{
	return D3DXSphereBoundProbe(&sphere->getPosition(), sphere->getRadius(), &m_vPos, &m_vDir);
	D3DXVECTOR3 v = m_vPos - sphere->getPosition();

	float b = 2.0f * D3DXVec3Dot(&m_vDir, &v);
	float c = D3DXVec3Dot(&v, &v) - (sphere->getRadius() * sphere->getRadius());

	float fDiscriminant = (b * b) - (4.0f * c);

	if (fDiscriminant < 0.0f)
		return false;
	fDiscriminant = sqrt(fDiscriminant);

	float s0 = (-b + fDiscriminant) / 2.0f;
	float s1 = (-b - fDiscriminant) / 2.0f;

	if (s0 >= 0.0f || s1 >= 0.0f)
		return true;
	return false;
}

cSphere* CRay::getLeftClickCheck(int _x, int _y)
{
	SetPosDir(_x, _y);
	cSphere* nearest = nullptr;
	float fNear = 99999;
	for (auto * target : *m_vecLeftTarget)
	{
		if (SphereIntersect(target))
		{
			if (nearest)
			{
				float fTempDist = D3DXVec3Length(&(m_vPos - target->getPosition()));
				if(fTempDist < fNear)
				{
					nearest = target;
					fNear = fTempDist;
				}
			}
			else
			{
				nearest = target;
				fNear = D3DXVec3Length(&(m_vPos - target->getPosition()));
			}
		}
	}
	return nearest;
}

bool CRay::getRightClickCheck(int _x, int _y, D3DXVECTOR3& vRet)
{
	SetPosDir(_x, _y);
	float garbage, fDist;
	DWORD dFaceIndex;
	BOOL isHit;
	D3DXIntersect(m_RightTarget->GetMesh(), &m_vPos, &m_vDir, &isHit, &dFaceIndex, &garbage, &garbage, &fDist, NULL, NULL);

	//D3DXVECTOR3 vRet{};
	if(isHit)
	{
		vRet = m_vPos + m_vDir * fDist;
	}
	return isHit;
}

void CRay::render()
{
	vector<D3DXVECTOR3> vecTemp;
	vecTemp.push_back(m_vPos);
	vecTemp.push_back(m_vPos + m_vDir * 50);

	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);

	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(D3DFVF_XYZ);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_LINELIST, 1, &vecTemp[0], sizeof D3DXVECTOR3);
}
