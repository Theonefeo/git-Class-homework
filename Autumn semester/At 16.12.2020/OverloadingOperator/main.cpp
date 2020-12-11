#include <iostream>
#include "OperatorOver.h"
using namespace std;

int main()
{
	int value = 42;
	int rows_count = 3;
	int columns_count = 4;
	Matrix matrix(rows_count, columns_count);
	matrix.print();
	int i = 1;
	int j = 2;
	matrix.setMatrixElement(i, j, value);
	cout << matrix.getMatrixElement(i, j);

	Matrix m1(matrix);
	m1.print();
	cout << endl << m1.getMatrixElement(i, j);

	matrix = matrix + m1;
	cout << endl << matrix.getMatrixElement(i, j);
	matrix = matrix - m1;
	cout << endl << matrix.getMatrixElement(i, j);

	cout << endl;
	cout << (matrix == m1) << endl;
	cout << (matrix != m1) << endl;

	return 0;
}
