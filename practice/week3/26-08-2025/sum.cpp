#include<iostream>
#include<vector>

int sum(int arr[])
{
    int sum = 0;
    for(int i = 0; i < 5; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}

int total(std::vector<int> a)
{
    int sum = 0;
    for(int i = 0; i < 5; i++)
    {
        sum = sum + a[i];
    }
    return sum;
}

void Double(int a[])
{
    for(int i = 0; i < 5; i++)
    {
        a[i] = 2*a[i];
    }
}

void DoubleVector(std::vector<int> a)
{
    for(int i = 0; i < 5; i++)
    {
        a[i] = 2*a[i];
    }
}

int main()
{
    int arr[] = {2, 5, 4, 54, 324};
    std::vector<int> a = {3, 4, 54, 12, 54};
    std::cout << sum(arr) << std::endl;
    std::cout << total(a) << std::endl;
    Double(arr);
    DoubleVector(a);
    for(int i = 0; i < 5; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    for(int i = 0; i < 5; i++)
    {
        std::cout << a[i] << std::endl;
    }
    return 0;
}