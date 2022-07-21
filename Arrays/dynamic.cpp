#include<iostream>
using namespace std;

int main()
{
    int A[5]={2,4,6,8,10}; 
    // Array inside Stack ~ 
    // Cannot be resized

    int *p;
    p=new int[5]; 
    // Array inside Heap ~ 
    // Can be resized
    p[0]=3;
    p[1]=5;
    p[2]=7;
    p[3]=9;
    p[4]=11;

    // Increasing size of Array
    int *q=new int[10];
    for (int i = 0; i < 5; i++)
    {
        q[i]=p[i];
    }
    delete []p;
    p=q;
    q=NULL;
    

    for (int i = 0; i < 5; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<p[i]<<" ";
    }
}