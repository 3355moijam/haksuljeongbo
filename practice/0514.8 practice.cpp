#include "stdafx.h"

void Menu(void);
int openMenu(void);
int getInput(void);
int Calculator(int op, int num1, int num2);
void Print(int answer);
int Add(int num1, int num2);
int Sub(int num1, int num2);
int Mul(int num1, int num2);
int Div(int num1, int num2);

int main(void)
{
	Menu();

	return 0;
}

void Menu(void)
{
	int operation = 0, num1 = 0, num2 = 0;
	while (1)
	{
		operation = openMenu();

		if (operation < 1 || operation > 5)
			continue;
		else if (operation == 5)
			break;

		num1 = getInput();
		num2 = getInput();

		Print(Calculator(operation, num1, num2));
	}
}



int openMenu(void)
{
	printf("���ϴ� ������?\n1.���� 2.���� 3.���� 4.������ 5.����\n");
	
	int input;
	scanf_s("%d%*c", &input);

	return input;
}

int getInput(void)
{
	printf("� ���� ����ұ��? : ");
	
	int input;
	scanf_s("%d%*c", &input);

	return input;
}

int Calculator(int op, int num1, int num2)
{
	switch (op)
	{
		case 1:
			return Add(num1, num2);
		case 2:
			return Sub(num1, num2);
		case 3:
			return Mul(num1, num2);
		case 4:
			return Div(num1, num2);
		default:
			break;
	}

	return 0;
}

void Print(int answer)
{
	printf("�� : %d\n\n", answer);
}

int Add(int num1, int num2)
{
	return num1 + num2;
}

int Sub(int num1, int num2)
{
	return num1 - num2;
}

int Mul(int num1, int num2)
{
	return num1 * num2;
}

int Div(int num1, int num2)
{
	if (num2 != 0)
		return num1 / num2;
	else
	{
		printf("Error : 0���� ���� �� �����ϴ�.\n");
		return 0;
	}
}