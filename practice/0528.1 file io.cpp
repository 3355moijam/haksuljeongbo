#include "stdafx.h"


int main(int argc, char* argv[])
{
	
	FILE *fp = NULL;

	fp = fopen("Test1.txt", "w");	// w는 기존 파일이 있다면 삭제하고 재생성함.
									// a는 기존 파일 뒤에 새로 추가
									// r은 읽기모드


	if (fp == NULL)
	{
		puts("ERROR: file open fail");
		return 0;
	}
	////printf("%x\n", *fp);
	//fprintf(fp, "%d, %s\n", 20, "Test");
	//fclose(fp);
	////printf("%x\n", *fp);	// 글자가 추가된 만큼 파일포인터가 증가
	//
	//fp = fopen("Test1.txt", "r");	
	//int nData = 0;
	//char szBuffer[32] = { 0 };
	//fscanf(fp, "%d,%s", &nData, szBuffer); // scanf와 같은데 키보드가 아니라 txt파일에서 파일을 읽어오기

	//int nClose = _fcloseall();
	//printf("close count : %d\n", nClose);

	//fclose(fp);

	//printf("%d, %s\n", nData, szBuffer);

	char ch;
	char szBuffer[512] = { 0 };

	fputs("Test string!\n", fp);
	fputs("Test strin!\n", fp);
	fputs("Test strg\n", fp);
	fclose(fp);

	fp = fopen("Test1.txt", "r");
	if (fp == NULL)
		return 0;
	//while ((ch = fgetc(fp)) != EOF) // fgetc 한글자씩 가져오기
	//{
	//	putchar(ch);
	//}

	while (fgets(szBuffer, sizeof(szBuffer), fp)) 
	{// szBuffer에 한 줄을 가져옴. 최대 szBuffer의 크기만큼 가져온다. 그래서 szBuffer는 크게 잡아야함
		printf("%s", szBuffer);
		memset(szBuffer, 0, sizeof(szBuffer)); // szBuffer 초기화. 안해주면 뒷줄이 앞줄보다 짧을경우+널문자가 없을 경우 overwrite 될 수 있다.
	}
	fclose(fp);
	return 0;
}

