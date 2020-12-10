#include <iostream>

using namespace std;

class Matrix
{
    public:
    int column;
    int line;
    int matrix[1][1];

    Matrix(int matrixSize){
        matrix[matrixSize][matrixSize];
        for(int i=0; i<matrixSize; i++)
        {
            for(int j=0;j<matrixSize;j++)
            {
                matrix[i][j] = 0;
            }

        }
    };
    void setMatrix(int column, int line, int value);
    //~Matrix();

};
void Matrix::setMatrix(int column, int line, int value)
{
    matrix[column][line] = value;
}


int main()
{
    int matrixSize = 4;
    Matrix matrix(matrixSize);
    int column=3;
    int line=3;
    int value = 1;
    matrix.setMatrix(column, line, value);


    return 0;
}
