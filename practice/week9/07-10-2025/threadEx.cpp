#include <iostream>
#include <thread>
#include <chrono>

static bool s_Finished = false;

void DoSomeWork()
{
    using namespace std::literals::chrono_literals;
    while(!s_Finished)
    {
        std::cout << "Working...!\n";
        std::this_thread::sleep_for(2s);
    }
}

int main()
{
    std::thread worker(DoSomeWork);
    std::cin.get();
    s_Finished = true;
    worker.join();
    std::cout << "Finished!!\n";
    return 0;
}