#include <iostream>
#include <thread>
using namespace std;

class SumFunctor {
public:
    int n;
    SumFunctor(int a) : n(a) {}

    void operator()() const {
        cout << n;
    }
};

int main() {
    thread t(SumFunctor(3));
    t.join();
    return 0;
}