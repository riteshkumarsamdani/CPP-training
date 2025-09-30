#include<iostream>
#include<array> 
#include<tuple> 
int main()
{
    std::array<int,6> ar = {1, 2, 3, 4, 5, 6};
    std::array<int,5> arr1;
    std::cout << "The array elements are (using at()) : ";
    for ( int i=0; i<6; i++)
    std::cout << ar.at(i) << " ";
    std::cout << std::endl;

    std::cout << "The array elements are (using get()) : ";
    std::cout << std::get<0>(ar) << " " << std::get<1>(ar) << " ";
    std::cout << std::get<2>(ar) << " " << std::get<3>(ar) << " ";
    std::cout << std::get<4>(ar) << " " << std::get<5>(ar) << " ";
    std::cout << std::endl;

    std::cout << "The array elements are (using operator[]) : ";
    for ( int i=0; i<6; i++)
    std::cout << ar[i] << " ";
    std::cout << std::endl;
    ar.front() = 10;
    std::cout << ar.size();
    std::cout << arr1.size();
    std::cout << arr1.empty();
    std::cout << ar.front();
    std::cout << ar.back();
    return 0;

}