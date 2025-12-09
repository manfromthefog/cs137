#include <stdio.h>
#include <math.h>

/***
 * Write a program that reads a positive integer and creates a new value with the
same digits as the input but in reverse order and prints the new integer in addition
to the total sum of both integers.

We need to make the number an array, and we need to consider going forwards and backwards.
***/

int lenint(long long int n) {
    int i = 0;
    while (n > 0) {
        i++;
        n /= 10;
    }
    return i;
}

int reversal(long long int n) {
    long long int rev = 0;
    int len = lenint(n);
    for (int i = 0; i < len; i++) {
        rev += (n % 10) * pow(10, len - i - 1);
        n /= 10;
    }
    return rev;
}

int main(void) {
    long long int n = 10;
    printf("%lld\n", n + reversal(n));
}