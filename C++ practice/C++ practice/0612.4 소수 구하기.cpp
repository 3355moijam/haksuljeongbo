#include "stdafx.h"

int prime[200];
int intRev(int pr);
void getAllPrime(int target);
int isPalind(int pr);
int isPrime(int pr);
int emirp(int pr);

int main()
{
	getAllPrime(1000);
	string s = "";
	// 소수(2~1000)
	s = "";
	cout << "소수" << endl;
	for (int k : prime)
	{
		if (k == NULL)
			break;
		else
			s += to_string(k) + '\n';
	}
	cout << s << endl << endl;

	// 회문소수
	s = "";
	cout << "회문소수" << endl;
	for (int k : prime)
	{
		if (k == NULL)
			break;
		else if (!isPalind(k))
			continue;
		else
			s += to_string(k) + '\n';
	}
	cout << s << endl << endl;

	// 수소
	s = "";
	cout << "수소" << endl;
	for (int k : prime)
	{
		int l = emirp(k);
		if (k == NULL)
			break;
		else if (l == 0)
			continue;
		else
			s += to_string(k) + ' ' + to_string(l) + '\n';
	}
	cout << s << endl << endl;
	return 0;
}

// 수소면 수소값, 아니면 0
int emirp(int pr)
{
	if (isPalind(pr))
		return 0;
	else
	{
		int rp = intRev(pr);
		if (isPrime(rp))
		{
			return rp;
		}
		else
			return 0;
	}
}

void getAllPrime(int target)
{
	int i = 2;
	int count = 1;
	
	prime[0] = i;
	bool flag = false;
	
	for (i = 3; i <= target; i++)
	{
		flag = false;
		int clamp = sqrt(i);
		for (int x : prime)
		{
			if (x == NULL)
				break;
			if (x > clamp)
				break;

			if (i % x == 0)
			{
				flag = true;
				break;
			}
		}

		if (!flag)
		{
			prime[count] = i;
			count++;
		}
	}
}

int isPalind(int pr)
{
	int rev = intRev(pr);
	if (pr == rev)
	{
		return 1;
	}
	else
		return 0;
}

int intRev(int pr)
{
	string tmp = to_string(pr);

	string rev = "";

	while (tmp != "")
	{
		rev += tmp.back();
		tmp.pop_back();
	}

	return atoi(rev.c_str());
}

int isPrime(int pr)
{
	for (int x : prime)
	{
		if (x == NULL)
		{
			return 0;
		}
		else
		{
			if (pr == x)
			{
				return 1;
			}
		}
	}

	return 0;
}