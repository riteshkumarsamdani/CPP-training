#include <iostream>
#include <vector>

int main() 
{
    int a = 2;
    int* ptr = &a;
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::vector<int>::iterator first = v.begin();
    std::vector<int>::iterator last = v.end();
    std::cout << last - first << std::endl;
    last++;
    std::cout << *last;
    for(int i : v)
    {
        i++;
    }
    while(first != last) 
    {
        std::cout << *first << " ";
        first++;
    }
    return 0;
}
