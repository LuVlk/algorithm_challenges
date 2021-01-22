/*

challenge:

Write a function `how_sum(target_sum, numbers)` that takes in a target_sum and an 
array of numbers as arguments.

The function should return on array containing any combination of elements that add
up to exactly the target_sum. If there is no combination that adds up to the target_sum,
then return null;

If there are multiple combinations possible, you may return any single one.

*/

const how_sum = (target_sum, numbers, memo = {}) => {
    if (target_sum in memo) return memo[target_sum];
    if (target_sum === 0) return [];
    if (target_sum < 0) return null;

    for (let num of numbers) {
        const new_sum = target_sum - num;
        rslt = how_sum(new_sum, numbers, memo);
        if (rslt !== null) {
            rslt = [ ...rslt, num];
            memo[target_sum] = rslt;
            return rslt;
        }
    }

    memo[target_sum] = null;
    return null;
};

console.log(how_sum(7, [2, 3])); // [3, 2, 2]
console.log(how_sum(7, [5, 3, 4, 7])); // [4, 3]
console.log(how_sum(7, [2, 4])); // null
console.log(how_sum(8, [2, 3, 5])); // [2, 2, 2, 2]
console.log(how_sum(300, [7, 14])) // null