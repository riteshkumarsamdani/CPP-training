#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream sourceFile("temp.txt");
    if (!sourceFile.is_open()) 
    {
        std::cerr << "Error: Could not open source.txt" << std::endl;
        return 1;
    }
    std::ofstream destFile("destination.txt");
    if (!destFile.is_open()) 
    {
        std::cerr << "Error: Could not open destination.txt" << std::endl;
        sourceFile.close();
        return 1;
    }

    std::string line;
    while (std::getline(sourceFile, line)) 
    {
        destFile << line << std::endl;
    }
    sourceFile.close();
    destFile.close();
    std::cout << "File copied successfully." << std::endl;
    return 0;
}
