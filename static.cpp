#include <iostream>

struct Entity{
    static int x, y;

    static void Print(){
        std::cout << x << "," << y << std::endl;
    }
};

//Setting the sccope of variables x and y
int Entity::x;
int Entity::y;

int main(){
    Entity e;
    e.x = 2;
    e.y = 3;

    //With a static variable this will not work
    // Entity e1 = {5, 8};

    //Updating the one (static) instance across all classes
    //x and y point to the same memory
    Entity e1;
    e1.x = 5;
    e1.y = 8;

    //Can instead do this, just updates Entity structs static variables
    Entity::x = 0;
    Entity::y = 0;

    //Incorrect way to call static function
    // e1.Print();
    // e.Print();

    Entity::Print();
    Entity::Print();

    std::cin.get();
    
}