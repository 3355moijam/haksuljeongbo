#include "stdafx.h"


int main(void)
{
	int aList[5] = { 30, 40, 10, 50, 20 };
	int nListLeng = sizeof(aList) / sizeof(int);
	// �ʱ� �迭
	printf("�ʱ� : ");
	for (int i = 0; i < nListLeng; i++)
	{
		printf("%d ", aList[i]);
	}
	printf("\n\n\n");
	
	//// �������ķ� �˷��� ��������(?) ��������. �������Ŀ� �����. 1���� ������ ��, 2���� ������ �� �س����� ����
	//for (int i = 0; i < nListLeng-1; i++)
	//{
	//	for (int j = i + 1; j < nListLeng; j++)
	//	{
	//		if (aList[i] > aList[j])
	//		{
	//			int tmp = aList[i];
	//			aList[i] = aList[j];
	//			aList[j] = tmp;
	//		}
	//	}
	//}
	////////////////

	// �������� 1��2, 2��3, 3��4 ... n-1�� n�� ���Ͽ� ��ȯ. n-1�� �ݺ�
	//for (int i = 0; i < nListLeng - 1; i++)
	//{
	//	for (int j = 0; j < nListLeng - 1; j++)
	//	{
	//		if (aList[j] > aList[j+1])
	//		{
	//			int tmp = aList[j];
	//			aList[j] = aList[j+1];
	//			aList[j+1] = tmp;
	//		}
	//	}
	//}
	//////////////////////////////////////

	// ��������. ���������� ���ϴ� ���� ��/ũ�ٴ°� Ȯ���ϰ� ���� �� �� ���� ��ȯ�Ѵ�.
	int index = 0;
	for (int i = 0; i < nListLeng - 1; i++)
	{
		index = i;
		for (int j = i+1; j < nListLeng; j++)
		{
			if (aList[index] > aList[j])
			{
				index = j;
			}
		}
		int tmp = aList[i];
		aList[i] = aList[index];
		aList[index] = tmp;

		// ��ȭ����
		for (int i = 0; i < nListLeng; i++)
		{
			printf("%d ", aList[i]);
		}
		printf("\n\n");
	}
	////////////////////////////////////


	// ��ºκ�
	printf("\n��� : ");
	for (int i = 0; i < nListLeng; i++)
	{
		printf("%d ", aList[i]);
	}
	printf("\n\n");




	return 0;
}

