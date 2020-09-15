#include "stdafx.h"
#include "cLoader.h"
#include "cAnimChar.h"

#include "cMap.h"
#include "cCharacter.h"
//Document cLoader::doc;
cLoader::cLoader(string FileName) : doc()
{
	FILE* fp = fopen(FileName.c_str(), "rb");

	char buffer[65536];
	FileReadStream is(fp, buffer, sizeof(buffer));
	doc.ParseStream(is);
	fclose(fp);
}


cLoader::~cLoader()
{
}

cMapLoader::cMapLoader(): cLoader("data/map.json"), map(nullptr)
{

}

cMap ** cMapLoader::LoadMap(string MapName)
{
	UnloadMap();
	const rapidjson::Value& mapList = doc["map"];
	for (auto& d : mapList.GetArray())
	{
		if (d["name"] == MapName.c_str())
		{
			map = new cMap(d);
			break;
		}
	}
	return &map;
}

void cMapLoader::UnloadMap()
{
	delete map;
	map = nullptr;
}


cAnimCharLoader::cAnimCharLoader() : cLoader("data/animation.json")
{
}


void cAnimCharLoader::LoadAnim(string type)
{
	const rapidjson::Value& anim = doc[type.c_str()];

	for (int i = 0; i < anim.Size(); i++)
	{
		cAnimChar::keyFrameData.emplace_back(0);
		for (int j = 0; j < anim[i]["keyframe"].Size(); j += 2)
		{
			for (int k = 0; k < anim[i]["keyframe"][j + 1].GetInt(); ++k)
			{
				cAnimChar::keyFrameData[i].emplace_back(anim[i]["keyframe"][j].GetInt());
			}
		}

		cAnimChar::moveData.emplace_back(0);
		for (auto& element : anim[i]["moveData"].GetArray())
		{
			cAnimChar::moveData[i].emplace_back(element["dir"].GetString(), element["dis"].GetInt());
		}

		cAnimChar::cameraMove.emplace_back(0);
		for (auto& element : anim[i]["cameraMove"].GetArray())
		{
			cAnimChar::cameraMove[i].emplace_back(element["dir"].GetString(), element["dis"].GetInt());
		}

		cAnimChar::keyUnlock.emplace_back(0);
		for (int j = 0; j < anim[i]["keyUnlock"].Size(); ++j)
		{
			cAnimChar::keyUnlock[i].emplace_back(anim[i]["keyUnlock"][j].GetInt());
		}
	}
}

cNPCLoader::cNPCLoader(): cLoader("data/npc.json")
{
}

cNPC* cNPCLoader::LoadNPC(string name)
{
	for (auto& target : doc["npc"].GetArray())
	{
		if(name == target["name"].GetString())
		{
			return new cNPC(target);
		}
	}
	return nullptr;
}
