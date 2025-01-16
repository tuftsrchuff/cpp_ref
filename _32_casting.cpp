#include <iostream>

class Base
{
public:
    Base(/* args */) {};
    virtual ~Base(){};
};

class Derived : public Base
{
private:
    /* data */
public:
    Derived(/* args */) {};
    ~Derived() {};
};


class AnotherClass : public Base
{
private:
    /* data */
public:
    AnotherClass(/* args */) {};
    ~AnotherClass() {};
};



int main()
{
    int a = 5;

    //Implicit conversion to double
    double value = a;

    double val2 = 5.25;
    int b = val2;
    

    //C-style cast
    double val3 = 5.25;
    double sum = (int)value + 5.3;

    //C++ cast
    double s = static_cast<int>(value) + 5.3;

    Derived* derived = new Derived();
    Base* base = derived;

    //Checks to see if cast possible, null otherwise
    //ac not able to be casted from derived to anotherclass
    AnotherClass* ac = dynamic_cast<AnotherClass*>(base);

    if (ac == nullptr){
        std::cout << "Couldn't cast\n";
    } else{
        std::cout << "Valid cast\n";
    }

    std::cin.get();

}