#include <iostream>

int main() {
    int x;
    std::cout << "Enter number for input\n";
    std::cin>>x;
    int& ref = x;
    std::cout << "Value of x: " << x << std::endl;
    std::cout << "Value of ref: " << ref << std::endl;
    std::cout << "enter number\n";
    std::cin >> ref;
    std::cout << "New value of x: " << x << std::endl;
    return 0;
}
