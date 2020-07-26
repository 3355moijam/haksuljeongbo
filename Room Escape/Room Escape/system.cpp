#include "stdafx.h"

#define INIT_FOCUS iFocus = NULL

//wchar_t **g_arrImg;
wchar_t *g_szTxt;
wchar_t *g_szMenu;

COORD locateImg = { 0,0 };
COORD locateTxt = { 0, _HEIGHT + 1 };
COORD locateMenu = { 0, _HEIGHT + 6 };

//#define _tHEIGHT 5

int g_state = HOME;
Item *iFocus = NULL;

void InitScreen(void)
{
	_wsetlocale(LC_ALL, L"Korean");
	system("mode con cols=128 lines=50");
	iFocus = NULL;

	g_szTxt = (wchar_t*)calloc(_WIDTH * 5, sizeof(wchar_t));
	g_szMenu = (wchar_t*)calloc(_WIDTH, sizeof(wchar_t));

	
	wcscpy_s(g_szTxt, _WIDTH,L"오늘도 눈을 떴다.\n");
	wcscpy_s(g_szMenu, _WIDTH,L"1. 게임 시작하기   2. 게임 종료");
}
void PrintScreen(void)
{
	system("cls");
	PrintImg();
	PrintTxt();
	PrintMenu();
}

void PrintImg(void)
{
	gotoXY(locateImg);
	printTitle();
}
void PrintTxt(void)
{
	gotoXY(locateTxt);
	wprintf(L"%s\n", g_szTxt);
}
void PrintMenu(void)
{
	gotoXY(locateMenu);
	wprintf(L"--------------------------------------------------------------------------------------------------------------------------------\n");
	wprintf(L"%s\n", g_szMenu);
}

int getInput(void)
{
	int num;
	scanf_s("%d", &num);
	rewind(stdin);

	return num;
}

int checkState(int input)
{
	int check = 0;
	if (g_state == HOME)
	{
		switch (input)
		{
		case 1:
			// 게임시작
			setTxt(L"무엇을 할까?\n");
			g_state = MENU;
			break;
		case 2:
			// 게임 종료
			gameExit();
			check = BREAK;
			g_state = EXIT;
			break;
		default:
			break;
		}
	}

	else if (g_state == MENU)
	{
		switch (input)
		{
		case 1:
			// 인벤토리 오픈 
			setTxt(L"소지품 목록\n");
			g_state = INVEN;
			break;
		case 2:
			// 방 조사
			setTxt(L"방에 무엇이 있나?\n");
			g_state = ROOMSCAN;
			break;
		case 3:
			// 홈으로 나가기
			check = BREAK;
			g_state = HOME;
		default:
			break;
		}
	}

	else if (g_state == INVEN)
	{
		if (input == 0)
		{
			//돌아가기
			//state -> menu
			setTxt(L"무엇을 할까?\n");
			g_state = MENU;
		}
		else if (input >= 1 && input <= 9)
		{
			// 아이템 설명 출력
			setTxt(getNode(input, invFirst)->title);
			g_state = INVEN;
		}
	}

	else if (g_state == ROOMSCAN)
	{
		INIT_FOCUS;

		if (input == 0)
		{
			//돌아가기
			//state -> menu
			setTxt(L"무엇을 할까?\n");
			g_state = MENU;
		}
		else if(input >= 1 && input <= 9)
		{
			//오브제(input);
			//state -> obj
			iFocus = getNode(input, r1First);
			setTxt(iFocus->name);
			g_state = OBJ;
		}
		else
		{
			
		}
	}

	else if (g_state == OBJ)
	{
		Item *tmp = NULL; // getNode(iFocus, r1First);
		if (input == 1)
		{
			//조사하기
			itemDetail(iFocus);
			if (iFocus->puzzle == TRUE)
			{
				g_state = PUZZLE;
			}
			else
			{
				g_state = OBJ;
			}
		}
		else if (input == 2)
		{
			if (iFocus->movable)
			{
				// 소지품에 넣기
				tmp = delNode(iFocus, &r1First, &r1Last);
				InputLast(tmp, &invFirst, &invLast);
				setTxt(L"소지품에 넣었다.\n");
				INIT_FOCUS;
				g_state = ROOMSCAN;
			}
			else
			{
				//아이템 사용
				g_state = OBJ_ITEM;
			}
		}
		else if (input == 3 && wcsstr(iFocus->name, L"방문") != NULL)
		{
			if (openDoor())
			{
				g_state = EXIT;
			}
		}
		else if (input == 0)
		{
			setTxt(L"방에 무엇이 있나?\n");
			g_state = ROOMSCAN;
		}
		else
		{
		
		}
	}

	else if (g_state == PUZZLE)
	{
		if (input == 0)
		{
			g_state = OBJ;
		}
		else
		{
			if (itemPuzzle(iFocus, input))
			{
				g_state = OBJ;
			}
		}

	}

	else if (g_state == OBJ_ITEM)
	{
		Item *usedItem = getNode(input, invFirst);
		if (input == 0)
		{
			setTxt(iFocus->name);
			g_state = OBJ;
		}
		else if (input >= 1 && input <= 9)
		{
			check = itemUse(iFocus, usedItem); // 성공여부 체크;

			if (check == SUCCESS)
			{
				g_state = ROOMSCAN;
			}
			else
			{
				g_state = OBJ_ITEM;
			}
		}
	}

	else if (g_state == EXIT)
	{
		switch (input)
		{
		case 1:
			check = BREAK;
			g_state = HOME;
			break;
		case 2:
			check = BREAK;
			gameExit();
			break;
		default:
			break;
		}
	}

	return check;
}

