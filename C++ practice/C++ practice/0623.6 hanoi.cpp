#include "stdafx.h"
#include "IntStack.h"

int hanoi(int count, int from, int to);
string alpha[3] = { "A", "B", "C" };
IntStack A;
IntStack B;
IntStack C;
IntStack *arrStk[3] = { &A, &B, &C };
void PrintStack(void);
int input;

int main()
{
	cout << "탑의 높이 : ";
	cin >> input;

	Initialize(&A, input);
	Initialize(&B, input);
	Initialize(&C, input);
	
	for (int i = input; i > 0 ; i--)
	{
		Push(arrStk[0], i);
	}

	hanoi(input, 0, 2);

	Terminate(&A);
	Terminate(&B);
	Terminate(&C);

	return 0;
}


int hanoi(int count, int from, int to)
{
	int bridge = 3 - from - to;
	int temp;
	if (count == 1)
	{
		cout << count << "를 " << alpha[from] << "에서 " << alpha[to] << "로 이동" << endl;

		Pop(arrStk[from], &temp);
		Push(arrStk[to], temp);
		PrintStack();
		return 1;
	}
	else
	{
		int k = hanoi(count - 1, from, bridge);
		cout << count << "를 " << alpha[from] << "에서 " << alpha[to] << "로 이동" << endl;

		Pop(arrStk[from], &temp);
		Push(arrStk[to], temp);
		PrintStack();
		int j = hanoi(count - 1, bridge, to);
		return  k + j + 1;
	}
}

void PrintStack(void)
{
	for (int i = input-1; i >= 0; i--)
	{
		if (i < Size(arrStk[0]))
			cout << arrStk[0]->stk[i];
		cout << '\t';
		if (i < Size(arrStk[1]))
			cout << arrStk[1]->stk[i];
		cout << '\t';
		if (i < Size(arrStk[2]))
			cout << arrStk[2]->stk[i];
		cout << '\t';
		cout << endl;
	}
	cout << endl;
}