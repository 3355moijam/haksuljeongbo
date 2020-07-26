#include "stdafx.h"
#include "namesp.h"

namespace pers
{
	void getPerson(Person & rp)
	{
		cout << "이름을 입력하십시오: ";
		cin >> rp.fname;
		cout << "성씨를 입력하십시오: ";
		cin >> rp.lname;
	}
	void showPerson(const Person & rp)
	{
		cout << rp.lname << ", " << rp.fname;
	}
}

namespace debts
{
	void getDebt(Debt & rd)
	{
		getPerson(rd.name);
		cout << "부채를 입력하십시오: ";
		cin >> rd.amount;
	}
	void showDebt(const Debt & rd)
	{
		pers::showPerson(rd.name);
		cout << ": $" << rd.amount << endl;
	}

	double sumDebts(const Debt ar[], int n)
	{
		double total = 0;
		for (int i = 0; i < n; i++)
			total += ar[i].amount;
		return total;
	}

}
