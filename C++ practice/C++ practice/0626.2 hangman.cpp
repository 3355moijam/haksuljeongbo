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
			cout << hang.getCount() << "번 만에 클리어!" << endl;
			break;
		}
		
		if (hang.checkEnd())
		{
			hang.draw();
			cout << hang.getChance() << "번 이내에 구출하지 못했다... END" << endl;
			cout << "답은 " << hang.getAnswer() << "입니다." << endl;
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