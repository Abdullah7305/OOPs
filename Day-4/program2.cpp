#include <iostream>
#include <cstring>
using namespace std;

// Implementing the Diamond Problem  and then it's Solution

class A
{

public:
    int a;
    A(int value) : a(value)
    {
        cout << "Values is " << a << endl;
    }
    int x;
};

class B : virtual public A
{
public:
    B(int a) : A(a) {};
};

class C : virtual public A
{
public:
    C(int c) : A(c) {};
};

class D : public B, public C
{
public:
    D(int val)
        : A(val), B(val), C(val)
    {
    }
};

int main()
{
    // here the b and the c class give the constructor value to the class A but the thing is
    // the constructor value for both of them will get ignored and only the value that is passed by the last class in the
    // hierarchy d will set the constructor value for the class A

    B b(100);
    D d(10);
    C c(80);
    

    return 0;
}