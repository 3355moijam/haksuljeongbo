#include "stdafx.h"
//
//int InputCount(void);
//int InputNum(int i);
//void Print(int num);
//void Swap(int *a, int *b);
//
int main(void)
{
	// memcmp(buf1, buf2, count) �� �޸𸮸� �־��� ���̸�ŭ ���ϴ� �Լ�	
	// ������ 0, ����� buf1 > buf2, ������ buf1 < buf2
	// ���� �� 1�� �ƴ϶� 0�� �Ϳ� ����

	char szBuffer[12] = { "TestString" };
	char *pszData = "TestString";

	printf("%d\n", memcmp(szBuffer, pszData, 10));		// ����� ���� ���� ���
	printf("%d\n", memcmp("teststring", pszData, 10));	// �ҹ����� ���
	printf("%d\n", memcmp("DataString", pszData, 10));	// ���̰� ���� ���


	printf("%d\n", szBuffer == pszData);		// �̰� ���� ����� �޸� �ּҸ� ���ϴ� ��.
	printf("%d\n", "TestString" == pszData);
	printf("%d\n", "Test" == pszData);

	printf("%d\n", strcmp(szBuffer, pszData));		// ���ڿ��� ���ϴ� �Լ�. memcmp�� ���̰� �޶� ��ġ�ϴ� �κ��� ���� �� ������ �̰� ���̰� �ٸ��� �׳� �ٸ���.
	printf("%d\n", strcmp("teststring", pszData));
	printf("%d\n", strcmp("DataString", pszData));


	return 0;
}

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