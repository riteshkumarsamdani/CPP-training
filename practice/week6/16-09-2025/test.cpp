#include <iostream>

class A
{
    public:
        virtual void print() = 0;
};

class B : public A
{
    public:
    void print() override
    {
        std::cout << "print\n";
    }
    void display()
    {
        std::cout << "display\n";
    }
};
int main()
{
    B* b = new B();
    b->print();
    b->display();
    
}