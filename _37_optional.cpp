#include <iostream>
#include <fstream>
#include <optional>

std::string ReadFileAsString(const std::string& filepath)
{

    std::ifstream stream(filepath);

    if (stream)
    {
        //read file
        stream.close();
        std::string result;
        return result;
    }

    //Couldn't open stream so return empty string
    return std::string();
}

std::optional<std::string> ReadFileAsStringOpt(const std::string& filepath)
{

    std::ifstream stream(filepath);

    if (stream)
    {
        //read file
        std::string result;
        std::getline(stream, result);
        stream.close();
        
        return result;
    }

    //Optional with no return
    return {};
}

int main()
{

    std::string data = ReadFileAsString("data.txt");
    if (data != "")
    {
        //Do something
    } else
    {
        std::cout << "Empty file" << std::endl;
    }

    std::optional<std::string> dataOpt = ReadFileAsStringOpt("data2.txt");

    //Default value if value is not present
    std::string value = data.value_or("Not present");
    if (dataOpt.has_value())
    {
        std::string& string = *dataOpt;
        std::cout << string << std::endl;
        std::cout << "File read successfully!\n";
    } else {
        std::cout << "Empty file with optional" << std::endl;
    }

}