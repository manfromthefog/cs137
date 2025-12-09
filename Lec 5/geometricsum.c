#include <stdio.h>

int power(int b, int n) {
    if (n == 1) {
        return b; // b^0 = 1
    }
    return b * power(b, n - 1);
}

int geometric_sum_helper(int n, int b, int acc) {
    if (n == 1) {
        return acc + b; // base case: b^1 = b
    }
    return geometric_sum_helper(n - 1, b, acc + power(b, n));
}

int geometric_sum(int n, int b) {
    return geometric_sum_helper(n, b, 0);
}

int main(void) {
    int n = 4;
    int b = 3;
    int result = geometric_sum(n, b);
    printf("%d", result);
    return 0;
}