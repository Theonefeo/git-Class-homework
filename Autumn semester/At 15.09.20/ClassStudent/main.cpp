#include <iostream>
#include <list>

using namespace std;

class Student{

   public:
       string fio;
       int year_numder;

       Student(string name, int year)
       {
        fio = name; year_numder = year;
       }
       void moveToNextYear()
       {
           year_numder++;
       }
       void Print()
       {
           cout<<"FIO="<<fio<<";year="<<year_numder<<endl;
       }
};
class StudentList{
  public:

      list<string> st;


      void add(list st) //�������� ��������
      {
        st.push_front("Karpov.F.V");
      }
      void getCount(list st)
      {

      }


      //Student at(int i);   //�������� �������� �� ������
      int getCount();    //�������� ���������� ���������
      void Print();   //������� ���� ��������� �� �����(�� ������ �� ������).��� ���������� �� ����� ������� ��������� � ����� Student, � ��������� ������ ������� ������ ����. � ����� ����������������� ������ �� ������� ������ ������� ������ - �������� ������ ���� �������  � ����� ���������� ������.

};


int main()
 {
     Student vasya("Vasya.V.V", 1);
     Student petya("Petya.P.P", 3);
     vasya.Print();
     petya.Print();
     vasya.moveToNextYear();
     vasya.Print();
     petya.Print();
     vasya.fio = "vvvv";
     return 0;
}


