#include "stdafx.h"

#define MOVABLE 1
#define PUZZLE 1

Item *invFirst = NULL;
Item *invLast = NULL;
Item *r1First = NULL;
Item *r1Last = NULL;

//priority
enum {VERY_LOW, LOW, MID, HIGH, VERY_HIGH};

// static	 
Item r1Door;
Item r1Desk;
Item r1Laptop;
Item r1Drawer;
Item r1Closet;
Item r1Shelf;
Item r1Poster;
Item r1Blanket;
			 
// movable	 
Item iHammer;
Item iCutter;
Item iDrawerKey;
Item iHanger;
Item r1Chair;

// clue
Item r1Memo01;
Item r1Memo02;
Item r1Memo03;
Item r1Memo04;
Item r1Memo05;

void InitItem(void)
{
	// static
	r1Door = { L"�湮", L"���� �����ִ�.\n", VERY_HIGH, 100, !MOVABLE, !PUZZLE, NULL, NULL };
	r1Desk = { L"å��", L"�̰��� ���� ������ �����ڸ�.\n�����ϰ� ����� ��ġ ��...\n", HIGH, 5, !MOVABLE, !PUZZLE, &iHammer, NULL };
	r1Laptop = { L"��Ʈ��", L"������ ��Ʈ���� �����ִ�.\n��й�ȣ�� �ɷ��ִ�.\n", MID, 3, !MOVABLE, PUZZLE, NULL, NULL };
	r1Drawer = { L"����", L"����ִ�.\n", MID, 3, !MOVABLE, !PUZZLE, NULL, NULL };
	r1Closet = { L"����", L"�ʵ��� �ɷ��ִ�.\n", HIGH, 5, !MOVABLE, !PUZZLE, &iHanger, NULL };
	r1Shelf = { L"����", L"���Ƽ� ���� ���� �ʴ´�.\n", MID, 5, !MOVABLE, !PUZZLE, NULL, NULL };
	r1Poster = { L"������", L"No.289 ����ŷ\nHP:150  ����:160  ���:100  Ư������:95  Ư�����:65  ���ǵ�:100\n�Ϸ� ���� ��� ä�� ��� ���ϸ�.\n���� ��� �������� �ڶ�� Ǯ�� ������ Ǯ�� �������� ������ �����δ�.\n���� ������ �������������� ���� �������� �Ѳ����� ������ ������ �Ŀ��� �����Ѵ�.\n", VERY_LOW, 1, !MOVABLE, !PUZZLE, NULL, NULL };
	r1Blanket = { L"�̺�", L"���� �� �̺�. �����ϴ�.\n", VERY_LOW, 1, !MOVABLE, !PUZZLE, NULL, NULL };
	r1Chair = { L"����", L"ǫ���ϴ�. �ɾ��ִٰ� ��� �� ����.\n", LOW, 1, !MOVABLE, !PUZZLE, NULL, NULL };

	// movable
	iHammer = { L"��ġ"	, L"�����ϴ�. �Ӹ��� ��¦ ��ſ����δ�.\n", HIGH, 2, MOVABLE, !PUZZLE, NULL, NULL };
	iCutter = { L"Ŀ��Į", L"���� �ڸ� �� ���� �п�ǰ.\n", LOW, 3, MOVABLE, !PUZZLE, NULL, NULL };
	iDrawerKey = { L"����", L"��� �� ���� ����. � �� �� �� ������?\n", VERY_HIGH, 1, MOVABLE, !PUZZLE, NULL, NULL };
	iHanger = { L"�ʰ���", L"���� �Ŵ� ����. ���� �κ��� Ȱ���� �� ���� ������?\n", LOW, 1, MOVABLE, !PUZZLE, NULL, NULL };

	// clue
	r1Memo01 = { L"�޸�1", L"���� �� �� ���� �� ���� ������ ���� �ʾ�?\n", LOW, 1, MOVABLE, !PUZZLE, NULL, NULL };
	r1Memo02 = { L"�޸�2", L"��� ������������. �׷��� ���� ���� ����.\n", LOW, 1, MOVABLE, !PUZZLE, NULL, NULL };
	r1Memo03 = { L"�޸�3", L"�����ϰ� ���� ���� ���� ũ�� ���ϴ� �����̾�.\n", LOW, 1, MOVABLE, !PUZZLE, NULL, NULL };
	r1Memo04 = { L"�޸�4", L"�������� ������ ������ �ʾ�. ��� �Ǵϱ� ������ ��.\n", LOW, 1, MOVABLE, !PUZZLE, NULL, NULL };
	r1Memo05 = { L"�޸�5", L"������ �־�. �� �� �־�.\n", LOW, 1, MOVABLE, !PUZZLE, NULL, NULL };

	invFirst = NULL;
	invLast = NULL;
	r1First = NULL;
	r1Last = NULL;
}
void InitList(void)
{
	InputLast(&r1Door, &r1First, &r1Last);	// 1���� �ݵ�� ��.
	InputLast(&r1Desk, &r1First, &r1Last);
	InputLast(&r1Drawer, &r1First, &r1Last);
	InputLast(&r1Chair, &r1First, &r1Last);
	InputLast(&r1Laptop, &r1First, &r1Last);
	InputLast(&r1Poster, &r1First, &r1Last);
	InputLast(&r1Shelf, &r1First, &r1Last);
	InputLast(&r1Closet, &r1First, &r1Last);
	InputLast(&r1Blanket, &r1First, &r1Last);
}

