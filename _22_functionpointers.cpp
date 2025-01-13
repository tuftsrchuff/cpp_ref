#include <iostream>
#include <vector>

void HelloWorld()
{
    std::cout << "Hello World" << std::endl;
}

void HelloWorld2(int a)
{
    std::cout << "Hello World " << a << std::endl;
}

void PrintValue(int value)
{
    std::cout << "Value: " << value << std::endl;
}

//Takes in a function pointer and calls function on each value in vector
void ForEach(const std::vector<int>& values, void(*func)(int))
{
    for (int value: values)
        func(value);
}

int main()
{
    typedef void(*HelloWorldFunction)();
    HelloWorldFunction function = HelloWorld;

    //Without auto keyword, use actual function pointer definition
    void (*fnpointer)();
    fnpointer = HelloWorld;

    auto function2 = HelloWorld;

    function();
    function();

    typedef void(*HelloWorldFunction2)(int);
    HelloWorldFunction2 newfunc = HelloWorld2;
    newfunc(2);

    //Using function pointers to pass into another function
    std::vector<int> values = {1, 5, 4, 2, 3};
    ForEach(values, PrintValue);

    std::cin.get();
}