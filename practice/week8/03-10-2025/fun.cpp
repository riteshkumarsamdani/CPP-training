#include <iostream>
#include <vector>
#include <algorithm>

class IsEven {
public:
    bool operator()(int value) const {
        return value % 2 == 0;
    }
};

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int evenCount = std::count_if(numbers.begin(), numbers.end(), IsEven());
    std::cout << "Number of even elements: " << evenCount << std::endl;
    return 0;
}
