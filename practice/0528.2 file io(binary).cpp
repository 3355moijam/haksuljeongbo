#include "stdafx.h"

struct USERDATA
{
	char szName[16];
	char szPhone[16];
};

int main(int argc, char* argv[])
{
	FILE *fp = NULL;
	USERDATA UserData = { 0 };//{ "Ho-sung", "123-1234" };

	fp = fopen("Test.dat", "rb");
	if (fp == NULL)
		return 0;
/*
	fread(&UserData, sizeof(USERDATA), 1, fp);
	fclose(fp);

	puts(UserData.szName);
	puts(UserData.szPhone);
*/

	fseek(fp, 0, SEEK_END);
	printf("size of Test.dat : %u\n", ftell(fp));

	return 0;
}