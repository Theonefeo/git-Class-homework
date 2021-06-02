#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector <double> runge_kutta(double h)
{
    vector <double> fi;
    vector <double> psi;
    double g = 9.8;
    double w = 3.130495;
    double ti;
    double Sfi;
    double Spsi;

    double A=2;
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
    cout<<"M= "<<Max<<endl;
    return Max;
}
double radian_error_to_mm(double element_runge)
{

    double r;
    r = sqrt(2-2*(cos(element_runge)));
    return r;
}
vector <double> solve_de(double eps, double &real_eps, double &h)
{
    vector <double> fi1;
    vector <double> fi2;

    h=0.01;
    do
    {
        fi1 = runge_kutta(h);
        fi2 = runge_kutta(h/2);
        real_eps = radian_error_to_mm(pravilo_runge(fi1, fi2, 2));
        h = h/2;
    }
    while (real_eps >= eps);

    return fi2;
}
int main()
{
    double eps = 1;
    vector <double> Fi;
    double Real_eps, h;

    Fi = solve_de(eps, Real_eps, h);

    cout<<"Solved with eps="<< Real_eps<< "h=" << h << endl;

    save_to_file(Fi);
    cout << "Max angle: " << abs(Fi).max();


    return 0;
}
