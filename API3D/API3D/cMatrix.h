#pragma once
#include "stdafx.h"

#include "cVector3.h"


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
	void putVectorInCol(int index, cVector3& vector3, float w = 0);
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
	
	static cMatrix scale(float degree);
	static cMatrix rotationX(float Angle);
	static cMatrix rotationY(float Angle);
	static cMatrix rotationZ(float Angle);
	static cMatrix translation(float x, float y, float z);
	static cMatrix translation(cVector3& v);
	static cMatrix view(cVector3& vEye, cVector3& vLookAt, cVector3& vUp = cVector3(0,1,0, 0));
	static cMatrix projection(float fFovY, float fAspect, float fNearZ, float fFarZ);
	static cMatrix viewport(float x, float y, float w, float h, float minZ = 0, float maxZ = 1);
	
};
