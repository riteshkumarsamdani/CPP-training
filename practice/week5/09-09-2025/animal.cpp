#include <iostream>

class Animal;

class Dog
{
    std::string name = "dog";
    friend class Animal;
};

class Animal
{
    public:
        void makeSound()
        {
            std::cout << "noise !!!!\n";
        }
        void eat(Dog& d)
        {
            std::cout << d.name << " eating\n";
        }
};

int main()
{
    Animal obj;
    Dog d;
    obj.makeSound();
    obj.eat(d);

    // makeSound();
    return 0;
}
