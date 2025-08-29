#include <iostream>

int main() 
{
    int rows = 3;
    int cols = 4;
    int** arr = new int*[rows];
    for (int i = 0; i < rows; ++i) 
    {
        arr[i] = new int[cols];
    }
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            arr[i][j] = i * cols + j + 1;
        }
    }
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < rows; ++i) 
    {
        delete[] arr[i];
    }
    delete[] arr; 
    arr = nullptr; 
    return 0;
}
