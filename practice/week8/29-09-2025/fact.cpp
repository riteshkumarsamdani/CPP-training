#include <iostream>

template <int N>
struct Factorial {
    static constexpr int value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> {
    static constexpr int value = 1;
};

int main() {
    std::cout << "Factorial of 5: " << Factorial<5>::value << std::endl;
    std::cout << "Factorial of 0: " << Factorial<0>::value << std::endl;

    return 0;
}
