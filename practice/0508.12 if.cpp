#include "stdafx.h"

int main(void)
{
	//int nAge = 0;

	//printf("���̸� �Է��ϼ���. : ");
	//scanf("%d", &nAge);

	//if (nAge >= 20)
	//	printf("����� ���̴� %d�� �Դϴ�.\n", nAge);

	//puts("End");
	///////////////////////////////


	//int nInput = 0;
	//
	//printf("���ڸ� �Է��ϼ���. : ");
	//scanf("%d", &nInput);

	//if (nInput > 0)
	//{
	//	printf("%d�� ����Դϴ�.\n", nInput);
	//}

	//if (nInput < 0)
	//{
	//	printf("%d�� �����Դϴ�.\n", nInput);
	//}

	//if (nInput == 0)
	//{
	//	printf("%d�� 0�Դϴ�.\n", nInput);
	//}
	////////////////////////////////////////////


	//int nInput = -9999, nMax = 0;

	//printf("�� ������ �־��ּ��� : ");
	//
	//scanf("%d", &nInput);
	//nMax = nInput;
	//
	//scanf("%d", &nInput);
	//if (nMax < nInput)
	//{
	//	nMax = nInput;
	//}

	//scanf("%d", &nInput);
	//if (nMax < nInput)
	//{
	//	nMax = nInput;
	//}

	//printf("�ִ� : %d\n", nMax);
	/////////////////////////////////////////


	printf("����� ���̴�? : ");
	int age = 0;
	float price = 1000;
	
	scanf("%d", &age);

	if (age < 20)
		price *= 0.75;

	printf("����� %.0f�� �Դϴ�.\n", price);
	/////////////////////////////////


	return 0;
}