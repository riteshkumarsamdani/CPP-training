#include <iostream>
#include <stdexcept>
#include <vector>
#include <limits>

void validateAge(int age) {
    if (age < 0) {
        throw std::invalid_argument("Age cannot be a negative number.");
    }
    std::cout << "Age validation successful: " << age << std::endl;
}

void accessVectorElement(const std::vector<int>& data, int index) {
    if (index >= data.size()) {
        throw std::out_of_range("Vector index is out of bounds.");
    }
    std::cout << "Value at index " << index << ": " << data.at(index) << std::endl;
}

void calculateSum(long a, long b) {
    if (a > 0 && b > 0 && a > std::numeric_limits<long>::max() - b) {
        throw std::overflow_error("Arithmetic overflow occurred.");
    }
    long sum = a + b;
    std::cout << "Sum is: " << sum << std::endl;
}

int main() {
    try 
    {
        validateAge(-5);
    } 
    catch (const std::invalid_argument& e) 
    {
        std::cerr << "Caught Invalid Argument Exception: " << e.what() << std::endl;
    }

    std::vector<int> my_vector = {10, 20, 30};
    try 
    {
        accessVectorElement(my_vector, 5);
    } 
    catch (const std::out_of_range& e) 
    {
        std::cerr << "Caught Out of Range Exception: " << e.what() << std::endl;
    }

    try 
    {
        calculateSum(std::numeric_limits<long>::max(), 1);
    } 
    catch (const std::overflow_error& e) 
    {
        std::cerr << "Caught Overflow Error Exception: " << e.what() << std::endl;
    }

    try 
    {
        throw std::runtime_error("This is a general runtime error.");
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Caught a general standard exception: " << e.what() << std::endl;
    }

    try 
    {
        throw 42; 
    } 
    catch (...) 
    {
        std::cerr << "Caught an unknown or unspecified exception." << std::endl;
    }
    return 0;
}
