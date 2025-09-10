#include <iostream>

class Utility 
{
    public:
        static void greet() 
        {
            std::cout << "Hello from static function!" << std::endl;
        }
};

int main() 
{
    Utility::greet(); 
    return 0;
}
