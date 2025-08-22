#include <iostream>

void swapWithReference(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 30, y = 40;
    std::cout << "Before swap (reference): x = " << x << ", y = " << y << std::endl;
    swapWithReference(x, y);
    std::cout << "After swap (reference): x = " << x << ", y = " << y << std::endl;
    return 0;
}
