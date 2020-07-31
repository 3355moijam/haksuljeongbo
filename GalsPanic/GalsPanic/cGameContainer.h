#pragma once
#include "framework.h"
//#include "cGame.h"
//#include "cUI.h"
enum mode { MainState, GameState, EndState };
class cGame;

class cGameContainer
{
private:
	cGame *game;
	cMainUI ui_main;
	cGameUI ui_game;
	cEndUI ui_end;

	mode scene_state;
public:
	cGameContainer();
	~cGameContainer();
	mode get_state() { return scene_state; }
	mode set_state(mode scene);
	void draw(HDC hdc);
	void update();
};

