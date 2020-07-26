#include "stdafx.h"
#include "class\List.h"

int getInput();
string getName();
void printMenu();

int main()
{
	List classmate;
	int nInput = 0;

	while (nInput != 5)
	{
		printMenu();
		nInput = getInput();
		int num;

		switch (nInput)
		{
		case 1:
		{
			num = getInput();
			string name = getName();
			classmate.push(num, name); 
		}
		break;
		case 2:
		{
			num = getInput();
			classmate.pop(num);
		}
			break;
		case 3:
		{
			num = getInput();
			classmate.printNode(classmate.find(num));
		}
			break;
		case 4:
		{
			classmate.print();
		}
			break;
		default:
			break;
		}

	}

}

int getInput()
{
	int num;
	cout << "번호: ";
	cin >> num;
	return num;
}

string getName()
{
	string name;
	cout << "이름: ";
	cin >> name;
	return name;
}

void printMenu()
{
	cout << "1. 추가  2. 삭제  3. 검색  4. 출력  5. 종료" << endl;
}
