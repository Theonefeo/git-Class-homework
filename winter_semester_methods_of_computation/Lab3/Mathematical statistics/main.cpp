#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    srand(time(0));


    int a;
    //cout<<a;
    /*
    vector<double> Sequence;
    ofstream fout("Sequence.txt");

    for(int i=0; i<14400; i++)
    {
        for(int j=0; j<9; j++)
        {


            double a = (double)rand()/RAND_MAX;
            Sequence.push_back(a);
            fout<<Sequence.at(j)<<" ";
        }
        fout<<"\n";
        Sequence.clear();

    }

    fout.close();

    fout.open("Sequence.txt");*/
    vector<double> det;
    ifstream fin("Sequence.txt");
    ofstream fout("Det1.txt");
    double determine;
    double Max = 0, Min = 0;
    int numberOfIntervals[20] = {0};
    int intervals = 0;
    double a11, a12, a13, a21, a22, a23, a31, a32, a33;
    for(int i=0; i<14400; i++)
    {



        fin>>a11>>a12>>a13>>a21>>a22>>a23>>a31>>a32>>a33;
        //cout<<a11<<" "<<a12<<"\n";

        i= i+9;
        determine = ((a11*a22*a33) - (a11*a23*a32) - (a12*a21*a33) + (a12*a23*a31) + (a13*a21*a32) - (a13*a22*a31));
        if(determine > Max)
        {
            Max = determine;
        }
        else if(determine<Min)
        {
            Min = determine;
        }



        det.push_back(determine);
        fout<<determine<<"\n";


        //считаем количество чисел в каждом интервале от -1 до 1. Для этого сопоставляем

            intervals = ((int)(determine*10)) + 10;
            if(determine<0)
                intervals--;
            numberOfIntervals[intervals]++;
    }
    cout<<"Max: "<<Max<<" "<<"Min: "<<Min;
    fin.close();
    fout.close();

    for(int i=0; i<20;i++)
    {
        cout<<numberOfIntervals[i]<<"\n";
    }

    return 0;
}
