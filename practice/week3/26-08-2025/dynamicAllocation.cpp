#include <iostream>

int main() {
    int* ptr = new int; 
    *ptr = 42; 
    std::cout << *ptr << "\n";
    delete ptr; 
    ptr = nullptr; 
    return 0;
}
