#include <iostream>

class Vehicle
{
    int price{};
    std::string modelName{};
    int modelNumber{};
    public:
    void setPrice(int price);
    void setModelNumber(int modelNumber);
    void setModelName(std::string modelName);
    int getPrice();
    int getModelNumber();
    std::string getModelName();
};

void Vehicle::setPrice(int price)
{
    this->price = price;
}

void Vehicle::setModelNumber(int modelNumber)
{
    this->modelNumber = modelNumber;
}

void Vehicle::setModelName(std::string modelName)
{
    this->modelName = modelName;
}

int Vehicle::getPrice()
{
    return this->price;
}

int Vehicle::getModelNumber()
{
    return this->modelNumber;
}

std::string Vehicle::getModelName()
{
    return this->modelName;
}

int main()
{
    Vehicle car{};
    std::cout << "name:" << car.getModelName() << "\nprice:" << car.getPrice() << "\nmodel:" << car.getModelNumber() << "\n";
    car.setModelName("volvo");
    car.setModelNumber(123);
    car.setPrice(1220000);
    std::cout << "name:" << car.getModelName() << "\nprice:" << car.getPrice() << "\nmodel:" << car.getModelNumber() << "\n";
    return 0;
}
