/*
challenge:

write a function `fib(n)` that takes in a number as an argument.
The function should return the n-th number of the Fibonacci sequence.
*/

#include <iostream>
#include <unordered_map>
#include <memory>

using map = std::unordered_map<int, unsigned long long int>;

unsigned long long int fib(const int n, std::shared_ptr<map> memo_ptr = std::shared_ptr<map>(new map()))
{
    if (memo_ptr->count(n))
        return memo_ptr->at(n);
    if (n <= 2)
        return 1;
    (*memo_ptr)[n] = fib(n - 1, memo_ptr) + fib(n - 2, memo_ptr);
    return memo_ptr->at(n);
}

int main()
{
    std::cout << fib(6) << "\n";  // 8
    std::cout << fib(7) << "\n";  // 13
    std::cout << fib(50) << "\n"; // 12586269025
}