#pragma once
#include <vector>

#include "cGroup.h"

class cCharacter
{
public:
	cCharacter();
	//~cCharacter();

protected:
	float			m_fRotY;
	D3DXVECTOR3		m_vDirection;
	D3DXVECTOR3		m_vPosition;
	D3DXMATRIXA16	m_matWorld;

public:
	virtual ~cCharacter();
	virtual void setup();
	virtual void update(const vector<cGroup*>& floor = vector<cGroup*>());
	virtual void render();

	virtual D3DXVECTOR3& getPosition();
	
};
