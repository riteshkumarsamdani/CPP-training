#include <iostream>

class Calc
{
    private:
        int a,b;
    public:
        int getA()
        {
            return a;
        }
        int getB()
        {
            return b;
        }
        void setA(int x)
        {
            a = x;
        }
        void setB(int y)
        {
            b = y;
        }
};

Calc operator+(Calc& obj1, Calc& obj2)
{
    Calc temp;
    temp.setA(obj1.getA()+obj2.getA());
    temp.setB(obj1.getB()+obj2.getB());
    return temp;
}

int main()
{
    Calc obj1;
    Calc obj2;
    obj1.setA(10);
    obj2.setA(5);
    obj1.setB(3);
    obj2.setB(20);
    Calc obj3 = obj1 + obj2;
    std::cout << obj3.getA() << obj3.getB();
    std::cout << std::endl << sizeof(obj1);
    return 0;
}