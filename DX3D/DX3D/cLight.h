#pragma once

class cLight
{
protected:
	D3DLIGHT9 light;
public:
	cLight();
	virtual ~cLight();
	virtual void setup();
	virtual void update();
	virtual void render();
	
};
