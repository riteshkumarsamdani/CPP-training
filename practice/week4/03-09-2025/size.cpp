#include <iostream>

class A
{
    public:
    int x;
    double y;
    int z;
};

int main()
{
    std::cout << sizeof(A);
    A obj;
    std::cout << sizeof(obj);
    std::cout << &obj <<std::endl<< &obj.x <<std::endl<< &obj.y  <<std::endl<< &obj.z  <<std::endl;
    int x;
    std::cout << sizeof(x);
}
