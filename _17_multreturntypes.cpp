#include <iostream>
#include <utility>
#include <tuple>

//Returns tuple of elements
std::tuple<int, double, std::string> getData() {
    return std::make_tuple(42, 3.14, "Hello");
}

//Returns stuct
struct Point {
    double x;
    double y;
};

Point getCoordinates() {
    Point p;
    p.x = 10.0;
    p.y = 20.0;
    return p;
}

//Returns pair
std::pair<int, int> getMinMax(int a, int b) {
    if (a < b){
        return { a, b};
    } else {
        return { b, a};
    }
}

//Pass by reference
void getSize(int& width, int& height) {
    width = 1920;
    height = 1080;
}

int main()
{
    auto [num, val, str] = getData(); //Uses structured bindings C++17
    std::pair<int, int> nums = getMinMax(4, 6);
    Point coord = getCoordinates();
    getSize(nums.first, nums.second);
    std::cout << num << ", " << val << ", " << str << std::endl;
    std::cin.get();
}