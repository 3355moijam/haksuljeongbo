#include "cGameContainer.h"

extern HWND g_hWnd;

cGameContainer::cGameContainer() : scene_state(mode::MainState), game(nullptr), ui_main(), ui_game(), ui_end()
{
	//game = ;
	// >> test¿ë
	//SetTimer(hWnd, 100, 17, NULL);
	// << 
}


cGameContainer::~cGameContainer()
{
	if (game != nullptr)
		delete game;
	KillTimer(g_hWnd, 100);
}

mode cGameContainer::set_state(mode scene)
{
	// ¼Ò¸ê
	switch (scene_state)
	{
	case MainState:
		break;
	case GameState:
		if (game != nullptr)
			delete game;
		KillTimer(g_hWnd, 100);
		break;
	case EndState:
		break;
	default:
		break;
	}

	// »ý¼º
	scene_state = scene;
	switch (scene_state)
	{
	case MainState:
		break;
	case GameState:
		game = new cGame();
		SetTimer(g_hWnd, 100, 17, NULL);
		break;
	case EndState:
		break;
	default:
		break;
	}

	return scene_state;
}

void cGameContainer::draw(HDC hdc)
{
	switch (scene_state)
	{
	case MainState:
		ui_main.draw(hdc);
		break;
	case GameState:
		game->show(hdc);
		ui_game.draw(hdc);
		break;
	case EndState:
		ui_end.draw(hdc);
		break;
	default:
		break;
	}
}

void cGameContainer::update()
{
	switch (scene_state)
	{
	case MainState:
		break;
	case GameState:
		game->update();
		break;
	case EndState:
		break;
	default:
		break;
	}
}
