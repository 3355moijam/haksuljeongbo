#include "stdafx.h"
//
//int InputNum(void);
//void Print(int num);
//
int main(void)
{
	////int* p �� int p*�� ������. �ʱ�ȭ�� &�� ���.
	//int a = 0;
	//int b = 0;
	//printf("%p\n", &a);

	//int *p1 = NULL; // �����ʹ� �η� �ʱ�ȭ
	//char *p2 = NULL;
	//double * p3 = NULL;

	//printf("%x %x %x\n", &p1, p1, *&p1);
	///////////////////

	//int x = 10;
	//int *pnData = &x;
	//printf("%x : %d\n", &x, x);
	//printf("%x : %x\n", &pnData, pnData);	  //&pnData == pnData�� �ּ�
	//printf("%x : %d\n", &pnData, *pnData);  //pnData == x�� �ּ�
	//										  //*pnData == x, pnData�� ������ �ִ� �ּҿ� ���� �� ���� �������� ��.	
	//*pnData = 20;
	//printf("x: %x : %d\n", &x, x);
	//printf("*pnData: %x : %d\n", &pnData, *pnData);
	//////////////

	//char c = 'A';
	//char *cp = NULL;
	//cp = &c;
	//printf("%x %c %c\n", &c, c, *&c);
	//printf("%x %x %x\n", &cp, cp, *&cp);

	//printf("%c  :  %c \n", c, *cp);

	//int a = 0, b = 0, d = 0;
	//int *ip = NULL;
	//ip = &a;
	//*ip = 10;

	//printf("a : %d, b : %d, d : %d, *ip : %d\n\n", a, b, d, *ip);

	//int num = 10;
	//ip = &num;
	//printf("%x %x %d \n", &*&ip, *&ip, **&ip);
	////&*&ip == ip�� �ּ�, *&ip == num�� �ּ�(&num), **&ip == num.
	//
	//int num2 = 0;
	//num2 = *ip + num;
	//printf("%d\n", num2);
	///////////////////////////

	int arr[3] = { 10,20,30 };
	//printf("%x %x %x\n", arr, arr + 0, &arr[0]);  // arr�� �ּ� = ù��° ����� �ּ�. 
	//printf("%x %x\n",arr + 1, &arr[1]);  // arr+0�� ù��° ��Ҹ� �ǹ�. +1�� �ι�° ���
	//printf("%x %x\n",arr + 2, &arr[2]);

	//printf("%d %d %d\n", sizeof(arr), sizeof(*(arr + 1)), sizeof(arr[1]));  // arr ��ü�� ũ��, 0������� ũ��, 0������� ũ��

	//printf("%d %d %d\n", *arr, *(arr + 0), *&arr[0]);
	//printf("%d %d\n", *(arr + 1), *&arr[1]);
	//printf("%d %d\n", *(arr + 2), *&arr[2]);


	int *p = NULL;
	p = arr;

	printf("%x %x %x\n", p, p + 0, &p[0]);
	printf("%x %x\n", p + 1, &p[1]);
	printf("%x %x\n", p + 2, &p[2]);

	printf("%d %d %d\n", *p, *(p + 0), p[0]);
	printf("%d %d\n", *(p + 1), p[1]);
	printf("%d %d\n", *(p + 2), p[2]);

	printf("%d %d\n", sizeof(arr), sizeof(p));  // p�� �ּҸ� ������ �ֱ� ������ 32��Ʈ�ϰ�� 4����Ʈ, 64��Ʈ�ϰ�� 8����Ʈ ����.
	
	p = arr + 1; // arr[1]�� �ּҸ� ������
	printf("%d %d %d\n", *p, *(p + 1), *(p + 2));  // p+2 == arr[3] �̱� ������ �����Ⱚ�� ���.
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

