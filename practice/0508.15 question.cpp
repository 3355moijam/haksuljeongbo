#include "stdafx.h"

int main(void)
{
	printf("������ �Է��� �ּ���(0~100) : ");
	int score;
	char grade;
	scanf("%d", &score);

	if (score >= 90)
		grade = 'A';
	else if (score >= 80)
		grade = 'B';
	else if (score >= 70)
		grade = 'C';
	else if (score >= 60)
		grade = 'D';
	else
		grade = 'F';

	printf("����� ������ %c�Դϴ�.\n", grade);
	////////////////////////////////

	return 0;
}
