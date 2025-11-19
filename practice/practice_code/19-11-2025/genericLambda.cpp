#include <iostream>
#include <string>

int main()
{
    auto glambda = [](auto a, auto b)
    {
        return a + b;
    };

    std::cout << glambda(2, 3) << "\n";
    std::cout << glambda(2.5, 4.1) << "\n"; 
    std::cout << glambda(std::string("Hi "), "there") << "\n";
}
