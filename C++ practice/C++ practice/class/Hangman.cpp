#include "Hangman.h"
#include "../stdafx.h"

const vector<string> Hangman::sQuestionTable = { "hello", "lovelive", "string", "question", "random", "hangman", "extension", "halation", "amazing", "guilty", "azalea", "sharon", "niconiconi" };
Hangman::Hangman()
{
	setQuest();
	setAnswer();
	count = 0;
}


Hangman::~Hangman()
{
}

void Hangman::setQuest(void)
{
	int i = randomInt(0, sQuestionTable.size() - 1);
	sQuest = sQuestionTable[i];
}

void Hangman::setAnswer(void)
{
	sAnswer = sQuest;
	for (size_t i = 0; i < sAnswer.size(); i++)
		sAnswer[i] = '*';
}
bool Hangman::checkAnswer(string input)
{
	count++;
	if (input.size() == 1)
	{
		for (size_t i = 0; i < sQuest.size(); i++)
		{
			if (sQuest[i] == input[0])
				sAnswer[i] = input[0];
		}

		if (sQuest == sAnswer)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (sQuest == input)
		{
			sAnswer = input;
			return true;
		}
		else
		{
			return false;
		}
	}
}

void Hangman::draw()
{
	switch (count)
	{
	case 1:
		cout << "   " << endl;
		cout << "   " << endl;
		cout << "   " << endl;
		cout << "  " << endl;
		cout << "￣" << endl;
		break;
	case 2:
		cout << "   " << endl;
		cout << "   " << endl;
		cout << "   " << endl;
		cout << "  " << endl;
		cout << "￣￣" << endl;
		break;
	case 3:
		cout << "   " << endl;
		cout << "   " << endl;
		cout << "   " << endl;
		cout << " | " << endl;
		cout << "￣￣" << endl;
		break;
	case 4:
		cout << "   " << endl;
		cout << "   " << endl;
		cout << " |  " << endl;
		cout << " | " << endl;
		cout << "￣￣" << endl;
		break;
	case 5:
		cout << " " << endl;
		cout << " |  " << endl;
		cout << " |  " << endl;
		cout << " | " << endl;
		cout << "￣￣" << endl;
		break;
	case 6:
		cout << "  _ " << endl;
		cout << " |  " << endl;
		cout << " |  " << endl;
		cout << " | " << endl;
		cout << "￣￣" << endl;
		break;
	case 7:
		cout << "  __ " << endl;
		cout << " |  " << endl;
		cout << " |  " << endl;
		cout << " | " << endl;
		cout << "￣￣" << endl;
		break;
	case 8:
		cout << "  __ " << endl;
		cout << " | ㅇ" << endl;
		cout << " |  " << endl;
		cout << " | " << endl;
		cout << "￣￣" << endl;
		break;
	case 9:
		cout << "  __ " << endl;
		cout << " | ㅇ" << endl;
		cout << " | ㅈ" << endl;
		cout << " | " << endl;
		cout << "￣￣" << endl;
		break;
	case 10:
		cout << "  __ " << endl;
		cout << " | ㅇ" << endl;
		cout << " |  " << endl;
		cout << " | ㅈ" << endl;
		cout << "￣￣ " << endl;
		break;
	default:
		break;
	}
	
}
void Hangman::ask()
{
	draw();
	cout << sAnswer << "는 무엇일까요?(알파벳 또는 영단어를 입력)" << endl;
}