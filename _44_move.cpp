#include <iostream>
#include <cstring>

class String
{
    public:
        //Default constructor, explicitly defined
        String() = default;

        //Pass in char pointer and allocated on heap
        String(const char* string)
        {
            printf("Created!\n");
            m_Size = strlen(string);
            m_Data = new char[m_Size];
            memcpy(m_Data, string, m_Size);
        }

        //Copy constructor
        String(const String& other)
        {
            printf("Copied!\n");
            m_Size = other.m_Size;
            m_Data = new char[m_Size];
            memcpy(m_Data, other.m_Data, m_Size);
        }

        //Move constructor that takes in an rvalue
        String(String&& other) noexcept
        {
            //Points to old string datadata
            printf("Moved!\n");
            m_Size = other.m_Size;
            m_Data = other.m_Data;

            //Takes over old string
            //Non-deep copy
            other.m_Size = 0;
            other.m_Data = nullptr;
        }

        ~String()
        {
            delete m_Data;
        }

        void Print()
        {
            for (uint32_t i = 0; i < m_Size; i++)
            {
                printf("%c", m_Data[i]);
            }
            printf("\n");
        }

    private:
        char* m_Data;
        uint32_t m_Size;
};

class Entity
{
    public:
    //Copies String into m_Name
    Entity(const String& name)
        : m_Name(name){}

    //Must explicitly cast to rval reference
    //Takes in temporary and moves to new spot
    Entity(String&& name) : m_Name((String&&)name)
    {}
    
    void PrintName()
    {
        m_Name.Print();
    }
    
    private:
        String m_Name;
};

int main()
{
    //Creates String in scope of main function
    //Then when entity constructor called, String copied
    //Two heap allocations
    Entity entity(String("Ryan"));
    entity.PrintName();

    Entity entity2("Ryan w move");
    entity2.PrintName();


    //Copies string
    String string = "Hello";
    String dest = string;

    //With casting now takes in string rvalue reference, so performs move
    String dest2 = (String&&)string;

    //Using move
    String dest3(std::move(string));

    std::cin.get();
}