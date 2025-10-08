// C++ Program using std::unique_lock
#include <mutex>
#include <thread>
#include <iostream>
using namespace std;

mutex mtx;
int shared_data = 0;
void increment_data() {
    unique_lock<mutex> lock(mtx, defer_lock); 
    lock.lock(); 
    shared_data += 2;
    lock.unlock(); 
}

int main() {
    thread t1(increment_data);
    thread t2(increment_data);
    t1.join();
    t2.join();
    cout << "Value of shared variable: " << shared_data;
    return 0;
}
