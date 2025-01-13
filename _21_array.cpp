#include <iostream>
#include <array>
using namespace std;

//If you don't want to pass in the size here you can use a template
template<class T, size_t I>
void printArray(array<T, I> a)
{
    for (auto &i : a)
    {
        cout << i << '\n';
    }
}

int main()
{
    array<int, 3> intArray {1, 2, 3};
    array<double, 2> doubleArray {2.3, 5.5};
    cout << "Printing Int Array" << '\n';
    printArray(intArray);
    cout << "Printing Double Array" << '\n';
    printArray(doubleArray);

    return 0;
};