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
//void Comb(int n, int r, int num) // nCr�� ��� ��� ���. num�� ó���� n�� �����Ͽ� �����ϱ� ����
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
//		// n-1Cr�� ��� ��� ��� // n�� ���Ե��� ���� ����� ��
//		Comb(n - 1, r, 0);
//		// n-1Cr-1�� ��� ��� ��� // n�� ���Ե� ����� ��
//		Comb(n - 1, r - 1, num);
//	}
//}