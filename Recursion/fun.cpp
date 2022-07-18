#include<iostream>
using namespace std;

// Tail Recursion
void tail(int n)
{
    if(n>0)
    {
        printf("%d ",n);
        tail(n-1);
    }
}

// Head Recursion
void head(int n)
{
    if(n>0)
    {
        head(n-1);
        printf("%d ",n);
    }
}

int main()
{
    int x=3;
    tail(x);
    head(x);
}