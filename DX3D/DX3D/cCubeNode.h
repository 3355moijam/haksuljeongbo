#pragma once
#include "cCubePNT.h"


class cCubeNode : public cCubePNT
{
public:
	cCubeNode();

protected:
	float			m_fRotX;
	D3DXVECTOR3		m_vLocalPos;
	D3DXMATRIXA16	m_matLocalTM;
	D3DXMATRIXA16	m_matWorldTM;

	vector<cCubeNode*> m_vecChild;

	Synthesize(D3DXMATRIXA16*, m_pParentWorldTM, ParentWorldTM);
	Synthesize(float, m_fRotDeltaX, RotDeltaX);

public:
	virtual ~cCubeNode();

	virtual void AddChild(cCubeNode* pChild);
	virtual void Destroy();

	virtual void setup() override;
	virtual void update() override;
	virtual void render() override;
};
