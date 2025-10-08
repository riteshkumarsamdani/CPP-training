#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;
int number = 0;

void increment(){
    mtx.lock();
    for(int i=0; i<1000000; i++){
        number++;
    }
    mtx.unlock();
}

int main()
{
    thread t1(increment);
    thread t2(increment);
    t1.join();
    t2.join();
    std::cout<<"Number after execution of t1 and t2 is "<<number;
    
    return 0;
}