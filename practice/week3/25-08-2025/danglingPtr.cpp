#include <iostream>
int* getPointer() {
    int x = 100;
    return &x;
}
int main() {
    int* ptr = getPointer();
    std::cout << "Dangling pointer example (invalid memory).\n";
    return 0;
}
