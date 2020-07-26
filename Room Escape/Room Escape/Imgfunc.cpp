#include "stdafx.h"


void printTitle(void)
{
	int x = 30, y = 5;
	gotoXY(x, y++);
	wprintf(L" __                        _ \n");
	gotoXY(x, y++);
	wprintf(L" | |           ___      _ | |                     __       _\n");
	gotoXY(x, y++);
	wprintf(L" | |____      / _ ¡¬   | || |                ____|  |___  | |\n");
	gotoXY(x, y++);
	wprintf(L" |______|    | | | |  _| || |    ________   |____     __| | |\n");
	gotoXY(x, y++);
	wprintf(L"__________   | | | | |_  || |   |______  |      / _  |    | |\n");
	gotoXY(x, y++);
	wprintf(L"|___   ___|  | |_| |   | || |       _  | |     / / | |    | |\n");
	gotoXY(x, y++);
	wprintf(L"    | |      ¡¬____/   |_|| |      | | |_|    /_/  |_|    | |\n");
	gotoXY(x, y++);
	wprintf(L"    |_|                   |_|  ____| |______              | |\n");
	gotoXY(x, y++);
	wprintf(L"                              |_____________|             |_|\n");
}