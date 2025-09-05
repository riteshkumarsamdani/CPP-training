#include <iostream>

class Shallow {
    int* data;
public:
    Shallow(int val) {
        data = new int(val);
    }
    Shallow(const Shallow& source) : data(source.data) {
        std::cout << "Shallow copy constructor called\n";
    }
    void show() {
        std::cout << "Value: " << *data << "\n";
    }
    void set(int val) {
        *data = val;
    }
    ~Shallow() {
        delete data;
    }
};

int main() {
    Shallow obj1(10);
    Shallow obj2 = obj1; 
    obj1.set(20);
    obj1.show(); 
    obj2.show(); 
    return 0;
}
