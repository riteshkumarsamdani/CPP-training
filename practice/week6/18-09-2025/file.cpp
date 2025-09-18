#include <iostream>
#include <fstream>

void writeIntoFile()
{
    int n = 3;
    std::fstream file("temp.txt", std::ios::app);
    if(!file)
    {
        throw "file unable to create!!";
    }
    while(n--)
    {
        std::string s;
        std::cout << "enter line: ";
        getline(std::cin, s);
        file << s << std::endl;
    }
    file.close();
}

void printFromFile()
{
    std::fstream file("temp.txt", std::ios::in);
    std::string s;
    if(!file.is_open())
    {
        throw "file not found to read!!";
    }
    while(getline(file,s))
    {
        std::cout << s << std::endl;
    }
    if(file.eof())
        std::cout << "reached at end!!\n";
    else
    {
        file.close();
        throw "error while reading file";
    }
    file.close();
}

int main()
{
    try
    {
        writeIntoFile();
        printFromFile();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const char* c)
    {
        std::cout << "error has occured: " << c << std::endl;
    }
    return 0;
}
