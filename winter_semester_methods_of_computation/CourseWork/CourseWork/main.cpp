#include <iostream>
#include <cmath>


using namespace std;

solution solve_de(double eps)
{
    double real_eps, h=1;
    do {
        fi1[] = runge_kutta(h);
        fi2[] = runge_kutta(h/2);

        real_eps = radian_error_to_mm(pravilo_runge(fi1, fi2, p = 2)); {|x(h/2) - x(h)|/(2^p - 1) } //pravilo_runge - вывод и сравнение результатов таблиц (не забыть про max d = max D/3), перевод радиан в мм то есть нахождение расхождения
        h = h/2;
    } while (real_eps >= eps);

    return fi2, real_eps, h;
}


int main()
{
    eps = 1;
    fi[], real_eps, h = solve_de(eps);
    cout << "Solved with eps={real_eps} and h={h}" << endl;
    save_to_file(fi);

    cout << "Max angle: " << abs(fi[]).max();




    cout << "Hello world!" << endl;
    for(int i=0; i<30; i++)
    {


    }


    return 0;
}
