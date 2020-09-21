#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>

using std::vector;

class cMatrix
{
private:
	int dimension_;
	class cRow
	{
	private:
		vector<float> row;
	public:
		cRow();
		cRow(int nDimension);
		~cRow();
		void resize(int nDimension);
		float& operator[](int n);
		float operator*(vector<float> right);
		vector<float>::iterator begin() { return row.begin(); }
		vector<float>::iterator end() { return row.end(); }
	};
	vector<cRow> rows;
public:
	cMatrix();
	cMatrix(int nDimension);
	cMatrix(const cMatrix& matrix);
	~cMatrix();

	friend std::ostream& operator<<(std::ostream& os, cMatrix& matrix);
	void resize(int nDimension);
	int dimension() { return dimension_; }
	void setRandomData();
	void setTestData();
	static cMatrix identity(int nDimension);
	cRow& operator[](int n);
	//===================================
	bool operator==(cMatrix& matrix);
	bool operator!=(cMatrix& matrix);
	cMatrix operator+(cMatrix& matrix);
	cMatrix operator-(cMatrix& matrix);
	cMatrix operator*(cMatrix& matrix);
	cMatrix operator*(float f);
	cMatrix operator/(float f);
	friend cMatrix operator*(float f, cMatrix& matrix);
	cMatrix transpose();
	cMatrix inverse(float& det);
	float determinant();
	cMatrix adjoint();
	float cofactor(int nRow, int nCol);
	cMatrix minor(int nRow, int nCol);
};
