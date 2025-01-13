#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

//Takes in a function pointer and calls function on each value in vector
void ForEach(const std::vector<int>& values, void(*func)(int))
{
    //Calling passed in lambda function here
    for (int value: values)
        func(value);
}

void ForEach2(const std::vector<int>& values, const std::function<void(int)>& func)
{
    //Calling passed in lambda function here
    for (int value: values)
        func(value);
}

int main()
{
    //Using lambda instead of function pointer
    std::vector<int> values = {1, 5, 4, 2, 3};
    ForEach(values, [](int value) { std::cout << "Value: " << value << std::endl;});

    

    //Can specify lambda separately as well
    int a = 5;
    //& passes by ref (all variables unless specific specified), = passes by value (all variables unless specific specified)
    auto lamda = [&](int value) { std::cout << "Value: " << a << std::endl;};
    ForEach2(values, lamda);

    //Using lambda function with built in algorithm
    auto it = std::find_if(values.begin(), values.end(), [](int value){ return value > 3;});
    std::cout << *it << std::endl;



    std::cin.get();
}