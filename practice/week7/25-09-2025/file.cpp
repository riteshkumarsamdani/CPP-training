#include <iostream>
#include <fstream>

int main()
{
    std::string str = "hello world\n";
    std::ofstream fout("temp.bin", std::ios::binary);
    if (!fout) {
        std::cerr << "Error opening file for writing.\n";
        return 1;
    }
    size_t strLength = str.length();
    fout.write(reinterpret_cast<const char*>(&strLength), sizeof(strLength));
    fout.write(str.c_str(), strLength);
    fout.close();
    std::ifstream fin("temp.bin", std::ios::binary);
    if (!fin) {
        std::cerr << "Error opening file for reading.\n";
        return 1;
    }
    fin.read(reinterpret_cast<char*>(&strLength), sizeof(strLength));
    char* buffer = new char[strLength + 1];
    fin.read(buffer, strLength);
    buffer[strLength] = '\0';

    std::string str1 = buffer;
    std::cout << "File Data: " << str1;

    delete[] buffer;
    fin.close();

    return 0;
}
