#include "stdafx.h"
#include <climits>

int main()
{
	int nInt = INT_MAX;
	short nShort = SHRT_MAX;
	long nLong = LONG_MAX;
	long long nLLong = LLONG_MAX;

	cout << "int는 " << sizeof(int) << "byte이다." << endl;
	cout << "short는 " << sizeof(short) << "byte이다." << endl;
	cout << "long는 " << sizeof(long) << "byte이다." << endl;
	cout << "long long는 " << sizeof(long long) << "byte이다." << endl;

	cout << "최댓값:" << endl;
	cout << "int: " << nInt << endl;
	cout << "short: " << nShort << endl;
	cout << "long: " << nLong << endl;
	cout << "long long: " << nLLong << endl << endl;
	cout << "int의 최솟값: " << INT_MIN << endl;
	cout << "바이트당 비트 수: " << CHAR_BIT << endl;
	return 0;
}
