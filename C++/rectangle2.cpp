#include <iostream>
using namespace std;

struct Rectangle // Class created
{
    // Data members
    int length;
    int breadth;
};

void initialize(struct Rectangle *ptr,int l, int b)
{
    ptr->length = l;
    ptr->breadth = b;
}

int area(struct Rectangle rect)
{
    return rect.length * rect.breadth;
}

int perimeter(struct Rectangle rect)
{
    return 2 * (rect.length + rect.breadth);
}

int main()
{
    Rectangle r = {0, 0};

    int length, breadth;
    printf("Enter length and breadth:");
    cin >> length >> breadth;

    initialize(&r,length, breadth); // Object Created

    // Member functions of the object
    cout << area(r) << endl;
    cout << perimeter(r) << endl;
}