#include <iostream>

class Entity
{
    private:
        int m_X, m_Y;
        int* m_X2;
        mutable int var = 2;
    
    public:
        //Method promises not to modify m_X
        int GetX() const
        {
            //Change mutable variable inside const function
            var = 4;
            return m_X;
        }

        //Returns pointer where mem location and value at mem can't be modified
        //Also promises not to modify contents inside
        const int* const GetX2() const
        {
            return m_X2;
        }

        
};

//This will not modify entity e, can only call const functions
void PrintEntity(const Entity& e)
{
    std::cout << e.GetX() << std::endl;
}


int main(){
    Entity e;
    //can't change this value now
    const int MAX_AGE = 90;

    //Can't change the value at the pointer, but can change pointer location
    const int* a = new int;

    //Can change value at pointer, just not pointer location
    int* const b = new int;

    e.GetX();



    //Not allowed
    // *a = 2;
    //Allowed
    a = (int*)&MAX_AGE;

    //Allowed
    *b = 2;

    //Not allowed
    // b = (int*)&MAX_AGE;

    std::cout << *a << std::endl;
    std::cout << *b << std::endl;

    std::cin.get();
}