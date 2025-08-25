#include <iostream>
int main() {
    int x = 42;
    void* vptr = &x;
    std::cout << "Value via void pointer: " << *(static_cast<int*>(vptr)) << "\n";
    return 0;
}
