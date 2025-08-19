#include <iostream>

int add(int a, int b) 
{
    int ans;
    ans = a + b;
    return ans;
}

int subtract(int a, int b) 
{
    int ans;
    ans = a - b;
    return ans;
}

long long multiply(int a, int b) 
{
    long long ans;
    ans = a * b;
    return ans;
}

double divide(int a, int b) 
{
    double ans;
    ans = static_cast<double> (a / b);
    return ans;
}
