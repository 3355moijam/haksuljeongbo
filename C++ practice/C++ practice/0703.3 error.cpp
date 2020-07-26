#include "stdafx.h"
#include <cmath>
#include "class\exc_mean.h"

double hmean(double a, double b) throw(bad_hmean);
double gmean(double a, double b) throw(bad_gmean);

int main()
{
	double x, y, z;
	cout << "�� ���� �Է��Ͻʽÿ�: ";
	while (cin >> x >> y)
	{
		try
		{
			z = hmean(x, y);
			cout << x << ", " << y << "�� ��ȭ����� "
				<< z << "�Դϴ�." << endl;
			cout << x << ", " << y << "�� ��������� "
				<< gmean(x, y) << "�Դϴ�." << endl;
			cout << "�ٸ� �� ���� �Է��Ͻʽÿ�(�������� q): ";
		}
		catch (bad_hmean & bh)
		{
			bh.mesg();
			cout << "�ٽ� �Ͻʽÿ�." << endl;
			continue;
		}
		catch (bad_gmean & bg)
		{
			cout << bg.mesg();
			cout << "Values used: " << bg.v1 << ", "
				<< bg.v2 << endl;
			cout << "�˼��մϴ�. �� �̻� ������ �� �����ϴ�." << endl;
			break;
		}
	}
	cout << "���α׷��� �����մϴ�." << endl;
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
	{
		throw bad_hmean(a, b);
	}
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) throw(bad_gmean)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a, b);
	return sqrt(a * b);
}
