#pragma once

class CSkinnedMesh;

class COBB
{
public:
	COBB();
	~COBB();

private:
	D3DXVECTOR3			m_vOriginCenterPos;
	D3DXVECTOR3			m_vOriginAxisDir[3];

	D3DXVECTOR3			m_vCenterPos;
	D3DXVECTOR3			m_vAxisDir[3];
	float				m_fAxisLen[3];

	float				m_fAxisHalfLen[3];

	D3DXMATRIXA16		m_matWorldTM;

public:
	void Setup(CSkinnedMesh* pSkinnedMesh);
	void Update(D3DXMATRIXA16 * pmatWorld);
	static bool IsCollision(COBB * pOBB1, COBB* pOBB2);

	void OBBBOX_Render(D3DCOLOR c);
};
