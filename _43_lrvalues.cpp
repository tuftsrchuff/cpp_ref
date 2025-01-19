#include <iostream>

//Returns rvalue
int GetValue()
{
    return 10;
}

//Returns lvalue
int& GetValue2()
{
    static int value = 10;
    return value;
}

//Pass in rvalue as reference
void PrintName(std::string&& name)
{
    std::cout << name << std::endl;
}

void PrintName(std::string& name)
{
    std::cout << name << std::endl;
}

int main()
{
    //lvalue = i, rvalue = 10
    int i = 10;

    //lvalue = a, rvalue = i
    int a = i;

    //GetValue returns an rvalue, temp value
    int val = GetValue();
    GetValue2() = 5;

    std::string firstName = "Ryan";
    std::string lastName = "Huffnagle";
    std::string fullName = firstName + lastName;

    //lvalue reference
    PrintName(fullName);

    //Rvalue reference
    PrintName(firstName + lastName);
}