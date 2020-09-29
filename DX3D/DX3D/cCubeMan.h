#pragma once
#include "cCharacter.h"

class cCubeNode;

class cCubeMan : public cCharacter
{
public:
	cCubeMan();
	virtual ~cCubeMan();

protected:
	cCubeNode*			m_pRoot;
	D3DMATERIAL9		m_stMtl;
public:
	virtual void setup() override;
	virtual void update() override;
	virtual void render() override;
};
