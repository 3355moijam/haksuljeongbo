// practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(void)
{

	printf("%d\n", 1234);
	printf("%d, %d\n", 1234, -5678);
	printf("%+d, %+d\n", 1234, -5678); // ��ȣ�ٿ��� ���

	printf("%8d\n", 1234); // 8�ڸ� ������ ���߰� ����������
	printf("%08d\n", 1234); // 8�ڸ� ������ ���ߵ� ���ڸ��� 0���� ä���
	printf("%-08d\n", 1234);  // 8�ڸ� ������ ���߰� ��������

	return 0;
}

