#include "stdafx.h"

int g_nCounter = 10;

void InitCounter(int i)
{
	g_nCounter = i;
}

void IncreaseCounter()
{
	g_nCounter++;
}
//
//int InputCount(void);
//int InputNum(int i);
//void Print(int num);
//void Swap(int *a, int *b);
//void MemError(void* arr);
//
//int main(int argc, char* argv[])
//{
//	// ���� ���۸�, �޸𸮹���, ȭ�� ������ ���ֱ�


//
//
//
//	return 0;
//}
//
//int InputCount(void)
//{
//	int num;
//	while (1)
//	{
//		printf("�� �� �Է��ұ��? : ");
//		scanf_s("%d%*c", &num);
//
//		if (num > 0)
//			break;
//		printf("����� �Է��� �ּ���.\n");
//	}
//	return num;
//}
//
//int InputNum(int i)
//{
//	printf("�Է� %d : ", i);
//	int num;
//	scanf_s("%d%*c", &num);
//
//	return num;
//}
//
//void Print(int num)
//{
//	printf("�����̴� %d���� �Դϴ�.\n", num);
//}
//
//void Swap(int *a, int *b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
// }
//void MemError(void* arr)
//{
//	printf("�޸� �Ҵ翡 �����߽��ϴ�.\n");
//	free(arr);
//	exit(1);
//}