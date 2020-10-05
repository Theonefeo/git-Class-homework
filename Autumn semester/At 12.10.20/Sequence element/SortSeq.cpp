#include <iostream>
#include <vector>
#include <algorithm>
#include "SortSeq.h"

SortSeq::SortSeq()
{
}
SortSeq::~SortSeq()
{
}
int SortSeq::Count()
{
    if(seque.empty())
    {
        return 0;
    }
    else
    {
        return seque.size();
    }
}
int &SortSeq::get(int i)  //Getting the sequence element
{
    return seque.at(i);
}
void SortSeq::remove(int i)  //Delete items
{
    seque.erase(seque.begin() + i);
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
