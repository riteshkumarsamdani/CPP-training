#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5, 5, 5};
    std::reverse(data.begin(), data.end());
    std::rotate(data.begin(), data.begin() + 2, data.end());
    auto newEnd = std::unique(data.begin(), data.end());
    data.erase(newEnd, data.end());
    for (int x : data) std::cout << x << " ";
    return 0;
}
