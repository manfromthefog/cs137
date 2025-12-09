#include <stdio.h>

int stairs_help(int n, int c, int p) {
    if (n == 1) return p;
    if (n == 2) return c;

    return stairs_help(n-1, c+p, c);
}

int stairs_tr(int n) {
    return stairs_help(n, 2, 1);
}

int stairs_re(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    return stairs_re(n - 1) + stairs(n - 2);
}

int main() {
    printf("%d\n", stairs_tr(10));
    printf("%d\n", stairs_re(10));
    return 0;
}