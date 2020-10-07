#pragma once
#include "cCharacter.h"

class cCubeNode;

class cCubeMan2 : public cCharacter
{
public:
	cCubeMan2();
	virtual ~cCubeMan2();

protected:
	cCubeNode*			m_pRoot;
	D3DMATERIAL9		m_stMtl;
	int					m_destID;
	vector<ST_PC_VERTEX>* m_pTraceline;
	float				m_fSpeed;

public:
	virtual void setup() override;
	virtual void update() override;
	virtual void render() override;
	void setGuide(vector<ST_PC_VERTEX>& line);
	LPDIRECT3DTEXTURE9 m_pTexture;
};
