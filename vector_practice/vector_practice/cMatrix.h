#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>

using std::vector;

class cMatrix
{
private:
	int dimension;
	class cRow
	{
	private:
		vector<float> row;
	public:
		cRow();
		cRow(int nDimension);
		~cRow();
		void Resize(int nDimension);
		float& operator[](int n);
		float operator*(vector<float> right);
		vector<float>::iterator begin() { return row.begin(); }
		vector<float>::iterator end() { return row.end(); }
	};
	vector<cRow> col;
public:
	cMatrix();
	cMatrix(int nDimension);
	cMatrix(const cMatrix& matrix);
	~cMatrix();

	friend std::ostream& operator<<(std::ostream& os, cMatrix& matrix);
	void Resize(int nDimension);
	int Dimension() { return dimension; }
	void setRandomData();
	void setTestData();
	static cMatrix Identity(int nDimension);
	cRow& operator[](int n);
	//===================================
	bool operator==(cMatrix& matrix);
	bool operator!=(cMatrix& matrix);
	cMatrix operator+(cMatrix& matrix);
	cMatrix operator-(cMatrix& matrix);
	cMatrix operator*(cMatrix& matrix);
	cMatrix operator*(float f);
	friend cMatrix operator*(float f, cMatrix& matrix);
	cMatrix Transpose();
	cMatrix Inverse();
	float Determinant();
	cMatrix Adjoint();
	float Cofactor(int nRow, int nCol);
	cMatrix Minor(int nRow, int nCol);
};
