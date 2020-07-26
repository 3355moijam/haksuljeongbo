#include "stdafx.h"

using namespace std;
float CtoF(float C);
float MtoKm(float M);

int main()
{
	cout << "몇 마일 움직였나요?" << endl;
	int n = 0;
	cin >> n;
	cout << "당신은 " << CtoF(n) << "km 움직였습니다." << endl << endl;

	cout << "섭씨 몇도?" << endl;
	int k = 0;
	cin >> k;
	cout << "섭씨 " << k << "도는 화씨로 " << MtoKm(k) << "도 입니다." << endl;


	return 0;
}

float CtoF(float C)
{
	return C*1.60934;
}

float MtoKm(float M)
{
	return M * 1.8 + 32.0;
}