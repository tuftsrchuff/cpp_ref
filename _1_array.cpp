#include <iostream>
#include <array>


int main(int argc, char* argv[]){

    //Create array on stack, deleted at end of main
    int example[5];
    
    //Get size of array
    int count = sizeof(example) / sizeof(int); //Only works with stack allocated array

    //Using pointers to update arrays (all legal/valid in C++)
    int* ptr = example;



    for (int i = 0; i < 5; i++){
        example[i] = 2;
    }

    example[0] = 10;
    example[4] = 50;
    //Pointer arithmetic to update values
    *(ptr + 2) = 6;


    //Prints first element
    std::cout << example[0] << std::endl;

    //Prints memory address of array
    std::cout << example << std::endl;

    //example[-1] - not a valid C++ access like in Python

    //Heap array
    int* arr2 = new int[5];
    for (int i = 0; i < 5; i++){
        arr2[i] = i;
    }

    delete[] arr2;

    //C++ 11 standard array, contains size and does bounds checking
    std::array<int, 5> newArr;
    for (int i = 0; i < newArr.size(); i++){
        newArr[i] = i * i;
    }

    std::cin.get();
    return 0;
}