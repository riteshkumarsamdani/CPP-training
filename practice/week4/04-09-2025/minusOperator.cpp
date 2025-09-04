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

    Calc operator-()
    {
        Calc temp;
        temp.a = -a;
        return temp;
    }
    Calc operator-(Calc obj)
    {
        Calc temp;
        temp.a=a-obj.a;
        return temp;
    }
};

int main()
{
    Calc obj;
    obj.setA(5);
    Calc obj2;
    -obj;
    -4;
    Calc obj4 ;
    obj4.setA(10);
    Calc obj3 = obj-obj4;
    std::cout << obj.getA() << "\n";
    std::cout << obj2.getA() << "\n";
    std::cout << obj3.getA() << "\n";
    std::cout << obj4.getA() << "\n";
    return 0;
}
