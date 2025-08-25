#include <iostream>

void modifyRvalue(int&& val) {
    val += 10;
    std::cout << "Modified rvalue: " << val << "\n";
}

void readRvalue(const int&& val) {
    std::cout << "Const rvalue (read-only): " << val << "\n";
}

int main() {
    modifyRvalue(20); 
    readRvalue(50);

    int x = 100;
    modifyRvalue(std::move(x));
}
