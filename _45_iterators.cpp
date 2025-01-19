#include <iostream>
#include <vector>
#include <unordered_map>

int main()
{
    std::vector<int> values = { 1, 2, 3, 4, 5 };

    //Increment with indexes
    for (int i = 0; i < values.size(); i++){
        std::cout << values[i] << std::endl;
    }

    //Range based for loop
    for (int value: values)
        std::cout << value << std::endl;

    
    //Iterator
    for (std::vector<int>::iterator it = values.begin(); it != values.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    std::unordered_map<std::string, int> map;
    map["Ryan"] = 5;
    map["C++"] = 3;

    //Easier type semantically for the for loop
    using ScoreMap = std::unordered_map<std::string, int>;
    using ScoreMapConstIterator = ScoreMap::const_iterator;
    for (ScoreMapConstIterator it = map.begin(); it != map.end(); it++){
        //Reference so not copying value
        auto& key = it->first;
        auto& value = it->second;

        std::cout << key << " = " << value << std::endl;
    }

    //Range based for loop doing same thing
    for (auto kv : map)
    {
        auto& key = kv.first;
        auto& value = kv.second;
        std::cout << key << " = " << value << std::endl;
    }

    //C++17 structured bindings
    for (auto [key, value] : map)
        std::cout << key << " = " << value << std::endl;

    std::cin.get();

}