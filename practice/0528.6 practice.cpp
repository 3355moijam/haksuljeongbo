#include "stdafx.h"

#define ERROR(string)	printf("ERROR: cannot open %s\n", string)
#define _NAMESIZE	16
struct Student
{
	int id;
	char name[_NAMESIZE];
};

int Menu(void);
void getInput(Student *stu);
int searchName(Student *stu);
void Print(Student *stu, int index);
void MemError(void* arr);

const int g_unit = 4096; // 파일 복사 크기

int main(int argc, char* argv[])
{

	// 번호, 이름을 입력받을 수 있는 구조체를 만들고 저장하는 프로그램
	// 
	// 1. 데이터 추가 - 번호중복x, 이름중복o. 반드시 번호 오름차순.
	// 2. 검색출력 - 번호 또는 이름으로 검색. 동명이인은 모두 출력 -1은 모두 출력
	// 3. 변경 - 변경번호: , 이름은?: 
	// 4. 복구 - old.dat -> sav.dat으로 치환.
	// 5. 종료 - 프로그램 종료
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);

	int menu, index;
	Student *stuClass = NULL;
	stuClass = (Student*)calloc(10, sizeof(Student));
	if (stuClass == NULL)
		MemError(stuClass);
	/*Student stuClass[10] = { 0 };*/

	while (1)
	{
		menu = Menu();

		// menu 처리
		if (menu == 1)
		{
			getInput();
		}
		else if (menu == 2)
		{
			search();
		}
		else if (menu == 3)
		{
			modify();
		}
		else if (menu == 4)
			backup(true);
		else if (menu == 5)
			break;
		else
			continue;
	}


	free(stuClass);
	_CrtDumpMemoryLeaks();

	return 0;
}

int Menu(void)
{
	printf("1.데이터 추가\t2.검색\t3.변경\t4.복구\t5.종료\n");
	int num;
	scanf_s("%d", &num);
	rewind(stdin);

	return num;
}

void getInput(void)
{
	backup(false);
	Student stu = { 0 };
	printf("번호 :");
	scanf_s("%d", &stu.id);
	rewind(stdin);

	printf("이름 :");
	scanf_s("%s", &stu.name, 10);
	rewind(stdin);

	// 검색 후 같은 번호가 있다면 에러 출력
	// 없다면 본래 위치에 바로 삽입정렬
	///////////수정필요. 스캔하다 위치가 나오면 그 이후는 tmp로 빼놓고, input을 쓴 다음 tmp를 뒤에 붙여줘야 함.
	FILE *fp = fopen("save.dat", "ab+");
	if (fp == NULL)
	{
		ERROR("save.dat");
	}

	Student *stBuffer = (Student*)calloc(1, sizeof(Student));
	int stLen = getFileSize(fp) / sizeof(Student);
	fseek(fp, 0, SEEK_SET);

	bool bFind = false;

	for (size_t i = 0; i < stLen; i++)
	{
		fread(stBuffer, sizeof(Student), 1, fp);

		if (stu.id == stBuffer->id)
		{
			bFind = true;
			printf("이미 자료가 존재합니다\n");
			break;
		}
		else if (stu.id < stBuffer->id)	// 중간에 삽입
		{
			fwrite(&stu, sizeof(Student), 1, fp);
			bFind = true;
			break;
		}
	}
	if (!bFind)	// 중복자료가 없는데 중간삽입도 못했을 때 맨 뒤에 추가.
	{
		fseek(fp, 0, SEEK_END);
		fwrite(&stu, sizeof(Student), 1, fp);
	}
	free(stBuffer);
	fclose(fp);
	return;

	
}
int search(void)	// 검색메뉴 및 수행
{
	char* szTargetName = (char*)calloc(_NAMESIZE, sizeof(char));
	int nTargetID;
	int check = searchMenu(&nTargetID, &szTargetName);
	if (check == -1)
	{
		return 0;
	}


	if (check == 1)	// 번호. 찾으면 인덱스, 못찾으면 -1 리턴
	{
		free(szTargetName);
		return compareID(nTargetID);
	}
	else if (check == 2)	// 이름. 찾으면 개수, 못찾으면 0 리턴
	{
		return compareName(szTargetName);
	}
	else if (check == 3)	// 전체
	{
		free(szTargetName);
		FILE *fp = fopen("save.dat", "rb");
		if (fp == NULL)
		{
			ERROR("save.dat");
		}

		Student *stBuffer = NULL;
		int stLen = getFileSize(fp) / sizeof(Student);
		fseek(fp, 0, SEEK_SET);

		for (size_t i = 0; i < stLen; i++)
		{
			fread(stBuffer, sizeof(Student), 1, fp);
			Print(stBuffer);
		}
		fclose(fp);
		return 1;
	}

	return -1;
}

