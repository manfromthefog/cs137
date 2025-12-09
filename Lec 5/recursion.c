#include <stdio.h>
#include <assert.h>

int factorial(unsigned int n) {
    if (n == 0) { // Base case
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Straight from the definition
int fib(unsigned int n) {
    if (n <= 1) { // Base case
        return n;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

// This version is "better" because it uses less stack frames
// It is called tail recursion
// It can be optimized by the compiler to avoid using stack frames
// The base case 
int sum_fib(int prev, int cur, int n) {
    if (n == 0) {
        return prev;
    } else {
        return sum_fib(cur, prev + cur, n - 1);
    }
}

int fib_tr(unsigned int n) {
    if (n == 0)
        return 0;
    return sum_fib(0, 1, n);
}

// Tail recursive example for factorial

int sum_fact(int n, int res) {
    if (n <= 1) {
        return res;
    } else {
        return sum_fact(n - 1, n * res);
    }
}
int factorial_tr(unsigned int n) {
    assert(n >= 0);
    return sum_fact(n, 1);
}

int main(void) {
    assert (factorial(0) == 1);
    assert (factorial(1) == 1);
    assert (factorial(6) == 720);
}