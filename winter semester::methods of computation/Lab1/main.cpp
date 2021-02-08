#include <iostream>
#include <ctime>
#include <cstdlib>


using namespace std;

class Matrix
{
    private:
    int rows_count;
    int columns_count;
    int **matrix;
    Matrix();

    public:
    Matrix(int rows_count, int columns_count)
	{
		this->rows_count = rows_count;
		this->columns_count = columns_count;

		matrix = new int*[rows_count];
		for (int i = 0; i < rows_count; i++)
		{

            matrix[i] = new int[rows_count];

			for(int j=0; j<columns_count;j++)
			{
                matrix[i][j] = rand()%10;
            }

		}
	}
	void setMatrixElement(int rows_count, int columns_count, int value);
	int getMatrixElement(int rows_count, int columns_count);
	void print();
	~Matrix();

};
Matrix::Matrix()
{
}
Matrix::~Matrix()
{
	delete[] matrix;
}
void Matrix::print()
{
	cout << endl;
	for (int i = 0; i < rows_count; i++)
	{
        for(int j=0; j< columns_count; j++)
        {
            cout << " " << matrix[i][j];
        }
        cout << endl;
	}
}
void Matrix::setMatrixElement(int i, int j, int value)
{
	matrix[i][j] = value;
}
int Matrix::getMatrixElement(int i, int j)
{
return matrix[i][j];
}

int main()
{
srand(time(0));
    //cout << "Please enter the quantity!" << endl;
    int value = 42;
	int rows_count = 3;
	int columns_count = 3;
	Matrix matrix(rows_count, columns_count);
	matrix.print();
	int i = 1;
	int j = 2;
    matrix.setMatrixElement(i, j, value);
	matrix.print();
	i = 2;
	j = 2;
    cout << matrix.getMatrixElement(i, j);

    return 0;
}
