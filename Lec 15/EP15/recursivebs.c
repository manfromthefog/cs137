#include <stdio.h>
// https://www.programiz.com/online-compiler/9bPtLti6JxRYX

int binary_search_helper(int a[], int start, int end, int value) {
    if (start >= end) return -1;
    int mid = start + (end - start) / 2;
    
    if (a[mid] == value) return mid;
    
    if (a[mid] < value) {
        return binary_search_helper(a, mid + 1, end, value);
    }
    if (a[mid] > value) {
        return binary_search_helper(a, start, mid - 1, value);
    }
}

int binary_search_recur(int *a, int n, int v) {
    return binary_search_helper(a, 0, n-1, v);
}

int main() {
    // Write C code here
    int a[10] = { -10, -2, -2, 3, 3, 3, 5, 7, 9, 9 };
    printf("%d\n", binary_search_recur(a, 10, 9));

    return 0;
}