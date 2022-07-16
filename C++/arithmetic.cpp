#include <iostream>
using namespace std;

// Template classes are used to create generic classes
template <class T>
class Arithmetic
{
private: // Data members are declared private
    /* data */
    T a;
    T b;

public: // Methods are declared as public to be accessible from anywhere
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
Arithmetic<T>::Arithmetic(/* args */ T a, T b) // :: Scope Resolution
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

