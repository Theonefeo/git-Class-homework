#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <vector>
#include <fstream>
#include <cmath>
#include <assert.h>
#include <cmath>

using namespace std;

double ndF(double x, double mu, double sigma)
{
    return 0.5*(1+erf( (x-mu)/(sigma*sqrt(2)) ));
}

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
    double Max = 0, Min = 0, Summ = 0, Xsr = 0;
    int numberOfIntervals[22] = {0};
    int intervals = 0;
    double a11, a12, a13, a21, a22, a23, a31, a32, a33;
    for(int i=0; i<14400; i++)
    {
        fin>>a11>>a12>>a13>>a21>>a22>>a23>>a31>>a32>>a33;


        determine = ((a11*a22*a33) - (a11*a23*a32) - (a12*a21*a33) + (a12*a23*a31) + (a13*a21*a32) - (a13*a22*a31));
        Summ = Summ + determine;
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

        //считаем количество чисел в каждом интервале от -1 до 1. Для этого сопоставляем [-1,-0.9] число 0, тогда [0.9,1] - 19 (пример деления).
        //тогда чттобы подсчитать сколько определителей входит в определенный интервал, преобразуем и пишем числа в массив,при этом прибавляя количество элементов массива по этому индексу.
        //в итоге получим распределение определителей по интервалу от -1 до 1.

            intervals = ((int)(determine*10)) + 11;
            if(determine<0)
                intervals--;
            if (intervals <0 || intervals > 19) {
                cout << "!!!huston help!" << intervals << " " << i << " " << determine << endl;

            }
            numberOfIntervals[intervals]++; // !!!!!!!!!
    }

    cout<<endl<<"Summ "<<Summ<<endl;

    Xsr = Summ/14400; //Arithmetic mean - среденее арифметическое

    cout<<endl<<"Xsr, Arithmetic mean "<<Xsr<<endl;

    cout << "Det size" << det.size() << endl;
    cout<<"Max: "<<Max<<" "<<"Min: "<<Min<<"\n";

    fin.close();
    fout.close();

    ofstream fout1("DetermineDistribution.txt");
    for(int i=0; i<22;i++)
    {
        cout<<"Number of intervals "<<i<<"  "<<numberOfIntervals[i]<<"\n";
        fout1<<i<<"  "<<numberOfIntervals[i]<<"\n";
    }
    fout1.close();

    double Sn=0 , Snp=0;

    for(int i=0; i<14400; i++)
    {
        Snp = Snp + pow((det.at(i) - 0),2);

    }

    cout<<endl<<"Snp "<<Snp<<endl;


    Sn = Snp/14400; //SampleVariance - выборочная дисперсия

    cout<<endl<<"Sn,SampleVariance "<<Sn<<endl;

    double arrayOfIntervals[] = {-1.1, -0.7, -0.5, -0.4, -0.3, -0.2, -0.1, 0, 0.1, 0.2, 0.3, 0.5, 1.1};
    double intervalCount = sizeof(arrayOfIntervals)/sizeof(double) - 1;
    assert(intervalCount == 12);

    double sample_hist[12] = {0};

    for(int si=0; si < det.size(); si++)
    {
        double s = det.at(si);
        for(int i=0; i<intervalCount; i++)
        {
            if (s >= arrayOfIntervals[i] && s < arrayOfIntervals[i+1])
            {
                sample_hist[i] ++;
            }
            //cout<<"This is interval [" << arrayOfIntervals[i] << "; " << arrayOfIntervals[i+1] << "]"<<endl;
        }
    }

    double __tmp=0;
    for (int i=0; i<intervalCount; i++)
    {
        //cout << "[" << arrayOfIntervals[i] << "; " << arrayOfIntervals[i+1] << "]\t" << sample_hist[i] << endl;
        __tmp += sample_hist[i];
    }
    assert(__tmp == 14400);



    double theor_hist[12] = {0};
    for (int i=0; i<intervalCount; i++)
    {
       theor_hist[i] = ndF(arrayOfIntervals[i+1], 0, sqrt(Sn)) - ndF(arrayOfIntervals[i], 0, sqrt(Sn));
    }


    __tmp = 0;
    for (int i=0; i<intervalCount; i++)
    {
        __tmp += theor_hist[i];
    }
    assert(abs(__tmp - 1) < 0.001);

    for (int i=0; i<intervalCount; i++)
    {
        cout << "[" << arrayOfIntervals[i] << "; " << arrayOfIntervals[i+1] << "]\t"
        << sample_hist[i] << "\t" << theor_hist[i]*14400 << endl;

    }
    double sumHipr = 0, sumHi = 0, Hi = 0;

    for (int i=0; i<intervalCount; i++)
    {

        sumHipr = pow(((sample_hist[i] /14400) - theor_hist[i]), 2)/theor_hist[i];
        sumHi = sumHi + sumHipr;

    }

    Hi = sumHi * 14400;
    cout<<endl<<"Hi^2 : "<<Hi<<endl;

    return 0;
}
