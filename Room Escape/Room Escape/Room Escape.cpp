// Room Escape.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
int nLoop = 0;

int main()
{
	while (1)
	{
		int nInput = 0;
		int gameEnd = 0;
		nLoop++;

		InitScreen();
		InitItem();
		InitList();

		while (1)
		{
			PrintScreen();
			nInput = getInput();
			gameEnd = checkState(nInput);
			setMenu();

			if (gameEnd == BREAK)
				break;
		}

		if (g_state == EXIT)
			break;
	}
    return 0;
}
