#include "stdafx.h"
#include "cCharacter.h"
#pragma comment (lib, "Msimg32.lib")


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

cPlayer::cPlayer() : cCharacter(), CameraPivot(Tile * (LocationOnMap.x - 4), Tile * (LocationOnMap.y - 4)), keyUnlock(true)
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
	DeleteDC(hImgMemDC);
}

void cPlayer::update()
{
	getInput();
	anim_.playAnim(this);
}

bool cPlayer::getInput()
{
	if (!keyUnlock)
		return false;
	
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		if (direct_ != enumDirect::LEFT && anim_.getRemainFrame() == 0)
		{
			anim_.setAnim(animState::ROT_LEFT);
			direct_ = enumDirect::LEFT;
		}
		else
		{
			anim_.setAnim(animState::MOVE_LEFT);
			LocationOnMap.x--;
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
			anim_.setAnim(animState::MOVE_UP);
			LocationOnMap.y--;
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
			anim_.setAnim(animState::MOVE_RIGHT);
			LocationOnMap.x++;
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
			anim_.setAnim(animState::MOVE_DOWN);
			LocationOnMap.y++;
		}
	}
	return false;
}
