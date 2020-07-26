#include "stdafx.h"
#include <cstdlib>

double hmean(double a, double b);
bool hmean(double a, double b, double * ans);

int main()
{
	double x, y, z;
	while (cin >> x >> y)
	{
		if (hmean(x, y, &z))
		{
			cout << x << ", " << y << "�� ��ȭ����� "
				<< z << "�Դϴ�.\n";
		}
		else
			cout << "���� ������ �� ���� ��ȭ����� ���� �� ����.\n";
			
		cout << "�ٸ� �� ���� �Է��Ͻʽÿ�. (�������� q): ";
	}
	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
	{
		cout << "�Ű��������� hmean()�� ������ �� �����ϴ�.\n";
		abort();
	}
	return 2.0 * a * b / (a + b);
}

bool hmean(double a, double b, double * ans)
{
	if (a == -b)
	{
		*ans = DBL_MAX;
		return false;
	}
	else
	{
		*ans = 2.0 * a * b / (a + b);
		return true;
	}
}