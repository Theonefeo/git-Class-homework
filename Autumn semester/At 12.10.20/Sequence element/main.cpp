#include <iostream>
#include <vector>
#include <cstdlib>
#include "SortSeq.h"
//#include "new_delete_Check_for_emptinesser.hpp"

using namespace std;

bool Check(bool cond, string else_message = "WRONG COMMAND\n")
{
    if (!cond)
    {
        cout << else_message;
    }
    return cond;
}

int main()
{
    SortSeq *Sequence = nullptr;
    int menuPos;
    int i;
    cout<<endl<<"Please enter the 0 for exit";
    cout<<endl<<"Please enter the 1 for to create sequence";
    cout<<endl<<"Please enter the 2 for delete sequence";
    cout<<endl<<"Please enter the 3 for to add an element to a vector";
    cout<<endl<<"Please enter the 4 for to print the number of elements in a vector";
    cout<<endl<<"Please enter the 5 for to get an item by index";
    cout<<endl<<"Please enter the 6 for delete an item by index"<<endl;
    cout<<"Please enter command: ";
    cin>>menuPos;
    while(menuPos)
    {
        switch(menuPos)
        {
        case 0:
        {
            cout<<"End of work"<<endl;
            break;
        }
        case 1:
        {
            if(Sequence) //Sequence!=nullptrptr
            {
                cout<<"Sequence already created\n";
            }
            else
            {
                int i;
                cout<<"Enter 0 to create an empty sequence"<<endl;
                cout<<"Enter 1 to create an the completed sequence"<<endl;
                cin>>i;
                if(i==0)
                {
                    Sequence = new SortSeq();
                    cout<<"Sequence  created\n";
                }
                else if(i==1)
                {
                    cout<<"Enter the size of the sequence\n";
                    int nn;
                    cin>>nn;

                    vector<int> data;
                    while(nn!=0)
                    {
                        data.push_back(rand() % 10 + 1);
                        nn--;
                    }
                    Sequence = new SortSeq(data);
                    cout<<"Sequence  created\n";
                }
            }
            break;
        }
        case 2:
        {
            if (Check(Sequence != nullptr, "No object for deletion\n"))
            {
                delete Sequence;
                Sequence = nullptr;
                cout<<"object for deletion\n";
            }
            break;
        }
        case 3:
        {
            if (Check(Sequence != nullptr))
            {
                int x; //Declaration of the element we want to add
                cout<<"Please enter the element "<<endl;
                cin>>x;
                Sequence->add(x);
            }
            break;
        }
        case 4:
        {
            if (Check(Sequence != nullptr))
            {
                cout<<endl<<Sequence->count()<<endl;
            }
            break;
        }
        case 5:
        {
            if (Check(Sequence != nullptr))
            {
                cout<<endl<<"Please enter the element for the receivings: ";
                cin>>i;
                if(Check(i<Sequence->count(),"WRONG COMMAND\n"))
                {
                    cout<<Sequence->get(i)<<endl;
                }
            }
            break;
        }
        case 6:
        {
            if (Check(Sequence != nullptr, "No element for deletion\n"))
            {
                cout<<endl<<"Please enter the element for the receivings: ";
                cin>>i;
                if(Check(i<Sequence->count(),"WRONG COMMAND\n"))
                {
                    Sequence->remove(i);
                }
            }
            break;
        }
        default:
        {
            cout<<"Wrong command number!!!"<<endl;
            break;
        }
        }
        if (Check(Sequence != nullptr))
        {
            Sequence->print();
        }
        cout<<"Please enter command: ";
        cin>>menuPos;
    }
    if(Sequence!=nullptr)
    {
        delete Sequence;
    }
    return 0;
}
