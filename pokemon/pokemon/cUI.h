#pragma once
#include "interface.h"

enum class UIState
{
	None = 0,
	OpenMenu = 1,
	Speak = 2,
	Battle = 10
};

class cUI : public cController, iActorBase
{
private:
	static HFONT hFont;
protected:
	HBITMAP hUIImg;
	BITMAP ImgData;
public:
	virtual void show(HDC hdc) = 0;
	virtual void update() = 0;
	virtual bool getInput() = 0;
};

class cUIMenu : public cUI
{
public:
	cUIMenu();
	~cUIMenu();
	void show(HDC hdc);
	void update();
	bool getInput();
};

class cUITalk : public cUI
{
public:
	cUITalk();
	~cUITalk();
	void show(HDC hdc);
	void update();
	bool getInput();
};
