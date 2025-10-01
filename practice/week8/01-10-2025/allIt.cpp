#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <string>
#include <iterator>
#include <numeric> 
#include <algorithm> 
#include <limits>

int main() {
    std::cout << "--- Input Iterator (Single-pass, Read-only) ---" << std::endl;
    std::cout << "Enter a few numbers separated by spaces (e.g., 10 20 30), then press Ctrl+D (or Ctrl+Z on Windows) and Enter:" << std::endl;
    std::istream_iterator<int> input_it(std::cin);
    std::istream_iterator<int> end_of_stream;

    int sum = std::accumulate(input_it, end_of_stream, 0);
    std::cout << "Sum of entered numbers: " << sum << std::endl << std::endl;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "--- Output Iterator (Single-pass, Write-only) ---" << std::endl;
    std::vector<int> numbers_to_print = {100, 200, 300};
    std::cout << "Writing to standard output with an ostream_iterator:" << std::endl;
    std::ostream_iterator<int> output_it(std::cout, " ");
    std::copy(numbers_to_print.begin(), numbers_to_print.end(), output_it);
    std::cout << std::endl << std::endl;

    std::cout << "--- Forward Iterator (Multi-pass, Read/Write, Forward) ---" << std::endl;
    std::forward_list<int> fwd_list = {1, 2, 3, 4, 5};
    std::cout << "Initial forward_list: ";
    for (int n : fwd_list) { std::cout << n << " "; }
    std::cout << std::endl;

    auto it_fwd = fwd_list.begin();
    while (it_fwd != fwd_list.end()) {
        if (*it_fwd == 3) {
            *it_fwd = 333;
        }
        ++it_fwd;
    }
    std::cout << "Modified forward_list: ";
    for (int n : fwd_list) { std::cout << n << " "; }
    std::cout << std::endl << std::endl;

    std::cout << "--- Bidirectional Iterator (Multi-pass, Read/Write, Bidirectional) ---" << std::endl;
    std::list<int> my_list = {1, 2, 3, 4, 5};
    std::cout << "Initial list: ";
    for (int n : my_list) { std::cout << n << " "; }
    std::cout << std::endl;

    std::cout << "Traversing list backward: ";
    for (auto it = my_list.rbegin(); it != my_list.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "--- Random-Access Iterator (Multi-pass, Read/Write, Random-Access) ---" << std::endl;
    std::vector<int> my_vector = {10, 20, 30, 40, 50};
    std::cout << "Vector elements: ";
    for (int n : my_vector) { std::cout << n << " "; }
    std::cout << std::endl;

    auto it_rand = my_vector.begin();
    it_rand += 2;
    std::cout << "Element at index 2 using arithmetic: " << *it_rand << std::endl;

    std::cout << "Accessing element at index 4 with subscript: " << my_vector.begin()[4] << std::endl;

    auto it_first = my_vector.begin();
    auto it_last = my_vector.end();
    std::cout << "Distance between begin and end: " << std::distance(it_first, it_last) << std::endl;

    return 0;
}
