#include "stdafx.h"
#include <climits>

int main()
{
	int nInt = INT_MAX;
	short nShort = SHRT_MAX;
	long nLong = LONG_MAX;
	long long nLLong = LLONG_MAX;

	cout << "int�� " << sizeof(int) << "byte�̴�." << endl;
	cout << "short�� " << sizeof(short) << "byte�̴�." << endl;
	cout << "long�� " << sizeof(long) << "byte�̴�." << endl;
	cout << "long long�� " << sizeof(long long) << "byte�̴�." << endl;

	cout << "�ִ�:" << endl;
	cout << "int: " << nInt << endl;
	cout << "short: " << nShort << endl;
	cout << "long: " << nLong << endl;
	cout << "long long: " << nLLong << endl << endl;
	cout << "int�� �ּڰ�: " << INT_MIN << endl;
	cout << "����Ʈ�� ��Ʈ ��: " << CHAR_BIT << endl;
	return 0;
}
