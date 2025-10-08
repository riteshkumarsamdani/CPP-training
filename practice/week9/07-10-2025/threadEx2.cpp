#include <iostream>
#include <thread>
#include <vector>

void PrintNumbers(int start, int end)
{
    for (int i = start; i <= end; ++i)
    {
        std::cout << "Number: " << i << "\n";
    }
}

int main()
{
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i)
    {
        threads.emplace_back(PrintNumbers, i * 10, (i + 1) * 10 - 1);
    }

    for (auto& thread : threads)
    {
        thread.join();
    }

    std::cout << "All threads completed!\n";
    return 0;
}