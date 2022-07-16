#include <iostream>
using namespace std;

class Rectangle //Class created
{
    // Data members
    int length;
    int breadth;
public:
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }

    int area()
    {
        return length * breadth;
    }

    void changeLength(int l)
    {
        length = l;
    }
};

int main()
{
    Rectangle r(10,5); //Object Created

    // Member functions of the object
    r.area();
    r.changeLength(20);
}