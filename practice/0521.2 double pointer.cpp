#include "stdafx.h"

int main(int argc, char* argv[])	// argc = argument count. 입력된 인자 개수.
{
	int i = 0;
	for (i = 0; i < argc; i++)
		puts(argv[i]);

	puts("End");

	return 0;
}
