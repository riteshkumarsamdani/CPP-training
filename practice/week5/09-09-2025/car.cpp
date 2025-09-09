#include <iostream>

class Car
{
    private:
        double price;
        std::string name;
    public:
        friend std::ostream& operator<<(std::ostream& out,const Car&);
        friend std::istream& operator>>(std::istream& in, Car&);
};

std::ostream& operator<<(std::ostream& out, const Car& obj)
{
    out << "price is:" << obj.price << std::endl << "name is:" << obj.name;
    return out;
}

std::istream& operator>>(std::istream& in, Car& obj)
{
    std::cout << "enter price\n";
    in >> obj.price;
    std::cout << "enter name\n";
    in >> obj.name;
    return in;
}

int main()
{
    Car c;
    std::cin >> c;
    std::cout << c;
    return 0;
}
