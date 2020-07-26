#include "stdafx.h"


int main()
{
	int ch;
	int count = 0;

	while ((ch = cin.get()) != EOF)
	{
		cout.put(char(ch));
		++count;
	}

	cout << count << " 문자를 읽었습니다.\n";

	return 0;
}
