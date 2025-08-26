#include<iostream>
#include<dlfcn.h>
#include<limits>
#define LIBRARY_PATH "lib/libexplicitMath.so"

void* getHandle() {
    static void* handle = nullptr;
    if (handle == nullptr) {
        handle = dlopen(LIBRARY_PATH, RTLD_LAZY);
        if (!handle) {
            std::cerr << "Error: " << dlerror() << std::endl;
        }
    }
    return handle;
}

void closeHandle() {
    void* handle = getHandle();
    if (handle) {
        dlclose(handle);
    }
}

int main() 
{
    void* handle = getHandle();
    typedef void (*Calculator)();
    Calculator calculator = (Calculator)dlsym(handle, "calculatorExplicit");
    calculator();
    closeHandle();
    return 0;
}
