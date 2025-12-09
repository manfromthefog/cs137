#include <stdio.h>
#include <assert.h>
// https://www.programiz.com/online-compiler/0EN1vmvNVkfjU

int power(int b, int n) {
    if (n == 0) 
        return 1;
    return b * power(b, n-1);
}

int geo_sum(int b, int n) {
    if (n == 0)
        return 1;
    return 1 + b * geo_sum(b, n-1);
}

int mult(int a, int b) {
    if (b == 0)
        return 0;

    return a + mult(a, b-1);
}

int triangle(int n) {
    if (n==0)
        return 0;
    return n + triangle(n-1);
}

int tetrahedral(int n) {
    if (n==0)
        return 0;
    return triangle(n) + tetrahedral(n-1);
}

int pentatope(int n) {
    if (n==0)
        return 0;
    return tetrahedral(n) + pentatope(n-1);
}

int main(void) {
    assert(triangle(2)==3);
    assert(triangle(3)==6);
    assert(triangle(5)==15);
    assert(tetrahedral(2)==4);
    assert(tetrahedral(3)==10);
    assert(pentatope(7)==210);
    assert(pentatope(12)==1365);
        
    int n = 67;
    printf("%d\n", triangle(n));
    printf("%d\n", tetrahedral(n));
    printf("%d\n", pentatope(n));
    return 0;
}
