// #include <exception>
// #include <iostream>
// using namespace std;

// void myhandler()
// {
//     cout << "Inside new terminate handler\n";
//     abort();
// }

// int main()
// {
//     set_terminate(myhandler); 
//     try {
//         cout << "Inside try block\n";
//         throw 100;
//     }
//     catch (char a) 
//     {
//         cout << "Inside catch block\n";
//     }
//     return 0;
// }

#include <iostream>
#include <stdexcept>

// Example demonstrating the base class catch
void might_throw_anything(int choice) {
    if (choice == 1) {
        throw std::runtime_error("A runtime error occurred.");
    }
    if (choice == 2) {
        throw std::invalid_argument("An invalid argument was given.");
    }
}

int main() {
    try {
        might_throw_anything(1);
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}
