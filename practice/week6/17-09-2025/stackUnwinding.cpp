#include <iostream>
#include <exception>

void func1()
{
    std::cout << "before throwing in func1\n";
    throw 1;
    std::cout << "after throwing in func1\n";
}

void func2()
{
    std::cout << "before calling func1\n";
    func1();
    std::cout << "after calling func1\n";
}

void func3()
{
    std::cout << "before calling func2\n";
    try{
        func2();
    }
    catch(int e)
    {
        std:: cout << e;
    }
    std::cout << "after calling func2\n";
}

int main()
{
    try{
        func3();
    }
    catch(int e)
    {
        std:: cout << e;
    }
    return 0;
}