#include "stdafx.h"


int main()
{
	float A, B, C, D, E, F;
	cout << "1�� ������ �� ���� �Է��� �ּ���." << endl;
	cout << "Ax + By = E" << endl;
	cout << "A :";
	cin >> A;
	cout << "B :";
	cin >> B;
	cout << "E :";
	cin >> E;
	cout << A << "x + " << B << "y = " << E << endl;

	cout << "Cx + Dy = F" << endl;
	cout << "C :";
	cin >> C;
	cout << "D :";
	cin >> D;
	cout << "F :";
	cin >> F;
	cout << C << "x + " << D << "y = " << F << endl;

	float X, Y;
	
	if (A * D - B * C != 0)
	{
		X = (E * D - B * F) / (A * D - B * C);
		Y = (A * F - E * C) / (A * D - B * C);

		cout << "x = " << X << endl;
		cout << "y = " << Y << endl;
	}
	else
	{
		cout << "�ذ� ����" << endl;
	}

	return 0;
}

