#include <iostream>
using namespace std;
int main() {
    try {
        int x = 0;
        if (x == 0) {
            throw invalid_argument("x cannot be zero");
        }
    } catch (invalid_argument e) {
        cout << "Exception: " << e.what() <<endl;
    }

    return 0;
}