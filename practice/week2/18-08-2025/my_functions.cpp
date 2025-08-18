#include "my_functions.h" 
#include <iostream> 
#include<string>

int add(int a, int b) {
    return a + b;
}

void greet(const std::string& name) {
    std::cout << "Hello, " << name << "!" << std::endl;
}

void MyClass::do_something() {
    std::cout << "MyClass is doing something." << std::endl;
}
