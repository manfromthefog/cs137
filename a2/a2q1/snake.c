#include <stdio.h>

int main(void) {
    int n, m;
    scanf("%d", &n);

    // We start with length of 1 since the for loop starts by adding 1 to it.
    int l = 1;

    for (int i = 0; i < n - 3; i++) {
        // Increase the length every other index since the dots are on odd indexes.
        if (i % 2 == 0) {
            l += 1;
        }

        // Initialize variable to calculate the length of the right half
        int x = n - (i + 4);
        // Initalize variable to calculate the length of the left half
        int y = n - x - l - 1;
        // printf("%d, %d", y, x);

        for (int a = 0; a < y; a++) {
            printf("_");
        }
        
        for (int j = 0; j < l; j++) {
            printf("X");
        }
        printf("H");
        
        // A very nice staggering trick. Let me explain. When the right side is even, we want to have an underscore first. When it's odd, we want to have a dot first. So we can use the modulo operator to check if both n and b are even or odd, and print accordingly.
        for (int b = x; b > 0; b--) {
            if (b % 2 == (n % 2)) {
                printf("_");
            }
            else {
                printf(".");
            }

        }
    
        printf("\n");
    }
    return 0;
}