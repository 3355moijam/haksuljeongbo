#include "stdafx.h"

int str_cmp(wstring target, wstring source);
int strfilter1(const wstring target, wstring &source);
int strfilter2(const wstring target, wstring &source);

int main()
{
	wcin.imbue(locale("korean"));
	wcout.imbue(locale("korean"));

	wcout << L"어디에서 어떤 단어를 찾을까요?" << endl;
	wcout << L"어디에서? ";
	wstring src = L"abcdefga";
	getline(wcin,src);
	wstring src2 = src;

	wcout << L"어떤 단어? ";
	wstring tar = L"def";
	wcin >> tar;
	wcin.ignore();

	cout << str_cmp(tar, src) << endl;
	strfilter1(tar, src);
	strfilter2(tar, src2);
	wcout << src << endl;
	wcout << src2 << endl;

	return 0;
}

int str_cmp(wstring target, wstring source)
{
	for (size_t i = 0; i < source.size() - (target.size() - 1); i++)
	{
		for (size_t j = 0; j < target.size(); j++)
		{
			if (source[i+j] != target[j])
				break;
			if (j == (target.size() - 1))
				return i;
		}
	}
	return -1;
}

int strfilter1(const wstring target, wstring & source)
{
	int dst = str_cmp(target, source);
	if (dst == -1)
		return 1;

	for (size_t i = 0; i < target.size(); i++)
	{
		source[i + dst] = '*';
	}
	return 0;
}

int strfilter2(const wstring target, wstring &source)
{
	int dst = source.find(target);
	if (dst == -1)
		return 1;

	for (size_t i = 0; i < target.size(); i++)
	{
		source[i + dst] = '*';
	}

	return 0;
}
