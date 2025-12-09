#include <math.h>
#include <assert.h>

/**
 * find_sqrt(n, tolerance)
 * Finds the square root of a real number using Newton's method until a given tolerance level.
 * requires: tolerance is reasonable
 */
double find_sqrt(double n, double tolerance) {
    double x = 1.0;
    while (fabs(x*x - n) > tolerance) {
        x = (x + n/x) / 2;
    }
    return x;
}

int main(void) {
    assert(find_sqrt(100.500000, 0.01) * find_sqrt(100.500000, 0.01) - 100.500000 <= 0.01);
    assert(find_sqrt(1123.525, 0.00123) * find_sqrt(1123.525, 0.00123) - 1123.525 <= 0.00123);
    assert(find_sqrt(10000.250000, 0.00000000001) * find_sqrt(10000.250000, 0.00000000001) - 10000.250000 <= 0.00000000001);
}