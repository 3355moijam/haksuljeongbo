#pragma once
#define QUATER_SQUARE 0.0625f

class cCubePNT
{
public:
	cCubePNT();
	virtual ~cCubePNT();

	virtual void setup();
	virtual void update();
	virtual void render();

	void TextureMapping(int i, float u, float v);
	
protected:
	vector<ST_PNT_VERTEX> m_vecVertex;
	
	//static LPDIRECT3DTEXTURE9 m_pTexture;
};
