#include <iostream>

class Date
{
public:
    int m_day{};
    int m_month{};
    int m_year{};
};

void printDate(const Date& date)
{
    std::cout << date.m_day << '/' << date.m_month << '/' << date.m_year << "\n";
}

int main()
{
    Date date{ 1, 8, 25 };
    printDate(date);
    return 0;
}
