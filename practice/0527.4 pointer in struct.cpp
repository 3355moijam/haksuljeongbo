#include "stdafx.h"



struct Point
{
	int *x;
	int *y;
};

struct Point2
{
	int *x;
	int **y;
};


void Method1();
void Method2();
void Struct1();

int main(int argc, char* argv[])
{

	Method1();


	return 0;
}



void Method1()
{
	int num1 = 4;
	int num2 = 5;
	Point p1;
	Point2 p2;
	Point *pp1 = &p1;
	p1.x = &num1;
	p1.y = &num2;

	p2.x = &num1;
	p2.y = &p1.x;
	printf("%d %d\n", *p2.x, **p2.y);
	printf("%x %x\n", pp1->x, pp1->y);	// �����Ϳ� �Ҵ�� ����ü �ּҴ� ������ ���� �����Ѵ�.
	printf("%x %x\n", (*pp1).x, (*pp1).y);	// ���� ���� ǥ��
}

