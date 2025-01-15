#include <iostream>
struct Entity
{
    int x, y;
};

int main()
{
    //Implicit conversion to double 
    int a = 50;
    double value = a;
    std::cout << value << std::endl;

    int b = 50;
    //Type punning - integer pointer, cast to double pointer and dereference
    double val = *(double*)&a;
    //Prints nonsense, goes 4 bytes past valid memory
    std::cout << val << std::endl;

    //Safe example of type punning
    Entity e = { 5, 8 };

    //Convert the struct into an int pointer 
    int* position = (int*)&e;
    //Access the members as idx as you would in an array
    std::cout << position[0] << ", " << position[1] << std::endl;




    std::cin.get();
}