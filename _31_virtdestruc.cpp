#include <iostream>

class Base
{
    public:
    Base() { std::cout << "Base constructor\n";}
    ~Base() { std::cout << "Base destructor\n";}
};


class Derived: public Base
{
    public:
    Derived() { m_Array = new int[5]; std::cout << "Derived constructor\n";}
    ~Derived() { delete[] m_Array; std::cout << "Derived destructor\n";}

    private:
    int * m_Array;
};

class Base2
{
    public:
    Base2() { std::cout << "Base2 constructor\n";}
    virtual ~Base2() { std::cout << "Base2 destructor\n";}
};


class Derived2: public Base2
{
    public:
    Derived2() { m_Array = new int[5]; std::cout << "Derived2 constructor\n";}
    ~Derived2() { delete[] m_Array; std::cout << "Derived2 destructor\n";}

    private:
    int * m_Array;
};

int main()
{
    Base* base = new Base();
    delete base;

    std::cout << "---------------\n";

    //Calls base constructor, derived constructor, derived destructor, base destructor
    Derived* derived = new Derived();
    delete derived;

    std::cout << "---------------\n";
    //Only base destructor, not both destructors called since not marked virtual
    //Memory leak in case of this example
    Base* poly = new Derived();
    delete poly;

    std::cout << "---------------\n";
    //Only base destructor, not both destructors called since not marked virtual
    //Memory leak in case of this example
    Base2* poly2 = new Derived2();
    delete poly2;

    std::cin.get();
}