#include<iostream>

class A
{
    public:
        A()
        {
            std::cout << "constructor called..." << std::endl;
        }
        ~A()
        {
            std::cout << "destructor called..." << std::endl;
        }
};

int main()
{
    A a;
    return 0;
}
