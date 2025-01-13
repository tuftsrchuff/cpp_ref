#include <iostream>
// #include "../glfw-3.4/include/GLFW/glfw3.h"
#include "GLFW/glfw3.h" //Needed to run sudo make install, loads header/lib into system directories

int main()
{
    int a = glfwInit();
    std::cout << "Compiled correctly!" << std::endl;
    std::cin.get();
}