void setMenu()
{
	memset(g_szMenu, 0, sizeof(g_szMenu));
	switch (g_state)
	{
	case HOME:
		setTxt(L"오늘도 눈을 떴다.\n");
		wcscpy_s(g_szMenu, _WIDTH, L"1. 게임 시작하기   2. 게임 종료");
		break;
	case MENU:
		wcscpy_s(g_szMenu, _WIDTH, L"1. 소지품   2. 방 조사   3. 게임 나가기");
		break;
	case INVEN:
		listSet(invFirst);// 아이템 목록 구해서 g_szMenu에 wcscpy_s하는 함수
		break;
	case ROOMSCAN:
		listSet(r1First);// 오브제 목록 구해서 g_szMenu에 wcscpy_s하는 함수
		break;
	case OBJ:
		if(iFocus->movable == TRUE)
			wcscpy_s(g_szMenu, _WIDTH, L"1. 조사하기   2. 소지품에 넣기   0. 돌아가기");
		else if(wcsstr(iFocus->name, L"방문"	) != NULL)
			wcscpy_s(g_szMenu, _WIDTH, L"1. 조사하기   2. 아이템 사용   3. 열기   0. 돌아가기");
		else
			wcscpy_s(g_szMenu, _WIDTH, L"1. 조사하기   2. 아이템 사용   0. 돌아가기");
		break;
	case PUZZLE:
		wcscpy_s(g_szMenu, _WIDTH, L"비밀번호를 입력해주세요.(3자리 숫자)   0. 돌아가기");
		break;
	case OBJ_ITEM:
		listSet(invFirst);// 아이템 목록 구해서 g_szMenu에 wcscpy_s하는 함수
		break;
	case EXIT:
		wcscpy_s(g_szMenu, _WIDTH, L"1. 다시하기   2. 게임 종료");
		break;
	default:
		break;
	}
}

void setTxt(wchar_t *txt)
{
	memset(g_szTxt, 0, sizeof(g_szTxt));
	wcscpy_s(g_szTxt, _WIDTH * 5, txt);
}

void addTxt(wchar_t *txt)
{
	wcscat_s(g_szTxt, _WIDTH, txt);
}
//void DoubleFree(void **arr, int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		if (arr[i] != NULL)
//			free(arr[i]);
//	}
//	free(arr);
//}

void gameExit(void)
{
	free(g_szTxt);
	free(g_szMenu);
	//exit(1);
}

void gotoXY(short x, short y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void gotoXY(COORD pos)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}