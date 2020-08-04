#include "stdafx.h"
#include "class\AVL.h"

void Menu();
int getInput();

int main()
{
	AVL AVLtree;
	int num;
	while (1)
	{
		Menu();
		num = getInput();
		switch (num)
		{
		case 1:
			AVLtree.push(getInput());
			break;
		case 2:
			AVLtree.pop(getInput());
			break;
		case 3:
			AVLtree.find(getInput());
			break;
		case 4:
			AVLtree.print();
			break;
		case 5:
			return 0;
		default:
			break;
		}
	}


	return 0;
}

int getInput()
{
	cout << "���ڸ� �Է����ּ���: ";
	int num;
	cin >> num;
	return num;
}

void Menu()
{
	cout << "1. �߰�  2. ����  3. �˻�  4. ���  5. ����" << endl;
}