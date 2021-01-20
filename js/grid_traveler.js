/* 

Say that you are a traveler on a 2D grid. Yout begin in the top-left corner and yout goal
is to travel to the botton-right corner. yout may only move down or right.

In how many ways can you travel to the goal on a grid with dimensions m * n?

write a function `grid_traveler(m, n)` that calcuates this.
*/

const grid_traveler = (m, n, memo = {}) => {
    const key = m + ',' + n;
    if (key in memo) return memo[key];
    if (m === 1 && n === 1) return 1;
    if (m === 0 || n === 0) return 0;
    memo[key] = grid_traveler(m - 1, n, memo) + grid_traveler(m, n - 1, memo);
    return memo[key];
};

console.log(grid_traveler(1, 1)) // 1
console.log(grid_traveler(2, 3)) // 3
console.log(grid_traveler(3, 2)) // 3
console.log(grid_traveler(3, 3)) // 6
console.log(grid_traveler(18, 18)) // 2333606220
