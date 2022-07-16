#include<iostream>
using namespace std;

struct Test
{
    int A[5];
    int n;
};

void fun(struct Test t1)
{
    t1.A[0]=10;
    t1.A[1]=9;
    t1.A[2]=8;
    t1.A[3]=7;
    t1.A[4]=6;
}

int main()
{
    struct Test t={{2,4,6,8,10},5};
    fun(t);
}