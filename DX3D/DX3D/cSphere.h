#pragma once

class cSphere
{
public:
	cSphere();
	cSphere(float _x, float _y, float _z);
	~cSphere();

private:
	LPD3DXMESH		m_pMesh;
	D3DMATERIAL9	m_stMtl;

	D3DXMATRIXA16	m_matWorld;
	D3DXVECTOR3		m_vPos;
	float			m_fRadius;

	bool			m_bFlip;
public:
	void setColor(D3DXCOLOR color);
	D3DXVECTOR3& getPosition() { return m_vPos; }
	void setPosition(float _x, float _y, float _z);
	void setPosition(D3DXVECTOR3& _xyz);
	
	float getRadius() { return m_fRadius; }
	LPD3DXMESH& getMesh() { return m_pMesh; }

	void FlipColor();
	void render();
};
