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
		cout << "대충 원 안에 있다는 내용" << endl;
	}
	else
	{
		cout << "대충 원 안에 없다는 내용" << endl;
	}

	rect rec;
	getRec(&rec);
	if (isInRec(&A, &rec))
	{
		cout << "대충 사각형 안에 있다는 내용" << endl;
	}
	else
	{
		cout << "대충 사각형 안에 없다는 내용" << endl;
	}



	return 0;
}

void getDot(dot *pDot)
{
	cout << "점의 좌표를 입력해주세요." << endl;
	cout << "X Y : ";
	cin >> pDot->x >> pDot->y;
}

float getDiameter(void)
{
	cout << "원의 지름을 입력해 주세요." << endl;
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
	cout << "사각형의 폭과 높이를 입력해주세요." << endl;
	cout << "폭 높이 : ";
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
