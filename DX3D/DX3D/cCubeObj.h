#pragma once

class cCubeObj
{
public:
	cCubeObj();
	~cCubeObj();

	void setup();
	void update();
	void render();
private:
	vector<ST_PNT_VERTEX> m_vecVertex;
	D3DMATERIAL9 m_stMtl;
	LPDIRECT3DTEXTURE9 m_pTexture;
	
};
