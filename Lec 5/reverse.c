#include <stdio.h>

int reverse_input_tail (int acc) {
    int n;

    // Base case: if input is not a number, return the accumulated minimum
    // Every time this will ask for an input
    if (!scanf("%d", &n)) {
        return acc;
    }
    else {
        if (n < acc) {
            acc = n;
        }
        int min = reverse_input_tail(acc);
        printf("%d\n", n);
        return min;
    }
}

void reverse_input_norm(void) {
    int n;
    scanf("%d", &n);
    int min = reverse_input_tail(n);
    printf("Minimum: %d\n", min);
}