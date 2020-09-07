#pragma once
#include "stdafx.h"
#include "data/rapidjson/document.h"
#include <map>
using std::map;
using std::pair;
using namespace rapidjson;

enum class enumMapStatus
{
	movable,
	unmovable,
	grass,
	sea,
	notice,
	cuttableTree,
	berryTree,
	item,
	poke,
	lslope = 15,
	rslope,
	uslope,
	dslope,
	linkedMap = 30,
	door = 31
};
class cMap : public iActorBase
{
private:
	string name;
	short **mapData;
	unsigned int width;
	unsigned int height;
	HBITMAP hMap;
	BITMAP bitmapData;
	map<Point, string> linkedMap;
	//vector<cWarpzone*> linkedMap; // �̸��� ��ǥ�� ���� ����. map���� ���
	vector<iSpeakActor*> object;
public:
	cMap(const rapidjson::Value &data);
	~cMap();
	void show(HDC hdc);
	void update() {}
	unsigned int getWidth() { return width; }
	unsigned int getHeight() { return height; }
	short* operator[] (unsigned int num) { return mapData[num]; }
};

class cWarpzone
{
	//�ε��� �ʿ� ���� ����, ��ġ�ε���
public:
	wstring mapname;
	POINT index;
};

class cNoticeSign : public iSpeakActor
{
public:
	void say();
};

class cCuttableTree : public iSpeakActor
{
public:
	void say();
};
//
//class cSea : public iSpeakActor
//{
//public:
//	void say();
//};