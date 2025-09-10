#include <iostream>

class IShape 
{
    public:
        virtual void draw() = 0;
};

class Circle : public IShape 
{
    public:
        void draw() override 
        {
            std::cout << "Drawing Circle" << std::endl;
        }
};

int main() 
{
    IShape* shape = new Circle();
    shape->draw();
    delete shape;
    return 0;
}
