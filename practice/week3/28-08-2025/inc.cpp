#include<iostream>

void inc(int *ptr)
{
    (*ptr)++;
    return ;
}

int main()
{
    int a = 10;
    int *ptr = &a;
    inc(ptr);
    std::cout << a;
    return 0;
}