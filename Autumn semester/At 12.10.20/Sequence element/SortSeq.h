#pragma once
#include <vector>

using namespace std;

class SortSeq
{
private:
    vector<int> seque;
public:
    SortSeq();   //Empty sequence конструктор
    ~SortSeq(); //деструктор
    void add(int x) {seque.push_back(x);}
    int Count();
    int&get(int i);
    void remove(int i);
    void print();

};
