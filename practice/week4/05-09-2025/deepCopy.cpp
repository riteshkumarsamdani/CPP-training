#include <iostream>

class Deep {
    int* data;
public:
    Deep(int val) {
        data = new int(val);
    }
    Deep(const Deep& source) {
        data = new int(*source.data);  
        std::cout << "Deep copy constructor called\n";
    }
    void show() {
        std::cout << "Value: " << *data << "\n";
    }
    void set(int val) {
        *data = val;
    }
    ~Deep() {
        delete data;
    }
};

int main() {
    Deep obj1(10);
    Deep obj2 = obj1; 
    obj1.set(20);
    obj1.show(); 
    obj2.show(); 
    return 0;
}
