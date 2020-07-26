#include "stdafx.h"
#include <string>

string sTable = { "0123456789abcdefghijklmnopqrstuvwxyz" };

#define nTos(n) sTable[n]
#define sTon(str) sTable.find(str)

string NtoN(string input, int IN, int OUT);

int main()
{

	string num;
	int fr, to;
	cout << "몇 진수의 수인가? :";
	cin >> fr;
	cout << "수 입력 :";
	cin >> num;
	cout << "몇 진수로 변환을 ? :";
	cin >> to;
	
	string answer = NtoN(num, fr, to);
	
	if(answer != "")
		cout << fr << "진수 " << num << "은 " << to << "진수로 " << answer << "이다." << endl;

	return 0;
}


string NtoN(string input, int IN , int OUT)
{
	string sInput = input;
	string temp = "";
	int num = 0;
	int index = 0;
	while (sInput != "")
	{
		temp = sInput.back();
		sInput.pop_back();
		
		if (sTon(temp) >= IN)
		{
			cout << "ERROR : "<< input << "은 " << IN << "진수가 아닙니다." << endl;
			return "";
		}

		num += sTon(temp) * pow(IN, index);
		index++;
	}
	
	if(OUT == 10)
		return to_string(num);

	int quot = num, remain;
	index = 0, temp = "";
	while (quot != 0)
	{
		remain = quot % OUT;
		quot /= OUT;
		temp = nTos(remain) + temp;
	}
	return temp;

}
