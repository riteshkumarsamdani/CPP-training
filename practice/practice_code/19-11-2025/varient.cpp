#include <cassert>
#include <iostream>
#include <string>
#include <variant>
 
int main()
{
    std::variant<int, float> v, w;
    v = 42;
    int i = std::get<int>(v);
    assert(42 == i);
    w = std::get<int>(v);
    w = std::get<0>(v);
    w = v; 
    try
    {
        std::get<float>(w);
    }
    catch (const std::bad_variant_access& ex)
    {
        std::cout << ex.what() << '\n';
    }
 
    using namespace std::literals;
 
    std::variant<std::string> x("abc");
    x = "def";
 
    std::variant<std::string, void const*> y("abc");
    assert(std::holds_alternative<void const*>(y));
    y = "xyz"s;
    assert(std::holds_alternative<std::string>(y));
}