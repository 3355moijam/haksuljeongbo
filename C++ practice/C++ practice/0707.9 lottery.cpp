#include "stdafx.h"
#include <iterator>
#include <algorithm>
#include <random>	

vector<int> Lotto(int max, int num);

int main()
{
	vector<int> winner = Lotto(45, 6);
	for (int i = 0; i < winner.size(); i++)
	{
		cout << winner[i] << ' ';
	}
	cout << endl;
}
vector<int> Lotto(int max, int num)
{
	vector<int> answer;
	vector<int> table;
	for (int i = 1; i <= max; i++)
		table.push_back(i);

	random_device rd; 
	mt19937_64 g(rd());
	shuffle(table.begin(), table.end(), g);
	answer.assign(table.begin(), table.begin() + num);
	sort(answer.begin(), answer.end());
	
	return answer;
}
