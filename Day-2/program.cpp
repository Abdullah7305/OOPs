#include <iostream>
#include <string>
using namespace std;
// Employee Payrole Gaurd

class Employee
{
private:
    string employeeId;
    string employeeName;
    double baseSalary;
    double hourlyRate;
    int hoursWorked;

public:
    Employee(string employeeId, string employeeName, double baseSalary)
    {
        if (baseSalary <= 0)
        {
            cout << "Negative OR Null  Salary not Allowed" << endl;
            throw invalid_argument("Negative Salary Not Allowed");
        }
        else
        {
            this->employeeId = employeeId;
            this->employeeName = employeeName;
            this->baseSalary = baseSalary;
            this->hoursWorked = 0;
        }
    }
    bool setBaseSalary(double salary)
    {
        if (salary <= 0)
        {
            cout << "Invalid Salary Entered";

            return false;
        }
        this->baseSalary = salary;
        return true;
    }
    void setHourlyRate(double rate)
    {
        if (rate >= 10.00 && rate <= 150)
        {
            this->hourlyRate = rate;
        }
        else
        {
            cout << "Hourly Rate between 10$ to 150$";
        }
    }
    bool updateHoursWorked(int additionalHours)
    {
        int isValidHoursWorked = hoursWorked + additionalHours;
        if (additionalHours < 0)
        {
            cout << "Negative Additional Hours Now Allowed" << endl;
            return false;
        }
        if (isValidHoursWorked > 60)
        {
            cout << "60 hours per week allowed";
            return false;
        }
        hoursWorked += additionalHours;
        cout << "Hours updated successfully" << endl;
        return true;
    }
    double calculateNetPayout()
    {
        double totalPay = baseSalary + (hoursWorked * hourlyRate);
        hoursWorked = 0;
        cout << "Total Will Be " << totalPay << endl;
        return totalPay;
    }
};

int main()
{
    Employee e("101", "Ali Ahmed", 60000);
    e.setBaseSalary(70000);
    e.setHourlyRate(50);
    e.updateHoursWorked(95);
    e.calculateNetPayout();
    return 0;
}