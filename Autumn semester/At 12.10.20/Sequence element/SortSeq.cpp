#include <iostream>
#include <vector>
#include "SortSeq.h"

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
    if(seque.empty())
    {
        cout<<endl<<"Wrong command!!!!!!"<<endl;
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
        cout<<endl<<"Wrong command!!!!!!"<<endl;
    }
    else
    {
        return seque.at(i);
    }
}
void SortSeq::remove(int i)  //Delete items
{
    if(i<seque.size())
    {
        if(seque.empty())
        {
            cout<<endl<<"Wrong command!!!!!!"<<endl;
        }
        else
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
/*
void SortSeq::deleteseque()
{
    seque.clear(); //Clearing a vector of elements
    vector<int>().swap(seque);
}*/
