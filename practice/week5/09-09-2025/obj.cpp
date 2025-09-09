#include<iostream>

class A
{
    public:
        void display()
        {
            std::cout << "class a\n";
        }
};

class B : public A
{
    public:
        void print()
        {
            std::cout << "class b\n";
        }
};

int main()
{
    A a;
    B b;
    A a1 = b;
    // A a2 = &b;
    // B b1 = a;
    // B b2 = &a;
    // a.print();
    a.display();
    b.print();
    b.display();
    // a1.print();
    a1.display();
    // b1.print();
    // b1.display();
    // a2.print();
    // a2.display();
    // b2.print();
    // b2.display();
    return 0;
}