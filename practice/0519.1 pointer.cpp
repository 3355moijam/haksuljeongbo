#include "stdafx.h"
//
//int InputNum(void);
//void Print(int num);
//
int main(void)
{
	////int* p 와 int p*는 같은것. 초기화는 &를 사용.
	//int a = 0;
	//int b = 0;
	//printf("%p\n", &a);

	//int *p1 = NULL; // 포인터는 널로 초기화
	//char *p2 = NULL;
	//double * p3 = NULL;

	//printf("%x %x %x\n", &p1, p1, *&p1);
	///////////////////

	//int x = 10;
	//int *pnData = &x;
	//printf("%x : %d\n", &x, x);
	//printf("%x : %x\n", &pnData, pnData);	  //&pnData == pnData의 주소
	//printf("%x : %d\n", &pnData, *pnData);  //pnData == x의 주소
	//										  //*pnData == x, pnData가 가지고 있는 주소에 가서 그 값을 가져오는 것.	
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
	////&*&ip == ip의 주소, *&ip == num의 주소(&num), **&ip == num.
	//
	//int num2 = 0;
	//num2 = *ip + num;
	//printf("%d\n", num2);
	///////////////////////////

	int arr[3] = { 10,20,30 };
	//printf("%x %x %x\n", arr, arr + 0, &arr[0]);  // arr의 주소 = 첫번째 요소의 주소. 
	//printf("%x %x\n",arr + 1, &arr[1]);  // arr+0은 첫번째 요소를 의미. +1은 두번째 요소
	//printf("%x %x\n",arr + 2, &arr[2]);

	//printf("%d %d %d\n", sizeof(arr), sizeof(*(arr + 1)), sizeof(arr[1]));  // arr 전체의 크기, 0번요소의 크기, 0번요소의 크기

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

	printf("%d %d\n", sizeof(arr), sizeof(p));  // p는 주소를 가지고 있기 때문에 32비트일경우 4바이트, 64비트일경우 8바이트 고정.
	
	p = arr + 1; // arr[1]의 주소를 가져옴
	printf("%d %d %d\n", *p, *(p + 1), *(p + 2));  // p+2 == arr[3] 이기 때문에 쓰레기값을 출력.
	return 0;
}
//
//int InputNum(void)
//{
//	printf("몇 개월이 지났나요? : ");
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

