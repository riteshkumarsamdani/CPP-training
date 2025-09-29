#include <iostream>

template <typename T = int>
class Counter {
private:
    T count;
public:
    Counter() : count(0) {}
    void increment() { ++count; }
    T getCount() const { return count; }
};

int main() {
    Counter<> defaultCounter;
    defaultCounter.increment();
    std::cout << "Default Counter: " << defaultCounter.getCount() << std::endl;

    Counter<double> doubleCounter;
    doubleCounter.increment();
    doubleCounter.increment();
    std::cout << "Double Counter: " << doubleCounter.getCount() << std::endl;

    return 0;
}
