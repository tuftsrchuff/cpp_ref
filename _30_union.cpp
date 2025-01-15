#include <iostream>

struct Vector2
{
    float x, y;
};

struct Vector4
{
    

    union
    {
        //Now a single member (which is what a union takes)
        struct
        {
            float x, y, z, w;
        };

        struct
        {
            //a is same memory as x and y, b is same memory as z and w
            Vector2 a, b;
        };
        
        
    };
};

void PrintVector2(const Vector2& vector){
    std::cout << vector.x << ", " << vector.y << std::endl;
}

int main()
{
    Vector4 vector = {1.0f, 2.0f, 3.0f, 4.0f};
    PrintVector2(vector.a);
    PrintVector2(vector.b);

    //Now modifies z which is same
    vector.z = 500.0f;
    PrintVector2(vector.a);
    PrintVector2(vector.b);
    
    std::cin.get();
}