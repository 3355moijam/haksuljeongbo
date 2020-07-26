#include "stdafx.h"
#include <iterator>
#include <algorithm>
#include <map>

typedef int KeyType;
typedef std::pair<const KeyType, string> Pair;
typedef std::multimap<KeyType, string> MapCode;

int main()
{
	MapCode codes;

	codes.insert(Pair(415, "샌프란시스코"));
	codes.insert(Pair(510, "오클랜드"));
	codes.insert(Pair(718, "브루클린"));
	codes.insert(Pair(718, "스태튼 섬"));
	codes.insert(Pair(415, "샌라파엘"));
	codes.insert(Pair(510, "버클리"));

	cout << "지역코드가 415인 도시 수: " << codes.count(415) << endl;
	cout << "지역코드가 718인 도시 수: " << codes.count(718) << endl;
	cout << "지역코드가 510인 도시 수: " << codes.count(510) << endl;

	cout << "지역코드    도시\n";
	MapCode::iterator it;
	for (it = codes.begin(); it != codes.end(); it++)
		cout << "    " << it->first << "    " << it->second << endl;

	pair<MapCode::iterator, MapCode::iterator> range = codes.equal_range(718);
	for (it = range.first; it != range.second; it++)
		cout << it->second << endl;

	return 0;
}
