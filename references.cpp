#include <iostream>

#define LOG(x) std::cout << x << std::endl

void Increment(int value){
    value++;
}

void IncrementWPtr(int* value){
    //value++ will just increment address, need to dereference
    //This notation dereferences pointer first, then increments it. Otherwise increments ptr then dereferences
    (*value)++;
}

void IncrementWRef(int& value){
    //Just passing it in with a reference
    value++;
}

int main()
{
    int a = 5;
    //Copy by value
    Increment(a);
    LOG(a);

    //Pass in memory address so it can be updated via ptr
    IncrementWPtr(&a);
    LOG(a);

    //Use reference here
    IncrementWRef(a);
    LOG(a);

    //Declaring reference to a, no extra memory allocated, ref is just now referring to a
    int& ref = a;
    ref = 2;
    LOG(a);

    //This doesn't change reference to b
    //Just makes a = b = 8
    int b = 10;
    ref = b;

    //Advantage of pointers, can change where they point to
    int* ref2 = &a;
    *ref2 = 1000;
    ref2 = &b;
    *ref2 = -4;
    LOG(a);
    LOG(b);


    std::cin.get();
}