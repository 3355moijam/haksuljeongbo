#include "stdafx.h"

#define runway(accel, targetSpeed) (targetSpeed*targetSpeed) / (2*accel)

int main()
{
	float accel = 0;
	float targetSpeed = 0;

	cout << "가속도를 입력해주세요 (단위 m/s^2): ";
	cin >> accel;
	cout << "이륙속도를 입력해주세요 (단위 m/s): ";
	cin >> targetSpeed;
	
	cout << "최소 활주길이는 " << runway(accel, targetSpeed) << "m 입니다." << endl;

	return 0;
}

