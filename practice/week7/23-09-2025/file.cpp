#include <iostream>
#include <fstream>
#include <sstream>

void func1(std::ifstream& file)
{
    file.seekg(3, std::ios::beg);
}

void func2(std::ifstream& file)
{
    file.seekg(6, std::ios::beg);
}

void func3(std::stringstream& ss)
{
    std::cout << ss.str();
    ss.seekg(3,std::ios::beg);
}

int main()
{
    std::stringstream ss;
    ss << "hello world!";
    func3(ss);
    std::cout << ss.tellg();
    std::cout << ss.str();
    std::ifstream file("temp.txt");
    char ch;
    file.get(ch);
    std::cout << "file position: " << file.tellg() << " char is: " << ch << "\n";
    func1(file);
    file.get(ch);
    std::cout << "file position: " << file.tellg() << " char is: " << ch << "\n";
    func2(file);
    file.get(ch);
    std::cout << "file position: " << file.tellg() << " char is: " << ch << "\n";
    file.seekg(0, std::ios::end);
    file.get(ch);
    std::cout << "end of file position: " << file.tellg() << " char is: " << ch << "\n";
    return 0;
}
