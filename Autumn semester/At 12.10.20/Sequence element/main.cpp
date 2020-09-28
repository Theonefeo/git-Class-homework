#include <iostream>
#include <vector>

using namespace std;

class SortSeq
{
private:
    vector<int> seque;

public:
    SortSeq();   //Empty sequence конструктор
    ~SortSeq(); //деструктор
    void add(int x)
    {
        seque.push_back(x);
    }
    int Count();
    int&get(int i);
    void remove(int i);
    void print();

};
SortSeq::SortSeq()
{
    seque.clear(); //Clearing a vector of elements
    vector<int>().swap(seque); //Clearing the memory space that the vector used to occupy
}
SortSeq::~SortSeq()
{
}
int SortSeq::Count()
{
    return seque.size();
}
int &SortSeq::get(int i)  //Getting the sequence element
{
    return seque.at(i);
}
void SortSeq::remove(int i)  //Delete items
{
    if(i<seque.size())
    {
        seque.erase(seque.begin() + i);
    }
    else
    {
        cout<<"Wrong index"<<endl;
    }
}
void SortSeq::print()  //Printing the sequence
{
    cout<<"{";
    for(int pi=0; pi<seque.size(); pi++)
    {
        cout<<" "<<seque.at(pi);
    }
    cout<<"}"<<endl;
}

int main()
{
    SortSeq *Sequence{}; //= new SortSeq;
    /*cout<<"To create a sequence press 1";
    int b;
    cin>>b;
    if(b==1)
     {*/
    //Sequence = new SortSeq;
    int menuPos;
    int i;
    cout<<endl<<"Please enter the 0 for exit";
    cout<<endl<<"Please enter the 1 for to create sequence";
    cout<<endl<<"Please enter the 2 for to add an element to a vector";
    cout<<endl<<"Please enter the 3 for to print the number of elements in a vector";
    cout<<endl<<"Please enter the 4 for to get an item by index";
    cout<<endl<<"Please enter the 5 for delete sequence ";
    cout<<endl<<"Please enter the 6 for delete an item by index"<<endl;
    while(menuPos)
    {
        cout<<"Please enter command: ";
        cin>>menuPos;
        switch(menuPos)
        {
        //Sequence.print();
        case 0:
        {
            cout<<"End of work"<<endl;
            break;
        }
        case 1:
        {
            //cout<<"End of work"<<endl;
            Sequence = new SortSeq;
            break;
        }
        case 2:
        {
            int x; //Declaration of the element we want to add
            cout<<"Please enter the element "<<endl;
            cin>>x;
            Sequence->add(x);
            break;
        }
        case 3:
        {
            cout<<endl<<Sequence->Count()<<endl;
            break;
        }
        case 4:
        {
            cout<<endl<<"Please enter the element for the receivings: ";
            cin>>i;
            //int a = Sequence.get(i);
            cout<<Sequence->get(i)<<endl;
            break;
        }
        case 5:
        {
            //Delete sequence
            delete Sequence;
            break;
        }
        case 6:
        {
            cout<<"Please enter index of element for delete: ";
            cin>>i;
            cout<<endl;
            Sequence->remove(i);
            break;
        }
        default:
        {
            cout<<"Wrong command number!!!"<<endl;
            break;
        }
        }
        if(menuPos!=5 || menuPos!=0)
        {

            Sequence->print();
        }
        //}
    }
    /*else
    {
         b = 0;
         cout<<"Enter 2 ";
    }*/

    return 0;
}
