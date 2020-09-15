#pragma once
#include "stdafx.h"

//#include "cCharacter.h"
class cNPC;

//#include "cAnimation.h"
//#include "cCharacter.h"
//#include "cMap.h"
class cMap;
#include "data/rapidjson/document.h"
#include "data/rapidjson/filereadstream.h"
#include "data/rapidjson/filewritestream.h"
using namespace rapidjson;
using std::string;

class cLoader
{
protected:
	Document doc;
public:
	cLoader(string Filename);
	virtual ~cLoader();
};
class cMapLoader : public cLoader // 맵 데이터를 불러와서 맵을 만들고 그 포인터를 넘겨줌
{
private:
	cMap* map;
public:
	cMapLoader();
	~cMapLoader() { UnloadMap(); }
	cMap** LoadMap(string MapName);
	void UnloadMap();
};


class cAnimCharLoader : public cLoader
{
public:
	cAnimCharLoader();
	void LoadAnim(string type);
};



class cNPCLoader : public cLoader
{
public:
	cNPCLoader();
	cNPC* LoadNPC(string name);
};