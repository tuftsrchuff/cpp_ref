#include <iostream>
#include <string>

class Entity
{
    public:
        int x;
        void Print() const {
            std::cout << "Hello!" << std::endl;
        }
};

class ScopedPtr
{
    private:
    Entity* m_Obj;

    public:
    ScopedPtr(Entity* entity)
        : m_Obj(entity){}
    
    ~ScopedPtr()
    {
        delete m_Obj;
    }

    //Overload operator to return the pointer object
    Entity* operator->()
    {
        return m_Obj;
    }

    //Overload operator to return the pointer object, returns const and operator is const indicating it doesn't update variable
    const Entity* operator->() const
    {
        return m_Obj;
    }

};

int main(){
    Entity e;
    e.Print();

    //Save mem location of e into pointer
    Entity* ptr = &e;
    //Derefernce pointer and save it as an entity reference
    Entity& entity = *ptr;
    entity.Print();

    //Operator precedence goes to Print before dereference with parentheses
    (*ptr).Print();
    ptr->Print();

    //Using overloaded arrow operator
    ScopedPtr entity2 = new Entity();
    entity2->Print();


    //Using overloaded arrow operator
    const ScopedPtr entity3 = new Entity();
    entity3->Print();

    std::cin.get();
}