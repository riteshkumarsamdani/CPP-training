#include <iostream>
void greet() {
    std::cout << "Hello from function pointer!\n";
}
int main() {
    void (*funcPtr)() = greet;
    funcPtr();
    return 0;
}
