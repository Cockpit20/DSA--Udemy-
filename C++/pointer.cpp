#include<iostream>
using namespace std;

#include<stdlib.h>

int main()
{
    int a=10;
    int *ptr;
    ptr=&a;
    cout<<*ptr<<endl;

    int A[5]={2,4,6,8,10};
    ptr=A;
    for (int i = 0; i < 5; i++)
    cout<<ptr[i]<<" ";
    
    int *p;
    p=(int *)malloc(5*sizeof(int)); // C
    p=new int[5]; //C++
    p[0]=10;
    p[1]=15;
    p[2]=14;
    p[3]=21;
    p[4]=31;
    for (int i = 0; i < 5; i++)
    cout<<p[i]<<" ";

    delete [ ] p;
}

