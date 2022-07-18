#include <iostream>
using namespace std;

float power(float x, float n)
{
    if (n == 0)
        return 1;
    return x * power(x, n - 1);
}

float fact(float n)
{
    if (n == 1 || n == 0)
        return 1;
    return n * fact(n - 1);
}

float e(float x, float n)
{
    if (n == 0)
        return 1;
    return (power(x, n) / fact(n)) + e(x, n - 1);
}

int main()
{
    cout << e(3, 4);
}