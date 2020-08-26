#include "stdafx.h"
#include "cJSONParser.h"


cJSONParser::cJSONParser(string Filename)
{
	//string json = " { \"hello\" : \"world\", \"t\" : true , \"f\" : false, \"n\": null, \"i\":123, \"pi\": 3.1416, \"a\":[[1, 2, 3, 4],[5, 6, 7, 8]] } ";
	//Document doc;
	//doc.Parse(json.c_str());
	//const rapidjson::Value& valueInfo = doc["a"];

	//for (SizeType i = 0; i < valueInfo.Size(); i++)
	//{

	//	for (SizeType j = 0; j < valueInfo[i].Size(); j++)
	//	{
	//		cout << valueInfo[i][j].GetInt() << " ";
	//	}
	//	cout << '\n';
	//}
	FILE *fp = fopen("sample.json", "rb");

	char buffer[65536];
	FileReadStream is(fp, buffer, sizeof(buffer));
	Document doc;
	doc.ParseStream(is);
	const rapidjson::Value& valueInfo = doc["a"];
	//cout << typeid(valueInfo.GetArray()).name() << endl;
	//for (SizeType i = 0; i < valueInfo.Size(); i++)
	//{
	//	for (SizeType j = 0; j < valueInfo[i].Size(); j++)
	//	{
	//	}
	//	cout << '\n';
	//}

	fclose(fp);
}


cJSONParser::~cJSONParser()
{
}
