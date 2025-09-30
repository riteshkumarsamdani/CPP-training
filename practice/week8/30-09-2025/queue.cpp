#include <iostream>
#include <queue>

int main() {
    std::queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    std::cout << q.front() << std::endl;
    std::cout << q.back() << std::endl;

    q.pop();
    std::cout << q.front() << std::endl;

    std::cout << q.size() << std::endl;
    std::cout << (q.empty() ? "Yes" : "No") << std::endl;

    std::queue<int> q2;
    q2.push(100);
    q2.push(200);
    q.swap(q2);

    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;

    return 0;
}
