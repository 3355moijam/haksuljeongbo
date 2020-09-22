#include "stdafx.h"
#include "cCharacter.h"

#include "cGameManager.h"
#pragma comment (lib, "Msimg32.lib")
#include <algorithm>

//#ifdef _DEBUG
//#include <iostream>
//using std::cout;
//using std::endl;
//#endif


void cCharacter::set_current_sprite(spriteState current_sprite)
{
	currentSprite = current_sprite;
}

void cCharacter::addPos(const string& dir, short dis)
{
	if (dir == "x")
		DrawPos.x += dis;
	else if (dir == "y")
		DrawPos.y += dis;
}

bool cCharacter::MoveOnMap(cMap& Map, const Point& tempLoc, enumDirect dir)
{
	direct_ = dir;
	switch (static_cast<enumMapStatus>(Map[tempLoc.y][tempLoc.x]))
	{
	case enumMapStatus::movable:
	case enumMapStatus::grass:
	case enumMapStatus::door:
		LocationOnMap = tempLoc;
		switch (dir)
		{
		case enumDirect::LEFT: 
			anim_.setAnim(animState::MOVE_LEFT);
			break;
		case enumDirect::UP: 
			anim_.setAnim(animState::MOVE_UP);
			break;
		case enumDirect::RIGHT: 
			anim_.setAnim(animState::MOVE_RIGHT);
			break;
		case enumDirect::DOWN: 
			anim_.setAnim(animState::MOVE_DOWN);
			break;
		default: break;
		}
		return true;
		break;
		
	case enumMapStatus::unmovable: 
	case enumMapStatus::sea: 
	case enumMapStatus::notice: 
	case enumMapStatus::cuttableTree: 
	case enumMapStatus::berryTree: 
	case enumMapStatus::item: 
	case enumMapStatus::poke:
		{
			switch (direct_)
			{
			case enumDirect::LEFT: 
				anim_.setAnim(animState::STOP_LEFT);
				break;
			case enumDirect::UP: 
				anim_.setAnim(animState::STOP_UP);
				break;
			case enumDirect::RIGHT: 
				anim_.setAnim(animState::STOP_RIGHT);
				break;
			case enumDirect::DOWN: 
				anim_.setAnim(animState::STOP_DOWN);
				break;
			default: break;
			}
		}
		return false;
		break;
		
	case enumMapStatus::lslope:
	{
		switch (direct_)
		{
		case enumDirect::LEFT:
			LocationOnMap = tempLoc;
			LocationOnMap.x--;
			anim_.setAnim(animState::JUMP_LEFT);
			break;
		case enumDirect::UP:
			anim_.setAnim(animState::STOP_UP);
			break;
		case enumDirect::RIGHT:
			anim_.setAnim(animState::STOP_RIGHT);
			break;
		case enumDirect::DOWN:
			anim_.setAnim(animState::STOP_DOWN);
			break;
		}
	}
		break;
	case enumMapStatus::rslope:
	{
		switch (direct_)
		{
		case enumDirect::LEFT:
			anim_.setAnim(animState::STOP_LEFT);
			break;
		case enumDirect::UP:
			anim_.setAnim(animState::STOP_UP);
			break;
		case enumDirect::RIGHT:
			LocationOnMap = tempLoc;
			LocationOnMap.x++;
			anim_.setAnim(animState::JUMP_RIGHT);
			break;
		case enumDirect::DOWN:
			anim_.setAnim(animState::STOP_DOWN);
			break;
		}
	}
		break;
	case enumMapStatus::uslope:
	{
		switch (direct_)
		{
		case enumDirect::LEFT:
			anim_.setAnim(animState::STOP_LEFT);
			break;
		case enumDirect::UP:
			LocationOnMap = tempLoc;
			LocationOnMap.y--;
			anim_.setAnim(animState::JUMP_UP);
			break;
		case enumDirect::RIGHT:
			anim_.setAnim(animState::STOP_RIGHT);
			break;
		case enumDirect::DOWN:
			anim_.setAnim(animState::STOP_DOWN);
			break;
		}
	}
		break;
	case enumMapStatus::dslope:
	{
		switch (direct_)
		{
		case enumDirect::LEFT:
			anim_.setAnim(animState::STOP_LEFT);
			break;
		case enumDirect::UP:
			anim_.setAnim(animState::STOP_UP);
			break;
		case enumDirect::RIGHT:
			anim_.setAnim(animState::STOP_RIGHT);
			break;
		case enumDirect::DOWN:
			LocationOnMap = tempLoc;
			LocationOnMap.y++;
			anim_.setAnim(animState::JUMP_DOWN);
			break;
		}
	}
		break;
		
	case enumMapStatus::linkedMap:
		LocationOnMap = tempLoc;
		anim_.setAnim(animState::MOVE_UP);
		break;
		
	//case enumMapStatus::door:
	//	// 앞으로 걷기
	//	// 걷기 애니메이션 끝난 후 맵 전환
	//	// json에 도착xy 추가.
	//	break;

	default:
		break;
	}
	return false;
}

