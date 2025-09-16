#include <iostream>
#include <exception>

void myhandler()
{
    std::cout << "Inside new terminate handler\n";
    abort();
}

int main()
{
    std::set_terminate(myhandler); 
    try {
        std::cout << "Inside try block\n";
        throw 100;
    }
    catch (char a)
    {
        std::cout << "Inside catch block\n";
    }
    return 0;
}