/*
challenge:

write a function `fib(n)` that takes in a number as an argument.
The function should return the n-th number of the Fibonacci sequence.
*/

const fib = (n, memo = {}) => {
    if (n in memo) return memo[n];
    if (n <= 2) return 1;
    memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
    return memo[n]
};

console.log(fib(6)); // 8
console.log(fib(7)); // 13
console.log(fib(50)); // 12586269025