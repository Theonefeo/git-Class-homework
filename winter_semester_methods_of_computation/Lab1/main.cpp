#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <vector>
#define DWR cout<<"!!!"<<endl;  /// Вставляйте слово DWR в код - это будет точка отладочного вывода.

using namespace std;

class Matrix
{
    private:
    int rows_count;
    int columns_count;
    double **matrix;
    Matrix(const Matrix &matrix) {}; //Конструктор копирования сделан приватным чтобы при передаче матрицы в функции не копировалась матрица старая в новую полностью (поскольку далее выпадает ошибка), но передается в функции ссылка на нее, чтобы работать с этой матрицей а не с ее копированной копией


    public:
    Matrix(int rows_count, int columns_count)
	{
		this->rows_count = rows_count;
		this->columns_count = columns_count;

		matrix = new double*[rows_count];
		for (int i = 0; i < rows_count; i++)/// может rows_count? - это решает Вашу проблему, но появляется Segmentation fault (уже лучше - эта ошибка традиционнее).
		{

            matrix[i] = new double[columns_count];

            int j=0;
			for(int j=0; j<columns_count;j++)
			{

                matrix[i][j] = rand()%10;
//                cin>>matrix[i][j];
            }
        }
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
if(0<=i && i<rows_count && 0<=j && j<columns_count)
	matrix[i][j] = value;
else
cout<<"errorSET";

}
double Matrix::getMatrixElement(int i, int j)
{
if(0<=i && i<rows_count && 0<=j && j<columns_count)
return matrix[i][j];
else
cout<<"errorGET";
}

int Matrix::minColumnsRowsCount()
{
    if(rows_count>columns_count)
        return columns_count;
    else
        return rows_count;
}
double* MethodGausa(Matrix &matrix)
{
    for(int i=0;i<matrix.minColumnsRowsCount(); i++)//ВЫБИРАЕМ МИНИМУМ; i++ /// Почему getColumns_Count(), а не min(col_count, row_count)?
    {

        int j,m,n,N = 0;
        int x = i;
        //Нахождение наибольшего элемента в колонке
        for(j=i+1; j<matrix.getRows_Count(); j++) /// почему с 1-й строки каждый раз ищем? надо с i+1.
        {
            if(matrix.getMatrixElement(j /*- номер строки  */ , i /*- номер столбца*/ )>matrix.getMatrixElement(x, i))
                x = j; //запоминаем номер строки с гланым элементом
        }
        cout<<"Main element in columns \n";
        cout<<matrix.getMatrixElement(i,j)<<endl;
        matrix.print();

        double MatrixElement;
        //Смена строчек(если нашли наибольшую то смеянем ее с первой строкой)
        for(j = 0; j<matrix.getColumns_Count(); j++) // j перебирает колонки :)
        {
            MatrixElement = matrix.getMatrixElement(x /*- номер строки*/, j);
            matrix.setMatrixElement(x, j,  matrix.getMatrixElement(i, j));
            matrix.setMatrixElement(i,j, MatrixElement);
        }
        cout<<"Changing lines \n";
        matrix.print();
        //Делим строку с наибольшим главным элементом
        double a;
        double c;
        c = matrix.getMatrixElement(i, i);
        for(j = 0; j<matrix.getColumns_Count(); j++)
        {
                a = matrix.getMatrixElement(i, j);

                //cout<<"!!!!!!!!!!!!"<<i<<" "<<j<<" "<<a<<" "<<c<<" "<<a/c<<" "<<endl;
                matrix.setMatrixElement(i, j, a/c);
        }
        cout<<"Dividing the row with the largest main element ";
        matrix.print();
        //приведение всей колонки к нулю кроме главного элемента (чтобы были нулевые элемнты под главным)
        double d;
        for(int ii = i+1; ii <matrix.getRows_Count(); ii++) /// Почему начинаете с первой строки, а не с i+1?
        {
            double koef = matrix.getMatrixElement(ii,i); //ii - номер строки, i - номер столбца.

/*
    Идем по строкам находясь на одном столбце при этом счетчик - до конца строчек для того чтобы не выйти за границы
*/
            for(j = 0; j<matrix.getColumns_Count(); j++)
            {

                d = matrix.getMatrixElement(ii,j) - matrix.getMatrixElement(i,j)*koef;
                matrix.setMatrixElement(ii, j, d);
                cout<<"String Conversion \n";
                cout<<matrix.getMatrixElement(ii, j);

            }
            matrix.print();
        }
        cout<<"Reducing the entire column to zero except for the main element \n";
        matrix.print();

    }
    matrix.print();

        for(int jj = matrix.minColumnsRowsCount() - 1; jj!=0; jj--)
        {
            float kf;

            float b; //свободные члены
            for(int dd = jj -1; dd>=0; dd--)
            {
                kf = matrix.getMatrixElement(dd, jj);
                matrix.setMatrixElement(dd, jj, 0);

                b = matrix.getMatrixElement(dd, matrix.getColumns_Count()-1) - matrix.getMatrixElement(jj, matrix.getColumns_Count()-1)*kf; //Закрепляемся с помощью jj на столбце и c помощью dd бегаем по строкам

                matrix.setMatrixElement(dd, matrix.getColumns_Count() -1 , b);
            }

        }
        cout<<"Reverse Gauss stroke \n";
        matrix.print();
}
void Formula(Matrix &matrix, int rows_count, int columns_count, float value)
{
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

}
vector<double> GetLastColumn(Matrix &matrix)
{
    vector<double> p;
    for(int i=0; i<matrix.minColumnsRowsCount(); i++)
    {
        p.push_back(matrix.getMatrixElement(i, matrix.getColumns_Count() - 1));
    }

    return p;

}
vector<double> MultMatrixVector(Matrix &matrix, vector<double> solution)
{
        vector<double> pp;
        double sum, sum1 = 0;

        for(int i=0; i<matrix.getRows_Count() - 1; i++) //we stand on the column of the matrix
        {

            for(int j=0; j<solution.size(); j++) //we go through the rows and sum their multiplication by a vector
            {
                sum1 = matrix.getMatrixElement(i, j) * solution.at(j);
                sum = sum + sum1;

            }

            pp.push_back(sum);
            sum = 0;
        }
        return pp;

}
bool CompareWithLastColumn(Matrix &matrix, vector<double> Y2, double eps)
{
    bool flag = true;
    matrix.print();
    for(int i=0; i<Y2.size(); i++)
    {
        if(abs(matrix.getMatrixElement(i, matrix.getColumns_Count() - 1)-Y2.at(i)) < eps)
        {
            cout<<"ok " << matrix.getMatrixElement(i, matrix.getColumns_Count() - 1)<<endl;
        }
        else
        {
         cout<<"no! " << matrix.getMatrixElement(i, matrix.getColumns_Count() - 1)<<endl;
         cout<<Y2.at(i)<<endl;
         cout<<abs(matrix.getMatrixElement(i, matrix.getColumns_Count() - 1)-Y2.at(i))<<endl;
         flag = false;
        }

    }

    return flag;

}


int main()
{

srand(time(0));
    float value = 42;
	int rows_count = 10;
	int columns_count =11;
	Matrix matrix(rows_count, columns_count);
	matrix.print();
    Formula(matrix, rows_count, columns_count, value);
    matrix.print();
	MethodGausa(matrix);
    matrix.print();

    vector<double> solution = GetLastColumn(matrix);


    // restore original equation
    Formula(matrix, rows_count, columns_count, value);

    vector<double> Y2 = MultMatrixVector(matrix, solution);


    double eps=0.001;
    bool ok = CompareWithLastColumn(matrix, Y2, eps); // i == j xxx abs(i-j) < eps


    //rows_count = 10;
    //columns_count = 10;
    //Formula(matrix, rows_count, columns_count, value);
    //matrix.print();



    return 0;
}
