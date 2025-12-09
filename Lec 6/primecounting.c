#include <stdio.h>

// Find all prime numbers up to n using an array

int main(void) {
    int n;
    scanf("%d", &n);

    int prime[n];

    prime[0] = 0;
    prime[1] = 0;
    for (int i = 2; i < n; i++) {
        prime[i] = 1;
    }

    // Stop when the number is larger than sqrt(n)
    for (int j = 2; j * j < n - 1; j++) {
        // Start by assuming the index at 1 is prime.
        if (prime[j]) {
            // Once we find a prime, we will find all multiples of the number and strike them out
            // Since we start from 2, we will very quickly strike out all multiples of 2, 3, 5, 7, etc.
            // Very efficient algorithm
            for (int k = 2 * j; k < n; k += j) {
                prime[k] = 0;
            }
        }
    }

    for (int a = 0; a < n; a++) {
        if (prime[a] == 1) {
            printf("%d ", a);
        }
    }
    printf("\n");
    return 0;
}