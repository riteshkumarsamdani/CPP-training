#include <iostream>
#include <dlfcn.h>
#include "math_utils.h"

int main() {
    void* handle = dlopen("./libmath.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Error: " << dlerror() << std::endl;
        return 1;
    }

    typedef int (*AddFunc)(int, int);
    AddFunc add = (AddFunc)dlsym(handle, "add");

    if (!add) {
        std::cerr << "Symbol error: " << dlerror() << std::endl;
        dlclose(handle);
        return 1;
    }

    std::cout << "Sum: " << add(10, 20) << std::endl;
    dlclose(handle);
    return 0;
}
