#include<iostream>

class A;

class B
{
    int b;
    public:
    bool valid(A obj, A obj1);
    void setB(int b)
    {
        this->b = b;
    }
    int getB()
    {
        return b;
    }
};

class A{
    int a;
    int x=5;
    public:
    void setA(int a)
    {
        this->a = a;
    }
    int getA()
    {
        return a;
    }
    A operator+(A obj)
    {
        B* b= new B();
        A temp;
        if(b->valid(*this, obj))
        {
            temp.a = a + obj.a;
        }
        else{
            temp.a = 0;
        }
        return temp;
    }
};

bool B::valid(A obj, A obj1)
{
    if(obj.getA()==obj1.getA()) return true;
    return false;
}

int main()
{
    A obj1;
    A obj2;
    obj1.setA(10);
    obj2.setA(10);
    // obj1.setB(12);
    A obj = obj1+obj2;
    // obj2.setB(13);
    // std::cout<<obj1.getA()<<obj2.getA()<<obj2.getB()<<obj.getA();
    std::cout<<obj1.getA()<<obj2.getA()<<obj.getA();
    return 0;
}
