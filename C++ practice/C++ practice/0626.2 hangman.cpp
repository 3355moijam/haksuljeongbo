#include "stdafx.h"
#include "class\Hangman.h"


void getInput(string & input);

int main()
{
	string sInput; 
	Hangman hang;
	while (1)
	{
		hang.ask();
		getInput(sInput);
		if (hang.checkAnswer(sInput))
		{
			cout << hang.getCount() << "�� ���� Ŭ����!" << endl;
			break;
		}
		
		if (hang.checkEnd())
		{
			hang.draw();
			cout << hang.getChance() << "�� �̳��� �������� ���ߴ�... END" << endl;
			cout << "���� " << hang.getAnswer() << "�Դϴ�." << endl;
			break;
		}
	}

	system("pause");

}

void getInput(string & input)
{
	cin >> input;
	cin.ignore();
	for (size_t i = 0; i < input.size(); i++)
	{
		input[i] = tolower(input[i]);
	}
}