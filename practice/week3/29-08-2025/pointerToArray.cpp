#include <iostream>
const int COLS = 4;
int main() 
{
    int rows = 3;
    int (*arr)[COLS] = new int[rows][COLS];
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < COLS; ++j) 
        {
            arr[i][j] = i * COLS + j + 1;
        }
    }
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < COLS; ++j) 
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    delete[] arr;
    arr = nullptr;
    return 0;
}
