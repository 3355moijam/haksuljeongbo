#include "stdafx.h"

void PutData(char *pszParam)
{
	if (*pszParam == '\0')
		return;

	putchar(*pszParam);
	PutData(pszParam + 1);
}
int main(int argc, char* argv[])
{
	// ����Լ��� ������ �׾ư��� ���ʷ� �����ϴ� ��.
	PutData("TestData");
	putchar('\n');


	return 0;
}
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