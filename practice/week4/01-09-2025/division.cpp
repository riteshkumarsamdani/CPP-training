#include <iostream>

struct fraction
{
private:
    int numerator{0};
    int denominator{1};
public:
    void setNumerator(int num)
    {
        numerator = num;
    }

    void setDenominator(int num)
    {
        if(num != 0)
        {
            denominator = num;
        }
        else
        {
            std::cout << "denominator can't be zero\n";
            denominator = 0;
        }
    }

    int getDenominator()
    {
        return denominator;
    }

    int getNumerator()
    {
        return numerator;
    }
};

int main()
{
    fraction f;
    std::cout << f.getNumerator() << std::endl;
    std::cout << f.getDenominator() << std::endl;
    f.setNumerator(5);
    f.setDenominator(10);
    std::cout << f.getNumerator() << std::endl;
    std::cout << f.getDenominator() << std::endl;
    double fraction = (double)f.getNumerator()/f.getDenominator();
    std::cout << fraction << "\n";
    f.setDenominator(0);
    std::cout << f.getDenominator() << std::endl;
    return 0;
}
