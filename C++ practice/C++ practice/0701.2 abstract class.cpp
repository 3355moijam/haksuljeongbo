#include "stdafx.h"
#include "class\AcctABC.h"
const int CLIENTS = 4;

int main()
{
	AcctABC * p_clients[CLIENTS];
	string temp;
	long tempnum;
	double tempbal;
	char kind;

	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "고객의 이름을 입력한다: ";
		getline(cin, temp);
		cout << "고객의 은행계좌 번호를 입력한다:";
		cin >> tempnum;
		cout << "계좌 개설을 입력한다: $";
		cin >> tempbal;
		cout << "Brass 계좌에 1번을 입력한다. 또는,"
			<< "BrassPlus 계좌에 2번을 입력한다 ";

		while ((cin >> kind && (kind != '1' && kind != '2')))
			cout << "1 또는 2를 입력한다. ";
		if (kind == '1')
		{
			p_clients[i] = new Brass(temp, tempnum, tempbal);
		}
		else
		{
			double tmax, trate;
			cout << "당좌대월 한계를 입력한다 : $";
			cin >> tmax;
			cout << "이자율을 입력한다."
				<< "소수점을 사용한다:";
			cin >> trate;
			p_clients[i] = new BrassPlus(temp, tempnum, tmax, trate);
		}
		while (cin.get() != '\n')
			continue;

	}

	cout << endl;

	for (int i = 0; i < CLIENTS; i++)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}

	for (int i = 0; i < CLIENTS; i++)
	{
		delete p_clients[i];
	}

	cout << "프로그램을 종료합니다." << endl;

	return 0;
}
