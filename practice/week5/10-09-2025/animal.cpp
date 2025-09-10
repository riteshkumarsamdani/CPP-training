#include <iostream>

class Animal {
public:
    virtual void speak() const = 0;
};

class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        std::cout << "Meow!" << std::endl;
    }
};

void makeItSpeak(const Animal& a) {
    a.speak();
}

int main() {
    Dog d;
    Cat c;
    makeItSpeak(d);
    makeItSpeak(c);
    return 0;
}
