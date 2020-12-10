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
        matrix = new int[rows_count*columns_count];
        for(int i=0; i<rows_count*columns_count; i++)
        {
                matrix[i]= 0;
        }
    };
    void setMatrixElement(int rows_count, int columns_count, int value);
    int getMatrixElement(int rows_count, int columns_count);
    ~Matrix() {};

};
void Matrix::setMatrixElement(int i, int j, int value)
{
    matrix[i] = value;
}
int Matrix::getMatrixElement(int i, int j)
{
    return  matrix[(i+j)/2];
}

int main()
{
    int value = 42;
    int rows_count = 3;
    int columns_count = 4;
    //int matrix[matrixSize][matrixSize];
    Matrix matrix(rows_count, columns_count);
    int i = 1;
    int j = 2;
    matrix.setMatrixElement(i, j, value);
    cout << matrix.getMatrixElement(i, j);
    /*matrix.print();
    a.get_rows_count();
    b.get_columns_count();*/
    /*В классе сделай поля double **matrix; int m; int n;
    в констукторе сделай так:
    matrix = new double*[m]; // выделяем массив из m указателей типа double
    for (int count = 0; count < n; ++count)
        matrix[count] = new double[n]; // а это наши столбцы
    В деструкторе напиши
    for (int count = 0; count < m; ++count) // удаляем каждую строку
        delete[] matrix[count];
    delete[] matrix; // это следует выполнять в конце

    m - обращение по номеру строки, n - по номеру элемента в матрице


    for(int i = 0; i < m; ++i){
   for(int j = 0; j<n; ++j){
        resultArray[i][j] = matrix1[i][j] + matrix2[i][j];
   }
}

 для вычитания двух матриц нужно

for(int i = 0; i < m; ++i){
   for(int j = 0; j<n; ++j){
        resultArray[i][j] = matrix1[i][j] - matrix2[i][j];
   }
}

 для сравнения двух матриц нужно

for(int i = 0; i < m; ++i){
   for(int j = 0; j<n; ++j){
        if( matrix1[i][j] != matrix2[i][j])
            return false;
   }
}
return true;
ы
if(obj1.m == obj2.m && obj1.n==obj2.n)
{выполнять сложение}

*/


    return 0;
}
