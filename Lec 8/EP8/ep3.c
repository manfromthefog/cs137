#include <math.h>
#include <stdio.h>
/**
 * factorial(n)
 * Returns the factorial of an integer n.
 */
int factorial(int n) {
    if (n == 1) return 1;
    return factorial(n-1) * n;
}

/**
 * maclaurin_cos(x, n)
 * Returns the maclaurin series approximation of cos(x) up to degree n.
 */
double maclaurin_cos(double x, int n) {
    int j = 1;
    double k = 1;
    for (int i=2;i<=n;i+=2) {
        k += (pow(x, i) / factorial(i)) * pow(-1, j%2);
        j++;
    }
    return k;
}

int main() {
    printf("%.2f\n", maclaurin_cos(1.57, 6));
}