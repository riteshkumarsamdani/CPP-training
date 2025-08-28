#include<iostream>

int main()
{
    int *ptr = new int(5);
    int *a = ptr;
    std::cout << a <<std::endl;
    std::cout << *ptr << std::endl;
    std::cout << ptr << std::endl;
    ptr = new int(10);
    std::cout << *ptr << std::endl;
    delete(ptr);
    // ptr = nullptr;
    std::cout << *ptr << std::endl;
    return 0;
}
