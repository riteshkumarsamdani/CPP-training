#include<iostream>

int *sum(int &a, int &b)
{
    int *output = new int(a + b);
    return output;
}

int sumRef(int *a, int *b)
{
    return *a + *b;
}

int main()
{
    int a=10;
    int b=10;
    int *ptr = sum(a,b);
    std::cout << *ptr;
    std::cout << sumRef(&a, &b);
    // std::cout << *sum(a,b);
}