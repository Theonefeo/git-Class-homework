#include <iostream>
#include <vector>
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
    }
    else
    {
        return seque.size();
    }
}
int &SortSeq::get(int i)  //Getting the sequence element
{
    if(seque.empty())
    {
        //cout<<endl<<"Wrong command!!!!!!"<<endl;
    }
    else if(i<0)
    {
        return seque.at(i);
    }
    return 0;
}
void SortSeq::remove(int i)  //Delete items
{
    if(i<seque.size())
    {
        if(seque.empty())
        {
        }
        else
        seque.erase(seque.begin() + i);
    }
    else
    {
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
