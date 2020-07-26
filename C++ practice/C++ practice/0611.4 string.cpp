#include "stdafx.h"
#include <string>


int main()
{
	//char charr1[20];
	//char charr2[20] = "jaguar";

	//string str1;
	//string str2 = "panther";

	//cout << "고양이과 동물 한 종 입력:";
	//cin >> charr1;
	//cout << "하나 더:";
	//cin >> str1;
	//cout << "다음은 모두 고양이과 입니다.";
	//cout << charr1 << " " << charr2 << " ";
	//cout << str1 << " " << str2 << " ";
	//cout << endl;

	//cout << charr2 << "의 세 번째 글자 :" << charr2[2] << endl;
	//cout << str2 << "의 세 번째 글자 :" << str2[2] << endl;
	/////////
	string str1 = "제가 LA에 있을때 이야기입니다. 아닌가 모르겠다 다시 돌아올까요? 그래야하나.. 아니 모르겠는데 어째야하지 흐으으으으으음...";
	string str2 = "zz", str3;
	str3 = str1 + str2;
	cout << sizeof str1 << endl;
	cout << str1.size() << endl;
	cout << sizeof str3 << endl;
	cout << str3.size() << endl;
	return 0;
}
