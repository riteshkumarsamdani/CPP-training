#include <iostream>
#include <stdexcept>

int main()
{
    int arr[3];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    // arr[3] = 8;
    // arr[4] = 9;
    arr[5] = 3;
    arr[6] = 2;
    std::cout << arr[6];
    return 0;
}
