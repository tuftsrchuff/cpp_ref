#include <iostream>
#include <chrono>
#include <thread>

struct Timer
{
    std::chrono::high_resolution_clock::time_point start, end;
    std::chrono::duration<float> duration;

    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer(){
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;

        float ms = duration.count() * 1000.0f;
        std::cout << "Timer took " << ms << "ms" << std::endl;
    }
};

void Function()
{
    //Times entire function
    Timer timer;
    for (int i = 0; i < 100; i++)
        std::cout << "Hello\n";
}

int main()
{
    //Specifically writing out timer durations
    using namespace std::literals::chrono_literals;


    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(1s);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration = end - start;
    std::cout << duration.count() << "s" << std::endl;

    //Using Timer struct
    Function();
}