#include<iostream>
using namespace std;

int sum(int n)
{
    static int x=0;
    if(n>0)
    {
        x++;
        return sum(n-1)+x;
    }
    return 0;
}

int main()
{
    cout<<sum(5)<<endl;

    cout<<sum(5);
}