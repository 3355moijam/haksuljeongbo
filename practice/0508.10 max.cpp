#include "stdafx.h"

int main(void)
{
	// ��ʸ�Ʈ ����� �ִ� �ּҰ��� ���ϴ� ���

	//int nMax = 0, nMin = 0;
	//int a, b, c;
	//scanf("%d%d%d", &a, &b, &c);
	//nMax = a > b ? a : b;
	//nMax = nMax > c ? nMax : c;
	//nMin = a < b ? a : b;
	//nMin = nMin < c ? nMin : c;

	//printf("�ִ�: %d\n�ּ�: %d\n", nMax, nMin);
	/////////////////////////////////////////////////

	
	//// �����̹� ����� �ִ�, �ּҰ��� ���ϴ� ���	
	//int nMax = 0, nMin = 0, nInput = 0;

	//printf("���ڸ� �� �� �Է��ϼ���\n");
	//scanf("%d", &nInput);
	//nMax = nInput;
	//nMin = nInput;
	//scanf("%d", &nInput);
	//nMax = nInput > nMax ? nInput : nMax;
	//nMin = nInput < nMin ? nInput : nMin;
	//scanf("%d", &nInput);
	//nMax = nInput > nMax ? nInput : nMax;
	//nMin = nInput < nMin ? nInput : nMin;
	//printf("�ִ� : %d\n�ּ� : %d\n", nMax, nMin);
	/////////////////////////////////////////////////


	//question
	int nMax = -100, nInput = 0;
	
	scanf("%d", &nInput);
	nMax = nInput > nMax ? nInput : nMax;

	scanf("%d", &nInput);
	nMax = nInput > nMax ? nInput : nMax;

	scanf("%d", &nInput);
	nMax = nInput > nMax ? nInput : nMax;

	printf("MAX : %d\n", nMax);




	return 0;
}
