#include "stdafx.h"
#include <vector>
#include <array>


int main()
{

	string a;
	char str[16];

	//cin.getline(str, 16); // 개행문자는 읽어와서 버림
	//cin >> str;
	cin.get(str, 16).get(); // get은 개행문자를 큐에 남겨둠. 그래서 뒤에 get을 한번 더 써줌
	cout << str << endl;
	cin.get(str, 16);
	cout << str << endl;

	

	return 0;
}
