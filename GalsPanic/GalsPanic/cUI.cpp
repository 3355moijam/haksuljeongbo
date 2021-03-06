#pragma once
#include "framework.h"
#include "cUI.h"
extern RECT g_view;
extern POINT g_center;

HFONT cUI::hFontNanum = CreateFont(75, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("��������"));

cUI::cUI()
{
}

cUI::~cUI()
{
}

cMainUI::cMainUI()
{
}

void cMainUI::draw(HDC hdc)
{
	HFONT hOldFont = (HFONT)SelectObject(hdc, hFontNanum);
	RECT title = { g_center.x - 300, g_center.y - 200, g_center.x + 300, g_center.y + 200 };
	DrawText(hdc, _T("School Panic"), _tcslen(_T("School Panic")), &title, DT_CENTER);
	
	SelectObject(hdc, hOldFont);
	RECT press_any_button = { g_center.x - 300, g_center.y + 200, g_center.x + 300, g_center.y + 400 };
	DrawText(hdc, _T("Press Any Button"), _tcslen(_T("Press Any Button")), &press_any_button, DT_CENTER);
	
}

cGameUI::cGameUI()
{
}

void cGameUI::draw(HDC hdc)
{
}

cEndUI::cEndUI()
{
}

void cEndUI::draw(HDC hdc)
{
}
