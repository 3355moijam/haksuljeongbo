#include "stdafx.h"
//#include "List.h"
#include "cUI.h"
extern HWND hWnd;
int score = 0;
extern vector<vector<cGame*>> objectList;
extern cChar* chara;
extern RECT view;


void cUI::draw_main(HDC hdc)
{
	DrawGrid(hdc, 0, 0, view.right, view.bottom, 50);
	int center = view.right / 2;
	button title(_T("Pong Like"), center, view.bottom / 4, center, view.bottom / 5);
	title.show(hdc);

	wstring temp = _T("ID: ") + user_id;
	SIZE tempSize;

	
	GetTextExtentPoint(hdc, temp.c_str(), temp.size(), &tempSize);
	button idInput(temp, center, view.bottom / 2, center, 50);
	
	idInput.show(hdc, DT_LEFT);
	SetCaretPos(idInput.get_letter_x() + tempSize.cx, idInput.get_letter_y() - 1);
}

void cUI::draw_game(HDC hdc)
{
	RECT idBox = { 20, 20, 100, 40 };
	RECT scoreBox = { view.right - 100, 20, view.right - 20, 40 };
	RECT maxBox = { view.right - 100, 40, view.right - 20, 60 };
	wstring tempID = _T("ID: ") + user_id;
	wstring tempScore = _T("score: ") + to_wstring(score);
	wstring tempMax = _T("maxBall: ") + to_wstring(cBullet::get_max());
	DrawText(hdc, tempID.c_str(), tempID.size(), &idBox, DT_LEFT | DT_SINGLELINE | DT_VCENTER);
	DrawText(hdc, tempScore.c_str(), tempScore.size(), &scoreBox, DT_LEFT | DT_SINGLELINE | DT_VCENTER);
	DrawText(hdc, tempMax.c_str(), tempMax.size(), &maxBox, DT_LEFT | DT_SINGLELINE | DT_VCENTER);

	if (counter != nullptr)
	{
		counter->show(hdc);
	}
}

void cUI::draw_gameover(HDC hdc)
{
	int center = view.right / 2;
	wstring FinalScore = _T("\" ") + user_id + _T(" \"의 최종 점수\r\n") + to_wstring(score) + _T("\r\n");
	FinalScore += sRank;
	RECT textBox = { center - center / 2, (view.bottom / 4) - view.bottom / 10, center + center / 2, (view.bottom / 4) + view.bottom / 10 };
	DrawRectangle(hdc, &textBox);
	DrawText(hdc, FinalScore.c_str(), FinalScore.size(), &textBox, DT_CENTER);

	static bool makeButton = false;
	while (!makeButton)
	{
		makeButton = true;
		retry = new button_retry(center / 2, view.bottom - view.bottom / 4, 120, 60);
		close = new button_close(center + center / 2, view.bottom - view.bottom / 4, 120, 60);
	} 

	(*retry).show(hdc);
	(*close).show(hdc);
	
}

//wstring cUI::user_id = _T("");
//int cUI::score = 0;
//int cUI::ui_mode = 0;
cUI::cUI() : retry(nullptr), close(nullptr), sRank(), ranking(nullptr)
{
}


cUI::~cUI()
{
	if(retry != nullptr)
		delete retry;
	if(close != nullptr)
		delete close;
}

void cUI::set_mode(mode nInput)
{
	ui_mode = nInput;
	switch (nInput)
	{
	case mode::main:
		user_id = _T("");
		break;
	case mode::game:
		DestroyCaret();
		score = 0;
		counter = new cCountDown;
		cGame::init();
		chara = dynamic_cast<cChar*> (objectList[0][0]);
		break;
	case mode::gameover:
		cGame::set_start();
		cGame::delete_all();
		KillTimer(hWnd, 2);
		load_ranking();
		break;
	default:
		break;
	}
}

void cUI::draw(HDC hdc)
{
	if (ui_mode == mode::main)
		draw_main(hdc);
	else if (ui_mode == mode::game)
		draw_game(hdc);
	else if (ui_mode == mode::gameover)
		draw_gameover(hdc);
}

int cUI::get_input(WPARAM wParam)
{
	if (wParam == VK_BACK)
	{
		if(user_id.size() > 0)
			user_id.pop_back();
		return 0;
	}
	else if (wParam == VK_RETURN)
	{
		return 1;
	}
	
	if (user_id.size() < 8)
		user_id.push_back(wParam);
	return 0;
}

int cUI::click(LPARAM lParam)
{
	int mx = LOWORD(lParam);
	int my = HIWORD(lParam);
	
	if (retry->getClick(mx, my))
		(*retry).on_event(this);
	else if (close->getClick(mx, my))
		(*close).on_event(this);
	return 0;
}

void cUI::load_ranking()
{
	ranking = new List();
	sRank = _T("");
	ranking->read_file();
	ranking->push(score, user_id);
	ranking->print_5(sRank);
	ranking->write_file();
	delete ranking;
	ranking = nullptr;
}


cCountDown::cCountDown(): count(5)
{
	SetTimer(hWnd, 1, 1000, NULL);
	letter_box = { view.right / 2 - 30, view.bottom / 2 - 10, view.right / 2 + 30, view.bottom / 2 + 10 };
}

cCountDown::~cCountDown()
{
	KillTimer(hWnd, 1);
	SetTimer(hWnd, 2, 17, NULL);
}

void cCountDown::show(HDC hdc)
{
	wstring tempcount;// = to_wstring(count);
	if (count > 0)
		tempcount = to_wstring(count);
	else if (count == 0)
		tempcount = L"START";

	DrawText(hdc, tempcount.c_str(), tempcount.size(), &letter_box, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
}
