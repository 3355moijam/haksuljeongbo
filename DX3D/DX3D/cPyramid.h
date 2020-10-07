#pragma once

class cPyramid
{
public:
	cPyramid();
	~cPyramid();

private:
	vector<ST_PC_VERTEX>	m_vecVertex;
	D3DXMATRIXA16			m_matR;
	D3DXMATRIXA16			m_matT;

public:
	void setup(D3DCOLOR c, D3DXMATRIXA16& matR, D3DXVECTOR3& pos = D3DXVECTOR3(0,0,0));
	//void setup(D3DCOLOR c, D3DXMATRIXA16& matR, D3DXVECTOR3& pos);
	void render();
};
