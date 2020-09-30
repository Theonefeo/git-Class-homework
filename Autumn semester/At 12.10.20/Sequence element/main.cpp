#include <iostream>
#include <vector>
#include "SortSeq.h"

using namespace std;

int main()
{
    SortSeq *Sequence{};
    int menuPos;
    int i;
    cout<<endl<<"Please enter the 0 for exit";
    cout<<endl<<"Please enter the 1 for to create sequence";
    cout<<endl<<"Please enter the 2 for to add an element to a vector";
    cout<<endl<<"Please enter the 3 for to print the number of elements in a vector";
    cout<<endl<<"Please enter the 4 for to get an item by index";
    cout<<endl<<"Please enter the 5 for delete sequence ";
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
            if(Sequence==NULL)
            {
                Sequence = new SortSeq;
            }
            else
             cout<<endl<<"WRONG COMMAND"<<endl;
            break;
        }
        case 2:
        {
            if(Sequence==NULL)
            {
                int x; //Declaration of the element we want to add
                cout<<"Please enter the element "<<endl;
                cin>>x;
                Sequence->add(x);
            }
            break;
        }
        case 3:
        {
            if(Sequence!=NULL)
            {
                cout<<endl<<Sequence->Count()<<endl;
            }
            break;
        }
        case 4:
        {
            if(Sequence!=NULL)
            {
                cout<<endl<<"Please enter the element for the receivings: ";
                cin>>i;
                cout<<Sequence->get(i)<<endl;
            }
            break;
        }
        case 5:
        {
            //*Sequence.clear();
            //vector<int>().swap(*Sequence);
            delete Sequence;
            break;
        }
        case 6:
        {
            if(Sequence!=NULL)
            {
                cout<<"Please enter index of element for delete: ";
                cin>>i;
                cout<<endl;
                Sequence->remove(i);
            }
            break;
        }
        default:
        {
            cout<<"Wrong command number!!!"<<endl;
            break;
        }
        }
        if(Sequence!=NULL)
        {
            Sequence->print();
        }
        cout<<"Please enter command: ";
        cin>>menuPos;
    }
    return 0;
}
