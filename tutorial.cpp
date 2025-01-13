#include <iostream>
//With ifndef in other head this still works
#include "Log.h"

int Multiply(int a, int b){
    return a * b;
}

void MultiplyAndLog(int a, int b){
    int result = Multiply(a, b);
    std::cout << result << std::endl;
}

int main(){
    int a = 8;
    a++;
    const char* string = "Hello";
    MultiplyAndLog(3, 2);
    MultiplyAndLog(8, 5);
    MultiplyAndLog(10, 12);
    Log("Hi");
    std::cin.get();

    //Doing inline comparison and variable assignment
    int x = 5;
    bool comparisonResult = x == 5;

    
}