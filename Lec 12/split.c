#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

int **split(int a[], int n, int p, int *len1, int *len2) {
    int **res = (int**)malloc(2 * sizeof(int*));
    int exceeds_p = 0;

    // First determine the partions we need to make
    for (int i = 0; i < n; i++) {
        if (a[i] > p) exceeds_p++;
    }

    // Next we make the heaps for both partitions
    res[0] = malloc((n - exceeds_p) * sizeof(int));
    res[1] = malloc(exceeds_p * sizeof(int));

    int c1 = 0, c2 = 0;
    // Then we assign our values =)
    for (int j = 0; j < n; j++) {
        // Ensure correct length by keeping counters for each
        if (a[j] > p) {
            res[1][c2] = a[j];
            c2++;
        }
        else {
            res[0][c1] = a[j];
            c1++;
        }
    }
    (*len1) = c1;
    (*len2) = c2;
    return res;
}

int main(void) {
    int a[] = { 9,3,2,6,-1,3,6,6,7,8,5,2,3,4,1,0 };
    int n = sizeof(a) / sizeof(a[0]);
    int n1, n2;

    int **ans = split(a, n, 5, &n1, &n2);
    assert(n1 == 10);
    assert(n2 == 6);

    printf("First Array\n");
    for (int i = 0; i < n1; i++) {
        printf("%d\n", ans[0][i]);
    }
    printf("Second Array\n");
    for (int i = 0; i < n2; i++) {
        printf("%d\n", ans[1][i]);
    }
    free(ans[1]);
    free(ans[0]);
    free(ans);
    return 0;
}