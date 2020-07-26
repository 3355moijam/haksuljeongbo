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
		{ "�迵��", 179, 79 },
		{ "������", 172, 63 },
		{ "�̼���", 176, 52 },
		{ "������", 165, 51 },
		{ "������", 181, 73 },
		{ "ȫ����", 172, 84 }
	};

	int nx = sizeof(x) / sizeof(x[0]);
	int retry;
	cout << "�̸����� �˻��մϴ�." << endl;
	do
	{
		Person tmp, *p;
		cout << "�̸� : ";
		cin >> tmp.name;

		p = (Person *)bsearch(&tmp, x, nx, sizeof(Person), (int(*)(const void *, const void *)) npcmp);

		if (p == NULL)
			cout << "�˻��� �����߽��ϴ�." << endl;

		else
		{
			cout << "�˻� ����!! �Ʒ� ��Ҹ� ã�ҽ��ϴ�." << endl;
			printf("x[%d] : %s %dcm %dkg\n", (int)(p - x), p->name, p->height, p->weight);
		}
		cout << "�ٽ� �˻��ұ��?(1) ��/(0)�ƴϿ� : ";
		cin >> retry;
	} while (retry == 1);


	return 0;
}
