#include <iostream>
#include "cstdio"
#include "cstdlib"

using namespace std;
class myClass
{
    private:
        int value;

    public:
        myClass();
        ~myClass();
        void showVal();
        void setVal(int k = 1) {value = k;};
        int getVal();
};
 myClass::myClass() {}
 myClass::~myClass() {}
 void myClass::showVal()
    {
        cout<<value;
    }
/*void myClass::setVal(int k)
    {
        cin>>k;
    }*/
int myClass::getVal()
    {
        return value;
    }
int main()
{
    myClass arr[10];
    int arrN = 0;
    int men;

    do
    {
        system("cls");
        //system("pause");
        cout << "1.Enter element massiv" << endl;
        cout << "2.Delete last element massiv" << endl;
        cout << "3.Show massiv" << endl;
        cout << "4.Processing massiv" << endl;
        cout << "5.Output" << endl;
        cin.sync();
        cin>>men;
        switch(men)
        {
            case 1:
                    //system("cls");
                    //system("pause");
                    int b;
                    cin>>b;
                    arr[arrN].setVal(b);
                    arrN++;
                    break;
            case 2:
                   // system("cls");
                   // system("pause");
                    arrN--;
                    break;
            case 3:
                    //system("cls");
                    //system("pause");
                    for(int i=0;i<arrN-1;i++)
                        {
                            arr[i].showVal();
                        }
                    break;
            case 4:
                   // system("cls");
                   // system("pause");
                   int a;
                   a=0;
                    for(int i=0;i<arrN-1;i++)
                        {
                            a=a+arr[i].getVal();
                        }
                        cout<<a<<"\n";
                    break;
            default:
                   // system("pause");
                    cout<<"WRONG"<<endl;
                    break;
        }
    }
    while(men!=5);
    return 0;
}
