#include "stdafx.h"


int main()
{
	double face = 0, tail = 0, toss = 0;
	double fper = 0;
	double tper = 0;
	int check = 100;

	srand(time(NULL));
	for (int i = 1; i <= 1000000; i++)
	{
		toss = rand() % 2;
		if (toss)
			face++;
		else
			tail++;

		if (i % check == 0)
		{
			fper = (face / (face + tail)) * 100;
			tper = (tail / (face + tail)) * 100;

			cout << i << "�� ����:" << endl;
			cout << "�ո��� ���� Ȯ�� : " << fper << endl;
			cout << "�޸��� ���� Ȯ�� : " << tper << endl << endl;

			check *= 10;
		}
	}

	return 0;
}
