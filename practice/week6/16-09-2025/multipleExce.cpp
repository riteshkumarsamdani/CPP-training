#include <iostream>

int main() {
    try {
        int choice;
        std::cout << "Enter 1 for invalid argument, "
            << "2 for out of range: ";
        std::cin >> choice;
        if (choice == 1) 
        {
            throw std::invalid_argument("Invalid argument");
        }
        else if (choice == 2) 
        {
            throw std::out_of_range("Out of range");
        }
        else 
        {
            throw "Unknown error";
        }
    }
    catch (std::invalid_argument e) 
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    catch (std::out_of_range e) 
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    catch (...) 
    {
        std::cout << "Caught an unknown exception." << std::endl;
    }
    return 0;
}