int checkClue(void)
{
	int count = 0;
	Item* tmp = invFirst;
	while (tmp != NULL)
	{
		if (wcsstr(tmp->name, L"�޸�") != NULL)
			count++;

		tmp = tmp->pNext;
	}
	return count;
}

int openDoor(void)
{
	int clue = checkClue();
	int open = 0;
	if (clue == 0)
	{
		setTxt(L"���� ���� �ʾ�.\n");
	}
	else if (clue == 1)
	{
		setTxt(L"������ �;�. ������ ������ ���� �ʾ�.\n");
	}
	else if (clue == 2)
	{
		setTxt(L"������. �׷��� �̴�� �ȵǴµ�..\n");
	}
	else if (clue == 3)
	{
		setTxt(L"���� �� �� ������?\n");
	}
	else if (clue == 4)
	{
		setTxt(L"������?\n");
	}
	else if (clue == 5)
	{
		setTxt(L"��ġ�� ���� ���ο� ��������.\nClear\n");
		open = 1;
	}
	return open;
}

void itemDetail(Item* target)
{
	setTxt(target->title);
	if (target->subItem != NULL && target->subItem->movable == TRUE)
	{
		printItemState(target->subItem, L"��(��) �߰��ߴ�!\n����ǰ�� �־���.");
		InputLast(target->subItem, &invFirst, &invLast);
		target->subItem = NULL;
	}
	else if (target->subItem != NULL && target->subItem->movable == FALSE)
	{
		printItemState(target->subItem, L"��(��) �߰��ߴ�!\n");
		InputLast(target->subItem, &r1First, &r1Last);
		target->subItem = NULL;
	}
	else
	{

	}
}

BOOLEAN itemPuzzle(Item* target, int input)
{
	BOOLEAN open = FALSE;
	if (target == &r1Laptop)
	{
		if (input == 289)
		{
			setTxt(L"��й�ȣ�� �����ƴ�.\n");
			wcscpy_s(target->title, L"���� ��ġ�� ����.\n");
			target->puzzle = FALSE;
			open = TRUE;
		}
	}

	return open;
}

