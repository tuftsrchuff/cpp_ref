#include <iostream>
#include <string>
#include <string.h>

struct Vector2
{
    float x, y;
};

//C-style string class
class String
{
    private:
    char* m_Buffer;
    unsigned int m_Size;

    public:
    String(const char* string)
    {
        m_Size = strlen(string); //C function for getting length of passed in string
        m_Buffer = new char[m_Size + 1]; //Allocate on heap
        memcpy(m_Buffer, string, m_Size); //Copy over the string onto the heap
        m_Buffer[m_Size] = 0;
    }

    //Will cause crash if there isn't a copy constructor when trying to make shallow copy
    ~String(){
        delete[] m_Buffer;
    }

    //Copy constructor if we don't want a copy constructor
    // String(const String& other) = delete;

    //Copy constructor that takes in other String object and creates new memory allocation with same content as other string
    String(const String& other)
        : m_Size(other.m_Size)
        {
            std::cout << "Copied String!" << std::endl;
            m_Buffer = new char[m_Size + 1];
            memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
        }

    char& operator[](unsigned int index)
    {
        return m_Buffer[index];
    }


    //Allows overloaded operator to access the private variable buffer outside the class
    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string){
    stream << string.m_Buffer;
    return stream;
}

//Creates a copy of string inside this function, must pass by ref/pointer to not copy
void PrintString(String string)
{
    std::cout << string << std::endl;
}

int main()
{
    Vector2 a = { 2, 3 };
    Vector2 b = a; //Copies a into b
    b.x = 5;

    std::cout << a.x << ", " << b.x << std::endl;

    Vector2* a1 = new Vector2();
    Vector2* b1 = a1; //Copies pointer, both pointing to the same place
    b1->x = 2;

    std::cout << a1->x << ", " << b1->x << std::endl; 

    String string = "Ryan";

    //Creates shallow copy here, will crash because trying to free same block of memory twice
    String second = string;
    second[3] = 'y'; //Overrides both strings, changes both
    std::cout << string << std::endl;
    std::cout << second << std::endl;

    PrintString(string);
    PrintString(second);

    std::cin.get();
}