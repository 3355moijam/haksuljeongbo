#include "stdafx.h"
#include <cctype>


int main()
{
	char ch;
	int whitespace = 0;
	int digits = 0;
	int chars = 0;
	int punct = 0;
	int others = 0;

	cin.get(ch);
	while (ch != '@')
	{
		if (isalpha(ch))
			chars++;
		else if (isspace(ch))
			whitespace++;
		else if (isdigit(ch))
			digits++;
		else if (ispunct(ch))
			punct++;
		else
			others++;
		cin.get(ch);
	}

	cout << "알파벳 문자 : " << chars << endl;
	cout << "공백 : " << whitespace << endl;
	cout << "숫자 : " << digits << endl;
	cout << "구두점 : " << punct << endl;
	cout << "기타 : " << others << endl;

	return 0;
}
