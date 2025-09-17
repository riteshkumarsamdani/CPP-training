#include <iostream>

int fact(int n)
{
    if(n < 0)
        throw "n cant be negative\n";
    if(n == 0)
    {
        return 1;
    }
    return n * fact(n-1);
}
int main()
{
    int n;
    std::cout << "inside factorial main\n";
    std::cout << "enter number to find factorial\n";
    std::cin >> n;
    try
    {
        int factorial = fact(n);
        std::cout << "factorial of " << n << " is : " << factorial << "\n";
    } 
    catch(char const*& e)
    {
        std::cerr << "exception found " << e;
    }
    catch(...)
    {
        std::cerr << "error for runtime";
    }
    return 0;
}