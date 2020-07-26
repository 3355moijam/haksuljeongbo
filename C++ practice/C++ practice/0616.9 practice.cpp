#include "stdafx.h"
#include <cstdio>

int sum(int, int);
int mul(int, int);
void gugu(int(*calc)(int, int));

int main()
{
	cout << "µ¡¼ÀÇ¥" << endl;
	gugu(sum);
	cout << endl << "°ö¼ÀÇ¥" << endl;
	gugu(mul);

	return 0;
}


int sum(int x1, int x2)
{
	return x1 + x2;
}

int mul(int x1, int x2)
{
	return x1 * x2;
}

void gugu(int(*calc)(int, int))
{
	int i, j;
	for ( i = 1; i <= 9; i++)
	{
		for (j = 1; j <= 9; j++)
		{
			//printf("%3d", (*calc)(i, j));
			cout.width(3);
			cout << (*calc)(i, j);
		}
		putchar('\n');
	}
}