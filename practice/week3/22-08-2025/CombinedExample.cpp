#include <iostream>

void updateWithPointer(int* p) {
    *p += 10;
}

void updateWithReference(int& r) {
    r += 20;
}

int main() {
    int value;
    std::cout << "enter number\n";
    std::cin >> value;
    updateWithPointer(&value);
    std::cout << "After pointer update: " << value << std::endl;
    updateWithReference(value);
    std::cout << "After reference update: " << value << std::endl;
    return 0;
}
