#include <iostream>
int main() {
    int x = 5;
    int* ptr = &x;
    int** pptr = &ptr;
    std::cout << "Value: " << **pptr << "\n";
    return 0;
}
