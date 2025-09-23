#include <iostream>
#include <fstream>

void readFromFile(std::string fileName)
{
    std::ifstream file;
    file.open(fileName);
    std::string s;
    while(getline(file,s))
    {
        std::cout << s << "\n";
    }
}

void writeToFile(std::string fileName)
{
    std::ofstream file;
    file.open(fileName, std::ios::app);
    std::string s;
    int n=5;
    while(n--)
    {
        getline(std::cin,s);
        file << s << "\n";
    }
}

int main()
{
    std::string fileName = "temp.txt";
    writeToFile(fileName);
    readFromFile(fileName);
    return 0;
}