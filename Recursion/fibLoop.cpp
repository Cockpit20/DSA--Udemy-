#include<iostream>
using namespace std;

int fib(int n)
{
    if(n==0 || n==1)
    return n;
    int t0=0,t1=1,sum;
    for (int i = 2; i <= n; i++)
    {
        sum=t0+t1;
        t0=t1;
        t1=sum;
    }
    return sum;
}

int main()
{
    cout<<fib(8);
}