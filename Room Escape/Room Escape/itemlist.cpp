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
	r1Door = { L"방문", L"굳게 닫혀있다.\n", VERY_HIGH, 100, !MOVABLE, !PUZZLE, NULL, NULL };
	r1Desk = { L"책상", L"이곳은 나의 포근한 보금자리.\n안전하고 편안한 고치 속...\n", HIGH, 5, !MOVABLE, !PUZZLE, &iHammer, NULL };
	r1Laptop = { L"노트북", L"언제나 노트북이 켜져있다.\n비밀번호가 걸려있다.\n", MID, 3, !MOVABLE, PUZZLE, NULL, NULL };
	r1Drawer = { L"서랍", L"잠겨있다.\n", MID, 3, !MOVABLE, !PUZZLE, NULL, NULL };
	r1Closet = { L"옷장", L"옷들이 걸려있다.\n", HIGH, 5, !MOVABLE, !PUZZLE, &iHanger, NULL };
	r1Shelf = { L"선반", L"높아서 손이 닿지 않는다.\n", MID, 5, !MOVABLE, !PUZZLE, NULL, NULL };
	r1Poster = { L"포스터", L"No.289 게을킹\nHP:150  공격:160  방어:100  특수공격:95  특수방어:65  스피드:100\n하루 내내 잠든 채로 사는 포켓몬.\n손이 닿는 범위에서 자라는 풀을 먹으며 풀이 없어지면 그제야 움직인다.\n세계 제일의 게으름뱅이지만 모인 에너지를 한꺼번에 내보내 무서운 파워를 발휘한다.\n", VERY_LOW, 1, !MOVABLE, !PUZZLE, NULL, NULL };
	r1Blanket = { L"이불", L"덮고 잔 이불. 포근하다.\n", VERY_LOW, 1, !MOVABLE, !PUZZLE, NULL, NULL };
	r1Chair = { L"의자", L"푹신하다. 앉아있다간 잠들 것 같다.\n", LOW, 1, !MOVABLE, !PUZZLE, NULL, NULL };

	// movable
	iHammer = { L"망치"	, L"묵직하다. 머리가 살짝 헐거워보인다.\n", HIGH, 2, MOVABLE, !PUZZLE, NULL, NULL };
	iCutter = { L"커터칼", L"무언가 자를 때 쓰는 학용품.\n", LOW, 3, MOVABLE, !PUZZLE, NULL, NULL };
	iDrawerKey = { L"열쇠", L"잠긴 걸 여는 도구. 어떤 걸 열 수 있을까?\n", VERY_HIGH, 1, MOVABLE, !PUZZLE, NULL, NULL };
	iHanger = { L"옷걸이", L"옷을 거는 도구. 갈고리 부분을 활용할 수 있지 않을까?\n", LOW, 1, MOVABLE, !PUZZLE, NULL, NULL };

	// clue
	r1Memo01 = { L"메모1", L"뭔가 할 수 있을 것 같은 느낌이 들지 않아?\n", LOW, 1, MOVABLE, !PUZZLE, NULL, NULL };
	r1Memo02 = { L"메모2", L"계속 망설여지겠지. 그래도 앞을 향해 나가.\n", LOW, 1, MOVABLE, !PUZZLE, NULL, NULL };
	r1Memo03 = { L"메모3", L"포기하고 싶을 때가 가장 크게 변하는 시점이야.\n", LOW, 1, MOVABLE, !PUZZLE, NULL, NULL };
	r1Memo04 = { L"메모4", L"움직이지 않으면 변하지 않아. 쉬어도 되니까 멈추지 마.\n", LOW, 1, MOVABLE, !PUZZLE, NULL, NULL };
	r1Memo05 = { L"메모5", L"기적은 있어. 할 수 있어.\n", LOW, 1, MOVABLE, !PUZZLE, NULL, NULL };

	invFirst = NULL;
	invLast = NULL;
	r1First = NULL;
	r1Last = NULL;
}
void InitList(void)
{
	InputLast(&r1Door, &r1First, &r1Last);	// 1번은 반드시 문.
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
		if (wcsstr(tmp->name, L"메모") != NULL)
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
		setTxt(L"열고 싶지 않아.\n");
	}
	else if (clue == 1)
	{
		setTxt(L"나가고 싶어. 하지만 나가고 싶지 않아.\n");
	}
	else if (clue == 2)
	{
		setTxt(L"무서워. 그래도 이대론 안되는데..\n");
	}
	else if (clue == 3)
	{
		setTxt(L"내가 할 수 있을까?\n");
	}
	else if (clue == 4)
	{
		setTxt(L"나갈까?\n");
	}
	else if (clue == 5)
	{
		setTxt(L"고치를 열고 새로운 세상으로.\nClear\n");
		open = 1;
	}
	return open;
}

