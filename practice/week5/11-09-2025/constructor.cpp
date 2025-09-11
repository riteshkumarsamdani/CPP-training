#include <iostream>

class A 
{
public:
    A() { std::cout << "A constructor\n"; }
};

class B : virtual public A 
{
public:
    B() { std::cout << "B constructor\n"; }
};

class C : virtual public A 
{
public:
    C() { std::cout << "C constructor\n"; }
};

class D : public B, public C 
{
public:
    D() { std::cout << "D constructor\n"; }
};

int main() 
{
    D obj;
    return 0;
}
