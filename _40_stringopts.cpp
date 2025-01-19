#include <iostream>
#include <string>

static uint32_t s_AllocCount = 0;

//Overload the new operator and track allocation counts
void* operator new(size_t size)
{
    s_AllocCount++;
    std::cout << "Allocating " << size << " bytes\n";
    return malloc(size);
}

void PrintName(const std::string& name){
    std::cout << name << std::endl;
}

int main()
{
    //Long string, not using small string optimization to keep on stack
    std::string name = "Ryan Huffnagle-----------------------------------------------------------";
    std::string firstName = name.substr(0,30);
    std::string lastName = name.substr(4,30);
    PrintName(name);

    int* number = new int;

    //No copying, just views
    std::string_view firstName2(name.c_str(), 3);

    //Or just use C-style string, no allocations
    const char* name2 = "Ryan Huffnagle";

    std::cout << s_AllocCount << " allocations" << std::endl;

    std::cin.get();
}