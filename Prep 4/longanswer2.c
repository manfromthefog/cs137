#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int *concatenate(int *a, int m, int *b, int n) {
    // Find the total length
    int total_length = m + n;

    // Allocate memory for the concatenated array
    int *concat = malloc(total_length * sizeof(int));
    if (!concat) return NULL;

    for (int i = 0; i < total_length; i++) {
        if (i < m)
            concat[i] = a[i];
        else
            concat[i] = b[i - m];
    }

    // Now for the swap... can we do it?
    // We need to swap the arrays and b in place
    /**
    for (int i = 0; i < n; i++) {
        int temp = a[i];
        a[i] = b[i];
        b[i] = temp; 
    }
     */
    // Actually impossible because a and b are memory incompatible

    return concat;
}

// Code snippet for array swap (source: ChatGPT)
// Works ONLY with heap-allocated arrays
// Does not work in our example.
void swap_arrays(int **a, int *m, int **b, int *n) {
    int *tmp_arr = *a;
    *a = *b;
    *b = tmp_arr;

    int tmp_len = *m;
    *m = *n;
    *n = tmp_len;
}

int main(){
    int m = 5, n = 3;
    int a[] = { 1, 2, 3, 4, 5 };
    int b[] = { 3, 2, 1 };
    int *c = concatenate(a, m, b, n);
    assert(c);

    // swap_arrays(&a, &m, &b, &n);

    for(int i = 0; i < m+n; i++){
        printf("%d", c[i]);
    }
    printf("\n");
    for(int i = 0; i < m; i++){
        printf("%d", a[i]);
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%d", b[i]);
    }
    printf("\n");
    free(c);
    return 0;
}