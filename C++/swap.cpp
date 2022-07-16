#include<iostream>
using namespace std;

void swap(int *x,int *y) //Pass by address
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void swap(int &x,int &y) //Pass by reference
{
    int temp=x;
    x=y;
    y=temp;
}

int main()
{
    int a=10,b=20;
    
    swap(&a,&b);
    cout<<a<<endl<<b<<endl;

    swap(a,b);
    cout<<a<<endl<<b<<endl;
}