bool cCharacter::StopMove(enumDirect direct)
{
	direct_ = direct;
	switch (direct_)
	{
	case enumDirect::LEFT:
		anim_.setAnim(animState::STOP_LEFT);
		break;
	case enumDirect::UP:
		anim_.setAnim(animState::STOP_UP);
		break;
	case enumDirect::RIGHT:
		anim_.setAnim(animState::STOP_RIGHT);
		break;
	case enumDirect::DOWN:
		anim_.setAnim(animState::STOP_DOWN);
		break;
	default: break;
	}
	return false;
}


Point cPlayer::getCameraPos() const
{
	return CameraPivot;
}

void cPlayer::setCameraPos(const Point& camera_pivot)
{
	CameraPivot = camera_pivot;
}

void cPlayer::addCameraPos(const string& dir, short dis)
{
	if (dir == "x")
		CameraPivot.x += dis;
	else if (dir == "y")
		CameraPivot.y += dis;
}

iSpeakActor* cPlayer::checkSpeaker(Point& front)
{
	cMap& cur_map = cGameManager::getInstance().Map;

	for (auto & speaker : cur_map.Speaker)
	{
		if (cNPC* npc = dynamic_cast<cNPC*>(speaker))
			if (npc->getLocationOnMap() == front)
				return speaker;
	}

	return nullptr;
}

cNPC::cNPC(const rapidjson::Value &data) : cCharacter(data)
{
	
}

cNPC::~cNPC()
{
}

void cNPC::show(HDC hdc)
{
	HDC hImgMemDC = CreateCompatibleDC(hdc);
	cPlayer& player = cGameManager::getInstance().player;
	HBITMAP hOldBitmap = static_cast<HBITMAP>(SelectObject(hImgMemDC, hImg));
	int bx = bitmapData.bmWidth;
	int by = bitmapData.bmHeight; // DrawPos 
	TransparentBlt(hdc, DrawPos.x - player.getCameraPos().x, DrawPos.y - player.getCameraPos().y, 16, 16, hImgMemDC, 16 * static_cast<int>(currentSprite), 0, 16, 16, RGB(255, 0, 255));
	SelectObject(hImgMemDC, hOldBitmap);
	DeleteDC(hImgMemDC);
}

void cNPC::update()
{
}

void cNPC::say()
{
}


cCharacter::cCharacter()
	: name("player"),
	direct_(enumDirect::DOWN),
	LocationOnMap(2, 3),
	DrawPos(4 * Tile, 4 * Tile - 4)
	//, animation()
	,currentSprite(spriteState::DOWN)
{
	
	
}

