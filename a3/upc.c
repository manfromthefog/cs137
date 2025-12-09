#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

// We must implement the function recursively
// We need to keep track of the position of the digit (odd/even)
// We need to keep track of the sum of odd and even positioned digits
// The base case is when upc is 0, at which point we check if the total sum is divisible by 10
// Note that we move down the digits every recursive call, all the way down to the first digit

// The UPC is 12 digits long, but we don't need to enforce that in the function
int implement_upc_helper(long long upc, int position, int sum_odd, int sum_even) {
    if (upc == 0) {
        int total_sum = sum_odd * 3 + sum_even;
        return total_sum % 10;
    }
    
    // I don't really care what happens
    // The function can deal with itself =)
    int digit = upc % 10;
    
    // Add the current digit to the appropriate sum based on its position
    // Position is 1-indexed from the right
    // UPC code is moved down by one digit
    if (position % 2 == 0) {
        return implement_upc_helper(upc / 10, position + 1, sum_odd, sum_even + digit);
    }
    else {
        return implement_upc_helper(upc / 10, position + 1, sum_odd + digit, sum_even);
    }
}

bool validate_upc(long long upc) {
    int check = upc % 10;
    upc /= 10; // Remove the check digit for processing
    // We start from the rightmost digit (position 1)

    int res = implement_upc_helper(upc, 1, 0, 0);

    if (res == 0) {
        return check == 0;
    } else {
        return check == (10 - res);
    }
}