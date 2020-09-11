#pragma once
#include "stdafx.h"

#include "cCharacter.h"
#include "cLoader.h"

class cUI;
class iActorBase;
enum class enumGameState
{
	Intro = 0,
	OnMap = 10,
	OnBattle = 20
};

class cGameManager : public iActorBase
{
private:
	cGameManager();
	enumGameState cur_state;
	cPlayer* _player;
	cMap** _Map;
	vector<cUI*> *activeUI;
	vector<iActorBase*> _actor;
	cMapLoader mapLoader;
	const float multiply = 4;
public:
	~cGameManager();
	enumGameState getState() { return cur_state; }
	enumGameState setState(enumGameState s) { return cur_state = s; }
	__declspec(property(get = getState, put = setState)) enumGameState state;

	cPlayer& getPlayer() { return *_player; }
	__declspec(property(get = getPlayer)) cPlayer& player;

	vector<iActorBase*>& getActor() { return _actor; }
	__declspec(property(get = getActor)) vector<iActorBase*>& actor;

	cMap& getMap() { return **_Map; }
	__declspec(property(get = getMap)) cMap& Map;

	float getMultiply() { return multiply; }
	static cGameManager &getInstance()
	{
		static cGameManager manager;
		return manager;
	}

	cGameManager(cGameManager const &) = delete;
	cGameManager(cGameManager &&) = delete;
	cGameManager &operator=(cGameManager const &) = delete;
	cGameManager &operator=(cGameManager &&) = delete;

	void LoadMap(string mapname) { mapLoader.LoadMap(mapname); }
	
	void show(HDC hdc);
	void update();
};
