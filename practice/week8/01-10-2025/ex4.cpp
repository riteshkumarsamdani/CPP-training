#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> nums = {5, 2, 8, 1, 3, 6};
    std::partition(nums.begin(), nums.end(), [](int x) { return x % 2 == 0; });
    std::sort(nums.begin(), nums.end());
    std::stable_sort(nums.begin(), nums.end(), [](int a, int b) { return a % 2 < b % 2; });
    for (int x : nums) std::cout << x << " ";
    return 0;
}
