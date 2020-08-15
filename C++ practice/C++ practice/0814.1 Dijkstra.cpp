#include "stdafx.h"
#include <vector>
using std::vector;

#define NUM_NODE 8
#define I 9999
int arrEdgeCost[NUM_NODE][NUM_NODE] =
{
	{ 0,2,I,I,I,3,I,I },
	{ 2,0,4,1,I,I,I,I },
	{ I,4,0,I,3,I,I,I },
	{ I,1,I,0,3,I,2,I },
	{ I,I,3,3,0,I,I,4 },
	{ 3,I,I,I,I,0,1,I },
	{ I,I,I,2,I,1,0,4 },
	{ I,I,I,I,4,I,4,0 }
};
int arrEdgeCost2[NUM_NODE][NUM_NODE] =
{
	{ 0,1,1,I,I,I,I,I },
	{ 1,0,I,2,I,I,I,I },
	{ 1,I,0,I,2,I,I,I },
	{ I,2,I,0,I,1,I,I },
	{ I,I,2,I,0,I,1,I },
	{ I,I,I,1,I,0,I,2 },
	{ I,I,I,I,1,I,0,1 },
	{ I,I,I,I,I,2,1,0 }
};
vector<int> path;
int Dijkstra(int start, int end);
void printPath();
int main()
{
	int startNode;
	cout << "시작 노드 : ";
	cin >> startNode;
	cin.ignore();
	startNode--;

	int endNode;
	cout << "도착 노드 : ";
	cin >> endNode;
	cin.ignore();
	endNode--;


	cout << "최단 거리 : " << Dijkstra(startNode, endNode) << endl;
	cout << "최단 경로 : ";
	printPath();
	return 0;
}

int Dijkstra(int start, int end)
{
	bool visitNode[NUM_NODE] = { false };
	visitNode[start] = true;
	int CurrentEdgeCost[NUM_NODE];
	int BeforeNode[NUM_NODE] = { start };
	memcpy(CurrentEdgeCost, arrEdgeCost[start], sizeof(int) * NUM_NODE);
	for(int i = 0; i < NUM_NODE - 1; i++)
	{
		int min = I;
		int	minNode;
		for (int j = 0; j < NUM_NODE; j++)
		{
			if (visitNode[j])
				continue;
			else
			{
				if (min > CurrentEdgeCost[j])
				{
					min = CurrentEdgeCost[j];
					minNode = j;
				}
			}
		}
		visitNode[minNode] = true;

		for (int j = 0; j < NUM_NODE; j++)
		{
			if (visitNode[j])
				continue;
			else
			{
				int temp = min + arrEdgeCost[minNode][j];
				CurrentEdgeCost[j] = CurrentEdgeCost[j] < temp ? CurrentEdgeCost[j] : temp;
				if (CurrentEdgeCost[j] == temp)
				{
					BeforeNode[j] = minNode;
				}

			}
		}
		


		
		if (int curPathSize = CurrentEdgeCost[end] < I)
		{
			bool isSmallest = true;
			for (int j = 0; j < NUM_NODE; j++)
			{
				if (visitNode[j])
					continue;
				else
				{
					if (CurrentEdgeCost[j] < curPathSize)
						isSmallest = false;
				}
			}
			if (isSmallest)
				break;
		}
		
	}

	path.push_back(end);
	int temp = BeforeNode[end];
	while (true)
	{
		if (temp == start)
			break;

		path.push_back(temp);
		temp = BeforeNode[temp];
	}
	path.push_back(start);

	return CurrentEdgeCost[end];

}

void printPath()
{
	int length = path.size();
	while(path.size())
	{
		cout << path.back() + 1;
		path.pop_back();
		if (path.size())
			cout << " - ";
	}
	cout << endl;
}