int compareID(int nTargetID)
{
	FILE *fp = fopen("save.dat", "rb");
	if (fp == NULL)
	{
		ERROR("save.dat");
	}

	Student *stBuffer = (Student*)calloc(1, sizeof(Student));;
	int stLen = getFileSize(fp) / sizeof(Student);
	fseek(fp, 0, SEEK_SET);

	for (size_t i = 0; i < stLen; i++)
	{
		fread(stBuffer, sizeof(Student), 1, fp);

		if (nTargetID == stBuffer->id)
		{
			Print(stBuffer);
			free(stBuffer);
			fclose(fp);
			return i;
		}
	}

	printf("발견하지 못했습니다.\n");
	free(stBuffer);
	fclose(fp);
	return -1;
}
int compareName(char* szTargetName)
{
	FILE *fp = fopen("save.dat", "rb");
	if (fp == NULL)
	{
		ERROR("save.dat");
	}

	Student *stBuffer = (Student*)calloc(1, sizeof(Student));;
	int stLen = getFileSize(fp) / sizeof(Student);
	fseek(fp, 0, SEEK_SET);

	int count = 0;
	for (size_t i = 0; i < stLen; i++)
	{
		fread(stBuffer, sizeof(Student), 1, fp);

		if (strcmp(szTargetName, stBuffer->name) == 0)
		{
			count++;
			Print(stBuffer);
			memset(stBuffer, 0, sizeof(Student));
		}

	}

	if (count == 0)
		printf("발견하지 못했습니다.\n");
	fclose(fp);
	free(stBuffer);
	free(szTargetName);
	return count;
}
int searchMenu(int* nID, char** szName)
{
	printf("1.번호로 찾기\t2.이름으로 찾기\t3.모두 출력\t4.돌아가기");
	int num;
	scanf_s("%d", &num);

	if (num == 1)
	{
		printf("찾는 번호?: ");
		scanf_s("%d", nID);
	}
	else if (num == 2)
	{
		printf("찾는 이름?: ");
		gets_s(*szName, _NAMESIZE);
	}
	else if (num == 3)
	{
		return num;
	}
	else
	{
		return -1;
	}
	rewind(stdin);
	return num;
}
void modify(void)
{
	printf("바꿀 ID : ");
	int nTargetID;
	char szTargetName[_NAMESIZE];

	// 입력 받기
	scanf_s("%d", &nTargetID);
	int check = compareID(nTargetID);
	// compareID 후 발견 못하면 return
	if (check == -1)
	{
		return;
	}
	// 발견하면 이름을 고친다.
	else
	{
		backup(false);
		printf("바꿀 이름 : ");
		gets_s(szTargetName, _NAMESIZE);
		
		FILE *fp = fopen("save.dat", "wb+");
		if (fp == NULL)
		{
			ERROR("save.dat");
		}
		fseek(fp, sizeof(Student) * check, SEEK_SET);

		Student *stBuffer = (Student*)calloc(1, sizeof(Student));
		fread(stBuffer, sizeof(stBuffer), 1, fp);
		strcpy(stBuffer->name, szTargetName);
		
		free(stBuffer);
		fclose(fp);
	}
}
void Print(Student *stu)
{
	printf("번호 : %d\t이름: %s\t성적 : %d\n", stu->id, stu->name);
}

void MemError(void* arr)
{
	printf("메모리 할당에 실패했습니다.\n");
	free(arr);
	exit(1);
}

void backup(bool recov)	// true:복원, false:백업
{
	char srcLink[16];
	char tarLink[16];
	if (recov)	// 복원
	{
		strcpy(srcLink, "old.dat");
		strcpy(tarLink, "save.dat");
	}
	else	// 백업
	{
		strcpy(srcLink, "save.dat");
		strcpy(tarLink, "old.dat");
	}
	FILE *src = fopen(srcLink, "rb");
	if (src == NULL)
	{
		ERROR(srcLink);
		exit(1);
	}
	FILE *target = fopen(tarLink, "wb");
	if (target == NULL)
	{
		ERROR(tarLink);
		exit(1);
	}

	long srcSize = getFileSize(src);
	fseek(src, 0, SEEK_SET);
	fseek(target, 0, SEEK_SET);

	char *szBuffer = (char*)malloc(g_unit);
	for (long i = 0; i < srcSize / g_unit; i++)
	{
		fread(szBuffer, g_unit, 1, src);
		fwrite(szBuffer, g_unit, 1, target);
		memset(szBuffer, 0, g_unit);
	}
	if (srcSize % g_unit != 0)
	{
		fread(szBuffer, srcSize % g_unit, 1, src);
		fwrite(szBuffer, srcSize % g_unit, 1, target);
		memset(szBuffer, 0, g_unit);
	}
	
	free(szBuffer);
	fclose(src);
	fclose(target);
}

long getFileSize(FILE *fp)
{
	fseek(fp, 0, SEEK_END);
	long tmp = ftell(fp);
	return tmp;
}