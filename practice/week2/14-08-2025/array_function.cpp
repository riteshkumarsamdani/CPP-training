#include "array_function.h"

void print_array(const int arr[], int size) {
    for (int i = 0; i < size; ++i) { 
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl; 
}

int max_element(const int arr[], int size) {
    if (size <= 0) {
        std::cerr << "Error: Array is empty or has an invalid size." << std::endl;
        return -1;
    }
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
