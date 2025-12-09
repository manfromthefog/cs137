#include <stdio.h>
#include <math.h>

/***
 * function ln_taylor_approximation()
 * @param positive integer n
 * @returns Approximates the natural logarithm of n using the taylor series approximation
 * 
 * The function calculates by first using a linear approximation ln(x) = ln(x/e^k) + k where k = floor(log_2(x))
 */
double ln_taylor_approximation(double x) {
    // Note here we changed bases, log2(x) = log(x) / log(2) is a logarithmic identity
    double k = floor(log(x) / log(2));
    double y = x / exp(k) - 1; // Subtracting y by 1 initially gives the approximation for ln(y-1+1)=ln(y)

    // ln(y + 1) = y - y^2/2 + y^3/3 - y^4/4 ... it is a well known fact
    // We will only go until the 30th term, which is what the question requires
    // Initialize the summation at y, and then start adding new terms
    double ln_y = y;
    for (int i = 2; i < 31; i++) {
        // Note we are controlling whether we add or subtract the nth term using (-1)^(n-1)
        // This is standard practice when writing a Taylor series in summation notation
        ln_y += (pow(y, i) / i) * pow(-1, i-1);
    }

    return ln_y + k;
}

int main(void) {
    // Read a positive double number
    double n;
    printf("Enter a positive number: ");
    if (scanf("%lf", &n) != 1 || n <= 0.0) {
        printf("Invalid input\n");
        return 1;
    }

    double approximated_ln = ln_taylor_approximation(n);
    double mathh_ln = log(n);

    printf("Approximated ln(%.2f) = %.8f\n", (double)n, approximated_ln);
    printf("math.h ln(%.2f) = %.8f\n", (double)n, mathh_ln);
    printf("Absolute difference = %.8f\n", fabs(approximated_ln - mathh_ln));    
    
    return 0;
}