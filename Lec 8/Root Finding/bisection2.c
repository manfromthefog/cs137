#include <assert.h>
#include <stdio.h>
#include "bisection2.h"

// Note we already included math.h in bisection.h

// No more hard-coded functions. The memory address of the function is passed into our function and returns a double.
double bisect(double a, double b, double epsilon, int iterations, double (*f) (double)) {
    // This time I'm going to try to use the f(a) version
    double m = b;
    double fa = f(a);

    assert(epsilon > 0 && f(a) * f(b) < 0);

    for (int i = 0; i < iterations; i++) {
        m = (a + b) / 2.0;
        if (fabs(f(m)) < epsilon) {
            return m;
        }

        // m and a are on the same side
        if (f(m) * f(a) > 0) {
            a = m;
            fa = f(a);
        }
        else {
            b = m;
        }
    }

    return m;
}

double f1(double x) {
    return x - cos(x);
}

double f2(double x) {
    return x*x*x - x + 1;
}

int main(void) {
    printf("%g\n", bisect(-10, 10, 0.0001, 50, f1));
    printf("%g\n", bisect(-10, 10, 0.0001, 50, f2));
    return 0;
}