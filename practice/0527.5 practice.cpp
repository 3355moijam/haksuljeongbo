#include "stdafx.h"

struct Student
{
	int id;
	char name[10];
	int grade;
};

int Menu(void);
void getInput(Student *stu);
int searchName(Student *stu);
void Print(Student *stu, int index);
void MemError(void* arr);

int main(int argc, char* argv[])
{
	
	// ��ȣ, �̸�, ������ �Է¹��� �� �ִ� ����ü�� �����
	// �л��� 10���� ���� �����͸� �Է¹޾� ����ϴ� �ڵ带 �����.
	// 1. �Է� -
	// 2. �˻� - �̸����� �˻�, �ش� �л��� ��ȣ, �̸�, ������ ���
	// 3. ��ü��� - ��ü �л��� ��ȣ, �̸�, ������ ���
	// 4. ���� - ���α׷� ����
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
			getInput(stuClass);
		}
		else if (menu == 2)
		{
			index = searchName(stuClass);
			Print(stuClass, index);
		}
		else if (menu == 3)
		{
			Print(stuClass, -2);	// -2�� ���� ���
		}
		else if (menu == 4)
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
	printf("1.�Է�\t2.�˻�\t3.��ü���\t4.����\n");
	int num;
	scanf_s("%d", &num);
	rewind(stdin);

	return num;
}

void getInput(Student *stu)
{
	static int count = 0;
	printf("��ȣ :");
	scanf_s("%d", &stu[count].id);
	rewind(stdin);

	printf("�̸� :");
	scanf_s("%s", &stu[count].name, 10);
	rewind(stdin);
	
	printf("���� :");
	scanf_s("%d", &stu[count].grade);
	rewind(stdin);

	count++;
}
int searchName(Student *stu)	// ã�� �л� �ε��� ��ȯ
{
	printf("ã�� �̸�?: ");
	char sName[10];
	scanf_s("%s", sName, 10);
	rewind(stdin);

	for (int i = 0; i < 10; i++)
	{
		if (strcmp(stu[i].name, sName) == 0)
		{
			return i;
		}
	}
	return -1;
}
void Print(Student *stu, int index)
{
	if (index == -1)
	{
		printf("�ڷᰡ �߰ߵ��� �ʾҽ��ϴ�.\n");
	}
	else if (index == -2)
	{
		for (int i = 0; i < 10; i++)
		{
			printf("��ȣ : %d\t�̸�: %s\t���� : %d\n", stu[i].id, stu[i].name, stu[i].grade);
		}
	}
	else
	{
		printf("��ȣ : %d\t�̸�: %s\t���� : %d\n", stu[index].id, stu[index].name, stu[index].grade);
	}
}

void MemError(void* arr)
{
	printf("�޸� �Ҵ翡 �����߽��ϴ�.\n");
	free(arr);
	exit(1);
}