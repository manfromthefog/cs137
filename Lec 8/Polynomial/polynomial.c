#include <stdio.h>
#include <assert.h>

double horner(double p[], int n, double x) {
    assert(n > 0);

    int c = p[n - 1]; // takes the value of (c)x^n 
    for (int i = n - 2; i >= 0; i--) {
        c = c * x + p[i]; // Add the new constant to the inner shell multiplied by x
    }
    return c;
}

int main(void) {
    int p[] = { 2, 9, 4, 3 };
    int len = sizeof(p) / sizeof(p[0]);

    printf("f(0) = %g\n", horner(p, len, 0));
    printf("f(1) = %g\n", horner(p, len, 1));
    printf("f(2) = %g\n", horner(p, len, 2));
    printf("f(-1) = %g\n", horner(p, len, -1));
    return 0;
}