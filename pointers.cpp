#include <iostream>
#include <cstring>

#define LOG(x) std::cout << x << std::endl

int main(){
    //Void type pointer
    //0 is an invalid mem address, same as NULL or nullptr
    // void* ptr = 0;
    void* ptr = nullptr;

    int var = 8;
    //Get memory address of var
    ptr = &var;

    //Dereference pointer, can R/W data
    //Will error if pointer is not an int now
    int* ptr2 = nullptr;
    ptr2 = &var;

    *ptr2 = 10;
    LOG(var);

    //Create char array of 8 bytes on the heap and return pointer to the starting location
    char* buffer = new char[8];
    //Fills block of memory with data we specify
    memset(buffer, 0, 8);

    //Pointer to the buffer pointer
    char** ptr3 = &buffer;
    //Need to clean up and delete buffer
    delete[] buffer;


    std::cin.get();
}