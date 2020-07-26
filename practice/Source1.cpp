#include "stdafx.h"
//void Comb(int n, int r, int num);
//
//
//int main(void) {
//	
//	Comb(4, 3,4);
//	return 0;
//}
//
//void Comb(int n, int r, int num) // nCr의 모든 경우 출력. num은 처음의 n을 유지하여 전달하기 위함
//{
//	if (r == 1)
//	{
//		printf("%dC%d : ", n, r);
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = n+1; j <= num; j++ )
//			{
//				printf("%d ", j);
//			}
//			printf("%d \n", i);
//		}
//		printf("\n");
//		return;
//	}
//	else if (r == n)
//	{
//		printf("%dC%d : ", n, r);
//		for (int i = 1; i <= n; i++)
//		{
//			printf("%d ", i);
//		}
//		for (int j = n + 1; j <= num; j++)
//		{
//			printf("%d ", j);
//		}
//		/*if (num)
//		{
//			printf("%d \n", num);
//		}*/
//		printf("\n");
//		return;
//	}
//	else
//	{
//		// n-1Cr의 모든 경우 출력 // n이 포함되지 않은 경우의 수
//		Comb(n - 1, r, 0);
//		// n-1Cr-1의 모든 경우 출력 // n이 포함된 경우의 수
//		Comb(n - 1, r - 1, num);
//	}
//}