#include <iostream>

struct Bad
{
    int m_data { 5 };
    int m_bad1 { m_data }; 
    int m_bad2 { fcn() };  
    int fcn() { return m_data; }
};

int main()
{
    Bad bad;
    std::cout << bad.m_bad1 <<std::endl;
    return 0;
}
