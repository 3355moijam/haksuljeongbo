#include "stdafx.h"
#include "cMap.h"

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
		linkedMap.emplace(temp, link[i]["name"].GetString());
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
	BitBlt(hdc, 0, 0, bx, by, hImgMemDC, 0, 0, SRCCOPY);
	SelectObject(hImgMemDC, hOldBitmap);
	DeleteDC(hImgMemDC);
}
