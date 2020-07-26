#include "stdafx.h"
#include "class/StringBad.h"

void callme1(MyString &);
void callme2(MyString);

const int ArSize = 10;
const int MaxLen = 81;

int main()
{
	//cout << "내부 블록을 시작한다." << endl;
	//{
	//	MyString headline1("Celery Stalks at Midnight");
	//	MyString headline2("Lettuce Prey");
	//	MyString sports("Spinach Leaves Bowl for Dollars");
	//	cout << "headline1: " << headline1 << endl;
	//	cout << "headline2: " << headline2 << endl;
	//	cout << "sports: " << sports << endl;
	//	callme1(headline1);
	//	cout << "headline1: " << headline1 << endl;
	//	//callme2(headline2); // 참조가 아니면 생성자도 없는데 소멸자가 호출된다
	//	//cout << "headline2: " << headline2 << endl;
	//	//cout << "하나의 객체를 다른 객체로 초기화: " << endl;
	//	//StringBad sailor = sports; // 재정의 한 적이 없음. 컴파일러의 자동 생성.
	//	//cout << "sailor: " << sailor << endl; // sailor가 사라지면서 sports에 할당된 메모리를 지워버리면서 에러
	//	cout << "하나의 객체를 다른 객체에 대입: " << endl;
	//	MyString knot;
	//	knot = headline1;
	//	cout << "knot: " << knot << endl;
	//	cout << "이 블록을 빠져나온다." << endl;
	//}
	//cout << "main()의 끝" << endl;

	MyString name;
	cout << "안녕하십니까? 성함이 어떻게 되십니까?\n >> ";
	cin >> name;
	
	cout << name << " 씨! 간단한 영어 속담 " << ArSize
		<< "개만 입력 해주십시오(끝내려면 Enter):\n";
	MyString sayings[ArSize];
	char temp[MaxLen];
	int i;
	for (i = 0; i < ArSize; i++)
	{
		cout << i + 1 << ": ";
		cin.get(temp, MaxLen);
		while (cin && cin.get() != '\n')
			continue;
		if (!cin || temp[0] == '\0')
			break;
		else
			sayings[i] = temp;
	}
	int total = i;
	if (total > 0)
	{
		cout << "(다음과 같은 속담들을 입력하셨습니다.)\n";
		for (i = 0; i < total; i++)
			cout << sayings[i][0] << ": " << sayings[i] << endl;

		int shortest = 0;
		int first = 0;
		for (i = 0; i < total; i++)
		{
			if (sayings[i].length() < sayings[shortest].length())
				shortest = i;
			if (sayings[i] < sayings[first])
				first = i;
		}

		cout << "가장 짧은 속담:\n" << sayings[shortest] << endl;
		cout << "사전순으로 가장 앞에 나오는 속담:\n" << sayings[first] << endl;
		cout << "이 프로그램은 " << MyString::HowMany() << "개의 MyString 객체를 사용하였습니다. 이상!\n";
	}
	else
		cout << "입력 금지! 이상.\n";

	return 0;
}

void callme1(MyString & rsb)
{
	cout << "참조로 전달된 StringBad:\n";
	cout << "    \"" << rsb << "\"\n";
}

void callme2(MyString sb)
{
	cout << "값으로 전달된 StringBad:\n";
	cout << "    \"" << sb << "\"\n";
}