#include <iostream>

template<typename T>
T compare(T a, T b)
{
    return (a > b) ? a : b;
}

template<class X, class Y>
X compare(X a, Y b)
{
    return (a > b) ? a : b;
}

int main()
{
    std::cout << compare(2, 3);
    std::cout << compare(2.0, 3.3);
    std::cout << compare('a', 'b');
    std::cout << compare(2.2, 5.6);
    std::cout << compare(2, 3.3);
    std::cout << compare(5.3,3);
    std::cout << compare('a', 99);
    return 0;
}