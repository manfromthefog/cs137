#include <stdio.h>

// the original function has max = 0
// automatically all Z- will give wrong results
int max_array(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
} 