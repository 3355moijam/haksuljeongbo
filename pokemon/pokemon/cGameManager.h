#pragma once
#include "stdafx.h"
enum class GameState
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
public:
	~cGameManager();
	GameState getState() { return cur_state; }
	GameState setState(GameState s) { return cur_state = s; }
	__declspec(property(get = getState, put = setState)) GameState state;
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
