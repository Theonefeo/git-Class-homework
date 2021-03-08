#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#define DWR cout<<"!!!"<<endl;  /// Вставляйте слово DWR в код - это будет точка отладочного вывода.

using namespace std;

class Matrix
{
    private:
    int rows_count;
    int columns_count;
    double **matrix;

    public:
    Matrix(int rows_count, int columns_count)
	{
		this->rows_count = rows_count;
		this->columns_count = columns_count;

		matrix = new double*[rows_count];
		for (int i = 0; i < rows_count; i++)/// может rows_count? - это решает Вашу проблему, но появляется Segmentation fault (уже лучше - эта ошибка традиционнее).
		{

            matrix[i] = new double[columns_count];

			for(int j=0; j<columns_count;j++)
			{
                matrix[i][j] = rand()%10;
            }

		}
     //cout<<matrix<<" "<<*((long*)(((char*)matrix)-8))<<"Konst\n";
	}
	void setMatrixElement(int rows_count, int columns_count, float value);
	double getMatrixElement(int rows_count, int columns_count);
	void print();
	int getRows_Count() {
	return rows_count;
	}

	int minColumnsRowsCount();

	int getColumns_Count() {
	return columns_count;
	}
	~Matrix();

};
Matrix::~Matrix()
{
    //cout<<matrix<<" "<<*((long*)(((char*)matrix)-8))<<"Destr\n";
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
void Matrix::setMatrixElement(int i, int j, float value)
{
	matrix[i][j] = value;
}
double Matrix::getMatrixElement(int i, int j)
{
return matrix[i][j];
}

int Matrix::minColumnsRowsCount()
{
    if(rows_count>columns_count)
        return columns_count;
    else
        return rows_count;
}
void MethodGausa(Matrix &matrix)
{
    for(int i=0;i<matrix.minColumnsRowsCount(); i++)//ВЫБИРАЕМ МИНИМУМ; i++ /// Почему getColumns_Count(), а не min(col_count, row_count)?
    {

        int j,m,n,N = 0;
        int x = i;
        //Нахождение наибольшего элемента в колонке
        for(j=i+1; j<matrix.getRows_Count(); j++) /// почему с 1-й строки каждый раз ищем? надо с i+1.
        {
            if(matrix.getMatrixElement(j /*- номер строки  */ , i /*- номер столбца*/ )>matrix.getMatrixElement(x, i)) /// эм, а почему это j задаёт номер колонки - колонку то мы рассматриваем одну (i-ю). А вот строки меняются.
                x = j; //запоминаем номер строки с гланым элементом
        }
         /// n=j ?????? n = matrix.getRows_Count()+1, а это за границами массива!
        double MatrixElement;
        //Смена строчек(если нашли наибольшую то смеянем ее с первой строкой)
        for(j = 0; j<matrix.getColumns_Count() - 1; j++) // j перебирает колонки :)
        {
            MatrixElement = matrix.getMatrixElement(x /*- номер строки*/, j);
            matrix.setMatrixElement(x, j,  matrix.getMatrixElement(i, j));
            matrix.setMatrixElement(i,j, MatrixElement);
        }
        //Делим строку с наибольшим главным элементом
        int a;
        int c;
        for(j = 0; j<matrix.getColumns_Count(); j++)
        {
            /// j это номер строки, а не столбца - см. условие выхода из цикла.
                a = matrix.getMatrixElement(i, j);
                c = matrix.getMatrixElement(i, i);
                matrix.setMatrixElement(i, j, a/c);
        }
        //приведение всей колонки к нулю кроме главного элемента (чтобы были нулевые элемнты под главным)
        int b;
        int d;
        for(int ii = i+1; ii <matrix.getRows_Count(); ii++) /// Почему начинаете с первой строки, а не с i+1?
        {
            double koef = matrix.getMatrixElement(ii,i); //ii - номер строки, i - номер столбца.

/*
    Идем по строкам находясь на одном столбце при этом счетчик - до конца строчек для того чтобы не выйти за границы
*/
            for(j = 0; j<matrix.getRows_Count(); j++)
            {

                d = matrix.getMatrixElement(ii,j) - matrix.getMatrixElement(i,j)*koef;
                matrix.setMatrixElement(ii, j, d);
            }
        }

        /////////////
        /*SmenaStrok(matrix.getRows_Count());
        for(int j = 0; j<minColumnsRowsCount(); j++) //Идем по столбцам
        {
            SmenaStrok(matrix.getColumns_Count());
            void SmenaStrok(int Count)
            {
                for(int ii = i+1; ii <Count; ii++) /// Почему начинаете с первой строки, а не с i+1?
                {
                    double koef = matrix.getMatrixElement(ii,i); //ii - номер строки, i - номер столбца.


            Идем по строкам находясь на одном столбце при этом счетчик - до конца строчек для того чтобы не выйти за границы

                    for(j = 0; j<matrix.getRows_Count(); j++)
                    {

                        d = matrix.getMatrixElement(ii,j) - matrix.getMatrixElement(i,j)*koef;
                        matrix.setMatrixElement(ii, j, d);
                    }
                }


            }
        }*/
        //////////

    }
}

int main()
{

srand(time(0));
    //cout << "Please enter the quantity!" << endl;
    float value = 42;
	int rows_count = 10;
	int columns_count = 10;
	Matrix matrix(rows_count, columns_count);
	matrix.print();
	for (int i = 0; i < rows_count; i++)
	{
        for(int j = 0; j< columns_count; j++)
        {
            if(i==j)
            {
                value=6;
                matrix.setMatrixElement(i, j, value);
            }
            else if(abs(i-j)==1)
            {
                value=2*sin(2*i+3*j);
                matrix.setMatrixElement(i, j, value);
            }
            else if(abs(i-j)==2)
            {
                value=sin(5*i+8*j);
                matrix.setMatrixElement(i, j, value);
            }
            else if(abs(i-j)>2)
            {
                value=0;
                matrix.setMatrixElement(i, j, value);
            }
        }
        cout << endl;
	}
    //matrix.setMatrixElement(i, j, value);

    matrix.print();
	//matrix.print();
	//i = 2;
	//j = 2;
    //cout << matrix.getMatrixElement(i, j);
    MethodGausa(matrix);
    matrix.print();



    return 0;
}

/*Здесь действительно есть где запутаться. Вот список правильных утверждений для самопроверки:
* Переменная AAA, которая бегает от 0 до rows_count - это номер строки. Это первый индекс  matrix[AAA][_]
* Переменная BBB которая бегает от 0 до columns_count - это номер столбца. Это второй индекс матрицы matrix[_][BBB]
* в строке columns_count элементов (да!)
* в столбце rows_count элементов.*/
