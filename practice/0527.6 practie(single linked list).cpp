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

	// 번호, 이름, 성적을 입력받을 수 있는 구조체를 만들고
	// 데이터를 입력받아 출력하는 코드를 만든다.
	// 1. 입력 -
	// 2. 검색 - 이름으로 검색, 해당 학생의 번호, 이름, 성적을 출력
	// 3. 전체출력 - 전체 학생의 번호, 이름, 성적을 출력
	// 4. 종료 - 프로그램 종료
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

		// menu 처리
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
			Print(pFirst, -2);	// -2면 전부 출력
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
	printf("1.입력\t2.검색\t3.전체출력\t4.종료\n");
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
	
	printf("번호 :");
	scanf_s("%d", &newNode->id);	// &newNode->id == id의 주소
	rewind(stdin);

	printf("이름 :");
	scanf_s("%s", &newNode->name, 10);
	rewind(stdin);

	printf("성적 :");
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
int searchName(Student *stu)	// 찾은 학생 인덱스 반환
{
	printf("찾는 이름?: ");
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
		printf("자료가 발견되지 않았습니다.\n");
	}
	else if (index == -2)
	{
		while (tmp->pNext != NULL)
		{
			tmp = getNode(stu, i++);
			printf("번호 : %d\t이름: %s\t성적 : %d\n", tmp->id, tmp->name, tmp->grade);
		}
	}
	else
	{
		tmp = getNode(stu, index);
		printf("번호 : %d\t이름: %s\t성적 : %d\n", tmp->id, tmp->name, tmp->grade);
	}
}

void MemError(void* arr)
{
	printf("메모리 할당에 실패했습니다.\n");
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