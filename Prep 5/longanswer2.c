#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int ** outerproduct(int a[], int m, int b[], int n) {
    int **c = malloc(sizeof(int *) * m);

    // Remember, for these double pointer problems, it's an array of pointers
    // For each element of the array, we need to malloc again
    for (int i = 0; i < m; i++) {
        c[i] = malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            c[i][j] = a[i] * b[j];
        }
    }

    return c;
}

int main() {
    int m = 5, n = 3;
    int a[] = { 1, 2, 3, 4, 5 };
    int b[] = { 3, 2, 1 };
    int **c = outerproduct(a, m, b, n);

    assert(c);
    assert(c[0][0] == 3);
    assert(c[0][1] == 2);
    assert(c[2][2] == 3);
    assert(c[4][0] == 15);

    int i;
    for (i = 0; i < m; i++) {
        free(c[i]);
    }
    free(c);
    return 0;
}
