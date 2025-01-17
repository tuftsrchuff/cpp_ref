#include <iostream>
#include <string>
#include <tuple>

std::tuple<std::string, int> CreatePerson()
{
    return { "Ryan", 24 };
}

int main()
{
    //Using tuple as return type, hard to read and understand return types
    auto person = CreatePerson();
    std::string& name = std::get<0>(person);
    int age = std::get<1>(person);

    //Pass in by reference, becomes slightly easier to understand
    std::string name2;
    int age2;
    std::tie(name2, age2) = CreatePerson();

    //C++ 17 with structured bindings
    auto [nameSB, ageSB] = CreatePerson();
    std::cout << nameSB << ": " << ageSB << std::endl;
}