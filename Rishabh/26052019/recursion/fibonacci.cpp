#include "fibonacci.h"
#include <map>

unsigned long long _fibonacci(unsigned int n, std::map<int, int> memory) {
    if(n == 0 || n == 1) return n;
    unsigned long long prev, cur;
    if(memory.find(n - 1) != memory.end()){
        prev = memory.find(n - 1)->second;
    }   else    {
        prev = _fibonacci(n - 1, memory);
        memory.insert({ n - 1, prev });
    }

    if(memory.find(n - 2) != memory.end()){
        prev = memory.find(n - 2)->second;
    }   else    {
        prev = _fibonacci(n - 2, memory);
        memory.insert({ n - 2, prev });
    }

    return prev + cur;
}

unsigned long long fibonacci(int n) {
    std::map<int, int> memory;
    return _fibonacci(n, memory);
}