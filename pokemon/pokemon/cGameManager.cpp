#include "stdafx.h"
#include "cGameManager.h"


cGameManager::cGameManager(): cur_state(enumGameState::OnMap), mapLoader()
{
	_Map = mapLoader.LoadMap("playerhouse00");
	_player = new cPlayer();
}


cGameManager::~cGameManager()
{
	delete _player;
}

void cGameManager::show(HDC hdc)
{
	(*_Map)->show(hdc);
	_player->show(hdc);
	//player->show(hdc);
}

void cGameManager::update()
{
	_player->update();
	//for (auto& ac : _actor)
		//ac->update();
}
