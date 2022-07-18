#include <iostream>
using namespace std;

int power(int x, int n)
{
    if (n == 0)
        return 1;
    return x * power(x, n - 1);
}

int power2(int x, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return (x * x, n / 2);
    else
        return x * power(x * x, (n - 1) / 2);
}

int main()
{
    cout << power(7, 4) << endl;
    cout << power2(2, 9);
}