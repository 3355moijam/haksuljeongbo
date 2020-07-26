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

const int g_unit = 4096; // ���� ���� ũ��

int main(int argc, char* argv[])
{

	// ��ȣ, �̸��� �Է¹��� �� �ִ� ����ü�� ����� �����ϴ� ���α׷�
	// 
	// 1. ������ �߰� - ��ȣ�ߺ�x, �̸��ߺ�o. �ݵ�� ��ȣ ��������.
	// 2. �˻���� - ��ȣ �Ǵ� �̸����� �˻�. ���������� ��� ��� -1�� ��� ���
	// 3. ���� - �����ȣ: , �̸���?: 
	// 4. ���� - old.dat -> sav.dat���� ġȯ.
	// 5. ���� - ���α׷� ����
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

		// menu ó��
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
	printf("1.������ �߰�\t2.�˻�\t3.����\t4.����\t5.����\n");
	int num;
	scanf_s("%d", &num);
	rewind(stdin);

	return num;
}

void getInput(void)
{
	backup(false);
	Student stu = { 0 };
	printf("��ȣ :");
	scanf_s("%d", &stu.id);
	rewind(stdin);

	printf("�̸� :");
	scanf_s("%s", &stu.name, 10);
	rewind(stdin);

	// �˻� �� ���� ��ȣ�� �ִٸ� ���� ���
	// ���ٸ� ���� ��ġ�� �ٷ� ��������
	///////////�����ʿ�. ��ĵ�ϴ� ��ġ�� ������ �� ���Ĵ� tmp�� ������, input�� �� ���� tmp�� �ڿ� �ٿ���� ��.
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
			printf("�̹� �ڷᰡ �����մϴ�\n");
			break;
		}
		else if (stu.id < stBuffer->id)	// �߰��� ����
		{
			fwrite(&stu, sizeof(Student), 1, fp);
			bFind = true;
			break;
		}
	}
	if (!bFind)	// �ߺ��ڷᰡ ���µ� �߰����Ե� ������ �� �� �ڿ� �߰�.
	{
		fseek(fp, 0, SEEK_END);
		fwrite(&stu, sizeof(Student), 1, fp);
	}
	free(stBuffer);
	fclose(fp);
	return;

	
}
int search(void)	// �˻��޴� �� ����
{
	char* szTargetName = (char*)calloc(_NAMESIZE, sizeof(char));
	int nTargetID;
	int check = searchMenu(&nTargetID, &szTargetName);
	if (check == -1)
	{
		return 0;
	}


	if (check == 1)	// ��ȣ. ã���� �ε���, ��ã���� -1 ����
	{
		free(szTargetName);
		return compareID(nTargetID);
	}
	else if (check == 2)	// �̸�. ã���� ����, ��ã���� 0 ����
	{
		return compareName(szTargetName);
	}
	else if (check == 3)	// ��ü
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

	printf("�߰����� ���߽��ϴ�.\n");
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
		printf("�߰����� ���߽��ϴ�.\n");
	fclose(fp);
	free(stBuffer);
	free(szTargetName);
	return count;
}
int searchMenu(int* nID, char** szName)
{
	printf("1.��ȣ�� ã��\t2.�̸����� ã��\t3.��� ���\t4.���ư���");
	int num;
	scanf_s("%d", &num);

	if (num == 1)
	{
		printf("ã�� ��ȣ?: ");
		scanf_s("%d", nID);
	}
	else if (num == 2)
	{
		printf("ã�� �̸�?: ");
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
	printf("�ٲ� ID : ");
	int nTargetID;
	char szTargetName[_NAMESIZE];

	// �Է� �ޱ�
	scanf_s("%d", &nTargetID);
	int check = compareID(nTargetID);
	// compareID �� �߰� ���ϸ� return
	if (check == -1)
	{
		return;
	}
	// �߰��ϸ� �̸��� ��ģ��.
	else
	{
		backup(false);
		printf("�ٲ� �̸� : ");
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
	printf("��ȣ : %d\t�̸�: %s\t���� : %d\n", stu->id, stu->name);
}

void MemError(void* arr)
{
	printf("�޸� �Ҵ翡 �����߽��ϴ�.\n");
	free(arr);
	exit(1);
}

void backup(bool recov)	// true:����, false:���
{
	char srcLink[16];
	char tarLink[16];
	if (recov)	// ����
	{
		strcpy(srcLink, "old.dat");
		strcpy(tarLink, "save.dat");
	}
	else	// ���
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