#include "stdafx.h"

int getResult(void);
char getGrade(int nScore);

int main(void)
{
	// �Լ�. main �Լ� �տ� �����ϴ���, �ڿ� �����ϰ� main �տ��� �����صδ���
	int nResult = 0;

	nResult = getResult();
	printf("����� ������ '%c'(%d)�Դϴ�.\n", getGrade(nResult), nResult);


	return 0;
}

int getResult(void) // �Ű������� ���� ������ ���� �̸����δ� �缱���� �Ұ���.
{
	int nResult = 0;  // �� �ȿ��� ������ ������ ����������, �� ���� ���������� ���Ѵ�.
	printf("����(0~100)�� �Է��ϼ���. : ");
	scanf("%d%*C", &nResult);
	
	return nResult;
}

char getGrade(int nScore)
{
	if (nScore >= 90) return 'A';
	else if (nScore >= 80) return 'B';
	else if (nScore >= 70) return 'C';
	else if (nScore >= 60) return 'D';
	else return 'F';
}