// Our goal is to divide two numbers
// Fully divisible is the base case
// If not, check for sign
// If positive, round up
// If negative, round down
// Store the value in a variable to reduce print statements
#include <stdio.h>

int main() {
    // Take two inputs
    int num, denom;
    scanf("%d %d", &num, &denom);
    
    // Initialize the result
    int res;
    
    // If the numbers are fully divisible no further actions are necessary, return the output
    if (num % denom == 0) {
        res = num / denom;
    }
    else if (num > 0 && denom > 0) {
        // For positive numbers round up (away from zero)
        res = num / denom + 1;
    } 
    else if (num < 0 || denom < 0) {
        // For negative numbers round down (away from zero)
        res = num / denom - 1;
    } 
    else {
        res = 0; // quotient is zero
    }

    printf("%d", res);
    return 0;
}
