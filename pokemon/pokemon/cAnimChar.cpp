#include "stdafx.h"
#include "cAnimChar.h"

#include "cLoader.h"
#include "cCharacter.h"
//
//vector<vector<short>> cAnimChar::keyFrameData;// = vector<vector<short>>();
//vector<vector<to_dir>> cAnimChar::moveData;// = vector<vector<to_dir>>();
//vector<vector<to_dir>> cAnimChar::cameraMove;// = vector<vector<to_dir>>();
//vector<vector<short>> cAnimChar::keyUnlock;// = vector<vector<short>>();

vector<vector<short>> cAnimChar::keyFrameData = vector<vector<short>>();
vector<vector<to_dir>> cAnimChar::moveData = vector<vector<to_dir>>();
vector<vector<to_dir>> cAnimChar::cameraMove = vector<vector<to_dir>>();
vector<vector<short>> cAnimChar::keyUnlock = vector<vector<short>>();

cAnimChar::cAnimChar()
	: cameraQ(),
	unlockQ(),
	moveQ(),
	frameData(),
	//remain_frame(),
	current_foot()
{
	if(keyFrameData.empty())
	{
		cAnimCharLoader loader;
		loader.LoadAnim("character");
	}
}

cAnimChar::~cAnimChar()
{
}

void cAnimChar::setAnim(animState anim)
{
	while (!frameData.empty())
		frameData.pop();
	while (!unlockQ.empty())
		unlockQ.pop();
	for (short ele : keyFrameData[static_cast<int>(anim)])
	{
		if (ele == static_cast<short>(spriteState::DOWN_MOVE_1) || ele == static_cast<short>(spriteState::UP_MOVE_1))
			frameData.emplace(ele + current_foot);
		else
			frameData.emplace(ele);
	}
	current_foot = !current_foot;
	for (short ele : keyUnlock[static_cast<int>(anim)])
	{
		unlockQ.emplace(ele);
	}
	for (const to_dir& ele : moveData[static_cast<int>(anim)])
	{
		moveQ.emplace(ele);
	}
	for (const to_dir& ele : cameraMove[static_cast<int>(anim)])
	{
		cameraQ.emplace(ele);
	}
}

void cAnimChar::playAnim(cCharacter* target)
{
	if(!frameData.empty())
	{
		short temp = frameData.front();
		target->CurrentSprite = static_cast<spriteState> (temp);
		frameData.pop();
	}
	if(!moveQ.empty())
	{
		to_dir temp = moveQ.front();
		target->addPos(temp.xy, temp.distance);
		moveQ.pop();
	}
	if(auto* player = dynamic_cast<cPlayer*> (target))
	{
		if(!unlockQ.empty())
		{
			bool temp = unlockQ.front();
			player->setKeyUnlock(temp);
			unlockQ.pop();
		}
		if(!cameraQ.empty())
		{
			to_dir temp = cameraQ.front();
			player->addCameraPos(temp.xy, temp.distance);
			cameraQ.pop();
		}
	}
	else
	{
		if (!cameraQ.empty())
		{
			to_dir temp = cameraQ.front();
			target->addPos(temp.xy, temp.distance);
			cameraQ.pop();
		}
	}
}

void cAnimChar::clear()
{
	while (!frameData.empty())
		frameData.pop();
	while (!unlockQ.empty())
		unlockQ.pop();
	while (!cameraQ.empty())
		frameData.pop();
	while (!moveQ.empty())
		unlockQ.pop();
}
