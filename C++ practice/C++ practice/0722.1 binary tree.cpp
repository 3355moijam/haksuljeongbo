#include "stdafx.h"
#include "class\biTree.h"

void Menu();
int getInput();

int main()
{
	biTree bTree;
	int num;
	while (1)
	{
		Menu();
		num = getInput();
		switch (num)
		{
		case 1:
			bTree.push(getInput());
			break;
		case 2:
			bTree.pop(getInput());
			break;
		case 3:
			bTree.find(getInput());
			break;
		case 4:
			bTree.print();
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