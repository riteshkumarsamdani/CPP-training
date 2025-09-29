#include <iostream>
#include <vector>

template <typename T>
class Stack {
private:
    std::vector<T> elements;
public:
    void push(const T &item) { elements.push_back(item); }
    void pop() { elements.pop_back(); }
    T top() const { return elements.back(); }
    bool isEmpty() const { return elements.empty(); }
};

int main() {
    Stack<int> intStack;
    intStack.push(100);
    intStack.push(200);
    std::cout << "Top of intStack: " << intStack.top() << std::endl;

    Stack<std::string> strStack;
    strStack.push("Apple");
    strStack.push("Banana");
    std::cout << "Top of strStack: " << strStack.top() << std::endl;

    return 0;
}
