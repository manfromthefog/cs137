#include <stdio.h>
// https://www.programiz.com/online-compiler/0Hh3MMYfmLd4f

int read_and_range(int *max, int *min, int *count_max, int *count_min) {
    int read = 0;
    int num;
    while (scanf("%d", &num) == 1) {
        if (read == 0) {
            *min = num;
        }
            
        if (num > *max) {
            *max = num;
            *count_max = 0;
        }
        if (num == *max) {
            (*count_max)++;
        }
        if (num < *min) {
            *min = num;
            *count_max = 0;
        }
        if (num == *min) {
            (*count_min)++;
        }
        read++;
    }
    return read;
}

int main(void) {
    int min = 0;
    int max = 0;
    int count_min = 0;
    int count_max = 0;
    int count = read_and_range(&max, &min, &count_max, &count_min);
    printf("min = %d\n", min);
    printf("max = %d\n", max);
    printf("count_min = %d\n", count_min);
    printf("count_max = %d\n", count_max);
    printf("count = %d\n", count);
}