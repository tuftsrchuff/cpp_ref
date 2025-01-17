#include <iostream>
#include <variant>

int main()
{
    std::variant<std::string, int> data;
    data = "Ryan";
    std::cout << std::get<std::string>(data) << "\n";
    data = 2;
    if (data.index() == 1)
        std::cout << std::get<int>(data) << "\n";
    
    data = "Ryan";
    if (auto value = std::get_if<std::string>(&data)){
        std::cout << *value << std::endl;
    }
    

    std::cin.get();

}