#pragma once
#include <vector>
#include <algorithm>

using namespace std;

class SortSeq
{
private:
    vector<int> seque;
public:
    SortSeq();   //Empty sequence конструктор
    SortSeq(vector <int> data)
    {
        seque = data;
        sort (seque.begin(), seque.end());
    }
    ~SortSeq(); //деструктор
    void add(int x)
    {
        seque.push_back(x);
        sort (seque.begin(), seque.end());
    }
    int Count();
    int&get(int i);
    void remove(int i);
    void print();

};
