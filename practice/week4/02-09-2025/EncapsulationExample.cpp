#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int age;
    std::string studentID;
public:
    Student(std::string n, int a, std::string id) {
        name = n;
        if (a > 0 && a < 120) 
        {
            age = a;
        } 
        else 
        {
            age = 0; 
            std::cout << "Invalid age provided for " << n << std::endl;
        }
        studentID = id;
    }
    std::string getName() 
    {
        return name;
    }
    int getAge() 
    {
        return age;
    }
    std::string getStudentID() 
    {
        return studentID;
    }
    void setAge(int newAge) 
    {
        if (newAge > 0 && newAge < 120) 
        {
            age = newAge;
        }
        else 
        {
            std::cout << "Invalid age provided." << std::endl;
        }
    }
};

int main() {
    Student student1("Ram", 20, "S12345");
    std::cout << "Student Name: " << student1.getName() << std::endl;
    std::cout << "Student Age: " << student1.getAge() << std::endl;
    std::cout << "Student ID: " << student1.getStudentID() << std::endl;
    student1.setAge(21);
    std::cout << "Updated Age: " << student1.getAge() << std::endl;
    student1.setAge(-5);
    std::cout << "Age after invalid attempt: " << student1.getAge() << std::endl;
    return 0;
}