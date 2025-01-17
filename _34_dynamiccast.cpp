#include <iostream>
#include <string>

class Entity
{
    public:
    virtual void PrintName() {}

};

class Player : public Entity
{};

class Enemy : public Entity
{};

int main()
{
    Player* player = new Player();
    //Implicit cast
    Entity* actualPlayer = player;

    Entity* actualEnemy = new Enemy();
    //Invalid cast
    // Player* p = e1;
    Player* p = (Player*) actualEnemy; //Valid cast but dangerous since Player shouldn't be casted to Enemy

    //Dynamic cast to verify can be casted 
    Player* p1 = dynamic_cast<Player*>(actualPlayer);

    if (p1 == nullptr){
        std::cout << "Can't be cast into a player\n";
    } else {
        std::cout << "Cast is valid\n";
    }
}