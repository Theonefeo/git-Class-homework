#include <iostream>

using namespace std;

class Matrix
{
private:
    int rows_count;
    int columns_count;
    int *matrix;

public:
    Matrix(int rows_count, int columns_count)
    {
        this->rows_count = rows_count;
        this->columns_count = columns_count;

        matrix = new int[rows_count*columns_count];
        for(int i=0; i<rows_count*columns_count; i++)
        {
            matrix[i]= 0;
        }
    };
    Matrix(const Matrix &matrix);
    void setMatrixElement(int rows_count, int columns_count, int value);
    int getMatrixElement(int rows_count, int columns_count);
    void print();
    void operator +(const Matrix &m1);
    void operator -(const Matrix &m1);
    bool operator==(const Matrix &m1);
    bool operator!=(const Matrix &m1);
    ~Matrix();

};
Matrix::~Matrix()
{
    delete[] matrix;
}
Matrix::Matrix(const Matrix &m1)
{

    this->columns_count = m1.columns_count;
    this->rows_count = m1.rows_count;
    matrix = new int[rows_count*columns_count];
    for(int i = 0; i<rows_count*columns_count; i++)
    {
        matrix[i] = m1.matrix[i];
    }
}
void Matrix::print()
{
    cout<<endl;
    for(int i = 0; i<rows_count*columns_count; i++)
    {
        cout<<" "<<matrix[i];
    }
    cout<<endl;
}
void Matrix::operator+(const Matrix &m1)
{
    if(rows_count == m1.rows_count && columns_count == m1.columns_count)
    {
        for(int i = 0; i<(rows_count*columns_count); i++)
        {
            matrix[i] = matrix[i] + m1.matrix[i];
        }
    }
    else
        cout<<endl<<"ERROR"<<endl;
}
void Matrix::operator-(const Matrix &m1)
{
    if(rows_count == m1.rows_count && columns_count == m1.columns_count)
    {
        for(int i = 0; i<(rows_count*columns_count); i++)
        {
            matrix[i] = matrix[i] - m1.matrix[i];
        }
    }
}
bool Matrix::operator==(const Matrix &m1)
{
    if(rows_count == m1.rows_count && columns_count == m1.columns_count)
    {
        for(int i = 0; i<(rows_count*columns_count); i++)
        {
            matrix[i] == m1.matrix[i];
        }
        return true;
    }
    else
        return false;
}
bool Matrix::operator!=(const Matrix &m1)
{
    if(rows_count == m1.rows_count && columns_count == m1.columns_count)
    {
        for(int i = 0; i<(rows_count*columns_count); i++)
        {
            matrix[i] != m1.matrix[i];
        }
        return true;
    }
    else
        return false;
}
void Matrix::setMatrixElement(int i, int j, int value)
{
    matrix[(i*(columns_count))+j] = value;
}
int Matrix::getMatrixElement(int i, int j)
{
    return  matrix[(i*(columns_count))+j];
}

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
    cout << endl<<m1.getMatrixElement(i, j);

    matrix+(m1);
    cout <<endl<< matrix.getMatrixElement(i, j);
    matrix-(m1);
    cout <<endl<< matrix.getMatrixElement(i, j);
    matrix==(m1);
    matrix!=(m1);




    return 0;
}
