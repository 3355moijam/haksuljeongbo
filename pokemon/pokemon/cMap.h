#pragma once
#include "stdafx.h"
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
	wstring name;
	short *map;
	unsigned int width;
	unsigned int height;
	HBITMAP hMap;
	BITMAP bitmapData;
	vector<cWarpzone*> linkedMap; // �̸��� ��ǥ�� ���� ����
	vector<iSpeakActor*> object;
public:
	cMap();
	~cMap();
	void show(HDC hdc);
	void update() {}
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

class cSea : public iSpeakActor
{
public:
	void say();
};