#include "stdafx.h"
//
//int InputCount(void);
//int InputNum(int i);
//void Print(int num);
//void Swap(int *a, int *b);
//
int main(void)
{
	char szBuffer[32] = { "I am a boy." };

	printf("%p\n", szBuffer);

	printf("%p\n", strstr(szBuffer, "am"));		// ���ڿ��� �˻��ϰ� ã�� ��ġ(�ּ�)�� ���
	printf("%p\n", strstr(szBuffer, "boy"));

	printf("Index : %d\n", strstr(szBuffer, "am") - szBuffer);		// ã�� �ּ� - �����ּ� ���ָ� ���ڿ��� �ε����� ����.
	printf("Index : %d\n", strstr(szBuffer, "boy") - szBuffer);

	char *pszBuffer = szBuffer;
	int index = 0;
	if(strstr(szBuffer, "boy") != NULL)
		index = strstr(szBuffer, "boy") - szBuffer;
	

	memcpy(szBuffer+index, "cat", 3);		// boy�� cat���� ġȯ
	printf("%s\n", szBuffer);
	printf("%s\n", szBuffer+index+3);
	//memcpy(pszBuffer, szBuffer, 5);
	printf("%s\n", pszBuffer);
	///////////////////////////////////


	//char szBuffer[32] = { "You are a girl." };

	//// ���� ����
	//printf("%c\n", szBuffer[0]);
	//printf("%c\n", *szBuffer);
	//printf("%c\n", *(szBuffer+0));

	//// ���� ����
	//printf("%c\n", szBuffer[5]);
	//printf("%c\n", *(szBuffer + 5));

	//// ���� ����
	//printf("%s\n", &szBuffer[4]);
	//printf("%s\n", &*(szBuffer + 4));
	//printf("%s\n", szBuffer + 4);
	////////////////////////////

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