#include "stdafx.h"
#include <string.h>
//
//int InputNum(void);
//void Print(int num);
//void Swap(int *a, int *b);
//
int main(void)
{
	char szBuffer[16] = { "Hello" };
	char *pszData = szBuffer;
	//int nLength = 0;

	//while (*pszData != '\0')
	//{
	//	pszData++;
	//	nLength++;
	//}

	//printf("Length : %d\n", nLength);
	//printf("Length : %d\n", strlen(szBuffer));
	//printf("Length : %d\n", strlen("World"));
	////////////////////////////

	while (*pszData != '\0')
	{
		pszData++;
	}

	printf("Length : %d\n", pszData - szBuffer);  // null�� ����� ��ġ - ������ġ = ����
	///////////////////////////


	return 0;
}
//
//int InputNum(void)
//{
//	printf("�� ������ ��������? : ");
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