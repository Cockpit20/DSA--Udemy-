#include <iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

void initialize(struct Rectangle *ptr,int l,int b)
{
    ptr->length=l;
    ptr->breadth=b;
}

int area(struct Rectangle rect)
{
    return rect.length*rect.breadth;
}

void  changeLength(struct Rectangle *ptr,int l)
{
    ptr->length=l;
}

int main()
{
    struct Rectangle r;

    initialize(&r,10,5);
    area(r);
    changeLength(&r,20);
}