#include <iostream>
int& getElement(int arr[], int index) {
    return arr[index];
}

int main() {
    int nums[] = {1, 2, 3};
    getElement(nums, 1) = 99;
    std::cout << "Reference Return: " << nums[1] << std::endl;
    return 0;
}
