#include "stdafx.h"
#include "cCharacter.h"

#include "cGameManager.h"
#pragma comment (lib, "Msimg32.lib")

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
		break;
	case enumMapStatus::rslope: 
		break;
	case enumMapStatus::uslope: 
		break;
	case enumMapStatus::dslope: 
		break;
		
	case enumMapStatus::linkedMap:
		LocationOnMap = tempLoc;
		anim_.setAnim(animState::MOVE_UP);
		break;
		
	case enumMapStatus::door:
		// ������ �ȱ�
		// �ȱ� �ִϸ��̼� ���� �� �� ��ȯ
		// json�� ����xy �߰�.
		break;

	default:
		break;
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



cCharacter::cCharacter()
	: name("player"),
	direct_(enumDirect::DOWN),
	LocationOnMap(73, 9),
	DrawPos(LocationOnMap.x * Tile, LocationOnMap.y * Tile - 4)
	//, animation()
	,currentSprite(spriteState::DOWN)
{
	
	
}

//cCharacter::cCharacter(const rapidjson::Value data)
//{
//}

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
	int by = bitmapData.bmHeight;
	TransparentBlt(hdc, DrawPos.x, DrawPos.y, 16, 16, hImgMemDC, 16 * static_cast<int>(currentSprite), 0, 16, 16, RGB(255,0,255));
	SelectObject(hImgMemDC, hOldBitmap);
	//if(warp.get_timer())
	//	warp.show(hdc);
	DeleteDC(hImgMemDC);
}

void cPlayer::update()
{
	cMap& cur_map = cGameManager::getInstance().Map;
	if(static_cast<enumMapStatus>(cur_map[LocationOnMap.y][LocationOnMap.x]) == enumMapStatus::linkedMap && keyUnlock)
	{
		// set fade_out func fade_in
		map<Point, cWarpzone>::const_iterator it = cur_map.LinkedMap.find(LocationOnMap);
		warp.set_timer();
		warp.set_destination(it->second);
		keyUnlock = false;
	}
	if (warp.get_timer() == 0)
	{
		_D cout << "x: " << LocationOnMap.x << ", y:" << LocationOnMap.y << endl;;
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
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		if (direct_ != enumDirect::LEFT && anim_.getRemainFrame() == 0)
		{
			anim_.setAnim(animState::ROT_LEFT);
			direct_ = enumDirect::LEFT;
		}
		else
		{
			// ui �����ִ��� Ȯ��.
			// ������ ��
			// �ȿ����� ��
			tempLocation.x--;
			if (!tempLocation.isOnMap(currentMap.getWidth(), currentMap.getHeight()))
			{
				// ���� ��ġ�� �������̸� ����
				return false;
			}
			else
			{
				// temploc�� npc�� �ִٸ� stop anim;
				return MoveOnMap(currentMap, tempLocation, enumDirect::LEFT);
			}
		}
	}
	else if (GetKeyState(VK_UP) & 0x8000)
	{
		if (direct_ != enumDirect::UP && anim_.getRemainFrame() == 0)
		{
			anim_.setAnim(animState::ROT_UP);
			direct_ = enumDirect::UP;
		}
		else
		{
			// ui �����ִ��� Ȯ��.
			// ������ ��
			// �ȿ����� ��
			tempLocation.y--;
			if (!tempLocation.isOnMap(currentMap.getWidth(), currentMap.getHeight()))
			{
				// ���� ��ġ�� �������̸� ����
				return false;
			}
			else
			{
				return MoveOnMap(currentMap, tempLocation, enumDirect::UP);
			}
		}
	}
	else if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		if (direct_ != enumDirect::RIGHT && anim_.getRemainFrame() == 0)
		{
			anim_.setAnim(animState::ROT_RIGHT);
			direct_ = enumDirect::RIGHT;
		}
		else
		{
			// ui �����ִ��� Ȯ��.
			// ������ ��
			// �ȿ����� ��
			tempLocation.x++;
			if (!tempLocation.isOnMap(currentMap.getWidth(), currentMap.getHeight()))
			{
				// ���� ��ġ�� �������̸� ����
				return false;
			}
			else
			{
				return MoveOnMap(currentMap, tempLocation, enumDirect::RIGHT);
			}
		}
	}
	else if (GetKeyState(VK_DOWN) & 0x8000)
	{
		if (direct_ != enumDirect::DOWN && anim_.getRemainFrame() == 0)
		{
			anim_.setAnim(animState::ROT_DOWN);
			direct_ = enumDirect::DOWN;
		}
		else
		{
			tempLocation.y++;
			if (!tempLocation.isOnMap(currentMap.getWidth(), currentMap.getHeight()))
			{
				// ���� ��ġ�� �������̸� ����
				return false;
			}
			else
			{
				return MoveOnMap(currentMap, tempLocation, enumDirect::DOWN);
			}
		}
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
	return false;
}
