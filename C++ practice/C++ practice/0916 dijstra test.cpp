#include "stdafx.h"
#include "class/cDijkstra.h"

int main()
{
	cDijkstra dijk;
	dijk.inputData();
	cout << dijk.find_route() << endl;
	
	return 0;
}