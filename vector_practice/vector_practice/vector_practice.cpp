// vector_practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "cVector3.h"

int main()
{
	//ºñ±³
	//µ¡¼À
	//³»Àû
	//¿ÜÀû
	//

	float x1, y1, z1;
	float x2, y2, z2;

	cout << "v1 »ý¼º. ¼ýÀÚ ¼¼°³ ÀÔ·Â : ";
	cin >> x1 >> y1 >> z1;
	cVector3 v1(x1, y1, z1);


	cout << "v2 »ý¼º. ¼ýÀÚ ¼¼°³ ÀÔ·Â : ";
	cin >> x2 >> y2 >> z2;
	cVector3 v2(x2, y2, z2);

	cout << "ºñ±³" << endl;
	cout << "v1 == v2 : " << (v1 == v2) << endl;
	cout << "v1 != v2 : " << (v1 != v2) << endl;
	cout << endl;

	cout << "µ¡¼À" << endl;
	cout << "v1 + v2 : " << (v1 + v2) << endl;
	cout << "»¬¼À" << endl;
	cout << "v1 - v2 : " << (v1 - v2) << endl;
	cout << "°ö¼À" << endl;
	cout << "v1 * 5 : " << (v1 * 5) << endl;
	cout << "³ª´°¼À" << endl;
	cout << "v1 / 5 : " << (v1 / 5) << endl;
	cout << endl;

	cout << "³»Àû" << endl;
	cout << "v1 dot v2 : " << cVector3::Dot(v1, v2) << endl;
	cout << endl;
	
	cout << "¿ÜÀû" << endl;
	cout << "v1 cross v2 : " << cVector3::Cross(v1, v2) << endl;
	cout << "v2 cross v1 : " << cVector3::Cross(v2, v1) << endl;
	cout << endl;

	
	
    return 0;
}

