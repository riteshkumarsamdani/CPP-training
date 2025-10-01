#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> scores = {85, 90, 78, 92, 88};
    auto it = std::find_if(scores.begin(), scores.end(), [](int x) { return x > 90; });
    if (it != scores.end()) std::cout << "First >90: " << *it << std::endl;
    std::cout << "All >70: " << std::all_of(scores.begin(), scores.end(), [](int x) { return x > 70; }) << std::endl;
    std::cout << "Any <80: " << std::any_of(scores.begin(), scores.end(), [](int x) { return x < 80; }) << std::endl;
    std::cout << "None <50: " << std::none_of(scores.begin(), scores.end(), [](int x) { return x < 50; }) << std::endl;
    return 0;
}