cCharacter::cCharacter(const rapidjson::Value& data)
	: name(data["name"].GetString()),
	direct_(enumDirect::DOWN),
	LocationOnMap(data["pos"]["x"].GetInt(), data["pos"]["y"].GetInt()),
	DrawPos(LocationOnMap * Tile),
	currentSprite(spriteState::DOWN)
{	
	DrawPos.y -= 4;

	string tempSrc(data["imgSrc"].GetString(), data["imgSrc"].GetStringLength());
	wstring tempWsrc;
	tempWsrc.assign(tempSrc.begin(), tempSrc.end());
	hImg = static_cast<HBITMAP>(LoadImage(NULL, tempWsrc.c_str(),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
	GetObject(hImg, sizeof(BITMAP), &bitmapData);

	if (data.HasMember("direct"))
	{
		direct_ = (enumDirect)data["direct"].GetInt();
		currentSprite = (spriteState)data["direct"].GetInt();
	}
}

cCharacter::~cCharacter()
{
}

enumDirect cCharacter::get_direct() const
{
	return direct_;
}

void cCharacter::set_direct(enumDirect dir)
{
	direct_ = dir;
}

cPlayer::cPlayer() : cCharacter(), CameraPivot(Tile * (LocationOnMap.x - 4), Tile * (LocationOnMap.y - 4)), keyUnlock(true), warp(this)
{
	hImg = static_cast<HBITMAP>(LoadImage(NULL, _T("src/gold_sprite.bmp"),
	                                      IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION));
	GetObject(hImg, sizeof(BITMAP), &bitmapData);
}

void cPlayer::show(HDC hdc)
{
	HDC hImgMemDC = CreateCompatibleDC(hdc);

	HBITMAP hOldBitmap = static_cast<HBITMAP>(SelectObject(hImgMemDC, hImg));
	int bx = bitmapData.bmWidth;
	int by = bitmapData.bmHeight; // DrawPos 
	TransparentBlt(hdc, DrawPos.x, DrawPos.y, 16, 16, hImgMemDC, 16 * static_cast<int>(currentSprite), 0, 16, 16, RGB(255,0,255));
	SelectObject(hImgMemDC, hOldBitmap);
	if(warp.get_timer())
		warp.show(hdc);
	DeleteDC(hImgMemDC);
}

void cPlayer::update()
{
	cMap& cur_map = cGameManager::getInstance().Map;
	if(static_cast<enumMapStatus>(cur_map[LocationOnMap.y][LocationOnMap.x]) == enumMapStatus::linkedMap && keyUnlock)
	{
		// set fade_out func fade_in
		anim_.clear(); // 애님큐 비우기
		map<Point, cWarpzone>::const_iterator it = cur_map.LinkedMap.find(LocationOnMap);
		warp.set_timer();
		warp.set_destination(it->second);
		keyUnlock = false;
	}
	if (warp.get_timer() == 0)
	{
		//_D cout << "x: " << LocationOnMap.x << ", y:" << LocationOnMap.y << endl;;
		getInput();
		anim_.playAnim(this);
	}
	else
	{
		warp.update();
	}
	// check warp
}

bool cPlayer::getInput()
{
	if (!keyUnlock)
		return false;
	Point tempLocation = LocationOnMap;
	cMap& currentMap = cGameManager::getInstance().Map;
	enumDirect dir = (enumDirect)0;
	animState rot = (animState)0;
	bool iskeyDownArrow = false;
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		dir = enumDirect::LEFT;
		rot = animState::ROT_LEFT;
		tempLocation.x--;
		iskeyDownArrow = true;
	}
	else if (GetKeyState(VK_UP) & 0x8000)
	{
		dir = enumDirect::UP;
		rot = animState::ROT_UP;
		tempLocation.y--;
		iskeyDownArrow = true;
	}
	else if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		dir = enumDirect::RIGHT;
		rot = animState::ROT_RIGHT;
		tempLocation.x++;
		iskeyDownArrow = true;
	}
	else if (GetKeyState(VK_DOWN) & 0x8000)
	{
		dir = enumDirect::DOWN;
		rot = animState::ROT_DOWN;
		tempLocation.y++;
		iskeyDownArrow = true;
	}
	else if (GetKeyState('z') & 0x8000 || GetKeyState('Z') & 0x8000)
	{
		
	}
	else if (GetKeyState('x') & 0x8000 || GetKeyState('X') & 0x8000)
	{

	}
	else if (GetKeyState(VK_RETURN) & 0x8000)
	{

	}
	iSpeakActor* target_before_player = checkSpeaker(tempLocation);

	if (iskeyDownArrow)
	{
		if (direct_ != dir && anim_.getRemainFrame() == 0)
		{
			anim_.setAnim(rot);
			direct_ = dir;
		}
		else
		{
			// ui 열려있는지 확인.
			// 열렸을 때
			// 안열렸을 때
			//if (!tempLocation.isOnMap(currentMap.getWidth(), currentMap.getHeight()))
			if (!currentMap.isOnMap(tempLocation))
			{
				// 현재 위치가 door이면 워프
				if(currentMap[LocationOnMap] == (int) enumMapStatus::door)
				{
					anim_.clear();
					map<Point, cWarpzone>::const_iterator it = currentMap.LinkedMap.find(LocationOnMap);
					warp.set_timer();
					warp.set_destination(it->second);
					keyUnlock = false;
					switch (dir)
					{
					case enumDirect::LEFT:
						currentSprite = spriteState::LEFT;
						break;
					case enumDirect::UP:
						currentSprite = spriteState::UP;
						break;
					case enumDirect::RIGHT:
						currentSprite = spriteState::RIGHT;
						break;
					case enumDirect::DOWN:
						currentSprite = spriteState::DOWN;
						break;
					}
				}
				else
				{
					// stop모션
					StopMove(dir);
				}
			}
			else
			{
				// temploc에 npc가 있다면 stop anim;
				if (target_before_player)
					return StopMove(dir);
				
				return MoveOnMap(currentMap, tempLocation, dir);
			}
		}
	}

	
	return false;
}