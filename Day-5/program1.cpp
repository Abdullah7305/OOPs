#include <iostream>
using namespace std;
// learning polymorphism
// function overloading

class Calculater
{
public:
    Calculater()
    {
        cout << "Default Constructor" << endl;
    }
    Calculater(int a)
    {
        cout << "Patrametrized Constructor " << endl;
    }
    int add(int a, int b)
    {
        return a + b;
    }
    double add(double a, double b) // function overloading done here
    {
        return a + b;
    }
    string add(string a, string b)
    {
        return a + b;
    }
};

int main()
{
    Calculater c;
    cout << c.add("Abdullah ", "Suleman") << endl;

    return 0;
}
