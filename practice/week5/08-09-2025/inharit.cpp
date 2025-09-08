#include <iostream>

class A
{
    public: 
    virtual void display()
    {
        std::cout << "this is class a\n";
    }
};

class B: public A
{
    public:
    void display() override
    {
        std::cout << "this is class b\n";
    }
    void print()
    {
        std::cout <<"b.print\n";
    }
};

void display(A a) {
    a.display();
}

int main()
{
    A a;
    B b;
    A a2=b;
    A* a1 = new B();
    a.display();
    b.display();
    a1->display();
    a2.display();
    display(b);
    // a2.print();

}
