#include <iostream>
#include <string>

//Paste in this code whenever WAIT is encountered
#define WAIT std::cin.get()

// #define LOG(x) std::cout << x << std::endl
#define DEBUG 1

#if DEBUG == 1
#define LOG(x) std::cout << "Debug mode enabled" << std::endl;
#else
#define LOG(x) std::cout << "Release mode" << std::endl;
#endif

int main(){
    LOG("Hello");

    WAIT;
}