#include <iostream>
#include <memory>
using namespace std;

int main()
{
    auto_ptr<int> ptr1(new int(10));
    cout << *ptr1 << endl;
    auto_ptr<int> ptr2 = ptr1;
    cout << *ptr2;
    return 0;
}