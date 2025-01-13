#include <iostream>
#include <string>

class Entity
{
    public:
        int x, y;
        Entity(int x, int y)
        {
            Entity* const e = this; //The const (not required) just means that this can't be reassigned
            this->x = x;
            this->y = y;
        }

        int GetX() const
        {
            const Entity* e = this;
            //this is now a const Entity* const, in non-const it's a Entity* const (can modify contents of pointer but can't reassign pointer)
            // this->x = x; //Not allowed because can't modify the contents that this is pointing at
        }
};

int main()
{
    std::cin.get();
}