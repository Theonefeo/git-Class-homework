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


      void add(list st) //добавить студента
      {
        st.push_front("Karpov.F.V");
      }
      void getCount(list st)
      {

      }


      //Student at(int i);   //получить студента по номеру
      int getCount();    //получить количество студентов
      void Print();   //вывести всех студентов на экран(по одному на строке).При реализации не стоит вносить изменения в класс Student, в начадьный момент времени список пуст. В майне продемонстрируйте работу на примере одного обЬекта списка - покажите работу всех методов  и общий функционал класса.

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


