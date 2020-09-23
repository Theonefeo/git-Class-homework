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
     vector<Student> listofstudents;


      void add(Student st) //Метод добавления студентов
      {
        listofstudents.push_back(st);
      }
      Student at(int i)
      {
        return listofstudents.at(i);
      }
      int getCount()
      {
        return listofstudents.size();
      }
      void Print()
      {
          cout<<"Студенты: \n";
          for(int i=0; i<listofstudents.size(); i++)
          {
              listofstudents.at(i).Print();
              cout<<endl;
           }
      }
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

     cout<<endl<<"/////////////Seconds///////////"<<endl;

     StudentList Spisok;
     Spisok.add(vasya);
     Spisok.add(petya);

     cout<<"Студент по номеру.... ";
     Spisok.at(1).Print();

     cout <<endl<<"Число студентов: "<< Spisok.getCount() << endl;

     Spisok.Print();

    cout<<endl;

     return 0;
}
