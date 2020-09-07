#pragma once
#include "stdafx.h"
//#include "cAnimation.h"
#include "cAnimChar.h"
class cMap;
//class cCharAnim;
//class cCharacter;

enum class animState
{
	MOVE_DOWN,
	ROT_DOWN,
	JUMP_DOWN,
	STOP_DOWN,
	MOVE_UP,
	ROT_UP,
	JUMP_UP,
	STOP_UP,
	MOVE_LEFT,
	ROT_LEFT,
	JUMP_LEFT,
	STOP_LEFT,
	MOVE_RIGHT,
	ROT_RIGHT,
	JUMP_RIGHT,
	STOP_RIGHT
};
enum class spriteState
{
	DOWN,
	DOWN_MOVE_1,
	DOWN_MOVE_2,
	UP,
	UP_MOVE_1,
	UP_MOVE_2,
	LEFT,
	LEFT_MOVE,
	RIGHT,
	RIGHT_MOVE
};
enum class enumDirect
{
	LEFT = static_cast<int>(spriteState::LEFT),
	UP = static_cast<int>(spriteState::UP),
	RIGHT = static_cast<int>(spriteState::RIGHT),
	DOWN = static_cast<int>(spriteState::DOWN)
};

class cCharacter : public iActorBase
{
protected:
	string name;
	enumDirect direct_;
	spriteState currentSprite;
	Point LocationOnMap;
	Point DrawPos;
	HBITMAP hImg;
	BITMAP bitmapData;
	cAnimChar anim_;
	bool isJumping;
public:
	cCharacter();
	//cCharacter(const rapidjson::Value data);
	virtual ~cCharacter();

	enumDirect get_direct() const;
	void set_direct(enumDirect dir);
	__declspec(property(get = get_direct, put = set_direct)) enumDirect direct;

	void set_current_sprite(spriteState current_sprite);
	__declspec(property(put = set_current_sprite)) spriteState CurrentSprite;

	void addPos(const string& dir, short dis);

	bool MoveOnMap(cMap& Map, const Point& tempLoc, enumDirect dir);
};

class cPlayer : public cCharacter//, public iController
{
private:
	Point CameraPivot;
	bool keyUnlock;
public:
	cPlayer();
	void show(HDC hdc) override;
	void update() override;
	bool getInput();

	Point getCameraPos() const;
	void setCameraPos(const Point& camera_pivot);
	void addCameraPos(const string& dir, short dis);

	void setKeyUnlock(bool b) { keyUnlock = b; }
	void setKeyUnlock() { keyUnlock = !keyUnlock; }
};

class cNPC : public cCharacter, public iSpeakActor
{
private:

public:
	cNPC();
	void show(HDC hdc) override;
	void update() override;
	bool move(cMap &map);
	void say() override;
};