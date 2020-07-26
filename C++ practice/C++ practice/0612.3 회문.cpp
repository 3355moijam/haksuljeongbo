#include "stdafx.h"

wstring strRev(wstring txt);


int main()
{
	wcin.imbue(locale("korean"));
	wcout.imbue(locale("korean"));

	wstring a = L"";
	wcout << L"���ڸ� �Է����ּ��� : ";
	wcin >> a;
	wstring rev = strRev(a);

	wcout << rev << endl;
	
	if (a == rev)
	{
		wcout << L"ȸ���Դϴ�." << endl;
	}
	else
	{
		wcout << L"ȸ���� �ƴմϴ�." << endl;
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