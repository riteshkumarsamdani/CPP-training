#include <iostream>

class A 
{
public:
    virtual void greet()
    {
        std::cout << "Hello from A\n";
    }
};

class B : virtual public A 
{
public:
    void greet() override 
    {
        std::cout << "Hello from B\n";
    }
};

class C : virtual public A 
{
public:
    void greet() override 
    {
        std::cout << "Hello from C\n";
    }
};

class D : public B, public C 
{
public:
    void greet() override 
    {
        std::cout << "Hello from D\n";
    }
};

int main() 
{
    D obj;
    obj.greet(); 
    return 0;
}