int itemUse(Item *_static, Item *_movable)
{
	int check = 0;
	int checkDest = 0;
	if (_static == &r1Door)
	{
		if (_movable == &iHammer)
		{
			if (checkClue() >= 3)
			{
				setTxt(L"�غ��� �̷��ɷ� �ν����� �ʾ�.\n");
			}
			else
			{
				setTxt(L"���� �μ������� ����..\n...���� ����\n");
			}
		}
		else if (_movable == &iCutter)
		{
			if (checkClue() >= 3)
			{
				setTxt(L"�غ��� �̷��ɷ� �ν����� �ʾ�.\n");
			}
			else
			{
				setTxt(L"���� �μ������� ����..\n...���� ����\n");
			}
		}
		else if (_movable == &iDrawerKey)
		{
			setTxt(L"������� �ʴ�.\n");
		}
		else
		{
			setTxt(L"�׷��� �� �� ����.\n");
		}

	}
	else if (_static == &r1Desk)
	{
		if (_movable == &iHammer)
		{
			setTxt(L"��ġ�� å���� ���ȴ�.\n");
			itemDestroy(_static, _movable);
			check = 1;
		}
		else if (_movable == &iCutter)
		{
			setTxt(L"Ŀ��Į�� å���� ���� �񷶴�.\n");
			itemDestroy(_static, _movable);
			check = 1;
		}
		else
		{
			setTxt(L"�׷��� �� �� ����.\n");
		}
	}
	else if (_static == &r1Laptop)
	{
		
		if (_movable == &iHammer)
		{
			setTxt(L"��ġ�� ��Ʈ���� ���ȴ�.\n");
			checkDest = itemDestroy(_static, _movable);
			check = 1;
		}
		else if (_movable == &iCutter)
		{
			setTxt(L"Ŀ��Į�� ��Ʈ���� ���� �񷶴�.\n");
			checkDest = itemDestroy(_static, _movable);
			check = 1;
		}
		else
		{
			setTxt(L"�׷��� �� �� ����.\n");
		}

		if (checkDest == 1 || checkDest == 3)
		{
			addTxt(L"��Ʈ�� �Ʒ����� �޸� �߰��ߴ�.\n����ǰ�� �־���.\n");
			InputLast(&r1Memo04, &invFirst, &invLast);
		}
	}
	else if (_static == &r1Drawer)
	{
		static int loopCheck = nLoop;
		static int count = 0;
		if (loopCheck != nLoop)
		{
			loopCheck = nLoop;
			count = 0;
		}

		if (_movable == &iHammer)
		{
			setTxt(L"��ġ�� ������ ���ȴ�.\n");
			checkDest = itemDestroy(_static, _movable);
			check = 1;
			if (count == 0 && (checkDest == 1 || checkDest == 3))
			{
				addTxt(L"�ȿ� �ִ� Ŀ��Į�� �޸� ����ǰ�� �־���.\n");
				InputLast(&iCutter, &invFirst, &invLast);
				InputLast(&r1Memo01, &invFirst, &invLast);
				count++;
			}
		}
		else if (_movable == &iDrawerKey)
		{
			if (count == 0)
			{
				setTxt(L"������ ������.\n�ȿ� �ִ� Ŀ��Į�� �޸� ����ǰ�� �־���.\n");
				wcscpy_s(_static->title, L"������ �� ����ִ�.\n");
				InputLast(&iCutter, &invFirst, &invLast);
				InputLast(&r1Memo01, &invFirst, &invLast);
				count++;
			}
			check = 1;
		}
		else
		{
			setTxt(L"�׷��� �� �� ����.\n");
		}

	}
	else if (_static == &r1Closet)
	{
		if (_movable == &iHanger)
		{
			setTxt(L"�ʰ��̸� �ٽ� ���� �־���.\n");
			_static->subItem = delNode(_movable, &invFirst, &invLast);
			check = 1;
		}
		else if (_movable == &iHammer)
		{
			setTxt(L"��ġ�� ������ ���ȴ�.\n");
			checkDest = itemDestroy(_static, _movable);
			check = 1;
		}
		else
		{
			setTxt(L"�׷��� �� �� ����.\n");
		}
	}
	else if (_static == &r1Shelf)
	{
		static int loopCheck = nLoop;
		static int count = 0;
		if (loopCheck != nLoop)
		{
			loopCheck = nLoop;
			count = 0;
		}

		if (_movable == &iHammer)
		{
			setTxt(L"��ġ�� ������ ���ȴ�.\n");
			checkDest = itemDestroy(_static, _movable);
			check = 1;
			if (count == 0 && (checkDest == 1 || checkDest == 3))
			{
				addTxt(L"���� ���� �ִ� ���踦 ����ǰ�� �־���.\n");
				InputLast(&iDrawerKey, &invFirst, &invLast);
				count++;
			}
		}
		else if (_movable == &iHanger)
		{
			if (count == 0)
			{
				setTxt(L"������ �Ⱦ���.\n���谡 ��������. ����ǰ�� �־���.\n");
				InputLast(&iDrawerKey, &invFirst, &invLast);
				count++;
				check = 1;
			}
			else
			{
				setTxt(L"������ �Ⱦ���.\n�ƹ� �͵� ����.\n");
				check = 1;
			}
		}
		else
		{
			setTxt(L"�׷��� �� �� ����.\n");
		}
	}
	else if (_static == &r1Poster)
	{
		static int loopCheck = nLoop;
		static int count = 0;
		if (loopCheck != nLoop)
		{
			loopCheck = nLoop;
			count = 0;
		}

		if (_movable == &iCutter)
		{
			if (count == 0)
			{
				setTxt(L"�����͸� ������.\n������ �ڿ��� �޸� �߰��ߴ�. ����ǰ�� �־���.\n");
				InputLast(&r1Memo05, &invFirst, &invLast);
				wcscpy_s(_static->name, L"������ ������");
				wcscpy_s(_static->title, L"\n������  ��������  ��������  ��������:95  Ư�����:65  ���ǵ�:100\n\n���� ���� �������� ������ ���� ������ ���� �������� ������ �����δ�.\n���� ������ �������������� ���� �������� �������� ������ ������ �Ŀ��� �����Ѵ�.\n");
				count++;
				check = 1;
			}
			else
			{
				setTxt(L"�̹� ������ ���´�.\n");
			}
		}
		else
		{
			setTxt(L"�׷��� �� �� ����.\n");
		}
	}
	else if (_static == &r1Blanket)
	{
		static int loopCheck = nLoop;
		static int count = 0;
		if (loopCheck != nLoop)
		{
			loopCheck = nLoop;
			count = 0;
		}

		if (_movable == &iCutter)
		{
			if (count == 0)
			{
				setTxt(L"�̺��� ������.\n�̺� �ӿ��� �޸� �߰��ߴ�. ����ǰ�� �־���.\n");
				InputLast(&r1Memo02, &invFirst, &invLast);
				wcscpy_s(_static->name, L"������ �̺�");
				wcscpy_s(_static->title, L"�� �̻� �� �������� ���� �� ����.\n");
				count++;
				check = 1;
			}
			else
			{
				setTxt(L"�̹� ������ ���´�.\n");
			}
		}
		else
		{
			setTxt(L"�׷��� �� �� ����.\n");
		}
	}
	else if (_static == &r1Chair)
	{
		if (_movable == &iHammer)
		{
			setTxt(L"��ġ�� ���ڸ� �����ƴ�.\n");
			checkDest = itemDestroy(_static, _movable);
			check = 1;
		}
		else if (_movable == &iCutter)
		{
			setTxt(L"Ŀ��Į�� ���� ������ ������.\n");
			checkDest = itemDestroy(_static, _movable);
			check = 1;
		}
		else
		{
			setTxt(L"�׷��� �� �� ����.\n");
		}

		if (checkDest == 1 || checkDest == 3)
		{
			addTxt(L"�μ��� ���ڿ��� �޸� �߰��ߴ�.\n����ǰ�� �־���.\n");
			InputLast(&r1Memo03, &invFirst, &invLast);
		}
	}
	return check;
}

