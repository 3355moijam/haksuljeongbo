// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <locale.h>
#include <iostream>
#include <string>
#include "rapidjson\document.h"
#include "rapidjson\filereadstream.h"
using namespace rapidjson;

using namespace std;

#include <typeinfo>


int main()
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
	int nArrTemp[2][4];
	const rapidjson::Value& valueInfo = doc["a"];
	memcpy(nArrTemp, &valueInfo.GetArray(), sizeof(int) * 2 * 4);
	//cout << typeid(valueInfo.GetArray()).name() << endl;
	for (SizeType i = 0; i < valueInfo.Size(); i++)
	{
		cout << typeid(valueInfo).name() << endl;
		cout << typeid(valueInfo[i]).name() << endl;
		for (SizeType j = 0; j < valueInfo[i].Size(); j++)
		{
			cout << typeid(valueInfo[i][j]).name() << endl;
			cout << valueInfo[i][j].GetInt() << " ";
		}
		cout << '\n';
	}

	fclose(fp);

	return 0;
}


//
//int str_len2(char src[], char tar[])
//{
//	int k = str_len1(src, tar);
//	if (k == -1)
//		return -1;
//
//	for (int i = 0; i < strlen(tar); i++)
//	{
//		src[k + i] = '*';
//	}
//	return 0;
//}

//bool isBetweenPt(POINT target, POINT p1, POINT p2)
//{
//	int distance1 = PtDistance(target, p1);
//	int distance2 = PtDistance(target, p2);
//	int distance3 = PtDistance(p1, p2);
//
//	if (distance1 + distance2 == distance3)
//		return true;
//	else
//		return false;
//}
//
//int PtDistance(POINT p1, POINT p2)
//{
//	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
//}