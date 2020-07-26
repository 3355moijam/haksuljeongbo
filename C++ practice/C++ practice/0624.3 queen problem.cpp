#include "stdafx.h"

void printChessBoard(const array<array<short, 8>, 8> & board);
void setQueen(int x, array<array<short, 8>, 8> & board);
void setBoard(int x, int y, array<array<short, 8>, 8> & board);

int main()
{
	array<array<short, 8>, 8> board = {};
	setQueen(0, board);
	return 0;
}
void setQueen(int y, array<array<short, 8>, 8> & board)
{
	if (y > 7)
	{
		static int count = 0;
		count++;
		cout << "°æ¿ì " << count << endl;
		printChessBoard(board);
		return;
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			if (board[i][y] == 0)
			{
				array<array<short, 8>, 8> temp = board;
				setBoard(i, y, temp);
				setQueen(y + 1, temp);
			}
		}
		return;
	}
}

void setBoard(int x, int y, array<array<short, 8>, 8> & board)
{
	board[x].fill(1);
	board[x][y] = 2;
	for (int i = 1; i < 8; i++)
	{
		if (x - i >= 0)
		{
			board[x - i][y] = 1;
			if(y + i < 8)
				board[x - i][y+i] = 1;
		}
		if (x + i < 8)
		{
			board[x + i][y] = 1;
			if(y + i < 8)
				board[x + i][y + i] = 1;
		}
		if (x + i >= 8 && x - i < 0)
			break;
	}
}


void printChessBoard(const array<array<short, 8>, 8> & board)
{
	for (int i = 0; i < 8; i++)
	{
		cout << "-------------------------" << endl;
		for (int j = 0; j < 8; j++)
		{
			cout << "|";
			if (board[i][j] == 0 || board[i][j] == 1)
				cout << "  ";
			else
				cout << "v ";
		}
		cout << "|" << endl;
	}
	cout << "-------------------------" << endl;
}