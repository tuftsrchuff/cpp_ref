#include <iostream>
#include <string>
#include <algorithm>

//Nested namespaces
namespace apple { namespace functions {
    void print(const std::string& text)
    {
        std::cout << text << std::endl;
    }
} }

namespace orange {
    void print(const char* text)
    {
        std::string temp = text;
        std::reverse(temp.begin(), temp.end());
        std::cout << temp << std::endl;
    }
}

int main(){
    apple::functions::print("Hello");
    orange::print("Hello");

    namespace a = apple::functions;
    a::print("Hi");


    std::cin.get();
}