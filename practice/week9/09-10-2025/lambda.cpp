#include <iostream>
using namespace std;

int main() {
    
    auto res = [](int x) {
        return x + x;
    };
    cout << res(5);
    cout << res(10);
    return 0;
}