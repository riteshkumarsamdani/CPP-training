#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    std::cout << v.at(1) << std::endl;
    std::cout << v.front() << std::endl;
    std::cout << v.back() << std::endl;

    for (int x : v) std::cout << x << " ";
    std::cout << std::endl;

    v.insert(v.begin() + 1, 15);
    v.erase(v.begin() + 2);
    v.resize(5);

    std::cout << v.size() << " " << v.capacity() << std::endl;
    std::cout << (v.empty() ? "Yes" : "No") << std::endl;

    std::vector<int> v2 = {100, 200};
    v.swap(v2);
    v.clear();
    v.assign(3, 7);

    int* ptr = v.data();
    std::cout << *ptr << std::endl;

    for (int x : v) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
