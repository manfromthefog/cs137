#include <stdio.h>

int countWays(int n) {
    if (n == 0) {
        return 1;
    }
    else if (n < 0) {
        return 0;
    }
    // Unlike the previous example anything can go, we can take 1, 3, or 4
    return countWays(n - 1) + countWays(n - 3) + countWays(n - 4);
}

int main(void) {
    printf("%d\n", countWays(6));
    return 0;
}