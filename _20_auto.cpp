#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Device {};

class DeviceManager
{
    private:
        std::unordered_map<std::string, std::vector<Device*>> m_Devices;
    public:
        const std::unordered_map<std::string, std::vector<Device*>>& GetDevices() const{
            return m_Devices;
        }
};

int main(){
    int a = 5;
    auto b = a;

    //Auto keyword makes a variable weakly typed
    b = 5;

    std::vector<std::string> strings;
    strings.push_back("Apple");
    strings.push_back("Orange");

    //Iterator to print each string without auto
    for (std::vector<std::string>::iterator it = strings.begin();
        it != strings.end(); it++){
            std::cout << *it << std::endl;
        }
    
    //Shorter with auto
    for (auto it = strings.begin();
        it != strings.end(); it++){
            std::cout << *it << std::endl;
        }


    //Unwieldy without auto for getting device manager
    DeviceManager dm;
    
    const std::unordered_map<std::string, std::vector<Device*>>& devices = dm.GetDevices();

    //One potential option to shorten type
    using DeviceMap = const std::unordered_map<std::string, std::vector<Device*>>;
    DeviceMap devices2 = dm.GetDevices();

    //Or use auto
    auto devices3 = dm.GetDevices();

    std::cin.get();
}