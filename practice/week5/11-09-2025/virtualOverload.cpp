#include <iostream>

class A 
{
public:
    int value;
    A() : value(42) {}
};

class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};

int main() 
{
    D obj;
    std::cout << "Value from A: " << obj.value << std::endl;
    return 0;
}
