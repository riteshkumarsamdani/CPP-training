#include<iostream>
#include"array_function.h"
int main(){
    int arr[5];
    std::cout << "enter the elements for array\n";
    for(int index = 0; index < 5; index++ ){
        std::cout << "enter element";
        std::cin >> arr[index];
    }
    print_array(arr,5);
    int max = max_element(arr,5);
    std::cout << "maximum element is: " << max;
    return 0;
}