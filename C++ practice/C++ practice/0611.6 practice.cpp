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
	SnackBar[1] = { "초코파이", 5, 200 };
	SnackBar[2] = { "콜라", 20, 150 };

	for (int i = 0; i < 3; i++)
	{
		cout << "스낵 이름: " << SnackBar[i].name << endl;
		cout << "스낵 중량: " << SnackBar[i].weight << endl;
		cout << "스낵 칼로리: " << SnackBar[i].calories << endl << endl;
	}

	delete[] SnackBar;
	return 0;
}
