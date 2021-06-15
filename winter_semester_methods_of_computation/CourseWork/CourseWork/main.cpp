#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

vector <double> runge_kutta(double h, double A)
{
    vector <double> fi;
    vector <double> psi;
    double g = 9.8;
    double w = 3.130495;
    double ti;
    double Sfi;
    double Spsi;

    fi= {0};
    psi= {0};


    for(int i=1; i<30/h+1; i++)
    {
        ti = i*h;
        double m = (((-g)*sin(fi.back()))+(A*sin(w*ti)*cos(fi.back())));

        Sfi = (fi.back()+(h*psi.back()));
        Spsi = (psi.back()+(h*m));
        fi.push_back(fi.back() + (h*(psi.back()+Spsi))*0.5);
        ti=(i+1)*h;
        double n = (((-g)*sin(Sfi))+(A*sin(w*ti)*cos(Sfi)));
        psi.push_back(psi.back()+(h*(m+n))*0.5);
    }


    return fi;
}
double pravilo_runge(vector <double> fi1, vector <double>  fi2, int p = 2)
{
    double element_runge;
    double Max = 0;
    for(unsigned i=0; i<fi1.size(); i++)
    {

        element_runge = (abs(fi1.at(i) - fi2.at(i*p))/(pow(2.,p) - 1));

        if(Max<element_runge)
            Max = element_runge;
    }
    cout<<endl<<"M= "<<Max<<endl;
    return Max;
}
double radian_error_to_mm(double element_runge)
{

    double r;
    r = sqrt(2-2*(cos(element_runge)));
    return r;
}
vector <double> solve_de(double eps, double &real_eps, double &h, double A)
{
    vector <double> fi1;
    vector <double> fi2;

    h=0.01;
    do
    {
        fi1 = runge_kutta(h, A);
        fi2 = runge_kutta(h/2, A);
        real_eps = radian_error_to_mm(pravilo_runge(fi1, fi2, 2));
        h = h/2;
    }
    while (real_eps >= eps);

    return fi2;
}
void save_to_file(vector <double> Fi, int i)
{
        ofstream fout;
        switch(i)
        {
            case 0:
            {
                fout.open("Angle_Fi2.txt");
                break;
            }
            case 1:
            {
                fout.open("Angle_Fi1.txt");
                break;
            }
            case 2:
            {
                fout.open("Angle_Fi0.5.txt");
                break;
            }
            default:
            {
                cout<<"WRONG";
                break;
            }
        }
    for(unsigned ii=0; ii<Fi.size(); ii++)
    {
        fout<<Fi.at(ii)<<" "<<endl;
    }

    fout.close();
}
double Max_angle(vector <double> Fi)
{
    double Max = 0;
    for(unsigned i=0; i<Fi.size(); i++)
    {
        if(Max<Fi.at(i))
        Max = Fi.at(i);
    }
    return Max;
}
int main()
{
    int i=0;
    double A;
    do{
        switch(i)
        {
            case 0:
            {
                A = 2;
                break;
            }
            case 1:
            {
                A = 1;
                break;
            }
            case 2:
            {
                A = 0.5;
                break;
            }
            default:
            {
                cout<<"WRONG";
                break;
            }
        }

        double eps = 1;
        vector <double> Fi;
        double Real_eps, h;

        Fi = solve_de(eps, Real_eps, h, A);

        cout<<endl<<"Solved with eps="<< Real_eps<< "h=" << h << endl;

        save_to_file(Fi, i);
        cout <<endl<< "Max angle: " <<Max_angle(Fi);
     i++;
    }
    while(i!=3);

    return 0;
}
