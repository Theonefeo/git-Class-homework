#pragma once
#include <iostream>

using namespace std;

class Matrix
{
private:
	int rows_count;
	int columns_count;
	int *matrix;
	Matrix();
public:
	Matrix(int rows_count, int columns_count)
	{
		this->rows_count = rows_count;
		this->columns_count = columns_count;

		matrix = new int[rows_count * columns_count];
		for (int i = 0; i < rows_count * columns_count; i++)
		{
			matrix[i] = 0;
		}
	}

	Matrix(const Matrix &matrix);
	void setMatrixElement(int rows_count, int columns_count, int value);
	int getMatrixElement(int rows_count, int columns_count);
	void print();
	Matrix operator +(const Matrix &m1);
	Matrix operator -(const Matrix &m1);
	bool operator==(const Matrix &m1);
	bool operator!=(const Matrix &m1);
	void operator =(const Matrix &m1);
	~Matrix();

};
