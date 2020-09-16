#include "stdafx.h"
#include "cMap.h"

#include "cGameManager.h"
extern RECT g_view;
cMap::cMap(const rapidjson::Value &data):name(data["name"].GetString()), width(data["width"].GetInt()), height(data["height"].GetInt()), hMap(), linkedMap(), speakers(), npcList(), npcLoader()
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

	const rapidjson::Value& npcNames = data["npc"];
	for (auto& name : npcNames.GetArray())
	{
		cNPC* newNPC = npcLoader.LoadNPC(name.GetString());
		if (newNPC)
		{
			speakers.emplace(newNPC->getLocationOnMap(), newNPC);
			npcList.emplace_back(newNPC);
		}
	}

}

cMap::~cMap()
{
	DeleteObject(hMap);
	for (int i = 0; i < height; i++)
		delete[] mapData[i];
	delete[] mapData;
	while (!speakers.empty())
	{
		iSpeakActor* temp = speakers.begin()->second;
		delete temp;
	}
	//while(!npcList.empty())
	//{
	//	delete* npcList.rbegin();
	//}
	//for (auto& k : linkedMap)
	//	delete k;
	//
	//for (auto& k : speakers)
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
	BitBlt(hdc, 0, 0, g_view.right, g_view.bottom, hImgMemDC, player.getCameraPos().x, player.getCameraPos().y, SRCCOPY);
	SelectObject(hImgMemDC, hOldBitmap);
	DeleteDC(hImgMemDC);

	for (auto npc : npcList)
	{
		npc->show(hdc);
	}
}

bool cMap::isOnMap(const Point& p)
{
	return (p.x >= 0 && p.x < width && p.y >= 0 && p.y < height);
}

cWarp::cWarp(cPlayer* player) : timer_(0), dest(), player(player)
{
	hBackBit = CreateBitmap(Tile * 10, Tile * 9, 1, ::GetDeviceCaps(NULL, BITSPIXEL), NULL);
	GetObject(hBackBit, sizeof(BITMAP), &bitData);
	HDC temphdc = CreateCompatibleDC(NULL);
	HBITMAP old = (HBITMAP)SelectObject(temphdc, hBackBit);
	PatBlt(temphdc, 0, 0, bitData.bmWidth, bitData.bmHeight, WHITENESS);
	SelectObject(temphdc, old);
	DeleteDC(temphdc);

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

	GdiAlphaBlend(hdc, 0, 0, bitData.bmWidth, bitData.bmHeight, hMemDC, 0, 0, bitData.bmWidth, bitData.bmHeight, alpha);
	
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
		cMap& cur_map = cGameManager::getInstance().Map;
		if (static_cast<enumMapStatus>(cur_map[player->getLocationOnMap().y][player->getLocationOnMap().x]) == enumMapStatus::linkedMap)
		{
			player->direct = enumDirect::DOWN;
			player->anim.setAnim(animState::MOVE_DOWN);
			player->addLocationOnMap(0, 1);
		}
		else
			player->setKeyUnlock(true);
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
	dest.clear();
}