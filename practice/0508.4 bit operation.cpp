#include "stdafx.h"

int main(void)
{
	
	int nData = 0x11223344;

	printf("%08X\n", nData & 0x00FFFF00); // AND ����
	printf("%08X\n", nData | 0x2211FFFF); // OR ����
	printf("%08X\n", nData ^ 0x2211FFFF); // XOR����
	printf("%08X\n", ~nData); // NOT ����
	printf("%08X\n", nData >> 8); // RIGTH SHIFT /2�� ������ ȿ���� ����. �ξ� ����
	printf("%08X\n", nData << 16); // LEFT SHIFT *2�� ������ ȿ���� ����. �ξ� ����

	int x = 20, y = 15;
	printf("%08X\n", x & y);
	printf("%08X\n", x | y);
	printf("%08X\n", x ^ y);
	printf("%08X\n", ~x);
	printf("%08X\n", x >> 1);
	printf("%08X\n", x << 1);

	//////////////////////////

	// ����ũ����. Ư�� ��Ʈ���� AND ������ �Ͽ� �˻��� �� �ְ� �ϴ� ����.
	// ex) xxxx�� 0100�� AND�Ͽ� �ι�° ���ڰ� 1���� �˻��ϴ� ����ũ����. 

	return 0;
}
