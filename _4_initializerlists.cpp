#include <iostream>
#include <string>

class Entity
{
    private:
    std::string m_Name;
    int m_score;

    public:
    //Member initializer list, should be defined in order
    Entity() : m_Name("Unknown"), m_score(100) {}

    //Less efficient way to create objects
    Entity(const std::string& name){
        m_Name = name;
    }

    const std::string& GetName() const { return m_Name; }

};

int main(){
    Entity e;
    std::cout << e.GetName() << std::endl;

    Entity e2("Ryan");
    std::cout << e2.GetName() << std::endl;

    std::cin.get();
}