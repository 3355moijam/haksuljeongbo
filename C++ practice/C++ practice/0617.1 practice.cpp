#include "stdafx.h"

struct dot
{
	float x;
	float y;
};

struct rect
{
	dot a;
	dot b;
};

void getDot(dot *pDot);
float getDiameter(void);
bool isInCircle(dot *pDot, float r);
void getRec(rect *pRec);
bool isInRec(dot *pDot, rect *pRec);

int main()
{
	dot A; float r;
	getDot(&A);
	r = getDiameter();

	if (isInCircle(&A, r))
	{
		cout << "���� �� �ȿ� �ִٴ� ����" << endl;
	}
	else
	{
		cout << "���� �� �ȿ� ���ٴ� ����" << endl;
	}

	rect rec;
	getRec(&rec);
	if (isInRec(&A, &rec))
	{
		cout << "���� �簢�� �ȿ� �ִٴ� ����" << endl;
	}
	else
	{
		cout << "���� �簢�� �ȿ� ���ٴ� ����" << endl;
	}



	return 0;
}

void getDot(dot *pDot)
{
	cout << "���� ��ǥ�� �Է����ּ���." << endl;
	cout << "X Y : ";
	cin >> pDot->x >> pDot->y;
}

float getDiameter(void)
{
	cout << "���� ������ �Է��� �ּ���." << endl;
	cout << "R : ";
	float tmp;
	cin >> tmp;

	return tmp;
}

bool isInCircle(dot *pDot, float r)
{
	bool a = pDot->x*pDot->x + pDot->y*pDot->y <= r*r;
	return a;
}

void getRec(rect *pRec)
{
	cout << "�簢���� ���� ���̸� �Է����ּ���." << endl;
	cout << "�� ���� : ";
	float w, h;
	cin >> w >> h;

	pRec->a.x = -w / 2;
	pRec->a.y = -h / 2;
	pRec->b.x = w / 2;
	pRec->b.y = h / 2;
}

bool isInRec(dot *pDot, rect *pRec)
{
	bool x = pDot->x >= pRec->a.x && pDot->x <= pRec->b.x;
	bool y = pDot->y >= pRec->a.y && pDot->y <= pRec->b.y;
	return x && y;
}
