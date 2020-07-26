#include "stock00.h"
#include "../../stdafx.h"


stock00::stock00()
{
	cout << "디폴트 생성자가 호출되었습니다." << endl;
	company = "no name";
	shares = 0;
	share_val = 0;
	total_val = 0;
}

stock00::stock00(const string & co, long n, double pr)
{
	cout << co << "를 사용하는 생성자가 호출되었습니다." << endl;

	acquire(co, n, pr);
}

stock00::~stock00()
{
	cout << "안녕, " << company << "!" << endl;
}
void stock00::acquire(const string & co, long n, double pr)
{
	company = co;
	if (n < 0)
	{
		cout << "주식 수는 음수가 될 수 없으므로, "
			<< company << " shares를 0으로 설정합니다.\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}

void stock00::buy(long num, double price)
{
	if (num < 0)
	{
		cout << "매입 주식 수는 음수가 될 수 없으므로, "
			<< "거래가 취소되었습니다.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void stock00::sell(long num, double price)
{
	if (num < 0)
	{
		cout << "매도 주식 수는 음수가 될 수 없으므로, "
			<< "거래가 취소되었습니다.\n";
	}
	else if (num > shares)
	{
		cout << "보유 주식보다 많은 주식을 매도할 수 없으므로, "
			<< "거래가 취소되었습니다.\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void stock00::update(double price)
{
	share_val = price;
	set_tot();
}

void stock00::show() const
{
	ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
	streamsize prec = cout.precision(3);

	cout << "회사명 : " << company
		<< " 주식 수 : " << shares << endl;

	cout << "주가 : " << share_val;
	cout.precision(2);
	cout << " 주식 총 가치: $" << total_val << endl;

	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
}