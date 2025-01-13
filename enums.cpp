#include <iostream>

enum Example : char
{
    A = 5, B, C
};

int main()
{
    Example value = B;

    if (value == 1)
    {
        //Do something here
    }

    std::cin.get();
}