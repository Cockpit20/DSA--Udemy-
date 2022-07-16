#include <iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
    char x;
};

// Call by value doesn't change the value of the variable in the main function
int area(struct Rectangle r1)
{
    return r1.length * r1.breadth;
}

// Call by address changes the value of the varaible in the main function
void changeLength(struct Rectangle *p,int l)
{
    p->length=l;
}

// Memory allocated dynamically in the heap and the address of the pointer pointing to it is returned to the main function
struct Rectangle *fun()
{
    struct Rectangle *p;
    p=new Rectangle;
    p->length=15;
    p->breadth=7;

    return p;
}

int main()
{
    struct Rectangle r = {10, 5};
    printf("%d \n", area(r));

    changeLength(&r,20);

    struct Rectangle *rect=fun();
    cout<<rect->length<<" "<<rect->breadth;

    //----------------------------------------------------

    struct Rectangle *p, *ptr = &r;

    r.length = 15;
    r.breadth = 10;

    (*ptr).length = 20;
    ptr->breadth = 15;

    p = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    p->length = 10;
    p->breadth = 5;

    cout << endl
         << "Area of the rectancgle is " << r.length * r.breadth << endl;

    cout << sizeof(r);
}