#include <bits/stdc++.h>
using namespace std;
int main() {
    try {
        int choice;
        cout << "Enter 1 for invalid argument, "
            << "2 for out of range: ";
        cin >> choice;
        if (choice == 1) {
            throw invalid_argument("Invalid argument");
        }
        else if (choice == 2) {
            throw out_of_range("Out of range");
        }
        else {
            throw "Unknown error";
        }

    }
    catch (invalid_argument e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    catch (out_of_range e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    catch (...) {
        cout << "Caught an unknown exception." << endl;
    }
    return 0;
}