#include "stdafx.h"


int main(int argc, char* argv[])
{
	
	FILE *fp = NULL;

	fp = fopen("Test1.txt", "w");	// w�� ���� ������ �ִٸ� �����ϰ� �������.
									// a�� ���� ���� �ڿ� ���� �߰�
									// r�� �б���


	if (fp == NULL)
	{
		puts("ERROR: file open fail");
		return 0;
	}
	////printf("%x\n", *fp);
	//fprintf(fp, "%d, %s\n", 20, "Test");
	//fclose(fp);
	////printf("%x\n", *fp);	// ���ڰ� �߰��� ��ŭ ���������Ͱ� ����
	//
	//fp = fopen("Test1.txt", "r");	
	//int nData = 0;
	//char szBuffer[32] = { 0 };
	//fscanf(fp, "%d,%s", &nData, szBuffer); // scanf�� ������ Ű���尡 �ƴ϶� txt���Ͽ��� ������ �о����

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
	//while ((ch = fgetc(fp)) != EOF) // fgetc �ѱ��ھ� ��������
	//{
	//	putchar(ch);
	//}

	while (fgets(szBuffer, sizeof(szBuffer), fp)) 
	{// szBuffer�� �� ���� ������. �ִ� szBuffer�� ũ�⸸ŭ �����´�. �׷��� szBuffer�� ũ�� ��ƾ���
		printf("%s", szBuffer);
		memset(szBuffer, 0, sizeof(szBuffer)); // szBuffer �ʱ�ȭ. �����ָ� ������ ���ٺ��� ª�����+�ι��ڰ� ���� ��� overwrite �� �� �ִ�.
	}
	fclose(fp);
	return 0;
}

