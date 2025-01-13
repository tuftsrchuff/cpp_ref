#include <iostream>
#include <string>

class Entity
{
    public:
        std::string GetName() { return "Entity"; }
};

class Player : public Entity
{
    private:
    std::string m_Name;
    public:
    Player(const std::string& name)
        : m_Name(name) {}

    std::string GetName() { return m_Name;}
};

//Will just call the entity type GetName function
void PrintName(Entity* entity)
{
    //Method with the arrow operator, easiest
    // std::cout << entity->GetName() << std::endl;

    //Dereference pointer first then access GetName
    std::cout << (*entity).GetName() << std::endl;
}

//Will now tell compiler to allow overrides for function
class Entity2
{
    public:
        virtual std::string GetName() { return "Entity"; }

        //Pure virtual function, must be overriden
        virtual std::string GetSize() = 0;
};

class Player2 : public Entity2
{
    private:
    std::string m_Name;
    public:
    Player2(const std::string& name)
        : m_Name(name) {}

    //Override now indicates overriden function in class
    std::string GetName() override { return m_Name;}

    std::string GetSize() override {
        return "Large";
    }
};

void PrintName2(Entity2* entity)
{
    std::cout << entity->GetName() << std::endl;
}

int main()
{
    Entity* e = new Entity();
    PrintName(e);

    Player* p = new Player("Ryan");
    PrintName(p);

    //Can now no longer instantiate Entity2 class because it has a pure virtual function
    // Entity2* e2 = new Entity2();
    // PrintName2(e2);

    Player2* p2 = new Player2("Ryan");
    PrintName2(p2);
    std::cout << p2->GetSize() << std::endl;

    std::cin.get();
}