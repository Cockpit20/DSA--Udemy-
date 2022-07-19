#include<iostream>

void TOH(int n,int A,int B,int C)
{
    if(n>0)
    {
        TOH(n-1,A,C,B);
        printf("\nFrom %d to %d",A,C);
        TOH(n-1,B,A,C);
    }
}
// Time Complexity: O(2^N)

int main()
{
    TOH(3,1,2,3);
}