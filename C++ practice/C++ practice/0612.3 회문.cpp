#include "stdafx.h"

wstring strRev(wstring txt);


int main()
{
	wcin.imbue(locale("korean"));
	wcout.imbue(locale("korean"));

	wstring a = L"";
	wcout << L"문자를 입력해주세요 : ";
	wcin >> a;
	wstring rev = strRev(a);

	wcout << rev << endl;
	
	if (a == rev)
	{
		wcout << L"회문입니다." << endl;
	}
	else
	{
		wcout << L"회문이 아닙니다." << endl;
	}

	return 0;
}


wstring strRev(wstring txt)
{
	wstring tmp = txt;
	
	wstring rev = L"";

	while (tmp != L"")
	{
		rev += tmp.back();
		tmp.pop_back();
	}

	return rev;
}