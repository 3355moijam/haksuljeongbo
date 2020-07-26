#pragma once
#include "../stdafx.h"
class Hangman
{
private:
	static const vector<string> sQuestionTable;
	string sQuest;
	string sAnswer; 
	int count;
	const int chance = 10;
	void setQuest(void);
	void setAnswer(void);
public:
	Hangman();
	~Hangman();

	bool checkAnswer(string input);
	int getCount(void) { return count; }
	int getChance(void) { return chance; }
	string getAnswer(void) { return sQuest; }
	bool checkEnd(void) { return count >= chance; }
	void ask(void);
	void draw(void);

};

