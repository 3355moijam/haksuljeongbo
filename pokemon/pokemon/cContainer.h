#pragma once
class cContainer
{
public:
	cContainer();
	virtual ~cContainer();
	virtual void show(HDC hdc) {}
	virtual void update() {}
};

