#include <iostream>
#include <memory>

struct AllocationMetrics
{
    uint32_t TotalAllocated = 0;
    uint32_t TotalFreed = 0;

    uint32_t CurrentUsage() { return TotalAllocated - TotalFreed; }
};

static AllocationMetrics s_AllocationMetrics;

void* operator new(size_t size){

    s_AllocationMetrics.TotalAllocated += size;

    //Allocates appropriate memory as expected
    return malloc(size);
}

//Track heap free
void operator delete(void* memory, size_t size)
{
    s_AllocationMetrics.TotalFreed += size;
    std::cout << "Freed " << size << std::endl;

    free(memory);
}

struct Object
{
    int x, y, z;
};

int main()
{
    std::string string = "Ryan";
    Object* obj = new Object;

    //Still calling new here
    std::unique_ptr<Object> obj2 = std::make_unique<Object>();
    delete obj;

    std::cout << "Total allocated: " << s_AllocationMetrics.TotalAllocated << std::endl;
    std::cout << "Total freed: " << s_AllocationMetrics.TotalFreed << std::endl;
}