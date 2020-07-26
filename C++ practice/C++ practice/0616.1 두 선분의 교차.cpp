#include "stdafx.h"

struct Dot
{
	float x;
	float y;
};

struct Line
{
	float slope;
	float y_inter;
	float scope1;
	float scope2;

	bool isOnLine(float scope)
	{
		if (scope >= scope1 && scope <= scope2)
			return true;
		else
			return false;
	}
};

Dot getInput(void);
Line getLine(Dot, Dot);
Dot getCross(Line, Line);

int main()
{
	// 두 선분이 만나는 경우
	// 1. 한 점에서 교차
	// 2. 교차하지 않음
	// 3. 평행함
	// 4. 같은 직선에 존재.

	Dot A, B, C, D;

	cout << "두 선이 교차하는지 판정." << endl;
	A = getInput();
	B = getInput();
	C = getInput();
	D = getInput();

	Line k, l;
	k = getLine(A, B);
	l = getLine(C, D);

	getCross(k, l);

	return 0;
}

Line getLine(Dot A, Dot B)
{
	Line line = {};
	if (A.x == B.x && A.y == B.y)
	{
		cout << "Error: 서로 다른 점을 넣어주세요." << endl;
		exit(1);
	}

	else if (A.x == B.x)
	{
		line.slope = 1;
		line.y_inter = A.x;
	}

	else
	{
		line.slope = (A.y - B.y) / (A.x - B.x);
		line.y_inter = A.y - A.x * line.slope;
	}

	if (A.x >= B.x)
	{
		line.scope1 = B.x;
		line.scope2 = A.x;
	}
	else
	{
		line.scope1 = A.x;
		line.scope2 = B.x;
	}

	return line;
}

Dot getInput(void)
{
	cout << "점을 입력해 주세요." << endl;
	cout << "X Y : ";
	Dot tmp;
	cin >> tmp.x >> tmp.y;
	return tmp;
}

Dot getCross(Line A, Line B)
{
	Dot tmp = {};
	// 같은 직선 위에 있음
	if (A.slope == B.slope && A.y_inter == B.y_inter)
	{
		if (A.isOnLine(B.scope1) || A.isOnLine(B.scope2))
		{
			cout << "같은 직선 위에 있고 서로 만남." << endl;
		}
		else
		{
			cout << "같은 직선 위에 있고 서로 만나지 않음." << endl;
		}
	}

	else if (A.slope == B.slope)
	{
		cout << "서로 평행함." << endl;
	}
	
	else
	{
		tmp.x = -(A.y_inter - B.y_inter) / (A.slope - B.slope);
		tmp.y = A.slope * tmp.x + A.y_inter;
		if (!(A.isOnLine(tmp.x) && B.isOnLine(tmp.x)))
		{
			cout << "교차점이 범위 바깥에 있음." << endl;
		}
		else
		{
			cout << "(" << tmp.x << ", " << tmp.y << ") 에서 만남." << endl;
		}
	}
	return tmp;
}