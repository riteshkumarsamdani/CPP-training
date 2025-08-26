#include<iostream>

int main()
{
    int a[] = {2, 3, 4, 10, 11};
    int length = sizeof(a)/sizeof(a[0]);
    for(int i = 0; i < length; i++)
    {
        std::cout << &a[i] << std::endl;
        std::cout << (a + i) << std::endl;
        std::cout << a[i] << std::endl;
        std::cout << *(a + i) << std::endl;
    }
    return 0;
}