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
//		printf("몇 번 입력할까요? : ");
//		scanf_s("%d%*c", &num);
//
//		if (num > 0)
//			break;
//		printf("양수를 입력해 주세요.\n");
//	}
//	return num;
//}
//
//int InputNum(int i)
//{
//	printf("입력 %d : ", i);
//	int num;
//	scanf_s("%d%*c", &num);
//
//	return num;
//}
//
//void Print(int num)
//{
//	printf("달팽이는 %d마리 입니다.\n", num);
//}
//
//void Swap(int *a, int *b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
// }