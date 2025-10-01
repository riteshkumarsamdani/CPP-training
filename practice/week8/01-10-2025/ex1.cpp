#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> nums = {10, 20, 5, 12, 8};
    int evenCount = std::count_if(nums.begin(), nums.end(), [](int x) { return x % 2 == 0; });
    std::cout << "Even count: " << evenCount << std::endl;
    std::transform(nums.begin(), nums.end(), nums.begin(), [](int x) { return x * x; });
    std::replace_if(nums.begin(), nums.end(), [](int x) { return x > 100; }, 100);
    for (int x : nums) std::cout << x << " ";
    return 0;
}
