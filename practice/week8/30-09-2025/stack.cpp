#include <iostream>
#include <stack>

int main() {
    std::stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;

    std::cout << s.size() << std::endl;
    std::cout << (s.empty() ? "Yes" : "No") << std::endl;

    std::stack<int> s2;
    s2.push(100);
    s2.push(200);
    s.swap(s2);

    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;

    return 0;
}
