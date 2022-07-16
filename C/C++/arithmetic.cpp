#include <iostream>
using namespace std;

template <class T>
class Arithmetic
{
private:
    /* data */
    T a;
    T b;

public:
    Arithmetic(/* args */ T a, T b);
    ~Arithmetic();

    T add()
    {
        return a + b;
    }

    T sub()
    {
        return a - b;
    }
};

template <class T>
Arithmetic<T>::Arithmetic(/* args */ T a, T b)
{
    this->a = a;
    this->b = b;
}

template <class T>
Arithmetic<T>::~Arithmetic()
{
}

int main()
{
    Arithmetic<int> ar(10,5);
    cout<<ar.add()<<endl;

    Arithmetic<float> ar1(1.5,1.2);
    cout<<ar1.add();
}