void itemDetail(Item* target)
{
	setTxt(target->title);
	if (target->subItem != NULL && target->subItem->movable == TRUE)
	{
		printItemState(target->subItem, L"을(를) 발견했다!\n소지품에 넣었다.");
		InputLast(target->subItem, &invFirst, &invLast);
		target->subItem = NULL;
	}
	else if (target->subItem != NULL && target->subItem->movable == FALSE)
	{
		printItemState(target->subItem, L"을(를) 발견했다!\n");
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
			setTxt(L"비밀번호가 해제됐다.\n");
			wcscpy_s(target->title, L"너의 고치를 찢어.\n");
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
				setTxt(L"해봤자 이런걸론 부숴지지 않아.\n");
			}
			else
			{
				setTxt(L"문이 부서질지도 몰라..\n...하지 말자\n");
			}
		}
		else if (_movable == &iCutter)
		{
			if (checkClue() >= 3)
			{
				setTxt(L"해봤자 이런걸론 부숴지지 않아.\n");
			}
			else
			{
				setTxt(L"문이 부서질지도 몰라..\n...하지 말자\n");
			}
		}
		else if (_movable == &iDrawerKey)
		{
			setTxt(L"잠겨있지 않다.\n");
		}
		else
		{
			setTxt(L"그렇게 할 순 없다.\n");
		}

	}
	else if (_static == &r1Desk)
	{
		if (_movable == &iHammer)
		{
			setTxt(L"망치로 책상을 때렸다.\n");
			itemDestroy(_static, _movable);
			check = 1;
		}
		else if (_movable == &iCutter)
		{
			setTxt(L"커터칼로 책상을 힘껏 찔렀다.\n");
			itemDestroy(_static, _movable);
			check = 1;
		}
		else
		{
			setTxt(L"그렇게 할 순 없다.\n");
		}
	}
	else if (_static == &r1Laptop)
	{
		
		if (_movable == &iHammer)
		{
			setTxt(L"망치로 노트북을 때렸다.\n");
			checkDest = itemDestroy(_static, _movable);
			check = 1;
		}
		else if (_movable == &iCutter)
		{
			setTxt(L"커터칼로 노트북을 힘껏 찔렀다.\n");
			checkDest = itemDestroy(_static, _movable);
			check = 1;
		}
		else
		{
			setTxt(L"그렇게 할 순 없다.\n");
		}

		if (checkDest == 1 || checkDest == 3)
		{
			addTxt(L"노트북 아래에서 메모를 발견했다.\n소지품에 넣었다.\n");
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
			setTxt(L"망치로 서랍을 때렸다.\n");
			checkDest = itemDestroy(_static, _movable);
			check = 1;
			if (count == 0 && (checkDest == 1 || checkDest == 3))
			{
				addTxt(L"안에 있던 커터칼과 메모를 소지품에 넣었다.\n");
				InputLast(&iCutter, &invFirst, &invLast);
				InputLast(&r1Memo01, &invFirst, &invLast);
				count++;
			}
		}
		else if (_movable == &iDrawerKey)
		{
			if (count == 0)
			{
				setTxt(L"서랍을 열었다.\n안에 있던 커터칼과 메모를 소지품에 넣었다.\n");
				wcscpy_s(_static->title, L"서랍은 텅 비어있다.\n");
				InputLast(&iCutter, &invFirst, &invLast);
				InputLast(&r1Memo01, &invFirst, &invLast);
				count++;
			}
			check = 1;
		}
		else
		{
			setTxt(L"그렇게 할 순 없다.\n");
		}

	}
	else if (_static == &r1Closet)
	{
		if (_movable == &iHanger)
		{
			setTxt(L"옷걸이를 다시 집어 넣었다.\n");
			_static->subItem = delNode(_movable, &invFirst, &invLast);
			check = 1;
		}
		else if (_movable == &iHammer)
		{
			setTxt(L"망치로 서랍을 때렸다.\n");
			checkDest = itemDestroy(_static, _movable);
			check = 1;
		}
		else
		{
			setTxt(L"그렇게 할 순 없다.\n");
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
			setTxt(L"망치로 선반을 때렸다.\n");
			checkDest = itemDestroy(_static, _movable);
			check = 1;
			if (count == 0 && (checkDest == 1 || checkDest == 3))
			{
				addTxt(L"선반 위에 있던 열쇠를 소지품에 넣었다.\n");
				InputLast(&iDrawerKey, &invFirst, &invLast);
				count++;
			}
		}
		else if (_movable == &iHanger)
		{
			if (count == 0)
			{
				setTxt(L"선반을 훑었다.\n열쇠가 떨어졌다. 소지품에 넣었다.\n");
				InputLast(&iDrawerKey, &invFirst, &invLast);
				count++;
				check = 1;
			}
			else
			{
				setTxt(L"선반을 훑었다.\n아무 것도 없다.\n");
				check = 1;
			}
		}
		else
		{
			setTxt(L"그렇게 할 순 없다.\n");
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
				setTxt(L"포스터를 찢었다.\n포스터 뒤에서 메모를 발견했다. 소지품에 넣었다.\n");
				InputLast(&r1Memo05, &invFirst, &invLast);
				wcscpy_s(_static->name, L"찢어진 포스터");
				wcscpy_s(_static->title, L"\n　　　  　　　　  　　　　  　수공격:95  특수방어:65  스피드:100\n\n　　 　　 　　　　 　　　 　　 　　　 　　 　　　　 그제야 움직인다.\n　　 　　　 　　　　　　　 　　 　　　　 　　　　 　　　 무서운 파워를 발휘한다.\n");
				count++;
				check = 1;
			}
			else
			{
				setTxt(L"이미 찢어진 상태다.\n");
			}
		}
		else
		{
			setTxt(L"그렇게 할 순 없다.\n");
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
				setTxt(L"이불을 찢었다.\n이불 속에서 메모를 발견했다. 소지품에 넣었다.\n");
				InputLast(&r1Memo02, &invFirst, &invLast);
				wcscpy_s(_static->name, L"찢어진 이불");
				wcscpy_s(_static->title, L"더 이상 날 숨겨주지 못할 것 같다.\n");
				count++;
				check = 1;
			}
			else
			{
				setTxt(L"이미 찢어진 상태다.\n");
			}
		}
		else
		{
			setTxt(L"그렇게 할 순 없다.\n");
		}
	}
	else if (_static == &r1Chair)
	{
		if (_movable == &iHammer)
		{
			setTxt(L"망치로 의자를 내리쳤다.\n");
			checkDest = itemDestroy(_static, _movable);
			check = 1;
		}
		else if (_movable == &iCutter)
		{
			setTxt(L"커터칼로 의자 가죽을 찢었다.\n");
			checkDest = itemDestroy(_static, _movable);
			check = 1;
		}
		else
		{
			setTxt(L"그렇게 할 순 없다.\n");
		}

		if (checkDest == 1 || checkDest == 3)
		{
			addTxt(L"부서진 의자에서 메모를 발견했다.\n소지품에 넣었다.\n");
			InputLast(&r1Memo03, &invFirst, &invLast);
		}
	}
	return check;
}

// 0: 파괴X, 1: static 파괴, 2: movable 파괴, 3: 둘 다 파괴
int itemDestroy(Item *_static, Item *_movable)
{
	int destroy = duraReduce(_static, _movable);

	if (destroy == 1 || destroy == 3)
	{
		delNode(_static, &r1First, &r1Last);
		printItemState(_static, L"이(가) 부숴졌다.	");
	}
	if (destroy == 2 || destroy == 3)
	{
		delNode(_movable, &invFirst, &invLast);
		printItemState(_movable, L"이(가) 부숴졌다.	");
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
				printItemState(_static, L"이(가) 조금 약해진 것 같다.");
			}
		}
		else
		{
			printItemState(_static, L"에 아무런 변화도 보이지 않는다.");
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
			printItemState(_static, L"이(가) 조금 약해진 것 같다.");
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