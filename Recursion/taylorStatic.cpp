#include <iostream>
using namespace std;

double e(double x, double n)
{
    static double f = 1, p = 1;
    double r;
    if (n == 0)
        return 1;
    else
    {
        r = e(x, n - 1);
        p = p * x;
        f = f * n;
        return r + p / f;
    }
}

int main()
{
    cout << e(4, 20);
}