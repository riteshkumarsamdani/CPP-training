#include <iostream>

class A 
{
public:
    void show() { std::cout << "Hello from A\n"; }
};

class B : public A {};
class C : public A {};
class D : public B, public C {}; 

int main() 
{
    D obj;
    // obj.show();   Ambiguous: compiler doesn't know whether to use B::A or C::A
    return 0;
}
