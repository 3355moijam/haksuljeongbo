#include "stdafx.h"

int g_nCounter = 0;
void InitCounter(int nData);
void IncreaseCounter(void);

int main(void)
{
	// ��������
	// include �Ʒ��� �Լ������ϵ��� �Ȱ��� ���� �������ָ� �ȴ�.
	// �� cpp ���� �ٸ� cpp���� ��뵵 ����. extern int variant;�� ������ �� ����
	// ���������� �������� �̸��� ���ٸ� ���������� �켱. ���������� ���� ::variant ������ ���.
	// ���������� ���������� �̸� �տ� g_�� �ٿ��ش�(global�̶� ��)

	InitCounter(10);

	printf("%d\n", g_nCounter);
	IncreaseCounter();
	printf("%d\n", g_nCounter);
	IncreaseCounter();
	printf("%d\n", g_nCounter);

	return 0;
}

void InitCounter(int nData)
{
	g_nCounter = nData;
}

void IncreaseCounter(void)
{
	g_nCounter++;
}