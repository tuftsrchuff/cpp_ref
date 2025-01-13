#include <iostream>
#include <thread>

static bool s_Finished = false;

void DoWork()
{
    using namespace std::literals::chrono_literals;

    std::cout << "Started thread id=" << std::this_thread::get_id() << std::endl;
    while (!s_Finished)
    {
        //Print working every 1s, without pausing will max CPU usage on thread
        std::cout << "Working...\n";
        std::this_thread::sleep_for(1s);
    }
}

int main()
{
    //Pass in function pointer to thread

    //Will continuously print working on one thread
    std::thread worker(DoWork);

    //Checks cin.get on another thread
    std::cin.get();
    s_Finished = true;

    //Waits for threads to complete
    worker.join();

    std::cout << "Finished." << std::endl;
    std::cout << "Started thread id=" << std::this_thread::get_id() << std::endl;

    std::cin.get();
}