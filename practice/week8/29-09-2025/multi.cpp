#include <iostream>

template <typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;
    Pair(T1 f, T2 s) : first(f), second(s) {}
};


int main() {
    Pair<int, std::string> p(1, "One");
    std::cout << "Pair: " << p.first << ", " << p.second << std::endl;

    Pair<double, wchar_t> q(3.14, L'π');
    std::wcout << L"Pair: " << q.first << L", " << q.second << std::endl;
    
    return 0;
}
