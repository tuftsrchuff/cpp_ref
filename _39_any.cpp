#include <iostream>
#include <any>

int main()
{
    std::any data;
    data = 2;
    data = "Ryan";
    data = std::string("Ryan");

    std::string string = std::any_cast<std::string>(data);
}