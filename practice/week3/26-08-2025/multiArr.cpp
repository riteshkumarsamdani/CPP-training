#include<iostream>

int main()
{
    int arr[] = {2, 3, 4, 5};
    int multiArr[3][4] = {
        {1, 2, 3, 5},
        {3, 4, 5, 6},
        {1, 2 ,3, 5}
    };
    std::cout << arr << std::endl;
    std::cout << multiArr << std::endl;
    std::cout << *arr << std::endl;
    std::cout << *multiArr <<std::endl;
    std::cout << arr[0] << std::endl;
    std::cout << multiArr[0] <<std::endl;
    std::cout << *multiArr + 1 << std::endl;
    std::cout << *(multiArr + 1) << std::endl;
    std::cout << **multiArr + 1 << std::endl;
    std::cout << **(multiArr + 1) << std::endl;
    return 0;
}