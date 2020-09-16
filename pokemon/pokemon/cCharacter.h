#pragma once
#include "stdafx.h"
//#include "cAnimation.h"
#include "cAnimChar.h"
#include "cMap.h"
//class cMap;
//class cWarpzone;
//class cMap;
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
	cCharacter(const rapidjson::Value& data);
	virtual ~cCharacter();

	enumDirect get_direct() const;
	void set_direct(enumDirect dir);
	__declspec(property(get = get_direct, put = set_direct)) enumDirect direct;

	void set_current_sprite(spriteState current_sprite);
	__declspec(property(put = set_current_sprite)) spriteState CurrentSprite;

	void addPos(const string& dir, short dis);

	cAnimChar& get_anim() { return anim_; }
	__declspec(property(get = get_anim)) cAnimChar& anim;
	
	bool MoveOnMap(cMap& Map, const Point& tempLoc, enumDirect dir);
	const Point& getLocationOnMap() const { return LocationOnMap; }
};

class cPlayer : public cCharacter//, public iController
{
private:
	Point CameraPivot;
	bool keyUnlock;
	cWarp warp;
	
public:
	cPlayer();
	void show(HDC hdc) override;
	void update() override;
	bool getInput();

	Point getCameraPos() const;
	void setCameraPos(const Point& camera_pivot);
	void setCameraPos() { CameraPivot.x = Tile * (LocationOnMap.x - 4); CameraPivot.y = Tile * (LocationOnMap.y - 4); }
	void addCameraPos(const string& dir, short dis);

	void setKeyUnlock(bool b) { keyUnlock = b; }
	void setKeyUnlock() { keyUnlock = !keyUnlock; }

	
	void setLocationOnMap(const Point& point)
	{
		LocationOnMap = point;
	}
	void addLocationOnMap(short x, short y)
	{
		LocationOnMap.x += x;
		LocationOnMap.y += y;
	}
	
};

class cNPC : public cCharacter, public iSpeakActor
{
private:

public:
	cNPC(const rapidjson::Value& data);
	~cNPC();
	void show(HDC hdc) override;
	void update() override;
	//bool move(cMap &map);
	void say() override;
};