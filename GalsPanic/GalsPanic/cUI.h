#pragma once
#include "framework.h"


class cUI
{
private:

public:
	cUI();
	static HFONT hFontNanum;
	virtual ~cUI();
	virtual void draw(HDC hdc) = 0;
};

class cMainUI : public cUI
{

public:
	cMainUI();
	void draw(HDC hdc);
};

class cGameUI : public cUI
{

public:
	cGameUI();
	void draw(HDC hdc);
};

class cEndUI : public cUI
{

public:
	cEndUI();
	void draw(HDC hdc);
};
