#include "stdafx.h"

struct Student
{
	int id;
	char name[32];
	int grade;
	Student *pNext;
};

int Menu(void);
void getInput(Student **first, Student **last);
int searchName(Student *stu);
void Print(Student *stu, int index);
Student* getNode(Student *first, int index);
void MemError(void* arr);

int main(int argc, char* argv[])
{

	// ��ȣ, �̸�, ������ �Է¹��� �� �ִ� ����ü�� �����
	// �����͸� �Է¹޾� ����ϴ� �ڵ带 �����.
	// 1. �Է� -
	// 2. �˻� - �̸����� �˻�, �ش� �л��� ��ȣ, �̸�, ������ ���
	// 3. ��ü��� - ��ü �л��� ��ȣ, �̸�, ������ ���
	// 4. ���� - ���α׷� ����
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);

	int menu, index;
	Student *pFirst = NULL;
	Student *pLast = NULL;
	/*Student *stuClass = NULL;
	stuClass = (Student*)calloc(10, sizeof(Student));
	if (stuClass == NULL)
		MemError(stuClass);*/
	/*Student stuClass[10] = { 0 };*/

	while (1)
	{
		menu = Menu();

		// menu ó��
		if (menu == 1)
		{
			getInput(&pFirst, &pLast);
		}
		else if (menu == 2)
		{
			index = searchName(pFirst);
			Print(pFirst, index);
		}
		else if (menu == 3)
		{
			Print(pFirst, -2);	// -2�� ���� ���
		}
		else if (menu == 4)
			break;
		else
			continue;
	}

	Student *tmp = pFirst;
	while (tmp != NULL)
	{
		tmp = pFirst->pNext;
		free(pFirst);
		pFirst = tmp;
	}

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

void getInput(Student **first, Student **last)
{
	static int count = 0;
	Student *newNode = (Student*)calloc(1, sizeof(Student));
	if (newNode == NULL)
	{
		MemError(newNode);
	}
	newNode->pNext = NULL;
	
	printf("��ȣ :");
	scanf_s("%d", &newNode->id);	// &newNode->id == id�� �ּ�
	rewind(stdin);

	printf("�̸� :");
	scanf_s("%s", &newNode->name, 10);
	rewind(stdin);

	printf("���� :");
	scanf_s("%d", &newNode->grade);
	rewind(stdin);
	
	if (count == 0)
	{
		*first = newNode;
	}
	else
	{
		(*last)->pNext = newNode;
	}

	*last = newNode;
	count++;
}
int searchName(Student *stu)	// ã�� �л� �ε��� ��ȯ
{
	printf("ã�� �̸�?: ");
	char sName[32];
	scanf_s("%s", sName, 32);
	rewind(stdin);

	Student *tmp = stu;
	int i = 0;
	while (tmp != NULL)
	{
		if (strcmp(tmp->name, sName) == 0)
		{
			return i;
		}
		i++;
		tmp = tmp->pNext;
	}
	return -1;
}
void Print(Student *stu, int index)
{
	Student *tmp = stu;
	int i = 0;
	if (index == -1)
	{
		printf("�ڷᰡ �߰ߵ��� �ʾҽ��ϴ�.\n");
	}
	else if (index == -2)
	{
		while (tmp->pNext != NULL)
		{
			tmp = getNode(stu, i++);
			printf("��ȣ : %d\t�̸�: %s\t���� : %d\n", tmp->id, tmp->name, tmp->grade);
		}
	}
	else
	{
		tmp = getNode(stu, index);
		printf("��ȣ : %d\t�̸�: %s\t���� : %d\n", tmp->id, tmp->name, tmp->grade);
	}
}

void MemError(void* arr)
{
	printf("�޸� �Ҵ翡 �����߽��ϴ�.\n");
	free(arr);
	exit(1);
}

Student* getNode(Student *first, int index)
{
	Student *tmp = first;
	for (int i = 0; i < index; i++)
	{
		tmp = tmp->pNext;
	}

	return tmp;
}