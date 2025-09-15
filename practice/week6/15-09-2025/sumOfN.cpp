#include <iostream>

int sumOfN(int n)
{
    int sum = 0;
    for(int i=1; i < n; i++)
    {
        sum += i;
    }
    return sum;
}

int main()
{
    int n;
    std::cin >> n;
    int sum = sumOfN(n);
    std::cout << sum;
    return 0;
}
