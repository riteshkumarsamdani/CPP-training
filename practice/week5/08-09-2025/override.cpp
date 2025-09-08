#include <iostream>

class Animal {
public:
    virtual void speak() {
        std::cout << "Animal speaks" << std::endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {
        std::cout << "Dog barks" << std::endl;
    }
};

int main() {
    Animal* a;
    Dog d;
    a = &d;

    a->speak();
    return 0;
}
