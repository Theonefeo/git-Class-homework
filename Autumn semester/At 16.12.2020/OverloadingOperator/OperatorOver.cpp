#include <iostream>
#include "OperatorOver.h"


Matrix::Matrix()
{
}

Matrix::~Matrix()
{
	delete[] matrix;
}
Matrix::Matrix(const Matrix &m1)
{

	this->columns_count = m1.columns_count;
	this->rows_count = m1.rows_count;
	matrix = new int[rows_count * columns_count];
	for (int i = 0; i < rows_count * columns_count; i++)
	{
		matrix[i] = m1.matrix[i];
	}
}
void Matrix::print()
{
	cout << endl;
	for (int i = 0; i < rows_count * columns_count; i++)
	{
		cout << " " << matrix[i];
	}
	cout << endl;
}
Matrix Matrix::operator+(const Matrix &m1)
{
	if (rows_count == m1.rows_count && columns_count == m1.columns_count)
	{
		Matrix result;
		result.rows_count = rows_count;
		result.columns_count = columns_count;
		result.matrix = new int[rows_count * columns_count];

		for (int i = 0; i < rows_count * columns_count; i++)
		{
			result.matrix[i] = matrix[i] + m1.matrix[i];
		}
		return result;
	}
	else
	{
		cout << endl << "ERROR: return *this;" << endl;
		return *this;
	}
}
Matrix Matrix::operator-(const Matrix &m1)
{
	if (rows_count == m1.rows_count && columns_count == m1.columns_count)
	{
		Matrix result;
		result.rows_count = rows_count;
		result.columns_count = columns_count;
		result.matrix = new int[rows_count * columns_count];

		for (int i = 0; i < rows_count * columns_count; i++)
		{
			result.matrix[i] = matrix[i] - m1.matrix[i];
		}
		return result;
	}
	else
	{
		cout << endl << "ERROR: return *this;" << endl;
		return *this;
	}
}
bool Matrix::operator==(const Matrix &m1)
{
	if (rows_count != m1.rows_count || columns_count != m1.columns_count)
		return false;

	for (int i = 0; i < (rows_count * columns_count); i++)
	{
		if (matrix[i] != m1.matrix[i])
			return false;
	}
	return true;

}
bool Matrix::operator!=(const Matrix &m1)
{
	return !this->operator ==(m1);
}
void Matrix::operator =(const Matrix &m1)
{
	delete matrix;
	columns_count = m1.columns_count;
	rows_count = m1.rows_count;
	matrix = new int[rows_count * columns_count];
	for (int i = 0; i < rows_count * columns_count; i++)
	{
		matrix[i] = m1.matrix[i];
	}
}

void Matrix::setMatrixElement(int i, int j, int value)
{
	matrix[(i * (columns_count)) + j] = value;
}
int Matrix::getMatrixElement(int i, int j)
{
	return matrix[(i * (columns_count)) + j];
}
