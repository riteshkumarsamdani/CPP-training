#include <iostream>
#include <fstream>
#include <string>

struct Person 
{
    char name[50];
    int age;
};

void write_to_binary() 
{
    std::ofstream outfile("data.bin", std::ios::binary);

    if (!outfile) 
    {
        std::cerr << "Error: Could not open the file for writing." << std::endl;
        return;
    }

    Person p = {"Alice", 30};

    outfile.write(reinterpret_cast<const char*>(&p), sizeof(Person));

    outfile.close();
    std::cout << "Data written to data.bin successfully." << std::endl;
}

void read_from_binary() 
{
    std::ifstream infile("data.bin", std::ios::binary);

    if (!infile) 
    {
        std::cerr << "Error: Could not open the file for reading." << std::endl;
        return;
    }

    Person p_read;
    infile.read(reinterpret_cast<char*>(&p_read), sizeof(Person));
    infile.close();

    std::cout << "Data read from data.bin:" << std::endl;
    std::cout << "Name: " << p_read.name << std::endl;
    std::cout << "Age: " << p_read.age << std::endl;
}

int main() 
{
    write_to_binary();
    read_from_binary();

    return 0;
}
