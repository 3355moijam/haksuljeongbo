#include "stdafx.h"
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>

struct Person
{
	string name;
	int height;
	int weight;
};

int npcmp(const Person *x, const Person *y)
{
	return x->name.compare(y->name);
}

int main()
{
	Person x[] = {
		{ "김영준", 179, 79 },
		{ "박현규", 172, 63 },
		{ "이수진", 176, 52 },
		{ "최윤미", 165, 51 },
		{ "함진아", 181, 73 },
		{ "홍연의", 172, 84 }
	};

	int nx = sizeof(x) / sizeof(x[0]);
	int retry;
	cout << "이름으로 검색합니다." << endl;
	do
	{
		Person tmp, *p;
		cout << "이름 : ";
		cin >> tmp.name;

		p = (Person *)bsearch(&tmp, x, nx, sizeof(Person), (int(*)(const void *, const void *)) npcmp);

		if (p == NULL)
			cout << "검색에 실패했습니다." << endl;

		else
		{
			cout << "검색 성공!! 아래 요소를 찾았습니다." << endl;
			printf("x[%d] : %s %dcm %dkg\n", (int)(p - x), p->name, p->height, p->weight);
		}
		cout << "다시 검색할까요?(1) 예/(0)아니오 : ";
		cin >> retry;
	} while (retry == 1);


	return 0;
}
