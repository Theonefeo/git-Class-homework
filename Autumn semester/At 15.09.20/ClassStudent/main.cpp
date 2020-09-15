#include <iostream>
#include <vector>

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

     vector<string> Spisok;


     void add(string v) //добавить студента
      {
        //int i=0;
        //for(i, i<)
        Spisok.push_back(v);
        //st.push_front("Licenko.E.C");
        //st.push_front("Gorelov.D.D");
      }
      int getCount()
      {
        return Spisok.size();
      }
      void Print()
      {
           for(int i=0; i<Spisok.size(); i++)
          {
              cout<<"students: "<<Spisok.at(i)<<endl;
          }

      }


      //Student at(int i);   //получить студента по номеру
      //int getCount();    //получить количество студентов
        //void Print(); //вывести всех студентов на экран(по одному на строке).При реализации не стоит вносить изменения в класс Student, в начадьный момент времени список пуст. В майне продемонстрируйте работу на примере одного обЬекта списка - покажите работу всех методов  и общий функционал класса.

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



     StudentList Spisok1;
     Spisok1.add("Misha.P.P");
     Spisok1.add("Jenya.V.V");

     cout << Spisok1.getCount() << endl;
     cout<<Spisok1.Spisok.at(1)<<endl; //.Print();

     Spisok1.Print();
     cout<<endl;




     return 0;
}


