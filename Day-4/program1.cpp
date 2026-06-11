#include <iostream>
using namespace std;

class Employee
{
public:
    int totalsalary;
    Employee(int s) : totalsalary(s) {}
    virtual int calculateBonus()
    {
        totalsalary += 190;
        cout << "Bonus+Salary is " << totalsalary << endl;
        return totalsalary;
    }
};

class Manager : public Employee
{
public:
    Manager(int val) : Employee(val) {}
    int calculateBonus() override
    {
        cout << "Salary is " << totalsalary + 10 << endl;
    }
};

// Fragile Base Class Problem occurs when changes to a base class unexpectedly break derived classes because those
// derived classes depend on the base class's internal implementation details rather than its public contract.
// This makes inheritance hierarchies difficult to maintain and evolve

int main()
{
    Manager m(200);
    m.calculateBonus();
}
