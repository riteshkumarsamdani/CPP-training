#include<iostream>

int increment(int a)
{
    return a + 1;
}

void inc(int *p)
{
    *p = ((*p)+1);
}

int main()
{
    int a = 10;
    a = increment(a);
    std::cout << a;
    inc(&a);
    std::cout << a;
    return 0;
}