#include <iostream>
#include <exception>

int func(int n)
{
    int* ptr = new int(n);
    return *ptr;
}

int main()
{
    int n;
    std::cout << "hello\n";
    std::cout << "enter number\n";
    std::cin >> n;
    try
    {
        std::cout << func(n);
    }
    catch(...)
    {
        std::cerr << "exception occured\n";
    }
    return 0;
}
