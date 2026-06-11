#include <iostream>
#include <cstring>
using namespace std;

class Product
{
protected:
    string productId;
    string name;
    double basePrice;

public:
    Product(string id, string nm, double price) : productId(id), name(nm), basePrice(price) {}

    virtual double calculateFinalPrice()
    {
        float tax = 0.05 * basePrice;
        basePrice += tax;
        cout << "Price is " << basePrice << endl;
        return basePrice;
    }
    double getBasePrice()
    {

        return basePrice;
    }
};

class PhysicalProduct : public Product
{
private:
    double shippingWieght;

public:
    PhysicalProduct(string id, string name, double price, double wieght) : Product(id, name, price), shippingWieght(wieght) {}
    double basePrice = getBasePrice();
    double calculateFinalPrice() override
    {
        double parentTotal = Product::calculateFinalPrice();
        double shippingPrice = shippingWieght * 2.0;
        parentTotal += shippingPrice;
        cout << "Price is " << parentTotal << endl;
        return parentTotal;
    }
};

class DigitalProduct : public Product
{
private:
    string downloadLink;

public:
    DigitalProduct(string id, string name, double price, string link) : Product(id, name, price), downloadLink(link) {}
    double basePrice = getBasePrice();
    double calculateFinalPrice()
    {
        cout << "Price is " << basePrice << endl;
        return basePrice;
    }
};

int main()
{
    PhysicalProduct prod("101", "Gloves", 5.4, 87.3);
    DigitalProduct digProd("102", "Software", 540, "www.google.com");
    prod.calculateFinalPrice();
    digProd.calculateFinalPrice();
    return 0;
}