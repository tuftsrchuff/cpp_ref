#include <iostream>

class Entity{
    public:
    float X, Y;

    //Default constructor
    Entity(){
        std::cout << "Created entity!" << std::endl;
    }

    //This makes it so you can't instantiate the entity class
    // Entity() = delete;

    //Constructor with variables
    Entity(float x, float y){
        X = x;
        Y = y;
    }

    //Destructor
    ~Entity(){
        std::cout << "Destroyed entity!" << std::endl;
    }

    void Print(){
        std::cout << X << ", " << Y << std::endl;
    }
};

void Function(){
    Entity e1;
    Entity e(10.0f, 5.0f);
    std::cout << e.X << std::endl;
    e.Print();
}

int main(){
    Function();

    std::cin.get();
}