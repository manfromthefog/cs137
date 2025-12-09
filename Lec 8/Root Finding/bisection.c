#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "bisection.h"


double f(double x) {
    return x - cos(x);
}

double bisect(double a, double b, double epsilon, int iter) {
    double m = a;

    // This is a good idea because later we will be finding which way to close the bounds
    // We already initalized m
    double fb = f(b);

    assert(epsilon > 0.0 && f(a) * f(b) < 0);

    for (int i = 0; i < iter; i++) {
        m = (a + b) / 2.0;

        // Alternatively fabs(f(m)) < epsilon is also valid
        if (fabs(b - a) < epsilon) {
            return m;
        }
        
        // Is f(m) on the same side as f(b)?
        // If yes, then set b to m, and find the new f(b) so next time we can know which side it's on
        if (f(m) * fb > 0) {
            b = m;
            fb = f(b);
        }

        // If f(m) is on the same side as a, then set a to m
        else {
            a = m;
        }
    }

    return m;
}

int main(void) {
    printf("%g\n", bisect(-10, 10, 0.0001, 50));
    return 0;
}