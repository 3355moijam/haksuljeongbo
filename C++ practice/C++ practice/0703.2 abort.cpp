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
			cout << x << ", " << y << "의 조화평균은 "
				<< z << "입니다.\n";
		}
		else
			cout << "서로 부정인 두 수의 조화평균은 구할 수 없다.\n";
			
		cout << "다른 두 수를 입력하십시오. (끝내려면 q): ";
	}
	cout << "프로그램을 종료합니다.\n";
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
	{
		cout << "매개변수들을 hmean()에 전달할 수 없습니다.\n";
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