#include "stdafx.h"
#include <thread>



int main()
{
	unsigned long long a, b, c;
	while(true)
	{
		cout << "a, b, c 입력(a = -1이면 종료) : ";
		cin >> a >> b >> c;
		if (a == -1)
			break;
		unsigned long long multiply = a;
		unsigned long long cut = pow(10, 9) + 7;

		for (unsigned long long i = 0; i < c; ++i)
		{
			multiply = (multiply*b) % cut;
		}
		cout << multiply << endl;
		
	}
	return 0;
}