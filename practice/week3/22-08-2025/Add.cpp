#include<iostream>

int add(int *a, int *b){
    *a++;
    return *a+*b;
}

int main()
{
    int a = 10;
    int b = 10;
    int *x = &a;
    int *y = &b;
    int ans=add(x, y);
    std::cout << *y;
    std::cout << ans;
    return 0;
}