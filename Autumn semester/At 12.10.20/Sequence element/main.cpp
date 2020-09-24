#include <iostream>
#include <vector>

using namespace std;

class SortSeq
{
    private:
    vector<int> seque;

    public:
    SortSeq()   //Empty sequence
    {
        seque.clear(); //Clearing a vector of elements
        vector<int>().swap(seque); //Clearing the memory space that the vector used to occupy
    }
    //~SortSeq();
    void add(int x)
    {

        seque.push_back(x);
    }
    int Count()
    {
        cout<<endl<<"The size of the vector: ";
        return seque.size();
    }
    int &get(int i)  //Getting the sequence element
    {
        cout<<"Element sequence by number "<<i<<": ";
        return seque.at(i);
    }
    void remove(int i)  //Delete items
    {
        seque.erase(seque.begin() + i);

    }

    void print()  //Printing the sequence
    {
        cout<<"{";
        for(int pi=0; pi<seque.size(); pi++)
        {
            cout<<" "<<seque.at(pi);
        }
        cout<<"}"<<endl;
    }

};



int main()
{
    SortSeq Sequence{};
    int menuPos;
    int i;
    cout<<endl<<"Please enter the 0 for exit";
    cout<<endl<<"Please enter the 1 for to clear a vector of numbers";
    cout<<endl<<"Please enter the 2 for to add an element to a vector";
    cout<<endl<<"Please enter the 3 for to print the number of elements in a vector";
    cout<<endl<<"Please enter the 4 for to get an item by index";
    cout<<endl<<"Please enter the 5 for to display a vector on the screen";
    cout<<endl<<"Please enter the 6 for delete an item by index"<<endl;
    while(menuPos)
    {
    cout<<"Please enter command: ";
    cin>>menuPos;
    switch(menuPos)
    {
    case 0:
        {
        cout<<"End of work"<<endl;
        break;
        }
    case 1:
        {//Clear vector
        break;
        }
    case 2:
        {
        int x; //Declaration of the element we want to add
        cout<<"Please enter the element sequence "<<endl;
        cin>>x;
        Sequence.add(x);
        break;
        }
    case 3:
        {
        cout<<endl<<Sequence.Count()<<endl;
        break;
        }
    case 4:
        {
        cout<<endl<<"Please enter the element sequence for the receivings: ";
        cin>>i;
        int a = Sequence.get(i);
        cout<<a<<endl;
        break;
        }
    case 5:
        {
        Sequence.print();
        break;
        }
    case 6:
        {
        Sequence.remove(i);
        break;
        }
    default:
        {
        cout<<"Wrong command number!!!";
        break;
        }
    }
    }

    return 0;
}