// 0: �ı�X, 1: static �ı�, 2: movable �ı�, 3: �� �� �ı�
int itemDestroy(Item *_static, Item *_movable)
{
	int destroy = duraReduce(_static, _movable);

	if (destroy == 1 || destroy == 3)
	{
		delNode(_static, &r1First, &r1Last);
		printItemState(_static, L"��(��) �ν�����.	");
	}
	if (destroy == 2 || destroy == 3)
	{
		delNode(_movable, &invFirst, &invLast);
		printItemState(_movable, L"��(��) �ν�����.	");
	}

	return destroy;
}
int duraReduce(Item *_static, Item *_movable)
{


	if (_static->priority > _movable->priority)
	{
		if(_static->priority - _movable->priority < 2)
		{
			_static->durability--;

			if (_static->durability != 0)
			{
				printItemState(_static, L"��(��) ���� ������ �� ����.");
			}
		}
		else
		{
			printItemState(_static, L"�� �ƹ��� ��ȭ�� ������ �ʴ´�.");
		}
		_movable->durability = 0;
	}
	else if (_static->priority < _movable->priority)
	{
		if (_movable->priority - _static->priority < 2)
		{
			_movable->durability--;
		}
		_static->durability = 0;
	}
	else
	{
		_static->durability--;
		_movable->durability--;

		if (_static->durability != 0)
		{
			printItemState(_static, L"��(��) ���� ������ �� ����.");
		}
	}


	if (_static->durability == 0 && _movable->durability == 0)
	{
		return 3;
	}

	else if (_static->durability == 0)
	{
		return 1;
	}
	else if (_movable->durability == 0)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

void printItemState(Item *target, wchar_t *state)
{
	wchar_t szBuffer[_WIDTH / 2] = { 0 };

	wsprintf(szBuffer, L"%s%s\n", target->name, state);
	addTxt(szBuffer);
}