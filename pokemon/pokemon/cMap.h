#pragma once
#include "stdafx.h"

enum class enumMapStatus
{
	movable,
	unmovable,
	grass,
	lslope,
	rslope,
	uslope,
	dslope,
	linkedMap = 20,
	linkedHouse = 30
};
class cMap : public iActorBase
{
private:
	wstring name;
	int *map;
	unsigned int width;
	unsigned int height;
	HBITMAP hMap;
	BITMAP bitmapData;
	vector<wstring> linkedMap;
	vector<wstring> linkedHouse;

public:
	cMap();
	~cMap();
	void show(HDC hdc);
	void update() {}
};

class cNoticeSign
{

};

class cCuttableTree
{

};

class cSea
{

};