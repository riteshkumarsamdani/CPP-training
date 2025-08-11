#include <iostream>
using namespace std;
void outerFunction() {
    try {
        try {
            throw runtime_error("Inner exception occurred");
        } catch (runtime_error e) {
            cout << "Caught inner exception: "<< e.what() <<endl;
            throw;
        }
    } catch (runtime_error e) {
        cout<< "Caught outer exception: "<<e.what()<<endl;
    }
}

int main() {
    outerFunction();
    return 0;
}