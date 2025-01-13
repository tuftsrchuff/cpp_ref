#include <iostream>

//No templates, need to overload Print
void Print(int number)
{
    std::cout << number << std::endl;
}

void Print(std::string str){
    std::cout << str << std::endl;
}

//Template evaluated at compile time
template<typename T>
void Print2(T value)
{
    std::cout << value << std::endl;
}

//Same exact thing as template above
template<class Ryan>
int add(Ryan a, Ryan b){
    return 1;
}

//Creates a class Array with m_Array as whatever size was specified
//Takes in any generic type
template<typename T,int N>
class Array
{
    private:
        T m_Array[N];
    public:
        int GetSize() const { return N; }
};

int main()
{
    Print(5);
    Print("Hello!");

    Print2(5.0f);
    Print2("Hello!");

    //Replaces with type int, usually automatically worked out
    Print2<int>(5);

    Array<int, 10> array;
    std::cout << array.GetSize() << std::endl;

    std::cin.get();
}