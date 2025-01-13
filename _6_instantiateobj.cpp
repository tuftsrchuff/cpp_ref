#include <iostream>
#include <string>

class Entity
{
    private:
    std::string m_Name;

    public:
    Entity() : m_Name("Unknown") {}
    Entity(const std::string& name) :m_Name(name) {}

    const std::string& GetName() const { return m_Name; }
};

void Function(){
    int a = 2;
    Entity entity = Entity("Cherno");
}

int main(){
    Function(); //Creates object on the stack, out of scope and deleted after Function popped off stack


    Entity entity; //Calls default constructor and allocates memory on the stack
    std::cout << entity.GetName() << std::endl;

    Entity* e;
    { //Creates new stack frame
        Entity* entity = new Entity("Cherno"); //Creates object on heap, returns pointer
        e = entity;
        std::cout << e->GetName() << std::endl;

    }

    int a = 2;
    int* b = new int[50]; //200 bytes created on heap
    delete b;

    Entity* e1 = new Entity[50]; //Allocates 50 Entity objects on the heap
    delete[] e1;
    
    std::cin.get();
    delete e; //Cleans up memory on heap
}