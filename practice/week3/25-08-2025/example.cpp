#include <iostream>
#include <memory>

void modifyValue(int* const ptr) {
    *ptr = 42;
    std::cout << "Modified value via constant pointer: " << *ptr << "\n";
}

void readValue(const int* ptr) {
    std::cout << "Read-only value via pointer to const: " << *ptr << "\n";
}

void useSmartPointer(std::unique_ptr<int>& smartPtr) {
    *smartPtr += 10;
    std::cout << "Smart pointer value: " << *smartPtr << "\n";
}

int main() {
    int x = 5;
    int* const constPtr = &x;
    modifyValue(constPtr);
    const int* ptrToConst = &x;
    readValue(ptrToConst);
    std::unique_ptr<int> smartInt = std::make_unique<int>(100);
    useSmartPointer(smartInt);
    return 0;
}
