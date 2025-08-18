#include <iostream>
#include<string>
#include "my_functions.h"

int main() {
    int a,b;
    std::cout << "enter two number to find sum\n";
    std::cin >> a >> b;
    int sum = add(a, b); 
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Enter your name: ";
    std::string name;
    std::cin >> name;
    greet("Hello " + name);

    MyClass obj;
    obj.do_something();

    return 0;
}
