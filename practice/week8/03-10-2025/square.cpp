#include <iostream>
#include <vector>
#include <algorithm>

class Square {
public:
    int operator()(int x) const {
        return x * x;
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::vector<int> squares(nums.size());

    std::transform(nums.begin(), nums.end(), squares.begin(), Square());

    for (int val : squares) {
        std::cout << val << " ";
    }
    return 0;
}
