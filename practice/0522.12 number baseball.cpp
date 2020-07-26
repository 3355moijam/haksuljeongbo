#include "stdafx.h"
#include <time.h>

int* setAnswer(void);
int* getAnswer(void);
void checkAnswer(int *answer, int *input);
void Print(int *Input);

int g_Strike = 0;
int g_Ball = 0;
int g_Out = 0;

int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);

	int *Answer = setAnswer();
	//// debug
	//for (int i = 0; i < 3; i++)
	//{
	//	printf("%d ", Answer[i]);
	//}
	//printf("\n\n");

	int *Input;
	while (1)
	{
		Input = getAnswer();

		checkAnswer(Answer, Input);
		Print(Input);

		if (g_Strike == 3)
		{
			break;
		}
	}

	free(Answer);
	_CrtDumpMemoryLeaks();

	return 0;
}

int* setAnswer(void)
{
	srand((unsigned)time(NULL));

	int *Answer = (int*)calloc(3, sizeof(int));
	int i = 0, nRandom = 0;
	bool check = 0;
	while (Answer[2] == 0)
	{
		nRandom = (rand() % 9) + 1;
		check = 0;
		for (int j = 0; j <= i; j++)
		{
			if (Answer[j] == nRandom)
			{
				check = !check;
				break;
			}
		}
		if (!check)
		{
			Answer[i] = nRandom;
			i++;
		}
	}

	return Answer;
}

int* getAnswer(void)
{
	int *Input = (int*)calloc(3, sizeof(int));
	bool flag = false;
	do
	{
		flag = false;
		//memset(Input, 0, 3 * sizeof(int));
		printf("숫자 셋을 입력하세요(1~9) : ");
		scanf_s("%d %d %d", &Input[0], &Input[1], &Input[2]);
		rewind(stdin);
		
		for (int i = 0; i < 3; i++)
		{
			if (Input[i] < 1 || Input[i] > 9)
			{
				flag = true;
				break;
			}
		}
		if (flag)
		{
			printf("범위를 벗어난 숫자가 입력됐습니다\n");
			continue;
		}

		if (Input[0] != Input[1] && Input[1] != Input[2] && Input[2] != Input[0])
			break;

		printf("서로 다른 숫자를 입력해주세요.\n");
	} while (1);
	
	return Input;
}

void checkAnswer(int *answer, int *input)
{
	// 초기화
	g_Strike = 0;
	g_Ball = 0;
	g_Out = 0;
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (answer[i] == input[j])
			{
				if (i == j)
					g_Strike++;
				else
					g_Ball++;
			}
		}
	}

	if (g_Strike == 0 && g_Ball == 0)
		g_Out = 1;
}

void Print(int *Input)
{
	static int count = 0;
	count++;
	if (g_Strike == 3)
	{
		printf("승리!(%d회 시도)\n", count);
		free(Input);
	}
	else
	{
		if (g_Out)
		{
			printf("Out!\n\n");
		}
		else
		{
			printf("%d 스트라이크, %d 볼\n\n", g_Strike, g_Ball);
		}
		free(Input);
	}
}