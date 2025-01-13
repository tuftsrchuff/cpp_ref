#include <iostream>

#define LOG(x) std::cout << x << std::endl

//Private by default
class Player
{
    public:
        int x, y;
        int speed;

        void Move(int xa, int ya){
            x += xa * speed;
            y += ya * speed;
        }
    
};

//All public by defualt, can make private members though
struct RandStruct{
    int x, y;
    int speed;
    private:
        bool sneak = false;
};

//NonOO way - pass in reference to player object
void Move(Player& player, int xa, int ya){
    player.x += xa * player.speed;
    player.y += ya * player.speed;
}

int main(){
    Player player;//Instantiate player
    player.x = 5;
    player.y = 6;
    Move(player, 2, 3);

    player.Move(5, 5);

    RandStruct rstuc;
    rstuc.x = 5;
    rstuc.y = 10;

    std::cin.get();
}