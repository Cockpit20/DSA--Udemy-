#include<iostream>
using namespace std;

int sum(int n)
{
    if(n==1)
    return 1;
    return n+sum(n-1);
}
// Time Complexity: O(N)
// Space Complexity: O(N)

int main()
{
    cout<<sum(8);
}