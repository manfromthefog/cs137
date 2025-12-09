#include <stdio.h>
#include <assert.h>
// https://www.programiz.com/online-compiler/5O0qoQdxnK63p

int sqrt_helper(int n, int i) {
    if (n==1) return 1;
    if (i==1) return -1;
    if (i*i == n) return i;
    else
        return sqrt_helper(n, --i);
}

int my_sqrt(int n) {
    return sqrt_helper(n,n);
}

int main() {
    // Write C code here
    assert(my_sqrt(25) == 5);
    assert(my_sqrt(4) == 2);
    assert(my_sqrt(26) == -1);
    assert(my_sqrt(67) == -1);

    return 0;
}