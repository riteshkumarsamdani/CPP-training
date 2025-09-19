#include <iostream>
#include <fstream>
#include <string>

struct Person 
{
    char name[50];
    int age;
};

void write_multiple_records() 
{
    std::ofstream outfile("people.bin", std::ios::binary);
    if (!outfile) 
    {
        std::cerr << "Error: Could not open the file for writing." << std::endl;
        return;
    }

    Person people[] = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 35}
    };

    for (const auto& p : people) 
    {
        outfile.write(reinterpret_cast<const char*>(&p), sizeof(Person));
    }
    outfile.close();
    std::cout << "Multiple records written to people.bin." << std::endl;
}

void read_specific_record(int record_index) 
{
    std::ifstream infile("people.bin", std::ios::binary);
    if (!infile) 
    {
        std::cerr << "Error: Could not open the file for reading." << std::endl;
        return;
    }

    Person p_read;
    long offset = record_index * sizeof(Person);
    infile.seekg(offset, std::ios::beg);
    if (infile.read(reinterpret_cast<char*>(&p_read), sizeof(Person))) 
    {
        std::cout << "\nReading record at index " << record_index << ":" << std::endl;
        std::cout << "Name: " << p_read.name << std::endl;
        std::cout << "Age: " << p_read.age << std::endl;
    } 
    else 
    {
        std::cerr << "\nError: Could not read record at index " << record_index << "." << std::endl;
    }

    infile.close();
}

int main() 
{
    write_multiple_records();
    read_specific_record(1); 
    read_specific_record(0);
    
    return 0;
}
