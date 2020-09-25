#pragma once

class cCubePC
{
private:
	vector<ST_PC_VERTEX>	m_vecVertex;
	float					m_fRotY;
	D3DXVECTOR3				m_vDirection;
	D3DXVECTOR3				m_vPosition;
	D3DXMATRIXA16			m_matWorld;
	
public:
	cCubePC();
	~cCubePC();

	void setup();
	void update();
	void render();

	D3DXVECTOR3& getPosition() { return m_vPosition; }
};
