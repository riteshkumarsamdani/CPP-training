#include <iostream>

int add(int a, int b)
{
    std::cout << "addition is:" << a+b;
    return a+b;
}

int main()
{
    add(5,2);
    // std::cout << add << std::endl << sizeof(add);
    std::cout << add;
    return 0;
}
