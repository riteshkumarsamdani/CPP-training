#include<iostream>

struct Temp
{
    int x{};
    double y{};
    int z{};
    void setVariable(int a,double b, int c)
    {
        x=a;
        y=b;
        z=c;
    }
};

int main()
{
    std::cout << sizeof(Temp);
    Temp obj;
    std::cout << sizeof(obj);
    obj.setVariable(3,4.1,5);
    std::cout << sizeof(obj);
    std::cout << &obj <<std::endl<< &obj.x <<std::endl<< &obj.y  <<std::endl<< &obj.z  <<std::endl;
    return 0;
}
