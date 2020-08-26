#pragma once
#include "stdafx.h"

enum class enumGameState
{
	Intro = 0,
	OnMap = 10,
	OnBattle = 20
};

class cGameManager
{
private:
	cGameManager();
	GameState cur_state;
	cPlayer* _player;
	cMap* map;
	vector<cUI*> &activeUI;
	const unsigned short multiply = 4;
public:
	~cGameManager();
	GameState getState() { return cur_state; }
	GameState setState(GameState s) { return cur_state = s; }
	__declspec(property(get = getState, put = setState)) GameState state;

	cPlayer& getPlayer() { return *_player; }
	__declspec(property(get = getPlayer)) cPlayer& player;

	unsigned short getMultiply() { return multiply; }
	cGameManager &getInstance()
	{
		static cGameManager manager;
		//manager.state = GameState::OnMap; // 생성자로
		return manager;
	}

	cGameManager(cGameManager const &) = delete;
	cGameManager(cGameManager &&) = delete;
	cGameManager &operator=(cGameManager const &) = delete;
	cGameManager &operator=(cGameManager &&) = delete;
};
