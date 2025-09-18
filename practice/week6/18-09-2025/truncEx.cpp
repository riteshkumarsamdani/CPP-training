#include <fstream>
#include <iostream>

int main() 
{
    std::ofstream report("summary.txt", std::ios::out | std::ios::trunc); 

    if (report.is_open()) 
    {
        report << "Sales Report - September\n";
        report << "Total Revenue: ₹1,25,000\n";
        report.close();
    } 
    else 
    {
        std::cerr << "Failed to open report file." << std::endl;
    }
    return 0;
}
