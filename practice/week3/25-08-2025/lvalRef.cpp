#include <iostream>

void modifyLvalue(int& ref) {
    ref += 5;
    std::cout << "Modified lvalue: " << ref << "\n";
}

void readLvalue(const int& ref) {
    std::cout << "Const lvalue (read-only): " << ref << "\n";
}

int main() {
    int x = 10;
    modifyLvalue(x); 
    readLvalue(x);  
    return 0;
}
