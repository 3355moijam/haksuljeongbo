#include "stdafx.h"
//
//int InputCount(void);
//int InputNum(int i);
//void Print(int num);
//void Swap(int *a, int *b);
//
int main(void)	
{
	//int nData = 10;
	//int *pnData = &nData;
	//int **ppnData = &pnData;

	//printf("%x %x %x\n", ppnData, *ppnData, pnData);
	///////////////


	char *astrList[3] = { "Hello", "World", "String" };

	printf("%s\n", astrList[0]);
	printf("%s\n", astrList[1]);
	printf("%s\n", astrList[2]);

	printf("%s\n", astrList[0] + 1);
	printf("%s\n", astrList[1] + 2);
	printf("%s\n", astrList[2] + 3);

	printf("%c\n", astrList[0][3]);
	printf("%c\n", astrList[1][3]);
	printf("%c\n", astrList[2][3]);

	/*printf("%s\n", astrList + 1);
	printf("%s\n", astrList + 2);
	printf("%s\n", astrList + 3);*/

	printf("%s\n", astrList[0] + 1);
	printf("%s\n", *(astrList + 0) + 1);



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