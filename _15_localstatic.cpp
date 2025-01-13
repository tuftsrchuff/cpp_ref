#include <iostream>

//Only allow single instance of class
class Singleton
{
    private:
        static Singleton* s_Instance;
    public:
        static Singleton& Get() { return *s_Instance; }
    
        void Hello() {}
};

Singleton* Singleton::s_Instance = nullptr;

//Can use local static, less code
class Singleton2
{
    public:
        static Singleton2& Get() { 
            //Without static keyword the instance destroyed when it is popped off stack

            //First time constructs instance, then all times after it returns existing instance
            static Singleton2 instance;
            return instance; 
            }
    
        void Hello() {}
};



//First call i is initialized
//All other calls i is not initialized and stays alive
void Function()
{
    static int i = 0;
    i++;
    std::cout << i << std::endl;
}

int main()
{
    Function();
    Function();
    Function();
    Function();
    Function();
    Singleton::Get().Hello();
    Singleton2::Get().Hello();
    std::cin.get();
}