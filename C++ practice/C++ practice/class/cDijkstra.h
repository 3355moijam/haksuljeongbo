#pragma once
#include <functional>
#include <queue>
using std::priority_queue;
using std::vector;
using std::string;
class node;
class cDijkstra
{
private:
	string* field;
	int width;
	int height;
	priority_queue<node, vector<node>, std::greater<>> openQ;
	vector<vector<node>> mapData;
	vector<node> visit;
	node* start;

public:
	~cDijkstra();
	cDijkstra();
	void inputData();
	int find_route();
	int search_near(node& current_node);
	void show();
};



class node
{
public:
	int x;
	int y;
	int dist;
	int beforeX;
	int beforeY;

	node() : x(-1), y(-1), beforeX(-1), beforeY(-1), dist(9999) {}
	node(int x, int y) : x(x), y(y), beforeX(-1), beforeY(-1), dist(9999) {}
	bool operator<(const node& tar) const { return dist < tar.dist; }
	bool operator>(const node& tar) const { return dist > tar.dist; }
	bool operator==(const node& tar) const { return (x == tar.x) && (y == tar.y); }
};

