#include <iostream>

int main()
{
    try
    {
        // std::string s= "something wrong";
        // throw "something went wrong"; 
        // throw s;
        throw 4;
        std::cout << "This never prints\n";
    }
    catch(double x)
    {
        std::cerr << "We caught a double of value: " << x << '\n';
    }
    catch(int x)
    {
        std::cerr << "new exception\n";
    }
    catch(std::string s)
    {
        std::cerr << "string:" << s;
    }
    catch(char const* c)
    {
        std::cerr << "char string:" << c;
    }
    return 0;
}