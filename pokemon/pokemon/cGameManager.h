#pragma once
#include "stdafx.h"

class cGameManager
{
private:
	cGameManager();

public:
	~cGameManager();

	cGameManager &getInstance()
	{
		static cGameManager manager;
		return manager;
	}

	cGameManager(cGameManager const &) = delete;
	cGameManager(cGameManager &&) = delete;
	cGameManager &operator=(cGameManager const &) = delete;
	cGameManager &operator=(cGameManager &&) = delete;
};
