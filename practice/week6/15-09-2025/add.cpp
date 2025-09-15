#include <iostream>

int add(int x, int y)
{
    return x + y;
}

int main()
{
    int x;
    int y = 0;
    x = 2;
    y = 10;
    int sum = add(x, y);
    std::cout << sum;
    return 0;
}
