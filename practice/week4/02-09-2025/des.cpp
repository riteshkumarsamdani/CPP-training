#include <iostream>

class DynamicArray {
private:
    int* arr;
    int size;

public:
    DynamicArray(int arraySize) {
        size = arraySize;
        arr = new int[size];
        std::cout << "Constructor called. Dynamic array of size " << size << " created." << std::endl;
    }

    ~DynamicArray() {
        delete[] arr;
        std::cout << "Destructor called. Dynamic memory freed." << std::endl;
    }

    void fillArray() {
        for (int i = 0; i < size; ++i) {
            arr[i] = i * 10;
        }
    }

    void printArray() {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    {
        DynamicArray my_array(5); 
        my_array.fillArray();
        my_array.printArray();
    } 
    std::cout << "End of main function." << std::endl;
    return 0;
}
