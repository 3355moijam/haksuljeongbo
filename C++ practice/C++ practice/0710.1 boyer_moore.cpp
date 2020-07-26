#include "stdafx.h"

int wcs_cmp(const wstring & source, const wstring & target);
void filter(wstring & source, const wstring & target);

int main()
{

	wstring src = L"abcxdezcabacabcd";
	wstring tar = L"abcxd";

	wcout << wcs_cmp(src, tar) << endl;
	wcout << src.find(tar) << endl;

	filter(src, tar);

	wcout << src << endl;

	return 0;
}

int wcs_cmp(const wstring & source, const wstring & target)
{
	int sSize = source.size();
	int tSize = target.size();

	int i = 0, j = 0;
	for (i = tSize; i <= sSize; i++)
	{
		bool isbreak = false; int tmpIndex = 0;
		for (j = 1; j <= tSize; j++)
		{
			if (source[i - j] != target[tSize - j])
			{
				tmpIndex = tSize - j;
				break;
			}
			if (j == tSize)
				return i - j;
		}

		for (int k = tmpIndex; k >= 0; k--)
		{
			if (source[i - j] == target[k])
			{
				isbreak = true;
				break;
			}
		}



		if (isbreak)
			continue;
		else
			i += tmpIndex;
	}

	return -1;
}

void filter(wstring & source, const wstring & target)
{
	int location = wcs_cmp(source, target);
	int tSize = target.size();

	if (location == -1)
		return;

	for (int i = 0; i < tSize; i++)
	{
		source[location + i] = L'*';
	}

}
