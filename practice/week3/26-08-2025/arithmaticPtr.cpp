#include<iostream>

int main()
{
    int a = 1050;
    int *p = &a;
    std::cout << "size of integer is: " << sizeof(a) << "\n";
    std::cout << "size of pointer is: " << sizeof(p) << "\n";
    std::cout << "value at p and *p is: " << p << " " << *p << "\n";
    std::cout << "value at p+1 and *p+1 is: " << p+1 << " " << *(p+1) << "\n";
    char *p1; 
    p1 = (char*)(p);
    std::cout << "size of pointer is: " << sizeof(p1) << "\n";
    std::cout << "value at p1 and *p1 is: " << (void*)p1 << " " << static_cast<int>(*p1) << "\n";
    std::cout << "value at p1+1 and *p1+1 is: " << (void*)(p1+1) << " " << static_cast<int>(*(p1+1)) << "\n";
    return 0;
}