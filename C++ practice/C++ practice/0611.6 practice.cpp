#include "stdafx.h"

struct CandyBar
{
	string name;
	double weight;
	unsigned int calories;
};
int main()
{

	CandyBar *SnackBar = new CandyBar[3];
	SnackBar[0] = { "Mocha Munch", 2.3, 350 };
	SnackBar[1] = { "��������", 5, 200 };
	SnackBar[2] = { "�ݶ�", 20, 150 };

	for (int i = 0; i < 3; i++)
	{
		cout << "���� �̸�: " << SnackBar[i].name << endl;
		cout << "���� �߷�: " << SnackBar[i].weight << endl;
		cout << "���� Į�θ�: " << SnackBar[i].calories << endl << endl;
	}

	delete[] SnackBar;
	return 0;
}
