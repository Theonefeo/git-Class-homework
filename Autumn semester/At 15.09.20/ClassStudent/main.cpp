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
  private:

     vector<string> Spisok;


      void add(string v) //�������� ��������
      {
        //int i=0;
        //for(i, i<)
        Spisok.push_front(v);
        //st.push_front("Licenko.E.C");
        //st.push_front("Gorelov.D.D");
      }
      int getCount()
      {
        return Spisok.size();
      }
      void Print()
      {
          while(!st.empty())
          {
              cout<<"students: "<<st.front()<<endl;
              st.pop_front();
          }

      }


      //Student at(int i);   //�������� �������� �� ������
      //int getCount();    //�������� ���������� ���������
        //void Print(); //������� ���� ��������� �� �����(�� ������ �� ������).��� ���������� �� ����� ������� ��������� � ����� Student, � ��������� ������ ������� ������ ����. � ����� ����������������� ������ �� ������� ������ ������� ������ - �������� ������ ���� �������  � ����� ���������� ������.

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



     StudentList Spisok;
     Spisok.add(vasya);
     Spisok.add(petya);

     cout << Spisok.getCount() << endl;
     Spisok.at(1).Print();

     Spisok.Print();



     fedya.add("Karpov.F.V");
     return 0;
}


