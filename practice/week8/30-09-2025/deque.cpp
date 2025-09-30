#include <iostream>
#include <deque>

int main() {
    std::deque<int> d;
    d.push_back(10);
    d.push_front(20);
    d.push_back(30);
    d.push_front(40);

    std::cout << d.at(1) << std::endl;
    std::cout << d.front() << std::endl;
    std::cout << d.back() << std::endl;

    for (int x : d) std::cout << x << " ";
    std::cout << std::endl;

    d.insert(d.begin() + 2, 25);
    d.erase(d.begin() + 1);
    d.resize(6);

    std::cout << d.size() << std::endl;
    std::cout << (d.empty() ? "Yes" : "No") << std::endl;

    std::deque<int> d2 = {100, 200};
    d.swap(d2);
    d.clear();
    d.assign(4, 5);

    for (int x : d) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
