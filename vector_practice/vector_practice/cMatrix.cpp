#include "cMatrix.h"

#include <cassert>
#include <random>
using std::cout;
using std::cin;
using std::endl;
#define EPSILON 0.000001f
float operator*(const vector<float> left, const vector<float> right)
{
	assert(left.size() == right.size());
	float sum = 0;
	int length = left.size();

	for (int i = 0; i < length; ++i)
	{
		sum += left[i] * right[i];
	}
	return sum;
}
cMatrix::cRow::cRow(): row(1)
{
}

cMatrix::cRow::cRow(int nDimension): row(nDimension)
{
	row.resize(nDimension);
}

cMatrix::cRow::~cRow()
{
}

void cMatrix::cRow::Resize(int nDimension)
{
	row.resize(nDimension);
	for (auto & value : row)
	{
		value = 0;
	}
}

float& cMatrix::cRow::operator[](int n)
{
	return row[n];
}

float cMatrix::cRow::operator*(vector<float> right)
{
	return row * right;
}

cMatrix::cMatrix() : col(1), dimension(1)
{
}

cMatrix::cMatrix(int nDimension): col(), dimension(nDimension)
{
	for (int i = 0; i < nDimension; ++i)
	{
		col.emplace_back(nDimension);
	}
	col.resize(nDimension);
}

cMatrix::cMatrix(const cMatrix& matrix): col(matrix.col), dimension(matrix.dimension)
{
}

cMatrix::~cMatrix()
{
}

std::ostream& operator<<(std::ostream& os, cMatrix& matrix)
{
	for (int i = 0; i < matrix.dimension; ++i)
	{
		for (auto& row : matrix[i])
		{
			os << std::fixed;
			os.precision(3);
			os << row << "   ";
		}
		os << endl;
	}
	return os;
}

void cMatrix::Resize(int nDimension)
{
	col.resize(nDimension);
	for (auto & row : col)
	{
		row.Resize(nDimension);
	}
	dimension = nDimension;
}

void cMatrix::setRandomData()
{
	std::random_device rd;
	std::mt19937_64 gen(rd());
	//std::uniform_real_distribution<float> dis(-500, 500); // 원하는 범위의 숫자
	std::uniform_int_distribution<int> dis(-10, 10);

	for (auto & row : col)
	{
		for (auto & value : row)
		{
			value = dis(gen);
		}
	}
}

void cMatrix::setTestData()
{
	if (dimension == 2)
	{
		col[0][0] = 1;
		col[0][1] = 2;
		col[1][0] = 1;
		col[1][1] = 3;
	}
	else if (dimension == 3)
	{
		col[0][0] = 2;
		col[1][1] = 1;
		col[2][2] = 2;
		//col[3][3] = 1;
	}
}

cMatrix cMatrix::Identity(int nDimension) // 항등행렬
{
	cMatrix temp(nDimension);
	for (int i = 0; i < nDimension; ++i)
	{
		temp[i][i] = 1;
	}
	return temp;
}

cMatrix::cRow& cMatrix::operator[](int n)
{
	return col[n];
}

bool cMatrix::operator==(cMatrix& matrix)
{
	if(dimension != matrix.dimension)
		return false;

	for (int i = 0; i < dimension; ++i)
	{
		for (int j = 0; j < dimension; ++j)
		{
			if (abs(col[i][j] - matrix[i][j]) > EPSILON)
				return false;
		}
	}
	return true;
}

bool cMatrix::operator!=(cMatrix& matrix)
{
	return !(*this == matrix);
}

cMatrix cMatrix::operator+(cMatrix& matrix)
{
	cMatrix temp(dimension);
	for (int i = 0; i < dimension; ++i)
	{
		for (int j = 0; j < dimension; ++j)
		{
			temp[i][j] = col[i][j] + matrix[i][j];
		}
	}
	return temp;
}

cMatrix cMatrix::operator-(cMatrix& matrix)
{
	cMatrix temp(dimension);
	for (int i = 0; i < dimension; ++i)
	{
		for (int j = 0; j < dimension; ++j)
		{
			temp[i][j] = col[i][j] - matrix[i][j];
		}
	}
	return temp;
}

cMatrix cMatrix::operator*(cMatrix& matrix)
{
	assert(dimension == matrix.dimension);
	cMatrix temp(dimension);

	for (int i = 0; i < dimension; ++i) // i - x좌표, j - y좌표
	{
		vector<float> right_col(dimension);
		for (int j = 0; j < dimension; ++j)
		{
			right_col[j] = matrix[j][i];
		}

		for (int j = 0; j < dimension; ++j)
		{
			temp[j][i] = col[j] * right_col;
		}
	}
	
	return temp;
}

cMatrix cMatrix::operator*(float f)
{
	cMatrix temp(dimension);
	for (int i = 0; i < dimension; ++i)
	{
		for (int j = 0; j < dimension; ++j)
		{
			temp[i][j] = col[i][j] * f;
		}
	}
	return temp;
}

cMatrix operator*(float f, cMatrix& matrix)
{
	return matrix * f;
}

cMatrix cMatrix::Transpose()
{
	cMatrix temp(dimension);
	for (int i = 0; i < dimension; ++i)
	{
		for (int j = 0; j < dimension; ++j)
		{
			temp[i][j] = col[j][i];
		}
	}
	return temp;
}

cMatrix cMatrix::Inverse()
{
	float D;
	if ((D = Determinant()) == 0)
		return{};
	
	//cMatrix temp(dimension);
	return 1 / D * Adjoint();
}

float cMatrix::Determinant()
{
	if (dimension < 1)
		return 0;
	if (dimension == 1)
		return col[0][0];
	if (dimension == 2)
		return col[0][0] * col[1][1] - col[0][1] * col[1][0];

	float sum = 0;
	for (int i = 0; i < dimension; ++i)
	{
		sum += col[0][i] * Cofactor(0, i);
	}
	return sum;
}

cMatrix cMatrix::Adjoint()
{
	cMatrix temp(dimension);
	for (int i = 0; i < dimension; ++i)
	{
		for (int j = 0; j < dimension; ++j)
		{
			temp[i][j] = Cofactor(j, i);
		}
	}
	return temp;
}

float cMatrix::Cofactor(int nRow, int nCol)
{
	return pow(-1, nRow + nCol) * Minor(nRow, nCol).Determinant();
}

cMatrix cMatrix::Minor(int nRow, int nCol)
{
	cMatrix temp(dimension - 1);
	for (int j = 0, tempj = 0; j < dimension; ++j)
	{
		if (nRow == j)
			continue;
		for (int i = 0, tempi = 0; i < dimension; ++i)
		{
			if (nCol == i)
				continue;
			temp[tempj][tempi] = col[j][i];
			tempi++;
		}
		tempj++;
	}
	return temp;
}
