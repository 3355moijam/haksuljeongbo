#pragma once
#include "stdafx.h"
enum class enumDirect
{
	LEFT,
	UP,
	RIGHT,
	DOWN
};
class cCharacter : public cContainer
{
protected:
	wstring name;
	enumDirect direct;
	POINT locationIndex;

public:
	cCharacter();
	virtual ~cCharacter();
	virtual bool move(cMap &map);
};

class cPlayer : public cCharacter
{
public:
	cPlayer();
	void show(HDC hdc);
	void update();
	bool move(cMap &map);
};

class cNPC : public cCharacter
{
private:
	vector<wstring> dialog;
	wstring cur_dialog;
	unsigned int countMeet;

public:
	cNPC();
	void show(HDC hdc);
	void update();
	bool move(cMap &map);
};