#include "stdafx.h"

int main(void)
{
	// 배열. 배열의 이름은 메모리의 주소다.
	// 배열의 초기화는 {0}으로. 아니면 배열 개수만큼 다 넣어주면 된다.
	// 변수를 5개 쓰면 메모리 아무 공간에나 5개가 할당이 되는데
	// 5칸짜리 배열을 쓰면 연속적인 메모리공간에 할당이 된다. 더 효율적.
	// 배열 선언시 개수 지정을 안해도 되는데 그런 경우엔 결국 나중에 개수 지정을 따로 해줘야함.
	// 배열 선언시 배열의 길이는 변수가 아니라 상수여야 함.
	// 유동적으로 배열의 길이를 조정하는 건 불가능. 배열은 정적이다.
	


	//int aList[5] = { 0 };
	//int i = 0;

	//for (i = 0; i < 5; i++)
	//	scanf_s("%d", &aList[i]);

	//for (i = 0;i < 5; i++)
	//	printf("%d\n", aList[i]);

	//for (i = 0;i < 5; i++)
	//	printf("%d\n", &aList[i]);

	//printf("%d %d\n", aList, &aList[0]);
	////////////////////////////


	int aList[5] = { 10, 20, 30, 40, 50 };
	int aListNew[5] = { 0 };
	int i = 0;

	//aListNew = aList;  // 메모리에 메모리를 할당하려 했기 때문에 에러 발생
	for (i = 0; i < 5; i++)
		aListNew[i] = aList[i];

	for (i = 0; i < 5; i++)
		printf("%d\t", aListNew[i]);
	putchar('\n');

	return 0;
}
