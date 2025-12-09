#include <stdio.h>

int main() {
    int a = 5, b = 15;

    a <<= 4;
    a = a & b;

    printf("%d\n", a);
    return 0;
}