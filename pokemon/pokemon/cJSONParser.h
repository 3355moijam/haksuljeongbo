#pragma once
#include "stdafx.h"
#include "data/rapidjson/document.h"
#include "data/rapidjson/filereadstream.h"
#include "data/rapidjson/filewritestream.h"
using namespace rapidjson;
using std::string;

class cJSONParser
{
public:
	cJSONParser(string Filename);
	~cJSONParser();
};

