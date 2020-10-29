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
        //system("clear");
        cout << "1.Enter element massiv" << endl;
        cout << "2.Delete last element massiv" << endl;
        cout << "3.Show massiv" << endl;
        cout << "4.Processing massiv" << endl;
        cout << "5.Output" << endl;
        cin.sync();
        cout<<"Please enter command: ";
        cin>>men;
        //system("read -rsp \"Press any key to continue...\"-n1 key");
        switch(men)
        {
            case 1:
                    system("clear"); //for linux
                    cout << "1.Enter element massiv" << endl;
                    int b;
                    cin>>b;
                    arr[arrN].setVal(b);
                    arrN++;
                    system("read -rsp \"Press any key to continue...\"-n1 key"); //Esli komandi "system & cls" ne rabotaut to ispolzuu ety stroku
                    break;
            case 2:
                    system("clear");
                    cout << "2.Delete last element massiv" << endl;
                    arrN--;
                    system("read -rsp \"Press any key to continue...\"-n1 key");
                    break;
            case 3:
                    system("clear");
                    cout << "3.Show massiv" << endl;
                    for(int i=0;i<=arrN-1;i++)
                        {
                            arr[i].showVal();
                        }
                    cout<<endl;
                    system("read -rsp \"Press any key to continue...\"-n1 key");
                    break;
            case 4:
                   system("clear");
                   cout << "4.Processing massiv" << endl;
                   int a;
                   a=0;
                    for(int i=0;i<=arrN-1;i++)
                        {
                            a=a+arr[i].getVal();
                        }
                        cout<<a<<"\n";
                    system("read -rsp \"Press any key to continue...\"-n1 key");
                    break;
            case 5:
                   system("clear");
                   cout<<endl<<"END OF WORK"<<endl;
                   system("read -rsp \"Press any key to continue...\"-n1 key");
                   break;
            default:
                    system("clear"); // pod windows rabotaet."cls" pod linux - net
                    cout<<"WRONG"<<endl;
                    cin.clear();
                    cin.sync();
                    men = 5;
                    system("read -rsp \"Press any key to continue...\"-n1 key"); //Esli komandi "system & cls" ne rabotaut to ispolzuu ety stroku
                    break;
        }
    }
    while(men!=5);
    return 0;
}
