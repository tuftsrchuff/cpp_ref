#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
    float x, y, z;

    Vertex(float x, float y, float z)
        : x(x), y(y), z(z)
        {}
    
    Vertex(const Vertex& vertex)
        : x(vertex.x), y(vertex.y), z(vertex.z)
        {
            std::cout << "Copied!" << std::endl;
        }
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
    stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
    return stream;
}

int main()
{
    std::vector<Vertex> vertices;
    // vertices.reserve(3); //Reserves starting size of 3, will usually 

    //Initializer list for vertice, implicit conversion to Vertex object
    //Creates vertex object THEN copies that vertex into the vector
    vertices.push_back({1, 2, 3});
    vertices.push_back({5, 6, 7});
    vertices.push_back({8, 9, 10});

    for(const Vertex& v : vertices)
        std::cout << v << std::endl;



    //Erase takes in an iterator
    vertices.erase(vertices.begin() + 1);

    for(const Vertex& v : vertices)
        std::cout << v << std::endl;
    
        //Clears all vertices
    vertices.clear();

    //No copy constructor called
    std::vector<Vertex> vertices2;
    vertices2.reserve(3);
    vertices2.emplace_back(1,2,3);
    vertices2.emplace_back(5, 6, 7);
    vertices2.emplace_back(8, 9, 10);

    for(const Vertex& v : vertices2)
        std::cout << v << std::endl;




    std::cin.get();
}