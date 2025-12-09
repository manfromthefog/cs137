#include <stdio.h>

/***
 * Write a function int read_and_range(int *max, int *min, int *count_max, int count_min) that reads integers until a
 * failure occurs and returns the number of integers successfully read. If no integers were successfully read in, the 
 * functions return zero and do not modify (mutate) the parameters' contents.
 */
int read_and_range(int *max, int *min, int *count_max, int *count_min) {
    int n;
    int c = 0;
    
    while (scanf("%d", &n) == 1) {
        if (c == 0) {
            *max = 0;
            *min = n;
        }
        else {
            if (n > *max) {
                *max = n;
                (*count_max) = 1;
            }
            else if (n == *max) {
                (*count_max)++;
            }
            else if (n < *min) {
                *min = n;
                (*count_min) = 1;
            }
            else if (n == *min) {
                (*count_min)++;
            }
        }
        c++;
    }
    return c;
}

int main() {
    int max = 0; 
    int min = 0;
    int count_min = 0;
    int count_max = 0;
    int count = read_and_range(&max, &min, &count_max, &count_min);

    printf("min = %d\n", min);
    printf("max = %d\n", max);
    printf("count_min = %d\n", count_min); printf("count_max = %d\n", count_max);
    printf("count = %d\n", count);
}
