#pragma once

#define _WIDTH 128

typedef struct _Item
{
	wchar_t name[16];
	wchar_t title[_WIDTH * 5];
	int priority;
	int durability;
	BOOLEAN movable;
	BOOLEAN puzzle;
	_Item *subItem;
	_Item *pNext;
}Item;

extern Item *invFirst;
extern Item *invLast;
extern Item *r1First;
extern Item *r1Last;




void InputLast(Item *input, Item **first, Item **last);
int getLen(Item *first);
Item* getNode(int index, Item *first);
int getIndex(Item *target, Item *first);
Item* delNode(int index, Item **first, Item **last);
Item* delNode(Item *target, Item **first, Item **last);
void listSet(Item *first);


void InitItem(void);
void InitList(void);

int openDoor(void);
int checkClue(void);
void itemDetail(Item *target);
BOOLEAN itemPuzzle(Item* target, int input);
int itemUse(Item *_static, Item *_movable);
int itemDestroy(Item *_static, Item *_movable);
int duraReduce(Item *_static, Item *_movable);
void printItemState(Item *target, wchar_t *state);
