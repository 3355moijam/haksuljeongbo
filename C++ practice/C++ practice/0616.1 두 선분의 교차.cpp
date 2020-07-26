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
	// �� ������ ������ ���
	// 1. �� ������ ����
	// 2. �������� ����
	// 3. ������
	// 4. ���� ������ ����.

	Dot A, B, C, D;

	cout << "�� ���� �����ϴ��� ����." << endl;
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
		cout << "Error: ���� �ٸ� ���� �־��ּ���." << endl;
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
	cout << "���� �Է��� �ּ���." << endl;
	cout << "X Y : ";
	Dot tmp;
	cin >> tmp.x >> tmp.y;
	return tmp;
}

Dot getCross(Line A, Line B)
{
	Dot tmp = {};
	// ���� ���� ���� ����
	if (A.slope == B.slope && A.y_inter == B.y_inter)
	{
		if (A.isOnLine(B.scope1) || A.isOnLine(B.scope2))
		{
			cout << "���� ���� ���� �ְ� ���� ����." << endl;
		}
		else
		{
			cout << "���� ���� ���� �ְ� ���� ������ ����." << endl;
		}
	}

	else if (A.slope == B.slope)
	{
		cout << "���� ������." << endl;
	}
	
	else
	{
		tmp.x = -(A.y_inter - B.y_inter) / (A.slope - B.slope);
		tmp.y = A.slope * tmp.x + A.y_inter;
		if (!(A.isOnLine(tmp.x) && B.isOnLine(tmp.x)))
		{
			cout << "�������� ���� �ٱ��� ����." << endl;
		}
		else
		{
			cout << "(" << tmp.x << ", " << tmp.y << ") ���� ����." << endl;
		}
	}
	return tmp;
}