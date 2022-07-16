#include<iostream>
using namespace std;

#include<stdlib.h>

int main()
{
    int a=10;
    int &r=a; //reference variable

    cout<<a<<endl;
    r++;
    cout<<r<<endl;
    cout<<a<<endl;
}