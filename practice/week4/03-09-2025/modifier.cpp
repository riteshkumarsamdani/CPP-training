#include<iostream>

class A
{
    private:
    int num{};
    public:
    const int& getNum() const
    {
        return num;
    }

    void setNum(int num)
    {
        (*this).num = num;
    }
};

int main()
{
    A a;
    a.setNum(5);
    int x = a.getNum();
    std::cout << x;
    x = 10;
    std::cout << x;
    std::cout << a.getNum();
    return 0;
}
