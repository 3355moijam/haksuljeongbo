#include "stdafx.h"

int solution(vector<string> order_times, int k);
//{ "12:10", "12:20", "12:40", "12:40", "12:50", "13:00", "13:20" };
//{ "00:59","01:10" ,"01:10" ,"01:20" ,"01:21" };
//{ "12:10", "12:20", "12:40", "12:40", "12:50", "13:00", "13:05", "13:06", "13:07", "13:08", "13:20" };
int main()
{
	vector<string> order_times = { "00:59","01:10" ,"01:10" ,"01:20" ,"01:21" };
	int k = 20;
	int ans = solution(order_times, 20);
	cout << ans << endl;

	return 0;
}

int solution(vector<string> order_times, int k)
{
	int answer = 0;

	// >> split to int
	vector<int> int_order;
	for (int i = 0; i < order_times.size(); i++)
	{
		int temp = atoi(&order_times[i][0]) * 60
			+ atoi(&order_times[i][3]);
		int_order.push_back(temp);
	}

	// >> count
	int max = 0;
	for (int i = 0; i < int_order.size(); i++)
	{
		int count = 0;
		for (int j = i; j < int_order.size(); j++)
		{
			if (int_order[j] - int_order[i] > k)
				break;
			else
				count++;
		}
		cout << count << endl;
		if (count > max)
			max = count;
	}
	answer = max;
	return answer;
}