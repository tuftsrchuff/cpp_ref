#include <iostream>
#include <string>
#include <memory>

class Entity
{
    public:
        Entity()
        {
            std::cout << "Created Entity!" << std::endl;
        }

        ~Entity()
        {
            std::cout << "Destroyed Entity!" << std::endl;
        }

        void Print() {
            //Do something
        }
};

int main(){
    //Weak pointer
    std::weak_ptr<Entity> e0;
    {
        //Unique pointer
        //Valid but not recommended
        std::unique_ptr<Entity> entity(new Entity());

        //Recommended for exception safey
        std::unique_ptr<Entity> entity2 = std::make_unique<Entity>();

        //std::unique_ptr<Entity> entity = new Entity(); //Not allowed because the unique_ptr constructor is explicit
        // std::unique_ptr<Entity> e0 = entity; //Not allowed because you can't copy unique_ptr
        entity2->Print();

        //Shared pointer
        std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
        {
            std::shared_ptr<Entity> sharedEntity2 = sharedEntity;
            e0 = sharedEntity2;
        }
        //Shared pointer still alive, weak_ptr still alive
        
    }
    //Shared pointer now dead, weak_ptr dead


    std::cin.get();
}