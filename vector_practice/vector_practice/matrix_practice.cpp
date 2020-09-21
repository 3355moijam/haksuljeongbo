#include "stdafx.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "cMatrix.h"

int main()
{
	//cout << "몇차 행렬? : ";
	//int nDimension;
	//cin >> nDimension;

	//cMatrix mat1(nDimension);
	//mat1 = cMatrix::identity(nDimension);

	//for (int row = 0; row < nDimension; ++row)
	//{
	//	for (int col = 0; col < nDimension; ++col)
	//	{
	//		printf("[ %d, %d ] : ", row + 1, col + 1);
	//		cin >> mat1[row][col];
	//	}
	//}

	//cout << "초기행렬 : " << endl;
	//cout << mat1 << endl << endl;

	//cout << "행렬식 : " << endl;
	//cout << mat1.determinant() << endl << endl;

	//cout << "Adjoint : " << endl;
	//cout << mat1.adjoint() << endl << endl;

	//float fDet;
	//cMatrix matInv = mat1.inverse(fDet);
	//cout << "역행렬 : " << endl;
	//cout << matInv << endl << endl;

	//cout << "역행렬 체크" << endl;
	//cout << (mat1 * matInv) << endl;
	//

	cMatrix mat2(5);
	mat2.setRandomData();
	cout << mat2 << endl;
	mat2.resize(2);
	cout << mat2 << endl;

	return 0;
}
