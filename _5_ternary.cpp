#include <iostream>
#include <string>

static int s_Level = 1;
static int s_Speed = 2;

int main()
{
        //Non-ternary option, longer
    if (s_Level > 5)
        s_Speed = 10;
    else
        s_Speed = 5;
    
    //Shorter and syntactically neater
    s_Speed = s_Level > 5 ? 10 : 5;

    std::cout << s_Speed << std::endl;

    std::cin.get();
}