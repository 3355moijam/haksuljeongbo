#include "stdafx.h"
#include <Windows.h>

int main(void)
{
	int aList[10][10] = { 0 }, count = 0;

	// �����̹迭
	int i = 0, j = -1, length = 5;
	bool check1 = true, check2 = true; // check1 = i����, 2 = j����
	bool check3 = false;			   // check3 = check12����

	int n = 0;
	while (n < 2 * length - 1)
	{
		for (int k = 0; k < (2*length-n)/2; k++)
		{
			if (check1 && check2)
				j++; // ����-���� j++
			else if (check1 && !check2)
				i++; // ����-���� i++
			else if (!check1 && !check2)
				j--; // ����-���� j--
			else
				i--; // ����-���� i--

			aList[i][j] = ++count;

		}
		
		if (check3)
			check1 = !check1;
		else
			check2 = !check2;

		check3 = !check3;
		n++;


		system("cls");
		for (int a = 0; a < 5; a++)
		{
			for (int b = 0; b < 5; b++)
			{
				printf("%2d ", aList[a][b]);
			}
			printf("\n\n");
		}
		Sleep(100);

	}


	return 0;
}
