#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> values = {3, 5, 1, 4, 2};
    std::sort(values.begin(), values.end());

    for (int value : values)
        std::cout << value << std::endl;

    std::cin.get();
}