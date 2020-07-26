#include "stdafx.h"
#include "class/StringBad.h"

void callme1(MyString &);
void callme2(MyString);

const int ArSize = 10;
const int MaxLen = 81;

int main()
{
	//cout << "���� ����� �����Ѵ�." << endl;
	//{
	//	MyString headline1("Celery Stalks at Midnight");
	//	MyString headline2("Lettuce Prey");
	//	MyString sports("Spinach Leaves Bowl for Dollars");
	//	cout << "headline1: " << headline1 << endl;
	//	cout << "headline2: " << headline2 << endl;
	//	cout << "sports: " << sports << endl;
	//	callme1(headline1);
	//	cout << "headline1: " << headline1 << endl;
	//	//callme2(headline2); // ������ �ƴϸ� �����ڵ� ���µ� �Ҹ��ڰ� ȣ��ȴ�
	//	//cout << "headline2: " << headline2 << endl;
	//	//cout << "�ϳ��� ��ü�� �ٸ� ��ü�� �ʱ�ȭ: " << endl;
	//	//StringBad sailor = sports; // ������ �� ���� ����. �����Ϸ��� �ڵ� ����.
	//	//cout << "sailor: " << sailor << endl; // sailor�� ������鼭 sports�� �Ҵ�� �޸𸮸� ���������鼭 ����
	//	cout << "�ϳ��� ��ü�� �ٸ� ��ü�� ����: " << endl;
	//	MyString knot;
	//	knot = headline1;
	//	cout << "knot: " << knot << endl;
	//	cout << "�� ����� �������´�." << endl;
	//}
	//cout << "main()�� ��" << endl;

	MyString name;
	cout << "�ȳ��Ͻʴϱ�? ������ ��� �ǽʴϱ�?\n >> ";
	cin >> name;
	
	cout << name << " ��! ������ ���� �Ӵ� " << ArSize
		<< "���� �Է� ���ֽʽÿ�(�������� Enter):\n";
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
		cout << "(������ ���� �Ӵ���� �Է��ϼ̽��ϴ�.)\n";
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

		cout << "���� ª�� �Ӵ�:\n" << sayings[shortest] << endl;
		cout << "���������� ���� �տ� ������ �Ӵ�:\n" << sayings[first] << endl;
		cout << "�� ���α׷��� " << MyString::HowMany() << "���� MyString ��ü�� ����Ͽ����ϴ�. �̻�!\n";
	}
	else
		cout << "�Է� ����! �̻�.\n";

	return 0;
}

void callme1(MyString & rsb)
{
	cout << "������ ���޵� StringBad:\n";
	cout << "    \"" << rsb << "\"\n";
}

void callme2(MyString sb)
{
	cout << "������ ���޵� StringBad:\n";
	cout << "    \"" << sb << "\"\n";
}