#include <iostream>
#include <cmath>

double mySqrt(int n)
{
    if(n < 0)
    {
        throw std::runtime_error("number can't be negative");
    }
    return std::sqrt(n);
}

int main()
{
    int n;
    std::cout << "enter number\n";
    std::cin >> n;
    try
    {
        std::cout << mySqrt(n);
    }
    catch(std::runtime_error& e)
    {
        std::cout << "exception occure: " << e.what();
    }
    return 0;
}
