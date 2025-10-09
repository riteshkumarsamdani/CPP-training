#include <iostream>
#include <thread>
#include <chrono>

unsigned long long odd = 0;
unsigned long long even = 0;
void oddSum(unsigned long long start, unsigned long long end)
{
    while(start <= end)
    {
        if(start%2 == 1)
        {
            odd += start;
        }
        start++;
    }
}

void evenSum(unsigned long long start, unsigned long long end)
{
    while(start <= end)
    {
        if(start%2 == 0)
        {
            even += start;
        }
        start++;
    }
}

void func(unsigned long long start, unsigned long long end)
{
    std::thread t3(evenSum, start, end);
    t3.detach();
}

int main()
{
    unsigned long long start = 0, end = 1000000;
    std::thread t1(oddSum, start, end);
    std::thread t2(func, start, end);
    t1.join();
    t2.join();
    // t1.detach();
    // t2.detach();
    std::cout << odd << std::endl;
    std::cout << even << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << even << std::endl;
    return 0;
}