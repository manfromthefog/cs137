#include <stdio.h>
#include <stdlib.h>

int intcompare(const void *a, const void *b) {
    int p = *(const int *)a;
    int q = *(const int *)b;

    if (p > q) return 1;
    else if (p == q) return 0;
    else return -1;
}

int charcompare(const void *a, const void *b) {
    char p = *(const char *)a;
    char q = *(const char *)b;

    if ((p+q) % 2 == 1) return 1;
    else if (p == q) return 0;
    else return -1;
}

void printarr(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[10] = {5,7,1,4,10,2,8,9,3,6};
    const int n = sizeof(a) / sizeof(a[0]);

    printarr(a,n);
    qsort(a, n, sizeof(int), intcompare); // magic
    printarr(a,n);

    char s[] = "hello";
    const int m = sizeof(s) / sizeof(s[0]) - 1; // excluding the \0
    printf("%s\n", s);
    qsort(s, m, sizeof(char), charcompare);
    printf("%s\n", s);
}