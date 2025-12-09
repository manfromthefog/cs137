#include <stdio.h>
#include <assert.h>
#include "fun.h"

// All assert test cases were passed!

int isSophieGermainPrime(int p) {
    // The most obvious check is that every prime number is greater than or equal to 2
    if (p < 2) return 0;

    // Check if p is prime. We used this algorithm in class.
    for (int i = 2; i * i <= p; i++) {
        if (p % i == 0) return 0; // Not prime
    }   

    // Repeat the algorithm for q = 2p + 1
    int q = 2 * p + 1;
    for (int i = 2; i * i <= q; i++) {
        if (q % i == 0) return 0; // Not prime
    }

    return 1; // Both p and q are prime
}

int base2nat(int bs, int num) {
    // Two variables to keep track of the result and the current power of the base
    int result = 0;
    int base_power = 1;

    while (num > 0) {
        // Extract the last digit
        int digit = num % 10;
        // Check if the digit is valid for the given base
        if (digit < 0 || digit >= bs) {
            return -1; // Invalid digit for the base
        }
        // Add the digit's contribution to the result
        result += digit * base_power;
        // Update the base power and remove the last digit
        base_power *= bs;
        // Remove the last digit
        num /= 10;
    }

    return result;
}

int nat2base(int bs, int num) {
    // Edge case: if num is 0, return 0
    if (num == 0) return 0;

    // Assuming the current base power is 1 (bs^0)
    int result = 0;
    int base_power = 1;

    while (num > 0) {
        // Extract the last digit in the new base
        int digit = num % bs;
        // Add the digit to the result in the correct position
        result += digit * base_power;
        // Update the base power and remove the last digit
        base_power *= 10;
        // Remove the last digit
        num /= bs;
    }

    return result;
}