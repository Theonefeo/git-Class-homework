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
        cout<<"}";
    }

};



int main()
{
   int x; //Declaration of the element we want to add
    cout<<"Please enter the element sequence "<<endl;
    cin>>x;

    SortSeq Sequence{};

    Sequence.add(x);
    cout<<Sequence.Count()<<endl;

    int i;
    cout<<"Please enter the element sequence for the receivings: ";
    cin>>i;
    int a = Sequence.get(i);
    cout<<a<<endl;

    Sequence.print();
    Sequence.remove(i);

    return 0;
}
