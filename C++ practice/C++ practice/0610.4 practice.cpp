#include "stdafx.h"

#define runway(accel, targetSpeed) (targetSpeed*targetSpeed) / (2*accel)

int main()
{
	float accel = 0;
	float targetSpeed = 0;

	cout << "���ӵ��� �Է����ּ��� (���� m/s^2): ";
	cin >> accel;
	cout << "�̷��ӵ��� �Է����ּ��� (���� m/s): ";
	cin >> targetSpeed;
	
	cout << "�ּ� Ȱ�ֱ��̴� " << runway(accel, targetSpeed) << "m �Դϴ�." << endl;

	return 0;
}

