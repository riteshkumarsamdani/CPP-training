#include <iostream>
#include <optional>
#include <string>

std::optional<std::string> create(bool b)
{
    if (b)
        return "Godzilla";
    return {};
}
 
auto create2(bool b)
{
    return b ? std::optional<std::string>{"Godzilla"} : std::nullopt;
}
 
int main()
{
    std::cout << "create(false) returned " << create(false).value_or("empty") << '\n';
    if (auto str = create2(true))
        std::cout << "create2(true) returned " << *str << '\n';
}