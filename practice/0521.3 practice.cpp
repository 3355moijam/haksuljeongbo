#include "stdafx.h"

int main(void)
{
	char* string[2] = { "I Love C", "Hello World" };

	printf("%s%s\n", string[0], string[1] + 5);
	printf("%s\n", *(string+1)+5);
	printf("%s\n", *(string + 1) + 5);
	//printf("%s%s\n", *(string[0] + 0), string[1] + 5);




	return 0;
}
