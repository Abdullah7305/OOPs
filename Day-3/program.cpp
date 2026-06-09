#include <iostream>
#include <string>
using namespace std;

// Creating the abstract class with the pure virtual function

class IVehicle
{
public:
    virtual double calculateRentalCost(int days) = 0;
    virtual string getVehicleName() = 0;
};

class Car : public IVehicle
{
private:
    double dailyRate;
    string carName;

public:
    Car(string name)
    {
        if (name.size() == 0)
        {
            throw invalid_argument("Name should be given propely ...");
        }
        dailyRate = 0;
        carName = name;
    }
    double calculateRentalCost(int days) override
    {
        if (days <= 0)
        {
            cout << "Enter Valid Days please" << endl;
            return 0.0;
        }
        if (dailyRate <= 0)
        {
            cout << "Daily Rate is Invalid add Proper Number " << endl;
            return 0.0;
        }
        if (days > 3)
        {
            double cost = (dailyRate * days) + 15.00;
            cout << "15 $ Added for cleaning fee to the total cost " << cost << endl;

            return cost;
        }
        double cost = dailyRate * days;
        cout << "Rental Cost is " << cost << endl;
        return cost;
    }

    void setDailyRate(double rate)
    {
        if (rate <= 0)
        {
            cout << "Enter Valid Rate" << endl;
        }
        else
        {
            dailyRate = rate;
        }
    }

    string getVehicleName() override
    {
        cout << "Car Name is " << carName << endl;
        return carName;
    }
};

class HeavyTruck : public IVehicle
{
private:
    double dailyRate;
    double weightTax;
    string truckName;

public:
    HeavyTruck(string name)
    {
        if (name.size() == 0)
        {
            throw invalid_argument("Name should be given propely ...");
        }
        dailyRate = 0;
        weightTax = 0;
        truckName = name;
    }

    double calculateRentalCost(int days) override
    {
        if (days <= 0)
        {
            cout << "Days are Negative Type Correct One " << endl;
            return 0.0;
        }
        if (weightTax <= 0)
        {
            cout << "Wieght is Nagitive or Invalid" << weightTax << endl;
            return 0.0;
        }
        if (dailyRate <= 0)
        {
            cout << "Invalid Rate " << dailyRate << endl;
            return 0.0;
        }
        double cost = (dailyRate * days) + weightTax;
        cout << "Total Truck Cost is " << cost << endl;
        return cost;
    }

    void setDailyRate(double rate)
    {

        if (rate <= 0)
        {
            cout << "Enter Valid Rate" << endl;
        }
        else
        {
            this->dailyRate = rate;
            cout << "Daily Rate Set " << rate << endl;
        }
    }

    void setWieghtTax(double tax)
    {

        if (tax <= 0)
        {
            cout << "Enter Valid Rate" << endl;
        }
        else
        {
            this->weightTax = tax;
            cout << "Wieght Tax is  " << weightTax << endl;
        }
    }

    string getVehicleName() override
    {
        cout << "Truck name is " << truckName << endl;
        return truckName;
    }
};

void printRentalQuota(IVehicle *ptr, int days)
{

    ptr->calculateRentalCost(days);
    ptr->getVehicleName();
}

int main()
{

    Car c("Mercedes");
    c.setDailyRate(1200);
    HeavyTruck t("Prime");
    t.setDailyRate(900);
    t.setWieghtTax(78);
    // printRentalQuota(&c, 10);
    printRentalQuota(&t, 30);
    return 0;
}