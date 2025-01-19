#include <iostream>

class Singleton
{
    public:
        //Delete copy constructor so only one instance can be made
        Singleton(const Singleton&) = delete;

        //Access class without instantiation
        static Singleton& Get()
        {
            return s_Instance;
        }

        void Function() {}

    private:
    //Don't want instantiation of class
    Singleton(){}

    static Singleton s_Instance;
};

//Would likely want to delete assignment operator as well
//Any other updates to ensure only single instance instantiated
class Random
{
    public:
        //Delete copy constructor so only one instance can be made
        Random(const Random&) = delete;

        //Access class without instantiation
        static Random& Get()
        {
            //Still in static memory, but don't need to instantiate it outside of the class
            static Random s_Instance;
            return s_Instance;
        }

        //Alternative way to just call
        static float Float() { return Get().IFloat(); }

    private:
    float IFloat() { return m_RandomGenerator; }

    //Don't want instantiation of class
    Random(){}

    float m_RandomGenerator = 0.5f;

    
};

//Instantiate singleton class
Singleton Singleton::s_Instance;

//Alternative method just using namespaces
namespace RandomClass {
    static float s_RandomGenerator = 0.5f;
    static float Float() { return s_RandomGenerator; }
}

int main()
{
    //Accesses singleton and the function associated with it
    Singleton& instance = Singleton::Get();
    Singleton::Get().Function();

    float number = Random::Float();
    std::cout << number << std::endl;

    //Using namespace instead of singleton
    float nameNum = RandomClass::Float(); 

    std::cin.get();
}