#include "stdafx.h"
#include "cObjMap.h"
#include "cObjectLoader.h"


cObjMap::cObjMap(char* szFolder, char* szFile, D3DXMATRIXA16* pmat)
{
	Load(szFolder, szFile, pmat);
}

cObjMap::~cObjMap()
{
}

void cObjMap::Load(char* szFolder, char* szFile, D3DXMATRIXA16* pmat)
{
	cObjectLoader l;
	l.LoadSurface(m_vecSurface, szFolder, szFile, pmat);
}

bool cObjMap::GetHeight(float x, float& y, float z)
{
	D3DXVECTOR3 vRayPos(x, y + 1, z);
	D3DXVECTOR3 vRayDir(0, -1, 0);

	for (int i = 0; i < m_vecSurface.size(); i += 3)
	{
		float u, v, f;
		if (D3DXIntersectTri
		(
			&m_vecSurface[i + 0],
			&m_vecSurface[i + 1],
			&m_vecSurface[i + 2],
			&vRayPos,
			&vRayDir,
			&u, &v,
			&f
		))
		{
			if (f > 3.0f + 0.9f)
				return false;
			y += 1 - f + 0.9f;
			return true;
		}
	}
	return false;
}

