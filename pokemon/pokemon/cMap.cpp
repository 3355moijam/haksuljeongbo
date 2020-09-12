#include "stdafx.h"
#include "cMap.h"

#include "cGameManager.h"

cMap::cMap(const rapidjson::Value &data):name(data["name"].GetString()), width(data["width"].GetInt()), height(data["height"].GetInt()), hMap(), linkedMap(), object()
{
	//name = data["name"].GetString();
	//width = data["width"].GetInt();
	//height = data["height"].GetInt();

	mapData = new short*[height];
	for (size_t i = 0; i < height; i++)
	{
		mapData[i] = new short[width];
		for (size_t j = 0; j < width; j++)
		{
			mapData[i][j] = data["infoArray"][i][j].GetInt();
		}
	}
	
	string tempSrc(data["imgSrc"].GetString(), data["imgSrc"].GetStringLength());
	wstring tempWsrc;
	tempWsrc.assign(tempSrc.begin(), tempSrc.end());
	hMap = (HBITMAP)LoadImage(NULL, tempWsrc.c_str(),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(hMap, sizeof(BITMAP), &bitmapData);

	const rapidjson::Value& link = data["linkedMap"];
	for (size_t i = 0; i < link.Size(); i++)
	{
		Point temp(link[i]["x"].GetInt(), link[i]["y"].GetInt());
		cWarpzone tempzone(link[i]["name"].GetString(), link[i]["dx"].GetInt(), link[i]["dy"].GetInt());
		linkedMap.emplace(temp, tempzone);
	}
}

cMap::~cMap()
{
	DeleteObject(hMap);
	for (int i = 0; i < height; i++)
		delete[] mapData[i];
	delete[] mapData;

	//for (auto& k : linkedMap)
	//	delete k;
	//
	//for (auto& k : object)
	//	delete k;
	//
}

void cMap::show(HDC hdc)
{
	HDC hImgMemDC = CreateCompatibleDC(hdc);

	HBITMAP hOldBitmap = (HBITMAP)SelectObject(hImgMemDC, hMap);
	int bx = bitmapData.bmWidth;
	int by = bitmapData.bmHeight;
	cPlayer& player = cGameManager::getInstance().player;
	BitBlt(hdc, player.getCameraPos().x, player.getCameraPos().y, Tile * 10, Tile * 9, hImgMemDC, player.getCameraPos().x, player.getCameraPos().y, SRCCOPY);
	SelectObject(hImgMemDC, hOldBitmap);
	DeleteDC(hImgMemDC);
}

cWarp::cWarp(cPlayer* player) : timer_(0), dest(), player(player)
{
	hBackBit = CreateCompatibleBitmap(NULL, Tile * 10, Tile * 9);
	GetObject(hBackBit, sizeof(BITMAP), &bitData);
	alpha = { AC_SRC_OVER, 0, 0, 0 };
}

cWarp::~cWarp()
{
	DeleteObject(hBackBit);
}

void cWarp::show(HDC hdc)
{
	HDC hMemDC = CreateCompatibleDC(hdc);
	HBITMAP OldBitmap = (HBITMAP)SelectObject(hMemDC, hBackBit);

	
	GdiAlphaBlend(hdc, player->getCameraPos().x, player->getCameraPos().y, bitData.bmWidth, bitData.bmHeight, hMemDC, 0, 0, bitData.bmWidth, bitData.bmHeight, alpha);
	
	SelectObject(hMemDC, OldBitmap);
	DeleteDC(hMemDC);
}

void cWarp::update()
{
	if (timer_ == 0)
	{
		alpha.SourceConstantAlpha = 0;
		return;
	}

	switch (timer_)
	{
	case 10:
		alpha.SourceConstantAlpha = 54;
		break;
	case 1:
	{
		alpha.SourceConstantAlpha = 54;
		player->setKeyUnlock(true);
		cMap& cur_map = cGameManager::getInstance().Map;
		if (static_cast<enumMapStatus>(cur_map[player->getLocationOnMap().y][player->getLocationOnMap().x]) == enumMapStatus::linkedMap)
		{
			player->direct = enumDirect::DOWN;
			player->anim.setAnim(animState::MOVE_DOWN);
			player->addLocationOnMap(0, 1);
		}
	}
		break;
	case 9:
	case 2:
		alpha.SourceConstantAlpha = 109;
		break;
	case 8:
	case 3:
		alpha.SourceConstantAlpha = 163;
		break;
	case 7:
	case 4:
		alpha.SourceConstantAlpha = 217;
		break;
	case 6:
		alpha.SourceConstantAlpha = 255;
		//ฟ๖วม
		warp();
		break;
	case 5:
	default: break;
	}
	timer_--;
	
}

void cWarp::warp()
{
	cGameManager::getInstance().LoadMap(dest.mapname);
	player->setLocationOnMap(dest.destination);
	player->setCameraPos();
}