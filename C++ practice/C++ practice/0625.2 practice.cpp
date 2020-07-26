#include "stdafx.h"
#include "class\MyPoint\MyPoint.h"

int main()
{
	MyPoint a;
	MyPoint b(10, 30.5);

	cout << a.getDistance(b) << endl;

	return 0;
}
