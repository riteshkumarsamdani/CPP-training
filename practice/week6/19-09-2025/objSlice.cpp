#include <iostream>
#include <stdexcept>

class MyDerivedException : public std::runtime_error 
{
    public:
        MyDerivedException() : std::runtime_error("Derived exception") {}
        void custom_info() const{ std::cerr << "Custom info: an extra detail." << std::endl; }
};

int main() {
    try {
        throw MyDerivedException();
    }
    catch (const MyDerivedException& e) 
    {
        std::cerr << "Caught derived exception: " << e.what() << std::endl;
        e.custom_info(); 
    }
    catch (const std::exception& e) 
    { 
        std::cerr << "Caught standard exception: " << e.what() << std::endl;
        // e.custom_info(); 
    }
    // catch (std::exception e) 
    // { 
    //     std::cerr << "Caught standard exception: " << e.what() << std::endl;
    //     // e.custom_info(); 
    // }
    return 0;
}
