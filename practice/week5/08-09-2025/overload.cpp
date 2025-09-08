#include <iostream>

class Printer {
public:
    void print(int i) {
        std::cout << "Printing int: " << i << std::endl;
    }

    void print(double d) {
        std::cout << "Printing double: " << d << std::endl;
    }

    void print(std::string s) {
        std::cout << "Printing string: " << s << std::endl;
    }
};

int main() {
    Printer p;
    p.print(10);
    p.print(3.14);
    p.print("Hello");
    return 0;
}
