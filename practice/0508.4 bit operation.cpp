#include "stdafx.h"

int main(void)
{
	
	int nData = 0x11223344;

	printf("%08X\n", nData & 0x00FFFF00); // AND 연산
	printf("%08X\n", nData | 0x2211FFFF); // OR 연산
	printf("%08X\n", nData ^ 0x2211FFFF); // XOR연산
	printf("%08X\n", ~nData); // NOT 연산
	printf("%08X\n", nData >> 8); // RIGTH SHIFT /2와 유사한 효과를 낸다. 훨씬 빠름
	printf("%08X\n", nData << 16); // LEFT SHIFT *2와 유사한 효과를 낸다. 훨씬 빠름

	int x = 20, y = 15;
	printf("%08X\n", x & y);
	printf("%08X\n", x | y);
	printf("%08X\n", x ^ y);
	printf("%08X\n", ~x);
	printf("%08X\n", x >> 1);
	printf("%08X\n", x << 1);

	//////////////////////////

	// 마스크연산. 특정 비트열에 AND 연산을 하여 검사할 수 있게 하는 연산.
	// ex) xxxx에 0100을 AND하여 두번째 숫자가 1인지 검사하는 마스크연산. 

	return 0;
}
