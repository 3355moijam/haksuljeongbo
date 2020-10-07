#pragma once
#include "cLight.h"

class cPointLight : public cLight
{
private:
	LPD3DXMESH m_pSphere;
	D3DXVECTOR3 m_Scale;
	D3DXVECTOR3 m_Position;
public:
	explicit cPointLight();

	~cPointLight() override;
	void setup() override;
	void update() override;
	void render() override;
};
