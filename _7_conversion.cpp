#include <iostream>
#include <string>

class Entity
{
    private:
    std::string m_Name;
    int m_age;

    public:
    Entity(const std::string& name) 
        : m_Name(name), m_age(-1) {}
    Entity(const std::string& name, int age) 
        : m_Name(name), m_age(age) {}

    explicit Entity(int age) 
        : m_Name("Unknown"), m_age(age) {}

    const std::string& GetName() const { return m_Name; }
};

void PrintEntity(const Entity& entity)
{
    //Printing
}


int main(){
    Entity a("Ryan");
    Entity b("Ryan", 30);
    //Explicit constructor, will fail
    // Entity e = 22;
    Entity e = (Entity) 22; //Explicitly cast to entity

    //Implicit conversion
    Entity c = std::string("Ryan"); //Uses Entity constructor for string for implicit conversion

    //Won't work because needs to be converted to string, can't convert char arr to string to entity implicitly
    // PrintEntity("Ryan");

    //Will work because now just converts string to entity
    PrintEntity(std::string("Ryan"));

    std::cin.get();
}