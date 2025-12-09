#include <stdio.h>

// We're not using all the coins
// We're not looking for the smallest number of coins
// Looking at the examples and realizing we have unlimited coins
// Also, can we use on answer to get to the next answer?

// 37 dollars?
// Since every coins is optional, we can start at 10
// We can use 10 or not use 10, use 5 or not use 5
// The choice is the function's problem to deal with
int countWays(int coins[], int m, int amount) {
    if (amount == 0) return 1;
    if (amount < 0 || m <= 0) return 0;

    // The amount of ways we can count with less coins (37 with 1,3,5) or the amount of ways with less (27 with 1,3,5,10)
    return countWays(coins, m - 1, amount) + countWays(coins, m, amount - coins[m - 1]);

}

// 1. What is a smaller problem
// 2. How to reach the next problem from our current problem
// 3. Figure out the base cases