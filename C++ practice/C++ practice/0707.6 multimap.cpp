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

	codes.insert(Pair(415, "�������ý���"));
	codes.insert(Pair(510, "��Ŭ����"));
	codes.insert(Pair(718, "���Ŭ��"));
	codes.insert(Pair(718, "����ư ��"));
	codes.insert(Pair(415, "�����Ŀ�"));
	codes.insert(Pair(510, "��Ŭ��"));

	cout << "�����ڵ尡 415�� ���� ��: " << codes.count(415) << endl;
	cout << "�����ڵ尡 718�� ���� ��: " << codes.count(718) << endl;
	cout << "�����ڵ尡 510�� ���� ��: " << codes.count(510) << endl;

	cout << "�����ڵ�    ����\n";
	MapCode::iterator it;
	for (it = codes.begin(); it != codes.end(); it++)
		cout << "    " << it->first << "    " << it->second << endl;

	pair<MapCode::iterator, MapCode::iterator> range = codes.equal_range(718);
	for (it = range.first; it != range.second; it++)
		cout << it->second << endl;

	return 0;
}
