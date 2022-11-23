#include "function.h"

std::vector<unsigned int> fib_below_n( unsigned int n )
{
    std::vector<unsigned int> numbers;
    if(n == 1 or n == 0){
        return numbers;
    }else{
        unsigned int previous = 0, current = 1, next;
        while(current < n) {
            next = previous + current;
            previous = current;
            numbers.push_back(current);
            current = next;
        }
    }
    return numbers;
}
