#include "stdafx.h"

int main(void)
{
	/*int nResult = 0;
	
	nResult = 3 + 4;

	printf("nResult : %d\n", nResult - 5);*/
	

	/*char ch = 'A';

	printf("%c\n", ch);

	printf("%c\n", ch + 1);
	printf("%c\n", 'A' + 2);

	printf("%d : d\n", 5.0 + 2);
	printf("%f : f\n", 5.0 + 2);*/

	//int x = 10;
	//
	//printf("%d\n", x * 10); // int * int
	//printf("%d\n", x * 10.0); // int * double > ��ºҴ�

	//printf("%d\n", x / 10);
	//printf("%d\n", 5 / 2); // int / int�� int�� ��µȴ�. �Ҽ����� ����
	//printf("%f\n", 5 / 2); // �̰͵� int / int�̹Ƿ� 2�� ���. �� double �������� ��µǾ� 2.0�� ���´�.

	//printf("%f\n", 5.0 / 2); // double / int �� double �� ���

	//int x = 0;
	//scanf("%d", &x);

	//printf("�� : %d\n", x / 3);
	//printf("������ : %d\n", x % 3);  
	//printf("������ : %d\n", x % 3.0); // ������������ �ݵ�� int�� ����Ѵ�.


	// szBuffer�� �迭�϶� szBuffer = 'A'��� �ϸ� szBuffer�� �޸𸮸� �����Ϸ��� �� ���̱� ������ �Ұ���. �迭�� & ���� ���� �ּҸ� ����Ų��.

	// >>���մ��� ������
	int nResult = 0, nData = 10;

	nResult += 3;
	printf("%d\n", nResult); 

	nResult *= nData;
	printf("%d\n", nResult);

	nResult /= 2;
	printf("%d\n", nResult);

	nResult -= nData - 5;
	printf("%d\n", nResult);

	nResult %= 3;
	printf("%d\n", nResult);
	// >> ��


	return 0;
}
