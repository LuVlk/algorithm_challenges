/*
challenge:

Write a function `can_sum(target_sum, numbers)` that takes in a target_sum and an array of
number as arguments.

The function should return a boolean indicationg wther or not it is possible to generate
the target_sum using numbers from the array.

Consider only positive input numbers for the array.
Double usage of numbers in the array is allowed.

*/

#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

using map = std::unordered_map<int, bool>;

bool can_sum(
    const int target_sum,
    const std::vector<int> numbers,
    std::shared_ptr<map> memo_ptr = std::shared_ptr<map>(new map()))
{
    if (memo_ptr->count(target_sum)) return memo_ptr->at(target_sum);
    if (target_sum == 0) return true;
    if (target_sum < 0) return false;

    for (const int &num : numbers)
    {
        const int new_sum = target_sum - num;
        if (can_sum(new_sum, numbers, memo_ptr))
        {
            (*memo_ptr)[target_sum] = true;
            return true;
        }
    }

    (*memo_ptr)[target_sum] = false;
    return false;
}

int main()
{
    std::cout << can_sum(7, {2, 3}) << "\n";                      // true
    std::cout << can_sum(7, {5, 3, 4, 7}) << "\n";                // true
    std::cout << can_sum(7, {2, 4}) << "\n";                      // false
    std::cout << can_sum(8, {2, 3, 5}) << "\n";                   // true
    std::cout << can_sum(300, {7, 14}) << "\n";                   // false

    return 0;
}