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

void cMatrix::cRow::resize(int nDimension)
{
	row.clear();
	row.resize(nDimension);
	//for (auto & value : row)
	//{
	//	value = 0;
	//}
}

float& cMatrix::cRow::operator[](int n)
{
	return row[n];
}

float cMatrix::cRow::operator*(vector<float> right)
{
	return row * right;
}

cMatrix::cMatrix() : rows(1), dimension_(1)
{
}

cMatrix::cMatrix(int nDimension): rows(), dimension_(nDimension)
{
	for (int i = 0; i < nDimension; ++i)
	{
		rows.emplace_back(nDimension);
	}
	rows.resize(nDimension);
}

cMatrix::cMatrix(const cMatrix& matrix): rows(matrix.rows), dimension_(matrix.dimension_)
{
}

cMatrix::~cMatrix()
{
}

std::ostream& operator<<(std::ostream& os, cMatrix& matrix)
{
	for (int i = 0; i < matrix.dimension_; ++i)
	{
		for (auto& row : matrix[i])
		{
			if (abs(row) <= EPSILON)
				os << "  0   ";
			else if (abs(row - 1) <= EPSILON)
				os << "  1   ";
			else
				os << "  " << row << "   ";
		}
		os << endl;
	}
	return os;
}

void cMatrix::resize(int nDimension)
{
	rows.resize(nDimension);
	for (auto & row : rows)
	{
		row.resize(nDimension);
	}
	dimension_ = nDimension;
}

void cMatrix::setRandomData()
{
	std::random_device rd;
	std::mt19937_64 gen(rd());
	//std::uniform_real_distribution<float> dis(-500, 500); // 원하는 범위의 숫자
	std::uniform_int_distribution<int> dis(-10, 10);

	for (auto & row : rows)
	{
		for (auto & value : row)
		{
			value = dis(gen);
		}
	}
}

void cMatrix::setTestData()
{
	if (dimension_ == 2)
	{
		rows[0][0] = 1;
		rows[0][1] = 2;
		rows[1][0] = 1;
		rows[1][1] = 3;
	}
	else if (dimension_ == 3)
	{
		rows[0][0] = 2;
		rows[1][1] = 1;
		rows[2][2] = 2;
		//rows[3][3] = 1;
	}
}

cMatrix cMatrix::identity(int nDimension) // 항등행렬
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
	return rows[n];
}

bool cMatrix::operator==(cMatrix& matrix)
{
	if(dimension_ != matrix.dimension_)
		return false;

	for (int i = 0; i < dimension_; ++i)
	{
		for (int j = 0; j < dimension_; ++j)
		{
			if (abs(rows[i][j] - matrix[i][j]) > EPSILON)
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
	cMatrix temp(dimension_);
	for (int i = 0; i < dimension_; ++i)
	{
		for (int j = 0; j < dimension_; ++j)
		{
			temp[i][j] = rows[i][j] + matrix[i][j];
		}
	}
	return temp;
}

cMatrix cMatrix::operator-(cMatrix& matrix)
{
	cMatrix temp(dimension_);
	for (int i = 0; i < dimension_; ++i)
	{
		for (int j = 0; j < dimension_; ++j)
		{
			temp[i][j] = rows[i][j] - matrix[i][j];
		}
	}
	return temp;
}

cMatrix cMatrix::operator*(cMatrix& matrix)
{
	assert(dimension_ == matrix.dimension_);
	cMatrix temp(dimension_);

	for (int i = 0; i < dimension_; ++i) // i - x좌표, j - y좌표
	{
		vector<float> right_col(dimension_);
		for (int j = 0; j < dimension_; ++j)
		{
			right_col[j] = matrix[j][i];
		}

		for (int j = 0; j < dimension_; ++j)
		{
			temp[j][i] = rows[j] * right_col;
		}
	}
	
	return temp;
}

cMatrix cMatrix::operator*(float f)
{
	cMatrix temp(dimension_);
	for (int i = 0; i < dimension_; ++i)
	{
		for (int j = 0; j < dimension_; ++j)
		{
			temp[i][j] = rows[i][j] * f;
		}
	}
	return temp;
}

cMatrix cMatrix::operator/(float f)
{
	float M_1_f = 1 / f;
	return *this * M_1_f;
}

cMatrix operator*(float f, cMatrix& matrix)
{
	return matrix * f;
}

cMatrix cMatrix::transpose()
{
	cMatrix temp(dimension_);
	for (int i = 0; i < dimension_; ++i)
	{
		for (int j = 0; j < dimension_; ++j)
		{
			temp[i][j] = rows[j][i];
		}
	}
	return temp;
}

cMatrix cMatrix::inverse(OUT float & det)
{
	det = determinant();
	if (abs(det) <= EPSILON)
	{
		cout << "역행렬이 존재하지 않음\n";
		return{};
	}
	
	//cMatrix temp(dimension_);
	return adjoint() / det;
}

float cMatrix::determinant()
{
	if (dimension_ < 1)
		return 0;
	if (dimension_ == 1)
		return rows[0][0];
	if (dimension_ == 2)
		return rows[0][0] * rows[1][1] - rows[0][1] * rows[1][0];

	float sum = 0;
	for (int i = 0; i < dimension_; ++i)
	{
		sum += rows[0][i] * cofactor(0, i);
	}
	return sum;
}

cMatrix cMatrix::adjoint()
{
	cMatrix temp(dimension_);
	for (int i = 0; i < dimension_; ++i)
	{
		for (int j = 0; j < dimension_; ++j)
		{
			temp[i][j] = cofactor(j, i);
		}
	}
	return temp;
}

float cMatrix::cofactor(int nRow, int nCol)
{
	return pow(-1, nRow +  nCol) * minor(nRow, nCol).determinant();
}

cMatrix cMatrix::minor(int nRow, int nCol)
{
	cMatrix temp(dimension_ - 1);
	for (int j = 0, tempj = 0; j < dimension_; ++j)
	{
		if (nRow == j)
			continue;
		for (int i = 0, tempi = 0; i < dimension_; ++i)
		{
			if (nCol == i)
				continue;
			temp[tempj][tempi] = rows[j][i];
			tempi++;
		}
		tempj++;
	}
	return temp;
}


