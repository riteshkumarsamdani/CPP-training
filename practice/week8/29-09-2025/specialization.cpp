#include <iostream>

template <typename T>
class Printer {
public:
    void print(T value) {
        std::cout << "Generic: " << value << std::endl;
    }
};

template <>
class Printer<bool> {
public:
    void print(bool value) {
        std::cout << "Boolean: " << (value ? "true" : "false") << std::endl;
    }
};

int main() {
    Printer<int> intPrinter;
    intPrinter.print(42);

    Printer<bool> boolPrinter;
    boolPrinter.print(false);

    Printer<std::string> strPrinter;
    strPrinter.print("Generic string");

    return 0;
}
