/* 
Say that you are a traveler on a 2D grid. Yout begin in the top-left corner and yout goal
is to travel to the botton-right corner. yout may only move down or right.

In how many ways can you travel to the goal on a grid with dimensions m * n?

write a function `grid_traveler(m, n)` that calcuates this.
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>

using map = std::unordered_map<std::string, unsigned long long int>;

unsigned long long int grid_traveler(
    const unsigned int m,
    const unsigned int n,
    std::shared_ptr<map> memo_ptr = std::shared_ptr<map>(new map()))
{
    const std::string key = std::string("") + (char)(m) + "," + (char)(n);
    if (memo_ptr->count(key))
        return memo_ptr->at(key);
    if (m == 1 && n == 1)
        return 1;
    if (m == 0 || n == 0)
        return 0;
    (*memo_ptr)[key] = grid_traveler(m - 1, n, memo_ptr) + grid_traveler(m, n - 1, memo_ptr);
    return memo_ptr->at(key);
}

int main()
{
    std::cout << grid_traveler(1, 1) << "\n"; // 1
    std::cout << grid_traveler(2, 3) << "\n"; // 3
    std::cout << grid_traveler(3, 2) << "\n"; // 3
    std::cout << grid_traveler(3, 3) << "\n"; // 6
    std::cout << grid_traveler(18, 18) << "\n"; // 2333606220
}
