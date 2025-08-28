#include<iostream>
#include<vector>

void arrDouble(int arr[])
{
    for(int i = 0; i < 5; i++)
    {
        arr[i] = arr[i]*2;
    }
}

void vecDouble(std::vector<int> v1)
{
    for(int i = 0; i < 5; i++)
    {
        v1[i] = v1[i]*2;
    }
}

void doDouble(int a)
{
    a = a*2;
}

void concate(char str[])
{
    for(int i = 0; i < 5; i++)
    {
        str[i] = (str[i] + 1);
    }
}

int main()
{
    std::vector<int> v1 = {2,3,4,5,6};
    vecDouble(v1);
    for(int i : v1)
    {
        std::cout << i << " "; 
    }
    std::cout << std::endl;
    int a = 10;
    doDouble(a);
    std::cout << a << std::endl;
    char str[] = "Hello";
    concate(str);
    std::cout << str << std::endl;
    int arr[] = {1,2,3,4,5};
    arrDouble(arr);
    for(int i : arr)
    {
        std::cout << i << " "; 
    }
    std::cout << std::endl;
    return 0;
}
