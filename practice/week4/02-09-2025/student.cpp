#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int rollNumber;

public:
    Student(std::string name, int rollNumber) {
        this->name = name;
        this->rollNumber = rollNumber;
        std::cout << "Constructor called for student: " << this->name << std::endl;
    }

    void displayInfo() {
        std::cout << "Name: " << this->name << ", Roll Number: " << this->rollNumber << std::endl;
    }
};

int main() {
    Student student1("Alice", 101);
    student1.displayInfo();
    return 0;
}
