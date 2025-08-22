#include <iostream>

int main() {
    int x;
    std::cout<<"enter value for number\n";
    std::cin >> x;
    int* ptr = &x;
    std::cout << "Value of x: " << x << std::endl;
    std::cout << "Address of x: " << &x << std::endl;
    std::cout << "Value stored in ptr (address of x): " << ptr << std::endl;
    std::cout << "Value pointed to by ptr: " << *ptr << std::endl;
    *ptr = 100;
    std::cout << "New value of x: " << x << std::endl;
    return 0;
}
