#include "stdafx.h"

int main(void)
{
	/*
	int nAge = 0;

	printf("���̸� �Է��ϼ���. : ");
	scanf("%d", &nAge); // scanf�� printf�� �Է¹���. %d(����)���� ����ڰ� �Է��ϸ� �� ���� nAge�� �ּҿ� �����Ѵ�.
						// �߸��� ���� �Է��ϸ� �Ҵ����� �ʴ´�.


	printf("����� ���̴� %d�� �Դϴ�.\n", nAge);
	*/
	/*
	int x = 0, y = 0;

	printf("�� ������ �Է��ϼ��� : ");

	scanf("%d %d", &x, &y); // %d ���̿� ������ �־ ���� ��.
	printf("�� ���� ���� %d �Դϴ�.\n", x + y);
	*/
	/*
	char szBuffer[32] = { 0 };

	scanf("%s", szBuffer); // ���ڿ��� szBuffer�� �ᵵ �ٷ� �ּҷ� ������ �ȴ�. & ������� ����.
	printf("%s\n", szBuffer);

	char szBufferLeft[32] = { 0 };
	char szBufferRight[32] = { 0 };

	scanf("%s%s", szBufferLeft, szBufferRight);
	printf("%s %s\n", szBufferLeft, szBufferRight); // ���⸦ �־ �Է¹ް� ������ �׳� gets_s�� ���� �� ����.
	*/
	
	char szName[32] = { 0 };
	int nAge = 0;

	printf("���̸� �Է��ϼ���. : ");
	scanf_s("%d", &nAge);

	printf("�̸��� �Է��ϼ���. : ");
	// fflush(stdin); // ���� �ȿ� ���� ���� ���� �ڵ�. �����ִ� ���๮�ڸ� ������. fflush�� vs2015���� ������ �����ߴ�.
	_fgetchar(); // ���ۿ� �ִ� �� �ϳ��� �������� �ڵ�. \n�� �������� ���� ���� ��.
	gets_s(szName, sizeof(szName));

	printf("%d, %s\n", nAge, szName);
	
	return 0;
}
