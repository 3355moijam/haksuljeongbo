#include "stdafx.h"
#include <Windows.h>

int main(void)
{
	int aList[10][10] = { 0 }, count = 0, length;

	// 달팽이배열
	printf("1부터 10까지 정수 : ");
	scanf_s("%d", &length);
	int i = 0, j = -1;

	int n = 0;
	while (n < 2 * length - 1)
	{


		for (int k = 0; k < (2 * length - n) / 2; k++)  // (2*length - n)/2 ==> 5 4 4 3 3 2 2 1 1
		{
			switch (n % 4)
			{
			case 0:
				j++;
				break;
			case 1:
				i++;
				break;
			case 2:
				j--;
				break;
			case 3:
				i--;
				break;
			default:
				break;
			}

			aList[i][j] = ++count;
		}

		n++;

		// 출력
		system("cls");
		for (int a = 0; a < length; a++)
		{
			for (int b = 0; b < length; b++)
			{
				printf("%3d ", aList[a][b]);
			}
			printf("\n\n");
		}
		Sleep(100);

	}


	return 0;
}
