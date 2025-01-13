#include <iostream>
//Bad function using stack memory, will fail
int* CreateArrayBad()
{
    int array[50];
    return array;
}

int* CreateArrayGood(){
    int* array = new int[50];
    return array;
}

class Entity
{
    public:
        Entity()
        {
            std::cout << "Created entity!" << std::endl;
        }

        ~Entity(){
            std::cout << "Destroyed entity!" << std::endl;
        }
};

class ScopedPtr
{
    private:
        Entity* m_Ptr;
    public:
        ScopedPtr(Entity* ptr)
            : m_Ptr(ptr) {}
    
        ~ScopedPtr()
        {
            delete m_Ptr;
        }
};



int main(){
    int* a = CreateArrayBad();//Array popped off of the stack and so invalid pointer
    int* b = CreateArrayGood(); //On heap now, doesn't go out of scope when CreateArrayGood popped off stack
    delete b;
    {
        ScopedPtr e = new Entity(); //Implicit conversion to ScopedPtr using entity pointer, doesn't get destroyed when out of scope
        Entity* e2 = new Entity(); //Gets destroyed when out of scope
    }
    std::cin.get();
}