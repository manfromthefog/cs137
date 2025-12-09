#include <stdio.h>

/***
 * Base Case
 * The number is 1 or 2.
 * 
 * 0, 1 -> 2 non-consecutive
 * 00, 01, 10, 11 -> 3 non-consecutive
 * 
 * 00 + 0 -> new valid sequence
 * 01 + 0 -> new valid sequence
 * 00 + 1 -> new valid sequence
 * 1 + 00 -> new valid sequence
 * 10 + 1 -> new valid sequence
 * 1 + 10 -> invalid
 * 01 + 1 -> invalid
 * 11 + anything -> invalid
 * 
 * We notice it's a fib seq starting from 2,3
 */

/***
 * @param n
 * Determine the number of binary numbers of length n that does not 
 */
int countSeq(int n) {
    if (n == 1) return 2;
    if (n == 2) return 3;
    return countSeq(n - 1) + countSeq(n - 2);
}

int main(void) {
    printf("%d\n", countSeq(4));
    return 0;
}