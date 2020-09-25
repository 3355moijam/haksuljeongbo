#pragma once

class cPyramid
{
public:
	cPyramid();
	~cPyramid();

private:
	vector<ST_PC_VERTEX>	m_vecVertex;
	D3DXMATRIXA16			m_matR;

public:
	void setup(D3DCOLOR c, D3DXMATRIXA16& mat);
	void render();
};
