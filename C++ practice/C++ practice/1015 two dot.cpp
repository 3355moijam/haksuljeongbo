#include "stdafx.h"

struct rowcol
{
	int row, col;
	rowcol() : row(0), col(0) {}
	rowcol(int row, int col) : row(row), col(col) {}
};

int solution(vector<vector<int> >& board);

int main()
{
	vector<vector<int> > board(4, vector<int>(4));
	cout << "input : ";
	scanf_s("[[%d,%d,%d,%d],[%d,%d,%d,%d],[%d,%d,%d,%d],[%d,%d,%d,%d]",
		&board[0][0], &board[0][1], &board[0][2], &board[0][3],
		&board[1][0], &board[1][1], &board[1][2], &board[1][3],
		&board[2][0], &board[2][1], &board[2][2], &board[2][3],
		&board[3][0], &board[3][1], &board[3][2], &board[3][3]
		);
	cout << "answer : " << solution(board) << endl;
	return 0;
}


int solution(vector<vector<int> >& board)
{
	int answer = -1;
	vector<rowcol> candidate;
	
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			int nNum = board[i][j];
			int nCount = 0;
		}
	}
	
	
	return answer;
}