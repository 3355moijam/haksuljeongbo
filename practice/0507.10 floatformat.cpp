#include "stdafx.h"

int main(void)
{

	double dData = 123.456;
	printf("%f, %f\n", dData, -123.456);

	printf("%.1f\n", dData); // �Ҽ��� 2��° �ڸ����� �ݿø��ϰ� ���ڸ����� ���
	printf("%.2f\n", dData); // 3���� �ݿø�, 2�ڸ� ���
	printf("%.3f\n", dData); // 4���� �ݿø�, 3�ڸ� ���

	printf("%8d\n", 123); // �Ҽ��� ���� 12�ڸ��� ���, �Ҽ��� ���� 4��°���� �ݿø��ϰ� 3�ڸ��� ���
	printf("%12.3f\n", dData);
	printf("%012.3f\n", dData);


	return 0;
}
