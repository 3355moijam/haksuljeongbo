#include "stdafx.h"
#include <Windows.h>

int main(int argc, char* argv[])
{
	/*char szCommand[512] = { 0 };
	printf("Input command: ");
	gets_s(szCommand);

	system(szCommand);*/
	/////////

	char ch;
	printf("Do you want to EXIT? (Y/N)\n");

	ch = _getch();

	if (ch == 'y' || ch == 'Y')
	{
		puts("Exit");
		exit(1);
	}

	puts("End of Main( )");

	return 0;
}