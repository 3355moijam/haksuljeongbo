#include "stock00.h"
#include "../../stdafx.h"


stock00::stock00()
{
	cout << "����Ʈ �����ڰ� ȣ��Ǿ����ϴ�." << endl;
	company = "no name";
	shares = 0;
	share_val = 0;
	total_val = 0;
}

stock00::stock00(const string & co, long n, double pr)
{
	cout << co << "�� ����ϴ� �����ڰ� ȣ��Ǿ����ϴ�." << endl;

	acquire(co, n, pr);
}

stock00::~stock00()
{
	cout << "�ȳ�, " << company << "!" << endl;
}
void stock00::acquire(const string & co, long n, double pr)
{
	company = co;
	if (n < 0)
	{
		cout << "�ֽ� ���� ������ �� �� �����Ƿ�, "
			<< company << " shares�� 0���� �����մϴ�.\n";
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
		cout << "���� �ֽ� ���� ������ �� �� �����Ƿ�, "
			<< "�ŷ��� ��ҵǾ����ϴ�.\n";
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
		cout << "�ŵ� �ֽ� ���� ������ �� �� �����Ƿ�, "
			<< "�ŷ��� ��ҵǾ����ϴ�.\n";
	}
	else if (num > shares)
	{
		cout << "���� �ֽĺ��� ���� �ֽ��� �ŵ��� �� �����Ƿ�, "
			<< "�ŷ��� ��ҵǾ����ϴ�.\n";
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

	cout << "ȸ��� : " << company
		<< " �ֽ� �� : " << shares << endl;

	cout << "�ְ� : " << share_val;
	cout.precision(2);
	cout << " �ֽ� �� ��ġ: $" << total_val << endl;

	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
}