#include <iostream>

class A
{
    public: A()
    {
        std::cout << "A\n";
    }
    void print()
    {
        std::cout << "print\n";
    }
};

class B : virtual public A
{
    public: B()
    {
        std::cout << "B\n";
    }
};

class C : virtual public A
{
    public: C()
    {
        std::cout << "C\n";
    }
};

class D : public B, public C
{
    public: D()
    {
        std::cout << "D\n";
    }
};

int main()
{
    D d;
    d.print();
    return 0;
}