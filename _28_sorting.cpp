#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
    std::vector<int> values = {3, 5, 1, 4, 2};
    std::sort(values.begin(), values.end(), std::greater<int>());

    for (int value : values)
        std::cout << value << std::endl;

    std::vector<int> values2 = {3, 5, 1, 4, 2};

    //Use lamda function for sorting
    std::sort(values.begin(), values.end(), [](int a, int b)
    {
        //Pushes 1 to front of list
        if (a == 1) return false;
        if (b == 1) return true;

        //If true then a appears before b in the list (see cppref docs)
        //Sorts in ascending order (a > b) sorts descending order
        return a < b;
    });

    std::sort(values2.begin(), values2.end(), std::greater<int>());

    for (int value : values2)
        std::cout << value << std::endl;

    std::cin.get();
}