#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// https://www.programiz.com/online-compiler/0n6PUchaEmm0D

int **outerproduct(int *a, int m, int *b, int n) {
    int **o = malloc(m * sizeof(int*));
    for (int i=0;i<m;i++) {
        o[i] = malloc(n * sizeof(int));
        for (int j=0;j<n;j++) {
            o[i][j] = a[i] * b[j];
        }
    }
    return o;
}

int main()
{
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
    for (i = 0; i < m; i++)
    {
        free(c[i]);
    }
    free(c);
    return 0;
}