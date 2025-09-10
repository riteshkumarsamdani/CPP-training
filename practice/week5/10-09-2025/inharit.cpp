#include <iostream>

class A
{
    public:
    A(int x)
    {
        std::cout << "hellos" << x;
    }
};
class B: public A
{
    public:
        B(int x):A(x)
        {
            std::cout << "this is b";
        }
};
int main()
{
    B b(4);
    return 0;
}