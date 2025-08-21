#include<iostream>
#include<dlfcn.h>
#include"add.h"
#include"subtract.h"

int main()
{
    std::cout << "enter the choice + for addition or - for subtration\n";
    char choice;
    double a, b;
    double ans;
    std::cin >> choice;
    void* handle = dlopen("./libmath.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Error: " << dlerror() << std::endl;
        return 1;
    }

    typedef double (*mathFunc)(double, double);
    mathFunc add = (mathFunc)dlsym(handle, "add");

    if (!add) {
        std::cerr << "Symbol error: " << dlerror() << std::endl;
        dlclose(handle);
        return 1;
    }

    mathFunc subtract=(mathFunc)dlsym(handle,"subtract");

    if (!subtract) {
        std::cerr << "Symbol error: " << dlerror() << std::endl;
        dlclose(handle);
        return 1;
    }

    switch(choice)
    {
        case '+':
            std::cout << "enter number for addition\n";
            std::cin >> a >> b;
            ans = add(a, b);
            std::cout << "\nans is : " << ans <<"\n";
            dlclose(handle);
            break;

        case '-':
            std::cout << "enter number for subtraction\n";
            std::cin >> a >> b;
            ans = subtract(a, b);
            std::cout << "\nans is : " << ans << "\n";
            dlclose(handle);
            break;

        default:
            std::cout << "not valid choice\n";
            dlclose(handle);
            break;
    }
    return 0;
}
