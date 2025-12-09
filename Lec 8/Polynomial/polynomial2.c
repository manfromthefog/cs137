#include <stdio.h>
#include <assert.h>

double horner_recursive(double p[], int n, double x) {
    assert(n > 0);
    if (n == 1) {
        return p[0];
    }
    // You're basically asking the function to calculate the next constant for you
    // At the end of the day you're starting at the outermost function and going in
    return horner_recursive(p, n - 1, x) * x + p[n - 1];
}

double horner_tail_helper(double p[], int n, double x, double acc) {
    if (n == 0) {
        return acc;
    }
    return horner_tail_helper(p, n - 1, x, acc * x + p[n - 1]);
}
double horner_tail(double p[], int n, double x) {
    assert(n > 0);
    return horner_tail_helper(p, n, x, 0);
}

int main(void) {
    // Note here the coefficient array is reversed, since the recursion goes from out to in.
    double p_h[] = { 3, 4, 9, 2 };
    double p_l[] = { 2, 9, 4, 3 };
    int len = sizeof(p_h) / sizeof(p_h[0]);

    printf("f(2) = %g\n", horner_recursive(p_h, len, 2));
    printf("f(1) = %g\n", horner_recursive(p_h, len, 1));
    printf("f(2) = %g\n", horner_tail(p_l, len, 2));
    printf("f(1) = %g\n", horner_tail(p_l, len, 1));

    return 0;
}