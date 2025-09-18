#include <fstream>
#include <iostream>

int main() 
{
    std::fstream file("temp.txt", std::ios::in | std::ios::ate);

    if (file.is_open()) 
    {
        std::streampos size = file.tellg(); 
        std::cout << "File size: " << size << " bytes" << std::endl;

        file.seekg(0); 
        std::string line;
        while (getline(file, line)) 
        {
            std::cout << line << std::endl;
        }
        file.close();
    } 
    else 
    {
        std::cerr << "Could not open file." << std::endl;
    }
    return 0;
}
