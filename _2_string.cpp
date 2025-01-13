#include <iostream>
#include <string>

void PrintStringCopy(std::string string)
{
    string += "!!!!!";
    std::cout << string << std::endl;
}

//If you don't want to override string, specify const in front of string
void PrintStringReference(std::string& string)
{
    string += "!!!!!";
    std::cout << string << std::endl;
}

int main(){
    //C-style way of declaring strings
    const char*  name = "Ryan";
    char name2 [5] = {'R', 'y', 'a', 'n', 0};
    std::cout << name2 << std::endl;

    std::string newname = "Ryan";
    std::cout << newname.size() << std::endl;

    //Append two strings
    newname += " Huffnagle";
    std::cout << newname << std::endl;

    //Find method in string
    bool contains = newname.find("ya") != std::string::npos;

    //Copies string
    PrintStringCopy(newname);
    std::cout << newname << std::endl;

    //Pass by reference
    PrintStringReference(newname);
    std::cout << newname << std::endl;



    std::cin.get();
}