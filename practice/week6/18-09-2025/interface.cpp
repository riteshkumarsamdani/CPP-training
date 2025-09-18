#include <iostream>

class IShape
{
    public: 
        virtual void printType() = 0;
};

class Triangle : public IShape
{
    public:
        void printType() override
        {
            std::cout << "Triangle\n";
        }
};

class Circle : public IShape
{
    public:
        void printType() override
        {
            std::cout << "Circle\n";
        }
        void display()
        {
            std::cout << "this is circle class\n";
        }
};

int main()
{
    IShape* c = new Circle();
    IShape* t = new Triangle();
    c->printType();
    t->printType();
    Circle* cir = new Circle();
    Triangle* tr = new Triangle();
    cir->display();
    cir->printType();
    return 0;
}