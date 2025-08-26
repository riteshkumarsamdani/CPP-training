#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int> ptr = std::make_unique<int>(99);
    std::cout << *ptr << "\n";
    return 0;
}
