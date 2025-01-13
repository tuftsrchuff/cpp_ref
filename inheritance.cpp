#include <iostream>

class Entity{
    public:
        float X, Y;

        void Move(float xa, float ya){
            X += xa;
            Y += ya;
        }
};

//Inherits from type entity
//Has type player and entity
class Player : public Entity
{
    public:
        const char* Name;

        void PrintName(){
            std::cout << Name << std::endl;
        }
};

int main()
{
    Player player;
    player.Move(5, 5);
    player.X = 2;

    std::cin.get();
}