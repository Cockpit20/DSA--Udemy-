#include <iostream>
using namespace std;

class Rectangle // Class created
{
// Data members
private:
    int length;
    int breadth;

public:
    // Constructors - has same name as the class
    Rectangle() // Default constructor
    {
        length=0;
        breadth=0;
    }

    Rectangle(int l, int b) // Overloaded / parameterised constructor
    {
        length = l;
        breadth = b;
    }

    // Member functions performing calculation on the data members
    int area()
    {
        return length * breadth;
    }

    int perimeter()
    {
        return 2 * (length + breadth);
    }

    
    // Setter function
    void setLength(int l)
    {
        length=l;
    }
    void setBreadth(int b)
    {
        breadth=b;
    }
    // Getter function
    int getLength()
    {
        return length;
    }
    int getBreadth()
    {
        return breadth;
    }

    // Destructor
    ~Rectangle(){
        cout<<"Destructor";
    }
};

int main()
{
    int length, breadth;
    printf("Enter length and breadth:");
    cin >> length >> breadth;

    Rectangle r(length, breadth); // Object of class Rectangle Created

    // Member functions of the object
    cout << r.area() << endl;
    cout << r.perimeter() << endl;
    r.setLength(20);
    cout<<r.getLength()<<endl;
}