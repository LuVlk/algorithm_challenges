/*

challenge:

Write a function `how_sum(target_sum, numbers)` that takes in a target_sum and an 
array of numbers as arguments.

The function should return on array containing any combination of elements that add
up to exactly the target_sum. If there is no combination that adds up to the target_sum,
return an unique value;

If there are multiple combinations possible, you may return any single one.

*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <memory>

using vec = std::vector<int>;
using map = std::unordered_map<int, vec>;
using map_ptr = std::shared_ptr<map>;

vec how_sum(
    const int target_sum,
    const vec numbers,
    map_ptr memo_ptr = map_ptr(new map()))
{
    if (memo_ptr->count(target_sum)) return memo_ptr->at(target_sum);
    if (target_sum == 0) return {};
    // {-1} is defined here as the base case for a not summarizable target_sum
    if (target_sum < 0) return {-1};

    for (const int & num: numbers)
    {
        const int new_sum = target_sum - num;
        vec rslt = how_sum(new_sum, numbers, memo_ptr);
        if (rslt != vec({-1}))
        {
            rslt.push_back(num);
            (*memo_ptr)[target_sum] = rslt;
            return rslt;
        }
    }

    (*memo_ptr)[target_sum] = {-1};
    return {-1};
}

template <typename T>
std::ostream & operator << (std::ostream & os, std::vector<T> const & values)
{
    auto first = values.cbegin();
    auto last = values.cend() - 1;
    os << "{";
    while(first != last)
    {
        os << *first << ", ";
        ++first;
    }
    os << *(last) << "}";
    return os;
}

int main()
{
    std::cout << how_sum(7, {2, 3}) << "\n";                      // {3, 2, 2}
    std::cout << how_sum(7, {5, 3, 4, 7}) << "\n";                // {4, 3}
    std::cout << how_sum(7, {2, 4}) << "\n";                      // {-1}
    std::cout << how_sum(8, {2, 3, 5}) << "\n";                   // {2, 2, 2, 2}
    std::cout << how_sum(300, {7, 14}) << "\n";                   // {-1}

    return 0;
}