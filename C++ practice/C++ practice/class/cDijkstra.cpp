#include "cDijkstra.h"
#include <iostream>
#include <string>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::string;

cDijkstra::~cDijkstra()
{
	delete[] field;
}

cDijkstra::cDijkstra() : field(nullptr), width(0), height(), openQ(), mapData(), visit()
{
}

void cDijkstra::inputData()
{
	cin >> height >> width;
	field = new string[height];
	for (int i = 0; i < height; ++i)
	{
		string input;
		cin >> input;
		field[i] = input;
		mapData.emplace_back();
		for (int j = 0; j < width; ++j)
		{
			mapData[i].emplace_back(j, i);
		}

		if (int k = field[i].find('S') != string::npos)
		{
			start = &mapData[i][k];
			start->dist = 0;
		}
	}
	openQ.push(*start);
}

int cDijkstra::find_route()
{
	while (!openQ.empty())
	{
		node now = openQ.top();
		openQ.pop();

		int distance = search_near(now);

		visit.push_back(now);
		//show();
		if (distance != -1)
			return distance;
	}
	return -1;
}

int cDijkstra::search_near(node& current_node)
{
	for (int i = 0; i < 4; ++i)
	{
		int tempX, tempY;
		switch (i)
		{
		case 0:
			tempX = current_node.x + 1;
			tempY = current_node.y;
			break;
		case 1:
			tempX = current_node.x;
			tempY = current_node.y + 1;
			break;
		case 2:
			tempX = current_node.x - 1;
			tempY = current_node.y;
			break;
		case 3:
			tempX = current_node.x;
			tempY = current_node.y - 1;
			break;
		default:
			tempX = -1;
			tempY = -1;
			break;
		}
		if(tempX >= 0 && tempX < width && tempY >= 0 && tempY < height)
		{
			if (field[tempY][tempX] == 'X')
				continue;
			node& target = mapData[tempY][tempX];
			if (std::find(visit.begin(), visit.end(), target) != visit.end())
				continue;
			
			if(target.dist > current_node.dist + 1)
			{
				target.dist = current_node.dist + 1;
				target.beforeX = current_node.x;
				target.beforeY = current_node.y;
				if (field[tempY][tempX] == 'F')
					return target.dist;
				openQ.push(target);
			}
		}
	}
	return -1;
}

void cDijkstra::show()
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if (mapData[i][j].dist == 9999)
				cout << "X ";
			else
				if (std::find(visit.begin(), visit.end(), mapData[i][j]) != visit.end())
					cout << "V ";
				else 
					cout << "O ";
				
		}
		cout << endl;
	}
	cout << endl;
}