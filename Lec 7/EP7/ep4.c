#include <stdio.h>

int index_max_array(int a[], int n) {
    int max = a[0], maxind = 0;
    int i = 0;

    for (;i<n;i++) {
        if (a[i] > max) {
            max = a[i];
            maxind = i;
        }
    }
    return maxind;
}

int main(void) {
    int a[5] = {5, 6, 4, 1, 6};
    int n = 5;
    printf("%d\n", index_max_array(a, n));
}