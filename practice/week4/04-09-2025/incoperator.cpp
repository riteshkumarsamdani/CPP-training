#include <iostream>

class Calc
{
    int a{};
    public:
    void setA(int a)
    {
        this->a = a;
    }

    int getA()
    {
        return a;
    }

    Calc operator++()
    {
        Calc temp;
        temp.a = ++a;
        return temp;
    }

    Calc operator++(int)
    {
        Calc temp;
        temp.a = a++;
        return temp;
    }

    int getx()
    {
        int x =10;
        return x;
    }
};

int number()
{
    return 2;
}

int main()
{
    number();
    Calc obj;
    obj.getx();
    obj.setA(5);
    ++obj;
    Calc obj3 = obj++;
    obj++;
    // Calc obj4;
    // obj4=obj;
    Calc obj2 = ++obj;
    std::cout << obj.getA() << "\n";
    std::cout << obj2.getA() << "\n";
    std::cout << obj3.getA() << "\n";
    // std::cout << obj4.getA() <<"\n";
    return 0;
}
