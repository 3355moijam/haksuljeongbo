#pragma once
#include "cLight.h"

class cSpotLight : public cLight
{
private:
	LPD3DXMESH m_pCylinder;
	D3DXVECTOR3 m_Rotation;
	D3DXVECTOR3 m_Position;
	
	D3DXMATRIXA16 matT, matRX, matRZ, matWorld, matLocalT, matLocalR;
public:


	cSpotLight();

	~cSpotLight() override;
	void setup() override;
	void update() override;
	void render() override;
};
