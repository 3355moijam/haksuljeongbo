#include "stdafx.h"

void showmenu();
void report();
void comfort();

int main()
{
	showmenu();
	int choice;
	cin >> choice;
	while (choice != 5)
	{
		switch (choice)
		{
		case 1: cout << "\a\n";
			break;
		case 2: report();
			break;
		case 3: cout << "������� ���� ȸ�翡 ��̽��ϴ�.\n";
			break;
		case 4: comfort();
			break;
		default: cout << "�װ��� ������ �� �����ϴ�.\n";
			break;
		}
		showmenu();
		cin >> choice;
	}
	cout << "���α׷��� �����մϴ�.\n";

	return 0;
}


void showmenu()
{
	cout << "1, 2, 3, 4, 5�� �߿��� �ϳ��� �����Ͻʽÿ� : " << endl;
	cout << "1) �����			2) ����" << endl;
	cout << "3) �˸�����			4) �ݷ���" << endl;
	cout << "5) ����" << endl;
}

void report()
{
	cout << "�̹� �б�� �濵 ������ ���� �����ϴ�." << endl;
	cout << "�Ǹŷ��� 120% �þ��, ����� 35% �پ����ϴ�." << endl;
}

void comfort()
{
	cout << "������� ����� ���� �ְ��� CEO��� �����ϰ� �ֽ��ϴ�." << endl;
	cout << "�̻�ȸ�� ����� ���� �ְ��� CEO��� �����ϰ� �ֽ��ϴ�." << endl;
}