#include<iostream>
using namespace std;

int main()
{
    int A[]={2,4,6,8,10};
    for (int i = 0; i < 5; i++)
    {
        cout<<A[i]<<" ";
        cout<<&A[i]<<" ";
        cout<<endl;
    }
    
    cout<<endl<<A[2]<<endl;
    cout<<2[A]<<endl;
    cout<<*(A+2);
}