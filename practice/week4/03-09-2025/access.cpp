#include<iostream>


class B
{
    public:
    int b = 5;
};

class A
{
    private:
    int a = 10;
    public:
    void print(B obj)
    {
        std::cout << a << obj.b << std::endl;
    }
};

int main()
{
    A a;
    B obj;
    a.print(obj);
    return 0;
}