#include "stdafx.h"

// �ܺ� �Լ� ����
void InitCounter(int i);
void IncreaseCounter();

// �ܺ� �������� ����. ���ǰ� �ƴ�. source�� �ִ�
extern int g_nCounter;

int main(int argc, char* argv[])
{
	

	printf("%d\n", g_nCounter);
	IncreaseCounter();
	printf("%d\n", g_nCounter);



	return 0;
}