#include <iostream>
using namespace std;
#include <stdlib.h>

void fun(int A[], int n)
{
    A[0] = 15;

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl
         << sizeof(A) / sizeof(int) << endl; // OUTPUT: 2
}

int *fun(int size) // Dynamic Memory Allocation in the Heap
{
    int *p;
    p = new int[size];

    for (int i = 0; i < size; i++)
    p[i]=i+1;
    
    return p;
}

int main()
{
    int A[] = {2, 4, 6, 8, 10};
    int n = 5;

    fun(A, 5);
    cout << sizeof(A) / sizeof(int) << endl; // OUTPUT: 5

    for (int x : A)
        cout << x << " ";

    int *ptr;
    ptr=fun(5);

    for (int i = 0; i < 5; i++)
    cout<<ptr[i]<<" ";
    
}