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
	cout << "�� ������ ���ΰ�? :";
	cin >> fr;
	cout << "�� �Է� :";
	cin >> num;
	cout << "�� ������ ��ȯ�� ? :";
	cin >> to;
	
	string answer = NtoN(num, fr, to);
	
	if(answer != "")
		cout << fr << "���� " << num << "�� " << to << "������ " << answer << "�̴�." << endl;

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
			cout << "ERROR : "<< input << "�� " << IN << "������ �ƴմϴ�." << endl;
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
