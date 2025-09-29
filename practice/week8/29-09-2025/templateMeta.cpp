#include <iostream>

template<int n> struct funStruct
{
    enum { val = 2*funStruct<n-1>::val };
};

template<> struct funStruct<0>
{
    enum { val = 1 };
};

int main()
{
    std::cout << funStruct<8>::val << std::endl;
    return 0;
}
