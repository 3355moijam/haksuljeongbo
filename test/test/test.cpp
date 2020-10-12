// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <locale.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//
//class Creature
//{
//public:
//	string name;
//	int attack, defense;
//	Creature(string name, int atk, int def) : name(name), attack(atk), defense(def) {};
//	friend ostream& operator<<(ostream& os, Creature& creat)
//	{
//
//	}
//
//};
//
//class CreatureModifier
//{
//	CreatureModifier* next{ nullptr };
//protected:
//	Creature& creature;
//public:
//	explicit CreatureModifier(Creature& creat)
//		:creature(creat) {}
//
//	void add(CreatureModifier* cm)
//	{
//		if (next) next->add(cm);
//		else next = cm;
//	}
//
//	virtual void handle()
//	{
//		if (next) next->handle();
//	}
//};
//
//class DoubleAttackModifier : public CreatureModifier
//{
//public:
//	explicit DoubleAttackModifier(Creature& creat)
//		: CreatureModifier(creat) {}
//	void handle()
//	{
//		creature.attack *= 2;
//		CreatureModifier::handle();
//	}
//};
//
//class IncreaseDefenseModifier : public CreatureModifier
//{
//public:
//	explicit IncreaseDefenseModifier(Creature& creat)
//		: CreatureModifier(creature) {}
//
//	void handle()
//	{
//		if (creature.attack <= 2)
//			creature.defense += 1;
//		CreatureModifier::handle();
//	}
//};

int main()
{
	
	return 0;
}


//
//int str_len2(char src[], char tar[])
//{
//	int k = str_len1(src, tar);
//	if (k == -1)
//		return -1;
//
//	for (int i = 0; i < strlen(tar); i++)
//	{
//		src[k + i] = '*';
//	}
//	return 0;
//}

//bool isBetweenPt(POINT target, POINT p1, POINT p2)
//{
//	int distance1 = PtDistance(target, p1);
//	int distance2 = PtDistance(target, p2);
//	int distance3 = PtDistance(p1, p2);
//
//	if (distance1 + distance2 == distance3)
//		return true;
//	else
//		return false;
//}
//
//int PtDistance(POINT p1, POINT p2)
//{
//	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
//}