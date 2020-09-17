#include "stdafx.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "cMatrix.h"

int main()
{
	//cMatrix matrix1;
	//cout << matrix1 << endl;
	//cMatrix matrix2(4);
	//cout << matrix2 << endl;

	//cout << cMatrix::Identity(4) << endl;

	//matrix2.setRandomData();
	//cout << matrix2 << endl;
	//cout << matrix2 * cMatrix::Identity(4) << endl;
	//cout << matrix2.Determinant() << endl;
	//cMatrix matrix3(matrix2.Inverse());
	//cout << matrix3 << endl;
	////cout << (matrix2 == matrix2) << endl;
	//cout << matrix2 * matrix3 << endl;
	//cout << (cMatrix::Identity(4) == matrix2 * matrix3) << endl;

	cMatrix m1(5);
	//m1.setTestData();
	m1.setRandomData();
	cout << m1.Determinant() << endl;
	cout << m1 << endl;
	cMatrix m2(m1.Inverse());
	cout << m2 << endl;
	cout << m2 * m1 << endl;
	m2.Resize(10);
	cout << m2 << endl;
	return 0;
}
