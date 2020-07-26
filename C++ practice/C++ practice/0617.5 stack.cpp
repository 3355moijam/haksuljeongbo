#include "stdafx.h"
#include "IntStack.h"

int main()
{
	IntStack s;
	if (Initialize(&s, 4) == -1)
	{
		cout << "���� ������ �����Ͽ����ϴ�." << endl;
		return 1;
	}

	while (1)
	{
		int menu, x;
		cout << "���� ������ �� : " << Size(&s) << "/ " << Capacity(&s) << endl;
		cout << "(1)Ǫ�� (2)�� (3)��ũ (4)��� (0)���� : ";
		cin >> menu;

		if (menu == 0) break;
		switch (menu)
		{
		case 1: // Ǫ��
			cout << "������ : ";
			cin >> x;
			if (Push(&s, x) == -1)
				cout << "\a���� : Ǫ�ÿ� �����Ͽ����ϴ�." << endl;
			break;

		case 2: // ��
			if (Pop(&s, &x) == -1)
				cout << "\a���� : �˿� �����Ͽ����ϴ�." << endl;
			else
				cout << "�� �����ʹ� " << x << "�Դϴ�." << endl;
			break;
			
		case 3: // ��ũ
			if (Peek(&s, &x) == -1)
				cout << "\a���� : ��ũ�� �����Ͽ����ϴ�." << endl;
			else
				cout << "��ũ �����ʹ� " << x << "�Դϴ�." << endl;
			break;

		case 4: // ���
			Print(&s);
			break;
		}
	}

	Terminate(&s);
	return 0;
}
