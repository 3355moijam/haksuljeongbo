#pragma once
#include "stdafx.h"
#include "data/rapidjson/document.h"
#include <map>

#include "cLoader.h"
class cPlayer;
class cNPC;
using std::map;
using std::pair;
using namespace rapidjson;
class cWarpzone;
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
	map<Point, cWarpzone> linkedMap;
	map<Point, iSpeakActor*> speakers;
	vector<cNPC*> npcList;
	cNPCLoader npcLoader;
public:
	cMap(const rapidjson::Value &data);
	~cMap();
	void show(HDC hdc);
	void update() {}
	unsigned int getWidth() { return width; }
	unsigned int getHeight() { return height; }
	short* operator[] (unsigned int num) { return mapData[num]; }
	short operator[] (const Point& loc) { return mapData[loc.y][loc.x]; }
	bool isOnMap(const Point& p);
	const map<Point, cWarpzone>& get_linked_map() 
	{
		return linkedMap;
	}

	__declspec(property(get = get_linked_map)) const map<Point, cWarpzone>& LinkedMap;

	map<Point, iSpeakActor*>& get_speakers()
	{
		return speakers;
	}
	__declspec(property(get = get_speakers)) map<Point, iSpeakActor*>& Speaker;

	vector<cNPC*>& get_npcList() { return npcList; }

};
class cWarpzone
{
	//로드할 맵에 대한 정보, 위치인덱스
public:
	string mapname;
	Point destination;
	cWarpzone() : mapname(), destination() {}
	cWarpzone(string name, int x, int y) : mapname(name), destination(x,y){}
	void clear() { mapname = ""; destination = { 0,0 }; }
};

class cWarp: public iActorBase
{
private:
	HBITMAP hBackBit;
	BITMAP bitData;
	BLENDFUNCTION alpha;
	cWarpzone dest;
	short timer_;
	cPlayer* player;
public:
	cWarp(cPlayer* player);
	~cWarp();
	short get_timer() const { return timer_; }
	void set_timer(short timer = 10) { timer_ = timer; }
	void set_destination(const cWarpzone& zone) { dest = zone; }

	void show(HDC hdc) override;
	void update() override;

	void warp();
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