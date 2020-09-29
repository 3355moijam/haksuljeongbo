#pragma once

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
	virtual void update();
	virtual void render();

	virtual D3DXVECTOR3& getPosition();
	
};
