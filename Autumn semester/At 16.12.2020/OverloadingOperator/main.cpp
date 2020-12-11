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
                matrix[i]= 0; /*3x4 -> элементов не 12 как может показать,
                а: 0...3 х 0....4 или 4х5 = 20 - столько элементов в массивe*/
        }
    };
    void setMatrixElement(int rows_count, int columns_count, int value);
    int getMatrixElement(int rows_count, int columns_count);
    ~Matrix() {};

};
void Matrix::setMatrixElement(int i, int j, int value)
{
    matrix[(i*(j+1))+j] = value; /*Если мы хотим получить в массиве двумерном число по коор-там 1х2 то это будет
    элемент 6 в матрице т.к отсчет компилятор ведет от 0 (0..1 - 2 эл. 0...2 - 3 элемента - следовательно 2х3 = 6)
    потому по такой формуле мы получим индекс одномерного массива - 5 - поскольку компилятор считает от 0.....5 = 6 следовательно
    значение будет по человеческим меркам лежать в 6 элементов а по меркам компилятора - в 5 */
}
int Matrix::getMatrixElement(int i, int j)
{
    return  matrix[(i*(j+1))+j];
}

int main()
{
    int value = 42;
    int rows_count = 3;
    int columns_count = 4;
    Matrix matrix(rows_count, columns_count);
    int i = 3;
    int j = 4;
    matrix.setMatrixElement(i, j, value);
    cout << matrix.getMatrixElement(i, j);

    return 0;
}
